void rgbInit() {
  handlePorts(RGBPort1);
  if (rgbSen.begin()) {
    Serial.println("RGB 1: OK.");
  } else {
    Serial.println("RGB 1: Não iniciou.");
  }

  handlePorts(RGBPort2);
  if (rgbSen.begin()) {
    Serial.println("RGB 2: OK.");
  } else {
    Serial.println("RGB 2: Não iniciou.");
  }
}

RGBC rgbGetRead(int port) {
  handlePorts(port);
  uint16_t rawR, rawG, rawB, rawC;

  rgbSen.getRawData(&rawR, &rawG, &rawB, &rawC);

  uint8_t r = map(rawR, 0, 4096, 0, 255);
  uint8_t g = map(rawG, 0, 4096, 0, 255);
  uint8_t b = map(rawB, 0, 4096, 0, 255);
  uint8_t c = map(rawC, 0, 4096, 0, 255);

  RGBC read;
  read.r = r;
  read.g = g;
  read.b = b;
  read.c = c;

  return read;
}

void rgbShowRead() {
  Serial.println("1:");
  
  RGBC colors = rgbGetRead(RGBPort1);

  Serial.print("Red: "); Serial.println(colors.r); 
  Serial.print("Green: "); Serial.println(colors.g); 
  Serial.print("Blue: "); Serial.println(colors.b); 
  Serial.print("Claridade: "); Serial.println(colors.c); 
  Serial.println(" ");
  delay(500);
  
  colors = rgbGetRead(RGBPort2);
  Serial.println("2:");
  Serial.print("Red: "); Serial.println(colors.r); 
  Serial.print("Green: "); Serial.println(colors.g); 
  Serial.print("Blue: "); Serial.println(colors.b); 
  Serial.print("Claridade: "); Serial.println(colors.c); 
  Serial.println(" ");
  delay(500);
}