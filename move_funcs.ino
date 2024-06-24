int curvePwm = 200;
int straightPwm = 180;

void handleMotor(uint8_t statLF, uint8_t statLB, uint8_t statRF, uint8_t statRB, uint8_t pwmR, uint8_t pwmL) {
  digitalWrite(wheelLF, statLF);
  digitalWrite(wheelLB, statLB);
  digitalWrite(wheelRF, statRF);
  digitalWrite(wheelRB, statRB);
  analogWrite(ENA, pwmR);
  analogWrite(ENB, pwmL);
} 

void moveFront() {
  handleMotor(HIGH, LOW, HIGH, LOW, straightPwm, straightPwm);
}

void moveBack() {
  handleMotor(LOW, HIGH, LOW, HIGH, straightPwm, straightPwm);
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
