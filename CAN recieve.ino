#include <SPI.h> //Library for using SPI Communication 
#include <mcp2515.h> //Library for using CAN Communication
#include <LiquidCrystal_I2C.h>

struct can_frame canMsg; 
MCP2515 mcp2515(53); // SPI CS Pin 10 
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  SPI.begin();   //Begins SPI communication
  Serial.begin(9600); //Begins Serial Communication at 9600 baud rate 

  mcp2515.reset();                          
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz 
  mcp2515.setNormalMode();  //Sets CAN at normal mode

  lcd.begin();                      // initialize the lcd 
  lcd.backlight();
}

void loop(){
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x036)){
     int x = canMsg.data[0];         
     int y = canMsg.data[1];  
/*
     Serial.print("Kelembaban: ");
     Serial.print(x);
     Serial.print(" Suhu: ");
     Serial.println(y);
*/
     lcd.setCursor(0,0);
     lcd.print("Arbitrary1:");
     lcd.setCursor(12,0);
     lcd.print(x);
     lcd.setCursor(15,0);
     lcd.print("%");

     lcd.setCursor(0,1);
     lcd.print("Arbitrary2:");
     lcd.setCursor(12,1);
     lcd.print(y);
     lcd.setCursor(15,1);
     lcd.print("%");
     delay(200);
    }
  /*
  lcd.setCursor(0,0);
  lcd.print("Hei på deg,");
  lcd.setCursor(0,1);
  lcd.print("Henrik");
  */
}
