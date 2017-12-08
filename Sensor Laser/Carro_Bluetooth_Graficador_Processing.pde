import processing.serial.*;  // carga libreria serial
Serial port;  // crea una variable (objeto) para puerto

// distancia [0] y ángulo en radianes [1]
int n=2;  // numero de variables que envía el arduino separadas por coma
float[] data = new float[n];

void setup()
{
  size(1360, 700);  // tamaño de la pantalla
  println(Serial.list());  // imprime la lista de puertos seriales
  port = new Serial(this, Serial.list()[0], 9600);  // se asigna el puerto serial del cual lee los datos y la velocidad
  port.bufferUntil('\n');
}

void draw()
{ 
  if (data[1]==0) {  // cuando el ángulo llega a 0 limpia la pantalla
    background(0);  // color negro de fondo
  }
  if (data[1]==180) {  // cuando el ángulo llega a 180 limpia la pantalla
    background(0);     // color negro de fondo
  }
  stroke(0, 255, 0, 255);  // color verde del punto de referencia
  point(width/2, 690);  // ubicación del punto de referencia
  strokeWeight(10);  // tamaño de los puntos
  pushMatrix();  // inicia un nuevo marco de referencia
  translate(width/2, 690);  // establece el nuevo punto de referecia
  rotate(-HALF_PI-data[1]*PI/180);  // rotación de los datos de ángulo en coodenadas polares
  stroke(255, 0, 0, 255);  // color rojo de los puntos para el mapeo
  point(0,data[0]/2);  // dibuja los puntos para el mapeo
  popMatrix();  // fin del nuevo marco de referencia
 }
 
// función que corre sola cada vez que entra información por el puerto serial 
void serialEvent(Serial port)
{
  String bufString = port.readString();
  data = float(split(bufString, ','));
}

// función que envia las letras establecidas por el puerto serial
void keyPressed()
{
  if(key=='w'){
    port.write('w');
  }
  if(key=='d'){
    port.write('d');
  }
  if(key=='a'){
    port.write('a');
  }
  if(key=='s'){
    port.write('s');
  }
  if(key=='r'){
    port.write('r');
  }
}