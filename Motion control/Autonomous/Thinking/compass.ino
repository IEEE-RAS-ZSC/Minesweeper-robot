
float compass() {
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.x, event.magnetic.z);
  float heading2 = atan2(event.magnetic.y, event.magnetic.x);

  float declinationAngle = 0.22;
  heading += declinationAngle;
  heading2 += declinationAngle;  
  if (heading < 0)
    heading += 2 * PI;
  if (heading > 2 * PI)
    heading -= 2 * PI;

  if (heading2 < 0)
    heading2 += 2 * PI;
  if (heading2 > 2 * PI)
    heading2 -= 2 * PI;
    
  headingDegrees = heading * 180 / M_PI;
  headingDegrees2 = heading2 * 180 / M_PI;
  float s = 2.3;
  degree = ((H + headingDegrees)+((H2+headingDegrees2)/s)) ;
  if (degree < 0)
    degree += 2 * 180;
  if (degree > 2 * 180)
    degree -= 2 * 180;
//    Serial.println(degree);
  return degree;
}



