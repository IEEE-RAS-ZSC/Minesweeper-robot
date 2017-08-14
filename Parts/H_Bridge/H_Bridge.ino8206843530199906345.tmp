const int in1 = 26;
const int in2 = 27;
const int in3 = 29;
const int in4 = 33;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);

}

void Reverse()      {moving(1,0,0,1);}
void Forward()      {moving(0,1,1,0);}
void Left()         {moving(0,1,0,1);}
void Right()        {moving(1,0,1,0);}
void Stop()         {moving(0,0,0,0);}

void moving(boolean m1 , boolean m2 , boolean m3 , boolean m4){
  digitalWrite (in1, m1);
  digitalWrite (in2, m2);
  digitalWrite (in3, m3);
  digitalWrite (in4, m4);
} 




void loop() {
analogWrite(6,1500);
analogWrite(7,1500);
  Forward();
  Serial.println("Forward");
  delay(5000);
  Reverse();
  Serial.println("Reverse");
  delay(5000);
  Left();
  Serial.println("Left");
  delay(5000);
  Right();
  Serial.println("Right");
  delay(5000);
  Stop();
  Serial.println("Stop");

}
