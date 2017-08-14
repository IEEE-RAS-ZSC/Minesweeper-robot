void OutPulse(int Trig)
{
  digitalWrite(Trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
}


int Ultra(int nomber,int dist)  {
  OutPulse(Trig[nomber]);
  float Time = pulseIn(Echo[nomber], HIGH);
  float Distance = Time / 29 / 2;
  Serial.println(Distance);
  if (Distance == 0)
    return 0 ;
  else{
    if (Distance < dist)
      return 1;
    else 
      return 0;
}
}
