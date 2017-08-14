void go_dist_F(float dist) {
  float first_dist = encoder();
    while (abs(encoder() - first_dist) - abs(dist) < dist_limit ) 
      Forward();
    Stop();
}


void go_dist_B(float dist) {
  float first_dist = encoder();
  while (abs(encoder() - first_dist) - abs(dist) < dist_limit ) 
    Reverse();
  Stop();

  }

