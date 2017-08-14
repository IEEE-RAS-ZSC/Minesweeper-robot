float encoder() {
  long newPosition = myEnc.read();
  long newPosition2 = myEnc2.read();
  oldPosition = newPosition;
  oldPosition2 = newPosition2;
  long real_pos = (newPosition + newPosition2) / 2;
  return real_pos * encoder_mes;
}

