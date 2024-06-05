#define ENB 10 
#define ENA 5
#define sensorCL A0
#define sensorCR A1
#define wheelLF 8
#define wheelRF 6
#define wheelLB 7
#define wheelRB 9

int curveValue = 520;

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(wheelLF, OUTPUT);
  pinMode(wheelLB, OUTPUT);
  pinMode(wheelRF, OUTPUT);
  pinMode(wheelRB, OUTPUT);
  
  pinMode(sensorCL, INPUT);
  pinMode(sensorCR, INPUT);
}

void loop() {
  int statusSensorCL = analogRead(sensorCL);
  int statusSensorCR = analogRead(sensorCR);
  Serial.print("Sensor esquerdo: ");
  Serial.print(statusSensorCL);
  Serial.print("Sensor direito: ");
  Serial.println(statusSensorCR);
  
  
}