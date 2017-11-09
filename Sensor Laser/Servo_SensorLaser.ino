
#include <Servo.h>
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
Servo servo;

int a = 0;
int dir = 5;

void setup()
{
  Serial.begin(9600);
  servo.attach(9);
  servo.write(0);
  
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous(10);
}

void loop()
{
  long distancia = sensor.readRangeContinuousMillimeters();
  
  Serial.print(distancia);
  Serial.print(",");
  Serial.println(a);

  a+=dir;
  servo.write(a);
  
  if(a==0)dir=5;
  if(a==180)dir=-5;

  delay(10);
}
