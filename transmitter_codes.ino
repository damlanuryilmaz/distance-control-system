#include <SPI.h>     //We include SPI library
#include <mcp2515.h>     //We include MCP2515 library

MCP2515 mcp2515(10);    //It is the pin that we connect SPI CS

const int trigPin = 7;               //We set the pins of distance sensor
const int echoPin = 6;                          
long duration;        // We define the duration
int distance;     //We define the distance

struct can_frame canMsg;  //It creates canMsg structure

void setup() {
  
  Serial.begin(9600);       //Starts the Serial communication
  while (!Serial){}; 
  
  SPI.begin();                // Starts the SPI communication      

  mcp2515.reset();        //We reset the settings
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);    //We set the bit and baud rate 
  mcp2515.setNormalMode();    //We set the normal mode.

  pinMode(trigPin, OUTPUT);   // We set the trigPin as an Output
  pinMode(echoPin, INPUT);    // We set the echoPin as an Input 

}

void loop() {
  
  digitalWrite(trigPin, LOW);     // We clear the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);   //We set the trigPin on HIGH state for 10 ms
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);    //We set the trigPin on LOW
  
  duration = pulseIn(echoPin, HIGH);    //We read the travel time from echoPin
  distance = (duration / 2 ) / 29.1;    //We calculate the distance

  canMsg.can_id = 0x036;         //We define the CANbus ID
  canMsg.can_dlc = 8;            //We define the data lenght
  canMsg.data[0] = distance;     //We set the distance data to CANbus data
  canMsg.data[1] = 0x00;         //We set other datas to 0
  canMsg.data[2] = 0x00;
  canMsg.data[3] = 0x00;
  canMsg.data[4] = 0x00;
  canMsg.data[5] = 0x00;
  canMsg.data[6] = 0x00;
  canMsg.data[7] = 0x00;

  mcp2515.sendMessage(&canMsg);     //We send the data to CANbus

  delay(100);       //We add delay

}
