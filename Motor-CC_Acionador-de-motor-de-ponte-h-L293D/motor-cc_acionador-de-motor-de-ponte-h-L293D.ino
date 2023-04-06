#define MOTOR 3
#define MOTOR_RIGHT 5
#define MOTOR_LEFT 4
#define INTERRUPTOR 2

char* direction = "L";

void setup()
{
  pinMode(MOTOR, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(INTERRUPTOR, INPUT);
  analogWrite(MOTOR,255);
  Serial.begin(9600);
}

void loop()
{
  
  if(digitalRead(INTERRUPTOR)==1){
    	direction = "L";
    }else{
    	direction = "R";
    }

  
  Serial.println(direction);
  
  if(direction == "R"){
    digitalWrite(MOTOR_RIGHT,LOW);
    digitalWrite(MOTOR_LEFT,HIGH);
  }else{
    digitalWrite(MOTOR_RIGHT,HIGH);
    digitalWrite(MOTOR_LEFT,LOW);
  }
  
  delay(1000);
}