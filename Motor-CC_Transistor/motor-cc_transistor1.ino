#define POTENCIOMETRO A0
#define TRANSISTOR 3

void setup()
{
  pinMode(POTENCIOMETRO, INPUT);
  pinMode(TRANSISTOR, OUTPUT);
}

void loop()
{
  analogWrite(TRANSISTOR,analogRead(POTENCIOMETRO)/4); 
  delay(1000);
}