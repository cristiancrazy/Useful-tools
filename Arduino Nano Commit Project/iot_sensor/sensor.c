/* ================================== *
 *  Author: Cristian Crazy
 *  To support a friend's friend.
 *  --
 *  Reading sensors utility
 * ================================== */
#include <Arduino.h>

#define TMP36 A0
#define VCC 3.3
#define ARES 12

void initSensors(){
  // Setting ADC resolution to 12 bit (0..4095)
  analogReadResolution(12);
  pinMode(TMP36, INPUT);
}

double readTemp(){ 
  return ((analogRead(TMP36)*(VCC/pow(2, ARES))) - 0.5) / 0.01;
}

double readTempVoltage(){ 
  return ((analogRead(TMP36)/pow(2, ARES))*VCC); 
}
