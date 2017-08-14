float encoder() {
  long newPosition = myEnc.read();
  long newPosition2 = myEnc2.read();
  oldPosition = newPosition;
  oldPosition2 = newPosition2;
  long real_pos = (newPosition + newPosition2) / 2;
  return real_pos * encoder_mes;
  
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

