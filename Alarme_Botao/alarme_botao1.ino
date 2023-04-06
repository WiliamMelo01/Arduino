#define BUTTON 13
#define BUZZER 6

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);

}

void loop()
{ 
  if(digitalRead(13) == 1){
    for(int count = 0;count < 5;count++){
    	tone(BUZZER,3101,200);
      	delay(500);
    }
  }
}