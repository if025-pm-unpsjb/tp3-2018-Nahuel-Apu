void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(72, OUTPUT);
  pinMode(73, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  digitalWrite(72, LOW);
  digitalWrite(73, LOW);
  delay(500);

  digitalWrite(13, LOW);
  digitalWrite(72, HIGH);
  digitalWrite(73, HIGH);
  delay(500);
}
