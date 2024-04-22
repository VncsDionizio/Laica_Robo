#define ENB 3 
#define esqF 2 
#define esqT 4
#define dirF 6 
#define dirT 7 
#define ENA 5
#define sensorD 8
#define sensorC 9
#define sensorE 10
//preto = 1 , branco = 0

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

if (estadoE == 0 & estadoC == 1 & estadoD == 0) {
frente();
}

else if (estadoE == 1 & estadoC == 0 & estadoD == 0) {
esquerda();
}

else if (estadoE == 1 & estadoC == 1 & estadoD == 0) {
devagar_esquerda();
}

else if (estadoE == 0 & estadoC == 0 & estadoD == 1) {
direita();
}

else if (estadoE == 0 & estadoC == 1 & estadoD == 1) {
devagar_direita();
}

else if (estadoE == 0 & estadoC == 0 & estadoD == 0) {
devagar();
}

else if (estadoE == 1 & estadoC == 0 & estadoD == 1) {
devagar();
}

else{
  parar();
}

Serial.print("D");
Serial.print(estadoD);
Serial.print(" C");
Serial.print(estadoC);
Serial.print(" E");
Serial.print(estadoE);
Serial.println();

}
