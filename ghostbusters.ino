#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>

SoftwareSerial sws(10, 11);
DFRobotDFPlayerMini music;
const int pushbutton = 7;
int i;

void setup() {
  pinMode(pushbutton, INPUT_PULLUP);
  
  Serial.begin(9600);
  sws.begin(9600);

  Serial.println("Hello.");
  
  if (!music.begin(sws)) {
   Serial.println("Error beginning DFPlayerMini object.");
  } else {
    music.volume(30);
  }

  i = 0;
}

void loop() {
  byte buttonState = digitalRead(pushbutton);

  if (buttonState == LOW) {
    i++;
    Serial.println("Button pressed.");

    switch (i) {
      case 1:
        music.play(1);
        break;
      case 2:
        music.play(2);
        break;
      case 3:
        music.stop();
        i = 0;
    }
  }

  delay(200);
}
