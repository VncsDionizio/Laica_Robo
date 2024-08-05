void reading() {
  readL = digitalRead(senL);
  readLC = analogRead(senLC);
  readC = digitalRead(senC);
  readRC = analogRead(senRC);
  readR = digitalRead(senR);
  bReadLC = (readLC < curveValue ? false : true);
  bReadRC = (readRC < curveValue ? false : true);
}

void showReading() {
  reading();

  Serial.print(readL);
  Serial.print(" ");
  Serial.print(readLC);
  Serial.print(" ");
  Serial.print(readC);
  Serial.print(" ");
  Serial.print(readRC);
  Serial.print(" ");
  Serial.print(readR);
  Serial.println();
}