#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Encoder.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(50, 51); //*********************TX, RX respetively*****************************************************
int BluetoothData;
int distance_wanted;
int angle_wanted;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
const int in1 = 14;
const int in2 = 15;
const int in3 = 16;
const int in4 = 17;
const int GoToMines = 12;
const int StartTheGame = 13;
Encoder myEnc(3, 2);
Encoder myEnc2(18, 19);
float H=0,H2=0, headingDegrees,headingDegrees2,degree;
long oldPosition  = -999;
long oldPosition2  = -999;
float encoder_mes = .055;
int deg_limit = 0;
int dist_limit = 0;
int x = 0 , y = 0 ;

int Echo[] = {7,9} ;
int Trig[] = {8,10} ;

int code;
void setup()
{
    BT.begin(9600); //*****************************activation bluetooth Module*********************************************

  pinMode(GoToMines, INPUT);
  pinMode(StartTheGame, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(Echo[0], INPUT);
  pinMode(Trig[0], OUTPUT);
  pinMode(Echo[1], INPUT);
  pinMode(Trig[1], OUTPUT);
  Serial.begin(9600);
  if (!mag.begin()) {
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }

}




