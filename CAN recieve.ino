#include <SPI.h> //Library for using SPI Communication 
#include <mcp2515.h> //Library for using CAN Communication
#include <LiquidCrystal_I2C.h> //Library for using 16x2 LCD display

struct can_frame canMsg; 
MCP2515 mcp2515(53); // SPI CS Pin 10 for Uno, Pin 53 for Mega2560 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 (Standard address) for a 16 chars and 2 line display

//Creating two custom characters to print on the display
byte smiley[8] = {
  B11011,
  B11011,
  B00000,
  B00000,
  B10001,
  B10001,
  B01110,
};
byte smileyWink[8] = {
  B00011,
  B11011,
  B00000,
  B00000,
  B10001,
  B10001,
  B01110,
};

void setup() {
  SPI.begin();   //Begins SPI communication
  Serial.begin(9600); //Begins Serial Communication at 9600 baud rate 

  mcp2515.reset(); //Reset mcp unit to ensure proper operation
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz 
  mcp2515.setNormalMode();  //Sets CAN at normal mode

  lcd.begin();  // initialize the lcd 
  lcd.backlight();  //Start backlighting for LCD display

  lcd.createChar(0, smiley);
  lcd.createChar(1, smileyWink);  
}

void loop(){
  
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x036)){
    int x = canMsg.data[0]; //Read data byte 0
    int y = canMsg.data[1]; //Read data byte 1

    lcd.clear();
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
    delay(5000);

    lcd.setCursor(15,0);
    lcd.write(byte(0));
    delay(1000);
    lcd.setCursor(15,0);
    lcd.write(byte(1));
    delay(5000);
  }
}
