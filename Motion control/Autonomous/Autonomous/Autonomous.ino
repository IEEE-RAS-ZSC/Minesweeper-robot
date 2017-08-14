#include <EEPROM.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Encoder.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
const int in1 = 46;
const int in2 = 48;
const int in3 = 50;
const int in4 = 52;
const int Echo = 7;
const int Trig = 6;
const int IRPin = 10;
const int StartTheGame = 9;
const int weFinished = 8;
const int GoToMines =11;
const int max_xy_value = 10, nomminpos = 2*max_xy_value + 15;
Encoder myEnc(2, 3);
Encoder myEnc2(18, 19);
int k = 0;
float last_distance = 0, H, headingDegrees, degree, Xd, Yd, Zd, x = 0, y = 0;
long oldPosition  = -999;
long oldPosition2  = -999;
float encoder_mes = .0527;
float x_test = 10000000000;
float y_test = 10000000000;
float sqr_tall = 25;


void setup()
{
  pinMode(IRPin, INPUT);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(StartTheGame, INPUT);
  pinMode(weFinished, INPUT);
  pinMode(GoToMines,INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  if (!mag.begin()) {
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }

}

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
void Left() {
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);
  digitalWrite (in3, LOW);
  digitalWrite (in4, HIGH);
}
void Right() {
  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);
  digitalWrite (in3, HIGH);
  digitalWrite (in4, LOW);
}
void Stop() {
  digitalWrite (in1, LOW);
  digitalWrite (in2, LOW);
  digitalWrite (in3, LOW);
  digitalWrite (in4, LOW);
}


float compass() {
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.x, event.magnetic.z);
  float declinationAngle = 0.22;
  heading += declinationAngle;
  if (heading < 0)
    heading += 2 * PI;
  if (heading > 2 * PI)
    heading -= 2 * PI;
  headingDegrees = heading * 180 / M_PI;
  degree = (H + headingDegrees) ;
  if (degree < 0)
    degree += 2 * 180;
  if (degree > 2 * 180)
    degree -= 2 * 180;
  //    Serial.print(Y_degree);Serial.print("   ");Serial.print(X_degree);Serial.print("   ");Serial.print(Z_degree);;Serial.print("   ");Serial.println(degree);
  return degree;
}

float encoder() {
  long newPosition = myEnc.read();
  long newPosition2 = myEnc2.read();
  oldPosition = newPosition;
  oldPosition2 = newPosition2;
  long real_pos = (newPosition + newPosition2) / 2;
  return real_pos * encoder_mes;
}

void OutPulse()
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
}

float Dest(int T)
{
  if (T == 0)
    return 0;
  else
    return (T / 29 / 2);
}

int Ultra()  {
  int t;
  OutPulse();
  double Time = pulseIn(Echo, HIGH);
  double Distance = Dest(Time);
  if (Distance < 50 && Distance > 0 )
    t = 1;
  else
    t = 2;
  return t ;
}

void x_y_cal() {
  double distance = encoder();
  float rad_angle = (compass() * PI) / 180;
  y = y + (distance - last_distance) * cos(rad_angle);
  x = x + (distance - last_distance) * sin(rad_angle);
  last_distance = distance;
    Serial.print(x); Serial.print("   "); Serial.print(y); Serial.print("   "); Serial.println(degree);

}

int Mape() {
  int type;
  // for (int i = 0; i <= 10; i++)
  type = Ultra();
  float x_ab = abs(x - x_test);
  float y_ab = abs(y - y_test);
  if (x_ab > 10 || y_ab > 10) {
    findMine(type);
//    Serial.print(x); Serial.print("   "); Serial.print( y); Serial.print("   "); Serial.println(type);
    x_test = x;
    y_test = y;
  }
}

void save_pos(float val, int first, int last) {
  float value = abs(val);
  for ( first ; first <= last ; first++)
  {
    if (value >= 255)
      EEPROM.write(first , 255);
    else if (value > 0 && value < 255)
      EEPROM.write(first, value);
    else
      EEPROM.write(first, 0);
    value = value - 255;
  }
  if (val < 0)
    EEPROM.write(last + 1, 1);
  else
    EEPROM.write(last + 1, 0);

}

float find_pos(int first, int last) {
  float pos = 0;
  for ( first ; first <= last ; first++) {
    pos = pos + EEPROM.read(first);
  }
  if (EEPROM.read(last + 1))
    pos = pos * (-1);
  return pos;
}

void clear_eeprom() {
  for (int i = 0 ; i < 100 ; i++)
    EEPROM.write(i, 0);
}

void Start_point() {
  clear_eeprom();
  compass();
  H = -headingDegrees;

}

void findMine(int type) {
  int nommine = EEPROM.read(nomminpos);
  save_pos(x,(2*nommine+2)*(max_xy_value + 10),(2*nommine+2)*(max_xy_value + 10) + max_xy_value);
  EEPROM.write((2*nommine+2)*(max_xy_value + 10) + max_xy_value + 5 , type);
  save_pos(y, (2*nommine + 3) * (max_xy_value + 10), (2*nommine + 3) * (max_xy_value + 10)+max_xy_value);
  EEPROM.write(nomminpos, nommine+1);
}

void drawMap() {
  while (k == 0)
  {
    k++;
    int nommine = EEPROM.read(nomminpos);
    for (int i = 0; i < nommine ; i++) {
      int X = find_pos((2*i+2)*(max_xy_value + 10), (2*i+2)*(max_xy_value + 10) + max_xy_value);
      int Y = find_pos((2*i + 3) * (max_xy_value + 10), (2*i + 3) * (max_xy_value + 10)+max_xy_value);
      int type = EEPROM.read((2*i+2)*(max_xy_value + 10) + max_xy_value + 5);
      Serial.print(X*(1/sqr_tall)); Serial.print(" "); Serial.print(Y*(1/sqr_tall)); Serial.print(" "); 
      if(type == 1)
      Serial.println("s");
      else
      Serial.println("b");
    }
  }
}

void start()
{
  x = find_pos(0, max_xy_value);
  y = find_pos(max_xy_value + 10, 2 * max_xy_value + 10);
  delay(500);
  x_y_cal() ;
  save_pos(x, 0, max_xy_value) ;
  save_pos(y, max_xy_value + 10, 2 * max_xy_value + 10) ;
}


void loop() {

  start();
  if (digitalRead(IRPin))
    Mape();
  if (digitalRead(StartTheGame))
    Start_point();
  if (digitalRead(weFinished))
    drawMap();
  if (digitalRead(GoToMines))
  GoToMine();
}


void GoToMine(){

//  int nommine = EEPROM.read(nomminpos);
//    for (int i = 0; i < nommine ; i++) {
//      int X = find_pos((2*i+2)*(max_xy_value + 10), (2*i+2)*(max_xy_value + 10) + max_xy_value);
//      int Y = find_pos((2*i + 3) * (max_xy_value + 10), (2*i + 3) * (max_xy_value + 10)+max_xy_value);
//      Serial.print(X); Serial.print(" "); Serial.print(Y);
//      int X = 30;
//      int Y = 30;
//        x_y_cal() ;

//      go_to(X-x,Y-y);
//      delay(3000);
    int  X = 0;
      int Y =100;
        x_y_cal() ;

      go_to(X-x,Y-y);
      delay(3000);
//      X = 30;
//      Y = 30;
//        x_y_cal() ;
////
//      go_to(X-x,Y-y);
//      delay(3000);
      Stop();
      delay(5000);
    }

  

void go_to(float x_point,float y_point  ) {
  
  float z = sqrt(pow(x_point, 2) + pow(y_point, 2));
  float z_angle = atan2 (y_point, x_point);
  goTo(z, z_angle);
}

void goTo(float dist, float angle) {
  compass_redir((angle * 180) / PI);

  float first_dist = encoder();

  while (int(encoder() - first_dist) - dist < 3 ){
    Serial.println("    1");
    Forward();
    if (abs(compass() - angle) < 10) {
          Serial.println("    2");
      Stop();
      compass_redir((angle * 180) / PI);
    }
  }
      Serial.println("    3");
  Stop();

}

void compass_redir(float angle) {
  float rec_angle = compass();
  if(angle<0)
  angle = angle+360;
  else if (angle>360)
  angle = angle - 360;
  if (RightOrLeft(angle, compass()) == 1) {
    while (abs(compass() - angle) > 5)
      Left();
  }
  else if (RightOrLeft(angle, compass()) == 0) {
    while (abs(compass() - angle) > 5)                    //0 - right , 1-left , 2 - stop
      Right();
  }
  Stop();
}

int RightOrLeft(float angle , float rec_angle) {
  float def = angle - rec_angle;
  if (360 - abs(def) > abs(def)) {
    if ( def < 0 )
      return 1;
    else
      return 0;
    }
  else if (360 - abs(def) < abs(def)) {
     if ( def > 0 )
      return 1;
    else
      return 0;
    }
  else
    return 2;
}



  

