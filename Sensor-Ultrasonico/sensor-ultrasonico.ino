#define TRIG 13
#define ECHO 12
#define BUZZER 2
void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  //Pega a duracao da onda em microsegundos
  float duration = pulseIn(ECHO,HIGH);
  float distance = (duration / 2) * 0.0343;
  
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println("cm");
  Serial.println("------------");
  
  if(distance < 50){
  	tone(BUZZER,2014);
  }else{
  	noTone(BUZZER);
  }
  
  delay(300);
  
}