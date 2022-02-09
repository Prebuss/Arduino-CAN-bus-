#include <SPI.h>                //Library for using SPI Communication
#include <mcp2515.h>            //Library for using CAN Communication
#include <LiquidCrystal_I2C.h>  //Library for using 16x2 LCD display

struct can_frame canMsg;
MCP2515 mcp2515(53);                 // SPI CS Pin 10 for Uno, Pin 53 for Mega2560
LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 (Standard address) for a 16 chars and 2 line display


void setup() {
  SPI.begin();         //Begins SPI communication
  Serial.begin(9600);  //Begins Serial Communication at 9600 baud rate

  mcp2515.reset();                            //Reset mcp unit to ensure proper operation
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);  //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();                    //Sets CAN at normal mode

  lcd.begin();      // initialize the lcd
  lcd.backlight();  //Start backlighting for LCD display
}

void loop() {

  //0x031 read SoC[0], SoH[1], Voltage hig/low[2/3], Current high/low[4/5], Error[6/7]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int SoC = anMsg.data[0];      //State of charge 
    int SoH = anMsg.data[1];      //State of health 
    int VtotH = anMsg.data[2];    //Battery pack voltage (High byte value) 
    int VtotL = anMsg.data[3];    //Battery pack voltage (Low byte value)
    int CtotH = anMsg.data[4];    //Battery pack current (High byte value)
    int CtotL = anMsg.data[5];    //Battery pack current (Low byte value)
    int error = anMsg.data[6];    //Error number (Check REC manual for what error)
    int errorid = anMsg.data[7];  //Number of the cell or temp.sensor with the error)
  }

  //0x032 read Cell temperature 1-8[0-7]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int T1 = anMsg.data[0]; //Temperature cell 1
    int T2 = anMsg.data[1]; //Temperature cell 2
    int T3 = anMsg.data[2]; //Temperature cell 3
    int T4 = anMsg.data[3]; //Temperature cell 4
    int T5 = anMsg.data[4]; //Temperature cell 5
    int T6 = anMsg.data[5]; //Temperature cell 6
    int T7 = anMsg.data[6]; //Temperature cell 7
    int T8 = anMsg.data[7]; //Temperature cell 8
  }
  
  //0x033 read Cell voltage high/low 1-4[0-7]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int V1H = anMsg.data[0];  //Voltage cell 1 (High byte value)
    int V1L = anMsg.data[1];  //Voltage cell 1 (Low byte value)
    int V2H = anMsg.data[2];  //Voltage cell 2 (High byte value)
    int V2L = anMsg.data[3];  //Voltage cell 2 (Low byte value)
    int V3H = anMsg.data[4];  //Voltage cell 3 (High byte value)
    int V3L = anMsg.data[5];  //Voltage cell 3 (Low byte value)
    int V4H = anMsg.data[6];  //Voltage cell 4 (High byte value)
    int V4L = anMsg.data[7];  //Voltage cell 4 (Low byte value)
  }

  //0x034 read Cell voltage high/low 5-8[0-7]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int V5H = anMsg.data[0];  //Voltage cell 5 (High byte value)
    int V5L = anMsg.data[1];  //Voltage cell 5 (Low byte value)
    int V6H = anMsg.data[2];  //Voltage cell 6 (High byte value)
    int V6L = anMsg.data[3];  //Voltage cell 6 (Low byte value)
    int V7H = anMsg.data[4];  //Voltage cell 7 (High byte value)
    int V7L = anMsg.data[5];  //Voltage cell 7 (Low byte value)
    int V8H = anMsg.data[6];  //Voltage cell 8 (High byte value)
    int V8L = anMsg.data[7];  //Voltage cell 8 (Low byte value)
  }

  //0x035 read Cell voltage high/low 9-12[0-7]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int V9H = anMsg.data[0];  //Voltage cell 9 (High byte value)
    int V9L = anMsg.data[1];  //Voltage cell 9 (Low byte value)
    int V10H = anMsg.data[2]; //Voltage cell 10 (High byte value)
    int V10L = anMsg.data[3]; //Voltage cell 10 (Low byte value)
    int V11H = anMsg.data[4]; //Voltage cell 11 (High byte value)
    int V11L = anMsg.data[5]; //Voltage cell 11 (Low byte value)
    int V12H = anMsg.data[6]; //Voltage cell 12 (High byte value)
    int V12L = anMsg.data[7]; //Voltage cell 12 (Low byte value)
  }

  //0x036 read Cell voltage high/low 13-16[0-7]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int V13H = anMsg.data[0]; //Voltage cell 13 (High byte value)
    int V13L = anMsg.data[1]; //Voltage cell 13 (Low byte value)
    int V14H = anMsg.data[2]; //Voltage cell 14 (High byte value)
    int V14L = anMsg.data[3]; //Voltage cell 14 (Low byte value)
    int V15H = anMsg.data[4]; //Voltage cell 15 (High byte value)
    int V15L = anMsg.data[5]; //Voltage cell 15 (Low byte value)
    int V16H = anMsg.data[6]; //Voltage cell 16 (High byte value)
    int V16L = anMsg.data[7]; //Voltage cell 16 (Low byte value)
  }

  //0x037 read Max charge voltage high/low[0/1] max charge current high/low[2/3]
  //Min discharge voltage high/low[4/5] max discharge current high/low[6/7]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int cVH = anMsg.data[0];  //Charge voltage (High byte value)
    int cVL = anMsg.data[1];  //Charge voltage (Low byte value)
    int cCH = anMsg.data[2];  //Charge current (High byte value)
    int cCL = anMsg.data[3];  //Charge current (Low byte value)
    int dcVH = anMsg.data[4]; //Discharge voltage (High byte value)
    int dcVL = anMsg.data[5]; //Discharge voltage (Low byte value)
    int dcCH = anMsg.data[6]; //Discharge current (High byte value)
    int dcCL = anMsg.data[7]; //Discharge current (Low byte value)
  }

  //0x038 read Ah high/low[0/1], BMS temperature[2], 
  //Realy output status{0-OFF,1-Precharge,2-ON}[3], optocoupler output status{0-OFF,1-ON}[4]
  if ((mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) && (canMsg.can_id == 0x031)){
    int AhH = anMsg.data[0];      //Amperehour (High byte value)
    int AhL = anMsg.data[1];      //Amperehour (Low byte value)
    int BMST = anMsg.data[2];     //BMS temperature
    int relayStat = anMsg.data[3];//Relay output status
    int optoStat = anMsg.data[4]; //Optocoupler output status
  }


}



