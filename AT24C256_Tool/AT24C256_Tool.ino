/**********************************************
 * Author: Cristian Capraro
 * Website: https://me.cristiancrazy.it
 * Prototyping Board: A. Leonardo
 * Under MIT Licence
 * Project: R/W AT24C256 I2C EEPROM
 * 
 * Project reference:
 * https://www.arduino.cc/en/reference/wire
 * https://t.ly/C4C2 (AT24C246 Datasheet)
 *********************************************/

#include <Wire.h>

/* ========== SETTINGS ========== */
#define EEPROM_ADDRESS 0x50 // Datasheet Reference (Master Only)
#define EEPROM_MEMSIZE 256 // Kbit Size of EEPROM
#define SERIAL_SPEED 9600 // Arduino Serial Speed
#define SERIAL_TOUT 5000 // Arduino Serial Timeout (ms)
#define PRINT_NEWLINE (EEPROM_MEMSIZE/16) // Formatting Output

/* ========== UTILS ========== */
void initBoard(){
  Serial.begin(SERIAL_SPEED);
  Serial.setTimeout(SERIAL_TOUT);
  Wire.begin(); // Join i2c bus
  delay(1000);
  while(!Serial); //Wait connection
}

void welcome(){
  Serial.println("*****[I2C EEPROM UTILITY PROGRAM]*****");
  Serial.print("Device Address: ");
  Serial.println(EEPROM_ADDRESS, 16);
  Serial.print("Device Memory Size: ");
  Serial.print(EEPROM_MEMSIZE);
  Serial.println(" Byte Slots");
  Serial.println("**************************************");
  delay(1000);
}

void displayChoice(){
  Serial.println();
  Serial.println("press r/R to read the EEPROM");
  Serial.println("press a/A to write an EEPROM slot");
  Serial.println("press e/E to wipe EEPROM data");
  while(!Serial.available());
  char choice = Serial.read();
  switch(choice){
    
    case 'e': case 'E': //Wipe all data
      for(int i = 0; i < EEPROM_MEMSIZE; ++i){
        writeSlot(0, i);
        delay(25);
      }
    break;
    
    case 'r': case 'R': //Read all data
      printEEPROM();
      break;
    case 'a': case 'A': //Write data
      Serial.println("Insert a byte value (0 ~ 255): ");
      while(!Serial.available());
      byte v = (byte)(Serial.readString().toInt());

      Serial.println("Insert EEPROM address (0-based): ");
      while(!Serial.available());
      unsigned int addr = (unsigned int) (Serial.readString().toInt());
      writeSlot(v , addr);
      break;
  }
}

/* ========== Write/Read EEPROM ========== */
void writeSlot(byte toWrite, unsigned int slot){
  if(slot < EEPROM_MEMSIZE){
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(slot >> 8)); //MSB
    Wire.write((int)(slot & 0xFF)); //LSB
    Wire.write(toWrite);
    Wire.endTransmission();
    Serial.println("[Success - EEPROM Written Successfully!]");
  }else{
    Serial.println("[Failed - Slot out of memory range available!]");
  }
  delayMicroseconds(500);
}

byte readSlot(unsigned int slot){
  if(slot < EEPROM_MEMSIZE){
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(slot >> 8)); //MSB
    Wire.write((int)(slot & 0xFF)); //LSB
    Wire.endTransmission();
    Wire.requestFrom(EEPROM_ADDRESS, 1);
    delayMicroseconds(500);
    if (Wire.available()) return (byte) Wire.read();
    else return 0;
  }else{
    Serial.println("[Failed - Slot out of memory range available!]");
    return 0;
  }
}

void printEEPROM(){
  Serial.println("The EEPROM contains: ");
  for(int i = 0, newline = 0; i < EEPROM_MEMSIZE; ++i){
    
    //Output data
    Serial.print("(");
    Serial.print(readSlot(i));
    Serial.print(") ");

    //Formatting output
    if((++newline) == PRINT_NEWLINE){
      Serial.println();
      newline = 0; //reset counter
    }
    
    // Output delay
    delay(25);
  }
}

/* ========== ARDUINO PROCEDURES ========== */
void setup() {
  initBoard();
  welcome();
}

void loop() {
  displayChoice();
}
