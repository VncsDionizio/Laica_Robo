void followLine(bool readSenL, int readSenLC, bool readSenC, int readSenRC, bool readSenR) {
  reading();

  if ((readL && bReadLC && readC && !readR) || (readR && bReadRC && readC && !readL) || (readR && readL)) {
    stopMoving();
    delay(50);
    moveBack();
    delay(100);
    digitalWrite(rgbLedR, HIGH);
    digitalWrite(rgbLedL, HIGH);
    delay(75);
    greenSide = readGreen();
    followGreen();
    digitalWrite(rgbLedR, LOW);
    digitalWrite(rgbLedL, LOW);
  } else if (readC) {
    int laserDist = laserSen();
    int sonicDist = sonicSen(TRIG_F, ECHO_F);
    if ((laserDist <= 12) && (sonicDist <= 12)) {
      obstacleToRight();
    }
    moveFront();
  } else {
    if ((readL && readLC) || (readL && !bReadLC)) {
      stopMoving();

      while (!readC) {
        reading();
        moveLeft();
      }
    } else if ((readR && readRC) || (readR && !bReadRC)) {
      stopMoving();

      while(!readC) {
        reading();
        moveRight();
      }
    } else if (readL || bReadLC) {
      moveLeft();
    } else if (readR || bReadRC) {
      moveRight();
    } else {
      moveFront();
    }
  }
}