int duration;
int distance;

int sonicSen() {
  pinMode(aci, OUTPUT);
  digitalWrite(aci, LOW);
  delayMicroseconds(2);
  digitalWrite(aci, HIGH);
  delayMicroseconds(10);
  digitalWrite(aci, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration / 29 / 2;
  
  delay(10);

  return distance;
}

void showUltraDistance() {
  Serial.print("Ultrassonico em cm: "); Serial.println(sonicSen());
}