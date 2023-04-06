#define TRANSISTOR 13
#define BOTAO 12

int count = 0;

void setup()
{
  pinMode(TRANSISTOR,OUTPUT);
  pinMode(BOTAO,INPUT);
}

void loop()
{
  if(digitalRead(BOTAO) == 1){
    count+=1;
  }
  if((count % 2)==0){
  	digitalWrite(TRANSISTOR,HIGH);
  }else{
  	digitalWrite(TRANSISTOR,LOW);
  }
  
  delay(200);
}