#include <Servo.h>
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
Servo servo;

int A = 29;       // primer motor giro atras
int B = 31;       // primer motor giro adelante
int C = 33;       // segundo motor giro atras
int D = 35;       // segundo motor giro adelante
int vel = 200;    // velocidad de los motores
int estado = 's'; // inicia detenido el carro

int a = 0;        // ángulo
int dir = 1;      // grados de giro para el servo


unsigned long tiempoAnterior = 0;   // tiempo de la última vez que se ejecutó el codigo del "graficador"
const long intervalo = 50;          // tiempo para que se vuelva a ejecutar el codigo del "graficador"

void setup()
{
  Serial1.begin(9600);  // inicia el puerto serial para comunicacion

  pinMode(A, OUTPUT);  // define los pines de los motores como salidas
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  
  servo.attach(8);  // define el pin para el servo
  servo.write(0);
  
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous(); // inicia el modo continuo back-to-back,
                            // toma las lecturas lo más rápido posible
}

void loop()
{ 
  graficador ();
  carro ();
}

void graficador()
{
  // variable para almacenar el tiempo transcurrido
  unsigned long tiempoActual = millis();
  
  // verifica si es hora de ejecutar el codigo dentro, es decir: 
  // si la diferencia entre el tiempoActual y el tiempoAnterior que se ejecutó el codigo,
  // es más grande que el intervalo de tiempo que deseamos para ejecutar el codigo
  if (tiempoActual - tiempoAnterior >= intervalo) {

  // almacena en una variable el valor de distancia
  long distancia = sensor.readRangeContinuousMillimeters();

  // imprime en el puerto serial
  Serial1.print(distancia);
  Serial1.print(",");
  Serial1.println(a);

  // mueve el servo
  a+=dir;
  servo.write(a);

  // cambia de dirección el servo
  if(a==0)dir=1;
  if(a==180)dir=-1;

  // guarda el tiempo de la ultima vez que se ejecutó el codigo
  tiempoAnterior = tiempoActual;

  }
}

void carro()
{
  if(Serial1.available()>0){  // lee el puerto serial y almacena en estado
    estado = Serial1.read();
  }
  if(estado=='w'){  // boton adelante
    analogWrite(A, 0);     
    analogWrite(B, vel); 
    analogWrite(C, 0);  
    analogWrite(D, vel);       
  }
   if(estado=='a'){  // boton izquierda
    analogWrite(A, 0);     
    analogWrite(B, 0); 
    analogWrite(C, 0);  
    analogWrite(D, vel);  
  } 
  if(estado=='d'){  // boton derecha
    analogWrite(A, 0);     
    analogWrite(B, vel); 
    analogWrite(C, 0);  
    analogWrite(D, 0);     
  }
  if(estado=='s'){  // boton parar
    analogWrite(A, 0);     
    analogWrite(B, 0); 
    analogWrite(C, 0);  
    analogWrite(D, 0);
  }
  if(estado=='r'){  // boton reversa
    analogWrite(A, vel);     
    analogWrite(B, 0); 
    analogWrite(C, vel);  
    analogWrite(D, 0);      
  }
}
