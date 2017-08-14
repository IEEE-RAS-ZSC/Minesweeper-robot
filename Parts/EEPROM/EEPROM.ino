#include <EEPROM.h>

void setup() {
  Serial.begin(9600);

}

void save_pos(float val, int first, int last) {
  float value = abs(val);
  for ( first ; first <= last ; first++)
  {
    if (value >= 255)
      EEPROM.write(first , 255);
    else if (value > 0 && value < 255)
      EEPROM.write(first, value);
    else
      EEPROM.write(first, 0);
    value = value - 255;
  }
  if (val < 0)
    EEPROM.write(last + 1, 1);
  else
    EEPROM.write(last + 1, 0);

}

float find_pos(int first, int last) {
  float pos = 0;
  for ( first ; first <= last ; first++) {
    pos = pos + EEPROM.read(first);
  }
  if (EEPROM.read(last + 1))
    pos = pos * (-1);
  return pos;
}

void clear_eeprom() { //make all values in EEPROM = 0;
  for (int i = 0 ; i < 100 ; i++)
    EEPROM.write(i, 0);
}



void loop() {
  int nomber_to_save = 1000; //what you want to save
  int start_pos = 0; //pos you want to save in
  int last_pos = (start_pos+nomber_to_save/255)+1;//the nomber will be saved between start_pos and last_pos
save_pos(nomber_to_save,start_pos,last_pos);
int nomber_saved = find_pos(start_pos,last_pos);
Serial.println(nomber_saved);

}
