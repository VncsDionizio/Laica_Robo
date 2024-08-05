void initLaser() {
  handlePorts(laserPort);
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  } else {
    Serial.println("VL53L0X booted");
  }
}

int laserSen() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  return measure.RangeMilliMeter/10;
}

int laserSenStatus() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  return measure.RangeMilliMeter == 4;
}