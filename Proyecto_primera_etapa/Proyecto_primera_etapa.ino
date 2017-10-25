//Control de Giro moto DC

const int pinPot=0;
const int pinMotorA=5;
const int pinMotorB=6;
const int pinMotorC=7;
const int pinMotorD=8;
int valorPot;


void setup() {

  pinMode(pinMotorA, OUTPUT); //Declaracion de pinesde control 
  pinMode(pinMotorB, OUTPUT); //como salidas

  pinMode(pinMotorC, OUTPUT); //Declaracion de pinesde control 
  pinMode(pinMotorD, OUTPUT); //como salidas

  digitalWrite(pinMotorA, LOW); //apagamos el motor
  digitalWrite(pinMotorB, LOW);//al inicio

  digitalWrite(pinMotorC, LOW); //apagamos el motor
  digitalWrite(pinMotorD, LOW);//al inicio
}

void loop() {

  valorPot = analogRead(pinPot); //leer valor de pot
  if(valorPot < 504) {
    digitalWrite(pinMotorA, HIGH); //giro a la izquierda
    digitalWrite(pinMotorB, LOW);
 }else if(valorPot > 520) {
    digitalWrite(pinMotorA, LOW); //giro a la iderecha
    digitalWrite(pinMotorB, HIGH);  
 }else {
    digitalWrite(pinMotorA, LOW); //apagamos motor
    digitalWrite(pinMotorB, LOW); 
  }
    
  

}
