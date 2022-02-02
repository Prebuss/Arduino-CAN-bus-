
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int tallVerdi = 200;
float prosent = 0.9999;
float soc = prosent*100;


void setup()
{
  //batteri informasjon
  
  /* Eksempel på hvordan å lagre en string med tekst
  char Str4[15] = "arduino";
  char Var2[8] = {'a', 'r', 'd', 'u', 'i', 'n', 'o'};
  */

  //LCD oppsett
  lcd.begin();                      // initialize the lcd 
  lcd.backlight();


  /* Print a message to the LCD.

  lcd.setCursor(0,0);
  //lcd.print("Batteriprosent:");
  lcd.setCursor(0,1);
  int bat1 = 80;
  //lcd.print("Soc: ");
  lcd.setCursor(5,1);
  lcd.print(soc);
  lcd.setCursor(10,1);
  lcd.print("%");
  */

}


void loop()
{
  lcd.setCursor(0,0);
  lcd.print("B1");
  lcd.setCursor(0,1);
  lcd.setCursor(3,0);
  lcd.print(69);
  lcd.setCursor(6,0);
  lcd.print("%");

  lcd.setCursor(8,0);
  lcd.print("B2");
  lcd.setCursor(0,1);
  lcd.setCursor(11,0);
  lcd.print(69);
  lcd.setCursor(14,0);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("B3");
  lcd.setCursor(3,1);
  lcd.print(69);
  lcd.setCursor(6,1);
  lcd.print("%");

  lcd.setCursor(8,1);
  lcd.print("B4");
  lcd.setCursor(11,1);
  lcd.print(169);
  lcd.setCursor(14,1);
  lcd.print("%");

  delay(5000);
  lcd.setCursor(0,0);
  lcd.print("                            "); //Clear first line of the screen
  lcd.setCursor(0,1);
  lcd.print("                            "); //Clear second line of the screen
  lcd.setCursor(0,0);
  lcd.print("Bat1:");
  lcd.setCursor(6,0);
  lcd.print("100%");
  lcd.setCursor(0,1);
  lcd.print("Bat2:");
  lcd.setCursor(6,1);
  lcd.print("100%");
  
  delay(5000);
  lcd.setCursor(0,0);
  lcd.print("                            "); //X321ANA
  lcd.setCursor(0,1);
  lcd.print("                            "); //Hugh Gee Rection
  
  lcd.setCursor(0,0);  
  lcd.print("Bat3:");
  lcd.setCursor(6,0);
  lcd.print("100%");
  lcd.setCursor(0,1);
  lcd.print("Bat4:");
  lcd.setCursor(6,1);
  lcd.print("100%");

  delay(5000);
  lcd.setCursor(0,0);
  lcd.print("                            ");
  lcd.setCursor(0,1);
  lcd.print("                            ");

}
