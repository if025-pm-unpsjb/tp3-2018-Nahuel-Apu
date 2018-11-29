
// Include Scheduler since we want to manage multiple tasks.
#include <Scheduler.h>
int retardo;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(72, OUTPUT);
  pinMode(73, OUTPUT);
  // initialize serial:
  Serial.begin(9600);
  retardo = 500;
  Scheduler.startLoop(loop2);
}

void loop() {
   // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  digitalWrite(72, LOW);
  digitalWrite(73, LOW);
  delay(retardo);

  digitalWrite(13, LOW);
  digitalWrite(72, HIGH);
  digitalWrite(73, HIGH);
  delay(retardo);
}

void loop2() {
  if (Serial.available() > 0) {
    retardo = Serial.parseInt();
  }  
  delay(100);
}
