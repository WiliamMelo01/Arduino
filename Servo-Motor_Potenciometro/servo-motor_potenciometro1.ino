#include<Servo.h>

#define POTENCIOMETRO A5
#define SERVO 3

Servo servo;
void setup()
{
  pinMode(POTENCIOMETRO, INPUT);
  Serial.begin(9600);
  servo.attach(SERVO);
  servo.write(0);
}

void loop()
{
  int potencia = analogRead(POTENCIOMETRO);
  float angulo = map(potencia,0,1023,0,180);
  servo.write(angulo);
  delay(100);
}