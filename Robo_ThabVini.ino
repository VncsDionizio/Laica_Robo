#define ENB 2 
#define esqF 3 
#define esqT 4
#define dirF 5 
#define dirT 6 
#define ENA 7
#define sensorD 8
#define sensorC 9
#define sensorE 10

bool estadoD, estadoC, estadoE;

void setup() {
  Serial.begin(9600);
  pinMode(ENB, OUTPUT);
  pinMode(esqF, OUTPUT);
  pinMode(esqT, OUTPUT);
  pinMode(dirF, OUTPUT);
  pinMode(dirT, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(sensorD, INPUT);
  pinMode(sensorC, INPUT);
  pinMode(sensorE, INPUT);
 
}
void loop() {
estadoD = digitalRead(sensorD);
estadoC = digitalRead(sensorC);
estadoE = digitalRead(sensorE); 
Serial.print("D");
Serial.print(estadoD);
Serial.print(" C");
Serial.print(estadoC);
Serial.print(" E");
Serial.print(estadoE);
Serial.println();

}