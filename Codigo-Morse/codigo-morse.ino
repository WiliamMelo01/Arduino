#include <LiquidCrystal.h>


#include <IRremote.h>

#define SENSOR_INFRAVERMELHO 2
#define LED 4
#define BUZZER 7

int pressedButton;
int ledStatus;
char morseCodes[10][6] = {
  "-----",
  ".----",
  "..---",
  "...--",
  "....-",
  ".....",
  "-....",
  "--...",
  "---..",
  "----."
};

IRrecv irrecv(SENSOR_INFRAVERMELHO);
LiquidCrystal lcd(8,9,10,11,12,13);

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  lcd.begin(16,2);
}

void loop() {
  
  if (irrecv.decode()) {
    lcd.clear();
    pressedButton = irrecv.decodedIRData.command;
    irrecv.resume();
    lcd.print("NUMBER: ");
    int buttonPressedOnRemoteControl = returnNumberPressOnRemoteControl(pressedButton);
    if(buttonPressedOnRemoteControl != 999){
    	lcd.print(buttonPressedOnRemoteControl);
    }else{
    	lcd.print("N/A");
    }
    char * numberInMorseCode = returnMorseCodeFromAGivenNumber(pressedButton);
    Serial.println(numberInMorseCode);
    lcd.setCursor(0,1);
    lcd.print("MORSE: ");
    lcd.print(numberInMorseCode);
    playMorseCode(numberInMorseCode);
  }
}

char* returnMorseCodeFromAGivenNumber(int number) {
  static char morseCodeFromPressedButton[6];
  switch (number) {
    case 12:
      strcpy(morseCodeFromPressedButton, morseCodes[0]);
      break;
    case 16:
      strcpy(morseCodeFromPressedButton, morseCodes[1]);
      break;
    case 17:
      strcpy(morseCodeFromPressedButton, morseCodes[2]);
      break;
    case 18:
      strcpy(morseCodeFromPressedButton, morseCodes[3]);
      break;
    case 20:
      strcpy(morseCodeFromPressedButton, morseCodes[4]);
      break;
    case 21:
      strcpy(morseCodeFromPressedButton, morseCodes[5]);
      break;
    case 22:
      strcpy(morseCodeFromPressedButton, morseCodes[6]);
      break;
    case 24:
      strcpy(morseCodeFromPressedButton, morseCodes[7]);
      break;
    case 25:
      strcpy(morseCodeFromPressedButton, morseCodes[8]);
      break;
    case 26:
      strcpy(morseCodeFromPressedButton, morseCodes[9]);
      break;
    default:
      strcpy(morseCodeFromPressedButton, "N/A");
      break;
  }
  return morseCodeFromPressedButton;
}
int returnNumberPressOnRemoteControl(int numberFromRemoteControl) {
  static int numberPressed;
  switch (numberFromRemoteControl) {
    case 12:
      numberPressed = 0;
      break;
    case 16:
      numberPressed = 1;
      break;
    case 17:
      numberPressed = 2;
      break;
    case 18:
      numberPressed = 3;
      break;
    case 20:
      numberPressed = 4;
      break;
    case 21:
      numberPressed = 5;
      break;
    case 22:
     numberPressed = 6;
      break;
    case 24:
      numberPressed = 7;
      break;
    case 25:
      numberPressed = 8;
      break;
    case 26:
      numberPressed = 9;
      break;
    default:
      numberPressed = 999;
      break;
  }
  return numberPressed;
}
void playMorseCode(char * morseCode) {
  pinMode(4,OUTPUT);
  irrecv.disableIRIn();
  for(int i = 0; i < strlen(morseCode); i++){
    if(morseCode[i] == '.'){
      tone(BUZZER,100,100);
      digitalWrite(4,HIGH);
      delay(100);
      digitalWrite(4,LOW);
      delay(700);
    }else if(morseCode[i] == '-'){
      tone(BUZZER,100,400);
      digitalWrite(4,HIGH);
      delay(400);
      digitalWrite(4,LOW);
      delay(700);
    }
  }
     
  irrecv.enableIRIn();
}


