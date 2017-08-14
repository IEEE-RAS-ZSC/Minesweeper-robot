void Start_point() {//to make a refrence to the compass
compass();
H = -headingDegrees + 180;

}

void GoToMine() { //start the task
  int z = 0;
  int z_angle = 160*.95;
  goTo(z,z_angle);

}
void loop() {
  Serial.println(encoder());

  x_y_cal() ;
  delay(500);

  if (digitalRead(StartTheGame))
    Start_point();

  if (digitalRead(GoToMines))
    GoToMine();
}


