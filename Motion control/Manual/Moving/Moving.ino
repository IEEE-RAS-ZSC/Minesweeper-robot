#include <SoftwareSerial.h>
SoftwareSerial BT(50, 51); //*********************TX, RX respetively*****************************************************
int BluetoothData;
const int in1 = 4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  BT.begin(9600); //*****************************activation bluetooth Module*********************************************
  Serial.begin(9600);

}

//**********************************************************************************************************************************
//**********************************************Moving******************************************************************************
//**********************************************************************************************************************************

void Reverse() {
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);
}
void Forward() {
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
  digitalWrite (in3, HIGH);
  digitalWrite (in4, LOW);
}
void Right() {
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);
}
void Left() {
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  digitalWrite (in3, HIGH);
  digitalWrite (in4, LOW);
}
void Stop() {
  digitalWrite (in1, LOW );
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
}



void loop() {
  if (BT.available())
  {
    BluetoothData = BT.read();
    Serial.println(BluetoothData-48);
        Serial.println("b");

    if (BluetoothData == 70)        //forward
      Forward();
    else if (BluetoothData == 66)      //reverse
      Reverse();
    else if (BluetoothData == 76)     //left
      Left();
    else if (BluetoothData == 82)    //right
      Right();
    else     //Stop
      Stop();
  }

}
