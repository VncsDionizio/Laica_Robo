void followLineInRamp(bool readSenL, int readSenLC, bool readSenC, int readSenRC, bool readSenR) {
  reading();

  if ((readL && bReadLC && readC && !readR) || (readR && bReadRC && readC && !readL) || (readR && readL)) {
    digitalWrite(rgbLedR, LOW);
    digitalWrite(rgbLedL, LOW);
  } else if (readC) {
    int laserDist = laserSen();
    int sonicDist = sonicSen(TRIG_F, ECHO_F);
    if ((laserDist <= 12) && (sonicDist <= 12)) {
      obstacleToRight();
    }
    moveFrontInRamp();
  } else {
    if ((readL && readLC) || (readL && !bReadLC)) {
      stopMoving();

      while (!readC) {
        reading();
        moveLeftInRamp();
      }
    } else if ((readR && readRC) || (readR && !bReadRC)) {
      stopMoving();

      while(!readC) {
        reading();
        moveRightInRamp();
      }
    } else if (readL || bReadLC) {
      moveLeftInRamp();
    } else if (readR || bReadRC) {
      moveRightInRamp();
    } else {
      moveFrontInRamp();
    }
  }
}