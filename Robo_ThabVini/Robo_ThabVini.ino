#include "Adafruit_VL53L0X.h"
#include "Adafruit_TCS34725.h"
#include <MPU6050_tockn.h>
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
int curvePwm = 160;
int straightPwmR = 150;
int straightPwmL = 150;
int curveValue = 800;

// Acelerômetro 
int accelPort = 2;
MPU6050 xlr8(Wire);
struct Accel {
  float x;
  float y;
  float z;
};
Accel firstAngle;

// Rampa
bool inRamp = false;
int curvePwmInRamp = 255 ;
int straightPwmRInRamp = 240;
int straightPwmLInRamp = 240;


void setup() {
  Serial.begin(9600);
  Wire.begin();

  initXlr8();
  firstAngle = getAngleRead(accelPort);

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
  Accel angle = getAngleRead(accelPort);
  // Serial.print("Inicial - ");
  // Serial.println(firstAngle.y);
  // Serial.print("Angulo - ");
  // Serial.println(angle.y);
  // delay(500);

  if ((angle.y - firstAngle.y) >= 15) {
    straightPwmLInRamp = 244;
    straightPwmRInRamp = 244;
    followLineInRamp(readL, readLC, readC, readRC, readR);
  } else if (angle.y < -15) {
    straightPwmLInRamp = 140;
    straightPwmRInRamp = 140;
    followLineInRamp(readL, readLC, readC, readRC, readR);
  } else {
    followLine(readL, readLC, readC, readRC, readR);
  }
}
