#include <SPI.h>     //We include SPI library
#include <mcp2515.h>     //We include MCP2515 library

const int led1 = 6;     //We set the leds' pins
const int led2 = 7;
const int led3 = 8;

struct can_frame canMsg;    //It creates canMsg structure
MCP2515 mcp2515(10);    //It is the pin that we connect SPI CS

void setup() {
  
  Serial.begin(9600);       // Starts the Serial communication  
  SPI.begin();                // Starts the SPI communication 
  
  pinMode(led1, OUTPUT);      //We define leds for OUTPUT pin
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  mcp2515.reset();        //We reset the settings
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);    //We set the bit and baud rate 
  mcp2515.setNormalMode();    //We set the normal mode.

}

void loop() {

  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    int distance = canMsg.data[0];           //we define distance
    if(distance <=15 ){
      digitalWrite(led1, HIGH);    //Red led is ON
      digitalWrite(led2, LOW);    //Yellow led is OFF
      digitalWrite(led3, LOW);    //Green led is OFF
      delay(100);
      }         
      if(distance <=30 && distance >15){
      digitalWrite(led1, LOW);    //Red led is OFF
      digitalWrite(led2, HIGH);    //Yellow led is ON
      digitalWrite(led3, LOW);    //Green led is OFF
      delay(100);
      }
      if(distance >30){
      digitalWrite(led1, LOW);    //Red led is OFF
      digitalWrite(led2, LOW);    //Yellow led is OFF
      digitalWrite(led3, HIGH);    //Green led is ON
      delay(100);
      }
    }
}
