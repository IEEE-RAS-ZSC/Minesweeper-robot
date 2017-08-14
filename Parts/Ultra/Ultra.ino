int Echo[] = {6,13} ;
int Trig[] = {7,13} ;

void setup() {
  // put your setup code here, to run once:
  pinMode(Echo[0], INPUT);
  pinMode(Trig[0], OUTPUT);
  pinMode(Echo[1], INPUT);
  pinMode(Trig[1], OUTPUT);
  Serial.begin(9600);

}


void OutPulse(int Trig)
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
}


int Ultra(int nomber)  {
  OutPulse(Trig[nomber]);
  double Time = pulseIn(Echo[nomber], HIGH);
  double Distance = Time / 29 / 2;

  if (Distance == 0)
  return 1000 ;
  else
  return Distance;
}

void loop() {
  // put your main code here, to run repeatedly:
//  int distance = Ultra(0);
//  Serial.print(distance);
//  Serial.print("      ");
  int distance = Ultra(0);
  Serial.println(distance);
  delay(100);
}
