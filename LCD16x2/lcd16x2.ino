#include <LiquidCrystal.h>

LiquidCrystal lcd(5,7,10,11,12,13);

byte loadingBlock[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
byte smile[8] ={0b00000,0b00000,0b01010,0b00000,0b10001,0b01110,0b00000,0b00000};
void setup()
{
  lcd.begin(16,2);
  lcd.createChar(1,loadingBlock);
  lcd.createChar(2,smile);
  lcd.setCursor(0,0);
  lcd.print("LOADING...");
  lcd.setCursor(0,1);
  for(int count = 0;count<=17;count++){
  	lcd.write(1);
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HELLO");
  lcd.setCursor(6,0);
  lcd.write(2);
  
}

void loop()
{
 
}