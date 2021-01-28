//pin 4:DAT
//pin5:HX711 CLK
//angle Z use pls
#include <Wire.h>
#include "HX711.h"

const int MPU=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
 
int minVal=265;
int maxVal=402;
 
double x,y,z;

//Load variables
//#define calibration_factor ??
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;
const int calibration_factor = -400;

HX711 loadcell;

 
void setup(){

//loadcell
loadcell.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
loadcell.set_scale(calibration_factor);
loadcell.tare(); //assume no weight at start up
delay(5000);
Serial.print("Weight: ");
Serial.print(loadcell.get_units(), 1);
Serial.print("Kg");

//accelerometer
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
Serial.begin(9600);
}
void loop(){

measureAnglefun();

/*Serial.print("AngleZ= ");
Serial.println(z);
Serial.println("-----------------------------------------");
delay(400);*/

}

void measureAnglefun(){
 Wire.beginTransmission(MPU);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU,14,true);
AcX=Wire.read()<<8|Wire.read();
AcY=Wire.read()<<8|Wire.read();
AcZ=Wire.read()<<8|Wire.read();
int xAng = map(AcX,minVal,maxVal,-90,90);
int yAng = map(AcY,minVal,maxVal,-90,90);
int zAng = map(AcZ,minVal,maxVal,-90,90);
 
z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

if(z < 355){
  Serial.println(f("Please make sure that the beam is 90 degrees wrt the base"));
}
 else{
  Serial.println(f("You may proceed with the experiment."));
}
