/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 2;
int ledPin = 8;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {

       if(results.value == 0xBD807F) //if the button press equals the hex value 0xC284
    {
        //do something useful here  digitalWrite(ledPin, HIGH);
        Serial.println("O led ligou porra!");
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);
    }
    irrecv.resume(); //receive the next value

    
    Serial.println(results.value, HEX);
  }
  delay(100);
}
