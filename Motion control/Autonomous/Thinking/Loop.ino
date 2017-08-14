void Start_point() {
  compass();
  H = -headingDegrees + 180;
  H2 = -headingDegrees2;
}

void loop() {



  if (digitalRead(StartTheGame))
    Start_point();
  if (digitalRead(GoToMines))
    GoToMine();
}


void GoToMine() {
  distance_wanted=100;
  angle_wanted = 0;
  compass_redir(angle_wanted);
  boolean done = true;
  while(done);{
  if (distance_wanted>60){
  goTo(30, 0);
  distance_wanted-=30;
  delay(2000);
  
}
else{
  goTo(distance_wanted, 0);
  done = false;
}
}
}
