// esq: echo 46, trig 47 
// dir: echo 27, trig 26

int sonicSen(int trig, int echo) {
  int duration;
  int distance;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration / 29 / 2;
  
  delay(10);

  return distance;
}

void showUltraDistance(int trig, int echo) {
  Serial.print("Ultrassonico em cm: "); Serial.println(sonicSen(trig, echo));
}