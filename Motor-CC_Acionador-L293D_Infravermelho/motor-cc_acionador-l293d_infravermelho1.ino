#include <IRremote.h>

#define MOTOR 11
#define MOTOR_RIGHT 9
#define MOTOR_LEFT 10
#define SENSOR_INFRAVERMELHO 12

// Cria um objeto IRrecv para ler os dados do sensor
IRrecv sensorInfravemelho(SENSOR_INFRAVERMELHO);

void setup()
{
  pinMode(MOTOR, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  pinMode(MOTOR_LEFT, OUTPUT);
  
  // Liga o motor e inicia a rotação no sentido horário
  analogWrite(MOTOR,255);
  digitalWrite(MOTOR_RIGHT,HIGH);
  digitalWrite(MOTOR_LEFT,LOW);
  
  // Inicia a leitura do sinal infravermelho pelo sensor
  sensorInfravemelho.enableIRIn();
  
}

void loop()
{
  // Verifica se um sinal infravermelho foi detectado
  if(sensorInfravemelho.decode()){
  	
    // Lê o valor do botão pressionado
    int pressedButton = sensorInfravemelho.decodedIRData.command;
    
    switch(pressedButton){
    	case 0:
      		// Para o motor
      		digitalWrite(MOTOR_RIGHT,LOW);
  			digitalWrite(MOTOR_LEFT,LOW);
      		break;
      	case 4:
      		// Roda o motor no sentido anti-horário		
      		digitalWrite(MOTOR_RIGHT,LOW);
  			digitalWrite(MOTOR_LEFT,HIGH);
     		break;
      	case 6:
      		// Roda o motor no sentido horário		
      		digitalWrite(MOTOR_RIGHT,HIGH);
  			digitalWrite(MOTOR_LEFT,LOW);
     		break;
      	default:
      		break;
    }
    
    // Retoma a leitura do sinal infravermelho pelo sensor
    sensorInfravemelho.resume();
  }
}