#include <Encoder.h>


Encoder myEnc(3, 2);
Encoder myEnc2(19, 18);

float last_distance = 0;
long oldPosition  = -999;
long oldPosition2  = -999;
float encoder_mes = .0527;


void setup() {
  Serial.begin(9600);

}


float encoder() {
  long newPosition = myEnc.read();
  long newPosition2 = myEnc2.read();
  oldPosition = newPosition;
  oldPosition2 = newPosition2;
  long real_pos = (newPosition + newPosition2) / 2;
  return real_pos * encoder_mes;
}


void loop() {
float distance = encoder();
Serial.println(distance);
}
