void initXlr8() {
  xlr8.begin();
  xlr8.calcGyroOffsets(true);
}

Accel getAngleRead(int port) {
  handlePorts(port);

  xlr8.update();
  int x = xlr8.getAngleX();
  int y = xlr8.getAngleY();
  int z = xlr8.getAngleZ();

  Accel read;
  read.x = x;
  read.y = y;
  read.z = z;

  return read;
}

void showAngles(int port) {
  handlePorts(port);

  Accel read = getAngleRead(accelPort);

  Serial.print("X - ");
  Serial.print(read.x);
  Serial.print("   Y - ");
  Serial.print(read.y);
  Serial.print("   Z - ");
  Serial.println(read.z);
}