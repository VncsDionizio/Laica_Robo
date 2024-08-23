void handleMotor(uint8_t statLF, uint8_t statLB, uint8_t statRF, uint8_t statRB, uint8_t pwmR, uint8_t pwmL) {
  digitalWrite(wheelLF, statLF);
  digitalWrite(wheelLB, statLB);
  digitalWrite(wheelRF, statRF);
  digitalWrite(wheelRB, statRB);
  analogWrite(ENA, pwmR);
  analogWrite(ENB, pwmL);
} 

void moveFront() {
  handleMotor(HIGH, LOW, HIGH, LOW, straightPwmL, straightPwmR);
}

void moveBack() {
  handleMotor(LOW, HIGH, LOW, HIGH, straightPwmL, straightPwmR);
}

void moveLeft() {
  handleMotor(LOW, HIGH, HIGH, LOW, curvePwm, curvePwm);
}

void moveRight() {
  handleMotor(HIGH, LOW, LOW, HIGH, curvePwm, curvePwm);
}

void stopMoving() {
  handleMotor(LOW, LOW, LOW, LOW, 0, 0);
}

/* <---------------------- Na Rampa ----------------------------> */

void moveFrontInRamp() {
  handleMotor(HIGH, LOW, HIGH, LOW, straightPwmRInRamp, straightPwmLInRamp);
}

void moveBackInRamp() {
  handleMotor(LOW, HIGH, LOW, HIGH, straightPwmRInRamp, straightPwmLInRamp);
}

void moveLeftInRamp() {
  handleMotor(LOW, LOW, HIGH, LOW, curvePwmInRamp, curvePwmInRamp);
}

void moveRightInRamp() {
  handleMotor(HIGH, LOW, LOW, LOW, curvePwmInRamp, curvePwmInRamp);
}

void stopMovingInRamp() {
  handleMotor(LOW, LOW, LOW, LOW, 0, 0);
}
