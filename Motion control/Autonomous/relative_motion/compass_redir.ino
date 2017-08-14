void compass_redir(float angle) {
  compass();
  float first_angle_real = degree_real;
  if (angle < 0) {
    float deg = abs(degree_real - first_angle_real) - abs(angle);
    while (deg < deg_limit ) {
      deg = abs(degree_real - first_angle_real) - abs(angle);
      Right();
      compass();
    }
  }
  else if (angle > 0) {
    float deg = abs(degree_real - first_angle_real) - abs(angle);
    while ( deg < deg_limit ) {
      deg = abs(degree_real - first_angle_real) - abs(angle);
      Left();
      compass();
    }
    Stop();
  }
}
