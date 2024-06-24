#define ENB 10 
#define ENA 5
#define wheelRF 6
#define wheelRB 7
#define wheelLF 9
#define wheelLB 8

#define senC 11
#define senR 2
#define senRC A0
#define senL 3
#define senLC A1

int curveValue = 540;

bool readL;
int readLC;
bool readC;
int readRC;
bool readR;

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
  reading();

  followLine2(readL, readLC, readC, readRC, readR);
}

void reading() {
  readL = digitalRead(senL);
  readLC = analogRead(senLC);
  readC = digitalRead(senC);
  readRC = analogRead(senRC);
  readR = digitalRead(senR);
  
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
