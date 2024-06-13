#define ENB 10 
#define ENA 5
#define wheelLF 8
#define wheelRF 6
#define wheelLB 7
#define wheelRB 9

#define senC 11
#define senR 2
#define senRC A0
#define senL 3
#define senLC 12

int curveValue = 540;

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(wheelLF, OUTPUT);
  pinMode(wheelLB, OUTPUT);
  pinMode(wheelRF, OUTPUT);
  pinMode(wheelRB, OUTPUT);
  
  pinMode(senLC, INPUT);
  pinMode(senL, INPUT);
  pinMode(senC, INPUT);
  pinMode(senRC, INPUT);
  pinMode(senR, INPUT);
}

void loop() {
  bool readL = digitalRead(senL);
  int readLC = analogRead(senLC);
  bool readC = digitalRead(senC);
  int readRC = analogRead(senRC);
  bool readR = digitalRead(senR);

  if (readL && readLC && readRC && readR) {
    moveFront();
  } else if (readL == HIGH && readLC > 500) {
    move90Right();
  } else if (readR == HIGH && readRC > 500) {
    move90Left(); 
  } else if (readL == HIGH || readLC > 500) {  
    moveRight();
  } else if (readR == HIGH || readRC > 500) {  
    moveLeft();
  } else if (readC == HIGH) {  
    moveFront();
  } else {
    moveFront();
  }
}

void handleMotor(uint8_t statLF, uint8_t statLB, uint8_t statRF, uint8_t statRB, uint8_t pwm) {
  digitalWrite(wheelLF, statLF);
  digitalWrite(wheelLB, statLB);
  digitalWrite(wheelRF, statRF);
  digitalWrite(wheelRB, statRB);
  analogWrite(ENA, pwm);
  analogWrite(ENB, pwm);
} 

void moveFront() {
  handleMotor(HIGH, LOW, HIGH, LOW, 165);
  delay(25);
}

void moveBack() {
  handleMotor(LOW, HIGH, LOW, HIGH, 165);
  delay(25);
}

void moveLeft() {
  handleMotor(HIGH, LOW, LOW, HIGH, 255);
  delay(25);
}

void moveRight() {
  handleMotor(LOW, HIGH, HIGH, LOW, 255);
  delay(25);
}

void move90Right() {
  handleMotor(LOW, HIGH, HIGH, LOW, 255);
  delay(500);
}

void move90Left() {
  handleMotor(HIGH, LOW, LOW, HIGH, 255);
  delay(500);
}

void stopMoving() {
  handleMotor(LOW, LOW, LOW, LOW, 0);
}

