//This code working to make the robot going to a point defined by the angle and the distance
//the parts of the code is : 
//compass: to find out the angle that the robot in 
//compass_redir: by sending an angle ... the robot will go right or left to be in your angle
//encoder: this part working on two encoder sensors to find out the total distance that the robot has traveled 
//goTo: this part makes the robot moving to the wanted distance
//moving: control on H_Bridge "Forward,Reverse,..."
//x_y_cal: this part working as a manager between compass&encoder to find out where tha robot in (x,y);

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Encoder.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345); 
const int in1 = 46;
const int in2 = 48;
const int in3 = 50;
const int in4 = 52;
const int GoToMines = 12;
const int StartTheGame = 10;
Encoder myEnc(3, 2);
Encoder myEnc2(18, 19);
float last_distance = 0, H, headingDegrees, degree, x = 0, y = 0;
long oldPosition  = -999;
long oldPosition2  = -999;
float encoder_mes = .055;
int deg_limit = 0;
int dist_limit = 0;
float degree_real;

void setup()
{
  pinMode(GoToMines, INPUT);
  pinMode(StartTheGame, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  if (!mag.begin()) { //to make sure the compass is connected 
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }

}




