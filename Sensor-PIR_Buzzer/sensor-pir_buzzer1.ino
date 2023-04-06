#define SENSOR_DISTANCIA A0
#define BUZZER 3


void setup()
{
  pinMode(SENSOR_DISTANCIA, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  const int moviment = digitalRead(SENSOR_DISTANCIA);
  if(moviment == 1){
  	tone(BUZZER,21);
  }else{
  noTone(BUZZER);
  }
  delay(200);
}