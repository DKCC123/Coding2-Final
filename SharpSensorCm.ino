#include <SharpIR.h>

#define ir A0
#define model 1080
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            (working distance range according to the datasheets)

SharpIR SharpIR(ir, model);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
unsigned long tt = 0;
int dis = 200;
void loop() {
  delay(20);
  if (millis() - tt > 500) {
    unsigned long pepe1 = millis(); // takes the time before the loop on the library begins

    dis = SharpIR.distance(); // this returns the distance to the object you're measuring
  }
  if (Serial.available()) {

    //Serial.print("Mean distance: ");  // returns it to the serial monitor
    Serial.print(dis / 100);
    Serial.print((dis - (dis / 100)) / 10);
    Serial.print(dis % 100);
    Serial.read();
    Serial.flush();

  }

  //  unsigned long pepe2=millis()-pepe1;  // the following gives you the time taken to get the measurement
  //  Serial.print("Time taken (ms): ");
  //  Serial.println(pepe2);

}
