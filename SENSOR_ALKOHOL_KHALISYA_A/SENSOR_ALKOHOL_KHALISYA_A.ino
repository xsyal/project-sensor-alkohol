#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11,10, 9, 8); 
int GAS = 3;
int LEDRED = 4;
int LEDGREEN = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode (GAS,INPUT);
  pinMode (LEDRED, OUTPUT);
  pinMode (LEDGREEN, OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("SISTEM PENDETEKSI");
  lcd.setCursor(0,1);
  lcd.print("ALKOHOL");
  lcd.setCursor(0,2);
  lcd.print("TELEKOMUNIKASI PNJ");
  delay (1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  int GAS_READ = digitalRead(GAS);
  if (GAS_READ == LOW) {
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print("ALCOHOL DETECTED");
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDGREEN, HIGH);
    delay(20);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print("ALCOHOL NOT DETECTED");
    digitalWrite(LEDGREEN, LOW);
    digitalWrite(LEDRED, HIGH);
    delay(20);
  }
}
