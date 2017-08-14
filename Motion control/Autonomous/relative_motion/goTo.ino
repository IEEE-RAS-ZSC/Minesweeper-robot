
void goTo(float dist, float angle) {
  compass_redir(angle);
  float first_dist = encoder();
  x_y_cal();
  if ( dist > 0) {
    while (abs(encoder() - first_dist) - abs(dist) < dist_limit ) {
      Forward();
    }
  }
  else {
    while (abs(encoder() - first_dist) - abs(dist) < dist_limit ) {
      Reverse();
    }
  }
  Stop();
}


