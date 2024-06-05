void handleMotor(uint8_t statLF, uint8_t statLB, uint8_t statRF, uint8_t statRB, uint8_t pwm) {
  digitalWrite(wheelLF, statLF);
  digitalWrite(wheelLB, statLB);
  digitalWrite(wheelRF, statRF);
  digitalWrite(wheelRB, statRB);
  analogWrite(ENA, pwm);
  analogWrite(ENB, pwm);
}

void moveFront() {
  handleMotor(HIGH, LOW, HIGH, LOW, 175);
}

void moveBack() {
  handleMotor(LOW, HIGH, LOW, HIGH, 175);
}

void moveLeft() {
  handleMotor(HIGH, LOW, LOW, HIGH, 255);
  delay(25);
}

void moveRight() {
  handleMotor(LOW, HIGH, HIGH, LOW, 255);
  delay(25);
}

void stopMoving() {
  handleMotor(LOW, LOW, LOW, LOW, 0);
}