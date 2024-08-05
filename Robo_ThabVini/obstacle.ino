void obstacleToRight() {
  int laserDist = laserSen();
  
  moveRight();
  delay(500);

  int ultraDist = sonicSen(TRIG_L, ECHO_L);

  while (!(ultraDist > 20)) {
    ultraDist = sonicSen(TRIG_L, ECHO_L);
    moveFront();
  }
  delay(350);

  moveLeft();
  delay(550);

  while (!(ultraDist < 20)) {
    ultraDist = sonicSen(TRIG_L, ECHO_L);
    moveFront();
  }
  while (ultraDist < 20) {
    ultraDist = sonicSen(TRIG_L, ECHO_L);
    moveFront();
  }
  moveFront();
  delay(500);

  moveLeft();
  delay(590);

  reading();
  while (!readC) {
    reading();
    moveFront();
  }
  moveFront();
  delay(150);
  reading();
  while (!readC) {
    reading();
    moveRight();
  }
  return;
}