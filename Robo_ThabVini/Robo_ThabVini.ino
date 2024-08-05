#include "Adafruit_VL53L0X.h"
#include "Adafruit_TCS34725.h"
#include <Wire.h>

// Esteira e motores
#define ENB 4 
#define ENA 5
#define wheelRF 37
#define wheelRB 36
#define wheelLF 34
#define wheelLB 35

// Sensores de reflectância
#define senC 8
#define senR 18
#define senRC A2
#define senL 22
#define senLC A1

// Ultrassônico
#define ECHO_F 15
#define TRIG_F 14
#define ECHO_R 27
#define TRIG_R 26
#define ECHO_L 46
#define TRIG_L 47

// Sensor a laser
#define laserPort 7
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

// Sensor RGB
#define RGBPort1 6
#define RGBPort2 1
String greenSide;
int changes;
int lastRead;
int goal;
Adafruit_TCS34725 rgbSen = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_16X);
struct RGBC {
  int r;
  int g;
  int b;
  int c;
};
int rgbLedR = 6;
int rgbLedL = 7;

// Variáveis de leitura
bool readL;
int readLC;
int readC;
int readRC;
bool readR;
bool bReadLC;
bool bReadRC;

// Valores para seguir linha 
int curvePwm = 190;
int straightPwmR = 120;
int straightPwmL = 120;
int curveValue = 800;

// Rampa
bool inRamp = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rgbInit();
  initLaser();
  pinMode(rgbLedR, OUTPUT);
  pinMode(rgbLedL, OUTPUT);
  digitalWrite(rgbLedR, LOW);
  digitalWrite(rgbLedL, LOW);

  pinMode(TRIG_F, OUTPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(ECHO_R, INPUT);
}

void loop() {
  // reading();
  // moveFront();
  followLine(readL,  readLC,  readC,  readRC,  readR);
  // showReading();
  // Serial.println(readGreen());

  // Serial.print("Esquerdo: ");
  // showUltraDistance(TRIG_L, ECHO_L);
  // Serial.print("Frente: ");
  // showUltraDistance(TRIG_F, ECHO_F);
  // Serial.print("Direito: ");
  // showUltraDistance(TRIG_R, ECHO_R);
  // delay(1000);
  // Serial.println("------------------------------");
}
