// pin 4:DAT
//pin 5:HX711 CLK
// Note: we need calibration factr
//Need mass, distance from pivot, 

#include "HX711.h"
//#define calibration_factor ??

const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;

double L, d;  
HX711 loadcell;

void setup() {
  Serial.begin(9600);
  Serial.println("Moments practical");

  /*loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  loadcell.set_scale(calibration_factor);
  loadcell.tare(); //assume no weight at start up*/

  Serial.println("Weight reading: ");

}

void loop() {
  Serial.print("Reading: ");
  //Serial.println(loadcell.get_units(), 1); scale.get_units() returns a float
  Serial.println(" kg"); //change this to kg by refactoring the calibration_factor
  Serial.println();

  Serial.print("Please type in the following variables and continue.");
  
  //Length
  Serial.print("Position of Newton meter, L: ");
  if(Serial.available()){
       L = Serial.parseFloat(SKIP_ALL);
       Serial.println("You have entered:" );
    }

}
