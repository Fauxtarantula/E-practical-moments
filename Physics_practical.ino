// pin 4:DAT
//pin 5:HX711 CLK
// Note: we need calibration factr

#include "HX711.h"
//#define calibration_factor ??

const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;

HX711 loadcell;

void setup() {
  Serial.begin(9600);
  Serial.println("Moments practical");

  loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  loadcell.set_scale(calibration_factor);
  loadcell.tare(); //assume no weight at start up

}

void loop() {
  // put your main code here, to run repeatedly:

}
