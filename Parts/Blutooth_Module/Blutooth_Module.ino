#include <SoftwareSerial.h>
SoftwareSerial BT(50, 51); //*********************TX, RX respetively*****************************************************
int BluetoothData;

void setup() {
  BT.begin(9600); //*****************************activation bluetooth Module*********************************************
  Serial.begin(9600);
}

void loop() {
  if (BT.available())
  {
    BluetoothData = BT.read();
    Serial.println(BluetoothData);
  }
}
