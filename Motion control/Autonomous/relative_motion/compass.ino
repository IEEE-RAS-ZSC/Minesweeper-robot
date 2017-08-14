void compass() {
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.x, event.magnetic.z);
  float declinationAngle = 0.22;
  heading += declinationAngle;
  //make the angle between 0&360
  if (heading < 0)
    heading += 2 * PI;
  if (heading > 2 * PI)
    heading -= 2 * PI;
  headingDegrees = heading * 180 / M_PI;
  degree = (H + headingDegrees) ;//To make the refrence
  //make the angle between 0&360 after adding the refrence
  if (degree < 0)
    degree += 2 * 180;
  if (degree > 2 * 180)
    degree -= 2 * 180;
  degree_real = degree;
}

