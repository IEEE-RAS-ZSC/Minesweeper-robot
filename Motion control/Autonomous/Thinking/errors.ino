void left_error(int dist){
  int degree = look(20,dist);
  go_dist_F(20);
  compass_redir(-degree);
  x = 20*sin(abs(degree));
  y = 20*cos(abs(degree));
  
}
void right_error(int dist){
  int degree = look(-20,dist);
  go_dist_F(20);
  compass_redir(-degree);
  x = 20*sin(abs(degree));
  y = 20*cos(abs(degree));
}




int look(int Step , int dist){
  int degree = 0;
  while(Ultra(1,dist)){
    compass_redir(Step);
    degree += Step;
  }
  return degree ;
}


