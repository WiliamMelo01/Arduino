#include <Adafruit_LiquidCrystal.h>

#define TEMP A0

Adafruit_LiquidCrystal lcd(0);

void setup()
{
  pinMode(TEMP, INPUT);
  Serial.begin(9600);
  
  
  lcd.begin(16,2);
  lcd.print("BEM VINDO!");
  delay(400);
  lcd.clear();
  lcd.print("CARREGANDO...");
  delay(200);
  lcd.clear();
  lcd.print("Temperatura:");
}

void loop()
{
  float TENSAO = (analogRead(TEMP)*5);
  TENSAO/=1024;

  float temp_c = (TENSAO-0.5) * 100;

  lcd.setCursor(0,1);
  lcd.print(temp_c);
  lcd.print("C");
  Serial.write(176);
  delay(300);
}