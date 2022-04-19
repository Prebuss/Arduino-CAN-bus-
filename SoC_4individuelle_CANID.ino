#include <Adafruit_GFX.h>    // Core graphics library
#include "Adafruit_ILI9341.h" // Hardware-specific library
#include <SPI.h>
#include "mcp2515_can.h"
#include <SD.h>


#define CAN_2515
#define TFT_DC 9
#define TFT_CS 10
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define SD_CS 4
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

const int SPI_CS_PIN = 9;
const int CAN_INT_PIN = 2;
const int LED        = 8;
boolean ledON        = 1;

mcp2515_can CAN(SPI_CS_PIN); // Set CS pin

void setup() {
  tft.begin();
  tft.fillScreen(WHITE);
  tft.fillRect(0, 0, 240, 79, BLACK);
  tft.fillRect(0, 80, 240, 79, BLACK);
  tft.fillRect(0, 160, 240, 79, BLACK);
  tft.fillRect(0, 240, 240, 80, BLACK);

  tft.setTextSize(3);
  tft.setCursor(0, 13);    tft.print("Battery 1");
  tft.setCursor(13, 43);    tft.print("SoC");
  tft.setCursor(0, 93);    tft.print("Battery 2");
  tft.setCursor(13, 123);    tft.print("SoC");
  tft.setCursor(0, 173);    tft.print("Battery 3");
  tft.setCursor(13, 203);    tft.print("SoC");
  tft.setCursor(0, 253);    tft.print("Battery 4");
  tft.setCursor(13, 283);    tft.print("SoC");

  delay(2000);
  SERIAL_PORT_MONITOR.begin(9600);

  pinMode(LED, OUTPUT);

  while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
        
  }
}// void setup


void loop() {
  unsigned char len = 0;
  unsigned char buf[8];
  unsigned long canid = CAN_MSGAVAIL;


  for (int p = 0; p <= 4; p++) {
    //Changing CAN ID
    if (p == 1){
      CAN.sendMsgBuf(0x19B50500, 1, 0, 0);
      delay(100);
    }
    else if(p == 2){
      CAN.sendMsgBuf(0x19B50001, 1, 0, 0);
      delay(100);
    }
    else if(p == 3){
      CAN.sendMsgBuf(0x19B50008, 1, 0, 0);
      delay(100);
    }
    else if(p == 4){
      CAN.sendMsgBuf(0x19B50000, 1, 0, 0);
      delay(100);
    }
    else if(p == 0){
      CAN.sendMsgBuf(0x19B50600, 1, 0, 0);
      delay(100);
    }

    CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

    unsigned long canId = CAN.getCanId();
    
    tft.setTextColor(WHITE); tft.setTextSize(3); 

    if(canId == 0x19B50500){
      int soc = (buf[6]);                             // SoC info - Battery 1
      tft.fillRect(80, 40, 169, 30, BLACK);
      tft.setCursor(136, 43);       tft.print(soc);
      tft.setCursor(220, 43);       tft.print("%");
    }

    if(canId == 0x19B60500){
      int soc2 = (buf[6]);                             //
      tft.fillRect(80, 120, 169, 30, BLACK);
      tft.setCursor(136, 123);      tft.print(soc2);
      tft.setCursor(220, 123);      tft.print("%");
    }
    if(canId == 0x19B70500){
      int soc3 = (buf[6]);                              //
      tft.fillRect(80, 200, 169, 30, BLACK); // 
      tft.setCursor(136, 203);    tft.print(soc3);
      tft.setCursor(220, 203);    tft.print("%");
    }
    if(canId == 0x19B80500){
      int soc4 = (buf[6]); //Number of live cells
      tft.fillRect(80, 280, 160, 30, BLACK); // 
      tft.setCursor(136, 283);    tft.print(soc4);
      tft.setCursor(220, 283);    tft.print("%");
    }
    /* 
    if(canId == 0x19B90500){
      int soc5 = (buf[6]);
      tft.fillRect(60, 0, 180, 40, BLACK);
      tft.setCursor(136, 13);     tft.print(soc5);
      tft.setCursor(220, 13);     tft.print("%");
    }*/

    for (int i = 0; i < len; i++) { 

      if (ledON && i == 0) {
        digitalWrite(LED, buf[i]);
        ledON = 0;
      }
      else if ((!(ledON)) && i == 4) {
        digitalWrite(LED, buf[i]);
        ledON = 1;

      }// else if
    }// for loop
  } // For loop
}// void loop

//END FILE