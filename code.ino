// project by learn - electronics 
// subscribe NOW !

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27 ,16 ,2);

int n = 0;

int oldValue = 1;
 
#define irPin 4
#define buttonPin 11

void setup(){
  pinMode(irPin,INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.begin();
  lcd.backlight();

}
void loop(){
    lcd.setCursor(0,0);
  lcd.print("Count : ");

  if(digitalRead(irPin)==0 && oldValue==1){
    oldValue=0;
    count();
  }
  else if(digitalRead(irPin)==1 && oldValue == 0){
    oldValue = 1;
  }

  if (digitalRead(buttonPin)==0){
    reset();
  }
  delay(100);

}
void count(){
  n = n + 1;

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(n);
}

void reset(){
  n = 0;
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(n);

}


