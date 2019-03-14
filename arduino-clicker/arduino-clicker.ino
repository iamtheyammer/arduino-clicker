/*

  Copyright 2019 iamtheyammer
  Licensed under the MIT License,
  available in the root of this repository.

*/

#include <Mouse.h>

uint8_t counter = 0;
bool shouldClick = false;

// HOW OFTEN TO CHECK FOR SWITCH, <<MUST>> BE UNDER 256 (to save RAM)
uint8_t howOftenToCheck = 10;

// WHAT PIN THE SWITCH IS ON
uint8_t switchPin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(switchPin, INPUT);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);

  counter = 0;

  Mouse.begin();
  Serial.begin(112500);
}

void loop() {
  // put your main code here, to run repeatedly:
  doClick();
}

void doClick() {
  if (shouldClickFun() == true) Mouse.click();
}

bool shouldClickFun() {
  if (shouldCheckPin() == true) {
    shouldClick = digitalRead(switchPin) == HIGH ? true : false;
    digitalWrite(LED_BUILTIN, shouldClick);
    return shouldClick;
  } else {
    //Serial.println("SHOULD NOT CHECK PIN");
    return shouldClick;
  }
}

bool shouldCheckPin() {
  counter = counter + 1;
  if (counter > howOftenToCheck) {
    counter = 0;
    return true;
  } else {
    return false;
  }
}
