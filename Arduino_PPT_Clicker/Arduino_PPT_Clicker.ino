/*********************************
 * Author: Cristian Capraro
 * Only for personal purposes
 * Board: Arduino Leonardo
 * Protocol Used: USB
 * Arduino based clicker. It will
 * work with an IR receiver and a
 * remote.
 *********************************/
//Headers
#include <Keyboard.h>
#include <IRremote.hpp>

//General specs
#define SERIAL_SPEED 9600 //in baud rate
#define DELAY_RELEASE 250 //in ms
#define DELAY_RESUME 250 //in ms

//PIN Definition
#define DATA_PIN A0 //IR Receiver pin
#define FEEDBACK_PIN LED_BUILTIN //IR Receiver feedback led

/* 
 * =======================================
 *  Action Definition [IR CODES BINDING]
 * (You must replace this part with
 *  your remote buttons code) 
 * =======================================
 */
#define CMD_SIZE 4

#define BEGIN_PPT 0x43
#define EXIT_PPT 0x16
#define NEXT_SLIDE 0x40
#define PREVIOUS_SLIDE 0x44

//Command binding and definition
uint16_t ircmd[CMD_SIZE]
{
  BEGIN_PPT,
  EXIT_PPT,
  NEXT_SLIDE,
  PREVIOUS_SLIDE
};

uint8_t keycmd[CMD_SIZE]
{
  KEY_F5,
  KEY_ESC,
  KEY_RIGHT_ARROW,
  KEY_LEFT_ARROW
};

//This function is used to parse command
void parsecmd(uint16_t command)
{
  //Sequencial research of ir command
  for(int i = 0; i < CMD_SIZE; ++i)
  {
    if(command == ircmd[i]) //Command found
    {
      Keyboard.press(keycmd[i]);
      Serial.println("Command Executed");
      delay(DELAY_RELEASE);
      Keyboard.releaseAll();
      return;
    }
  }
}

void setup() 
{
  //Init components
  Serial.begin(SERIAL_SPEED);
  Serial.println("Init in progress...");
  delay(2000);
  IrReceiver.begin(DATA_PIN, FEEDBACK_PIN);
  Keyboard.begin();
  Serial.println("OK.");
}

void loop() 
{
  //Receive and parse data
  if(IrReceiver.decode())
  {
    //Print received command on serial
    Serial.print("Received the following command: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    
    //Parsing
    parsecmd(IrReceiver.decodedIRData.command);
    delay(DELAY_RESUME);
    IrReceiver.resume();
  } 
}
