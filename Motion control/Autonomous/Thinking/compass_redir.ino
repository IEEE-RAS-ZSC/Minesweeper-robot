void compass_redir(float angle) {
  float first_angle = compass();
  
    while (abs(compass() - first_angle) - abs(angle) < deg_limit && angle < 0) {
      Left();
      compass();
    }
    while (abs(compass() - first_angle) - abs(angle) < deg_limit && angle > 0) {
      Right();
      compass();
    }     
  Stop();
  H+= angle;
}
