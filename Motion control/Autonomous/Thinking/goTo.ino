void goTo(float dist, float angle) {
  think(dist);
  Serial.println(code);
  delay(5000);
  do_the_true(dist);
}


int think(int dist) {
  if (dist > 0) {
    int U0 = Ultra(0, dist);
    int U1 = Ultra(1, dist);
    code = 1000 + 10 * U0 + U1;
    code += 100;
  }
  else
    code = 1000;
}


void do_the_true(int dist) {
  int degree ;
  switch (code) {
    case 1000 :
      go_dist_B(dist);
      y = 0 ;
      break;
    case 1100 :
      go_dist_F(dist);
      y = 0 ;
      break;
    case 1101 :
      while (Ultra(1, (dist - y)))
        left_error(dist);
      go_dist_F(dist - y);
      compass_redir(90);
      degree = look(20,x / cos(degree));
      go_dist_F(x / cos(degree));
      compass_redir(-90 + degree);
      y += (x / cos(degree) * sin(degree));
      break;
    case 1110 :
      while (Ultra(0, (dist - y)))
        right_error(dist);
      go_dist_F(dist - y);
      compass_redir(-90);
      degree = look(-20,x / cos(abs(degree)));
      go_dist_F(x / cos(abs(degree)));
      compass_redir(-90 + degree);
      y += (x / cos(degree) * sin(abs(degree)));
      break;
    case 1111 :
      while (Ultra(1, (dist - y)))
        left_error(dist);
      go_dist_F(dist - y);
      compass_redir(90);
      degree = look(20,x/cos(degree));
      go_dist_F(x / cos(degree));
      compass_redir(-90 + degree);
      y += (x / cos(degree) * sin(degree));
      break;
    default :
    Stop();
      break;
  }
}
