// Pins Connection for Arduino MEGA
/*
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 48
   4 - CSN to Arduino pin 49
   5 - SCK to Arduino pin 52
   6 - MOSI to Arduino pin 51
   7 - MISO to Arduino pin 50
   8 - UNUSED
*/
 // Pins Connection for Arduino UNO If used UNO, don't forgetChange CE & CSN Pins to any pins such as pin 9 & pin 10
 /*
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED*/
   
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN 9
#define CSN_PIN 10

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };


RF24 radio(CE_PIN, CSN_PIN);
int flage = 0;
int i = 0;
int Signal = 1;
unsigned long x = 0;
void setup()
{
  radio.begin();
  radio.setRetries(15, 15);
  radio.setPayloadSize(8);

  Serial.begin(9600);

  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1, pipes[0]);
  radio.startListening();
  sender(Signal);
}

int recever() {
  radio.startListening();
  unsigned long started_waiting_at = millis();
  boolean timeout = false;
  while ( ! radio.available() && ! timeout )
    if (millis() - started_waiting_at > 1000)
      timeout = true;
  int rec;

  if ( timeout )
  {
    Serial.println("**********");
  }
  else
  {
    radio.read( &rec, sizeof(int) );
    Serial.println(rec);

  }
  return rec;

}


void sender(int sw) {

  radio.stopListening();
  radio.write( &sw, sizeof(int) );
}



void loop()
{
  int send_value = 10;//value you want to transfer
  sender(send_value);
  int receved_value = recever();
  Serial.println(receved_value);//print receved data
}


