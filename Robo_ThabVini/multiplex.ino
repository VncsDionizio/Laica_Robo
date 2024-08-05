void handlePorts(int bus) {
  Wire.beginTransmission(0x70);  
  Wire.write(1 << bus);            
  Wire.endTransmission();
  delay(3);  
}