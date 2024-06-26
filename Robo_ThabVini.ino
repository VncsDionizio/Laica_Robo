#include "Adafruit_VL53L0X.h"

// Esteira e motores
#define ENB 10 
#define ENA 5
#define wheelRF 6
#define wheelRB 7
#define wheelLF 9
#define wheelLB 8

// Sensores de reflectância
#define senC 11
#define senR 2
#define senRC A0
#define senL 3
#define senLC A1

// Ultrassônico
#define echo 12
#define aci 13

// Sensor a laser
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// Variáveis de leitura
bool readL;
int readLC;
bool readC;
int readRC;
bool readR;

// Valores de velocidade
int curvePwm = 255;
int straightPwm = 230;

// Rampa
bool naRampa = false;

void setup() {
  Serial.begin(9600);

  if (!lox.begin()) {
    Serial.println("Failed to boot VL53L0X sensor!");
    while (1); 
  }
  
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
  // moveFront();

  // if (!naRampa) {
  //   if (laserSenStatus()) {
  //     straightPwm = 180;
  //   } else if ((laserSen() - sonicSen()) > 5) {
  //     straightPwm = 255;
  //     naRampa = true;

  //     if (!laserSenStatus()) {
  //       moveFront();
  //       delay(1000);
  //     }
  //   }
  // }

  // if (naRampa) {
  //   if ((laserSen() - sonicSen()) > 5) {
  //       straightPwm = 180;
  //       naRampa = false;
  //   }
  // }

  followLine(senL, senLC, senC, senRC, senR);
}

