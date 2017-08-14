void x_y_cal() {
  double distance = encoder();
  compass();
  float rad_angle = ( degree_real * PI) / 180;
  y = y + (distance - last_distance) * cos(rad_angle);
  x = x + (distance - last_distance) * sin(rad_angle);
  last_distance = distance;
  Serial.print(x); Serial.print("   "); Serial.print(y); Serial.print("   "); Serial.println(degree);
}

