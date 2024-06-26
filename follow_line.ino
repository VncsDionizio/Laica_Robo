int curveValue = 540;

void followLine(bool readSenL, int readSenLC, bool readSenC, int readSenRC, bool readSenR) {
  bool bReadLC;
  bool bReadRC;

  reading();

  if (readC) {
    moveFront();
  } else {
    bReadLC = (readLC < curveValue ? false : true);
    bReadRC = (readRC < curveValue ? false : true);

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
    }

    else if (readL || bReadLC) {
      moveLeft();
    } else if (readR || bReadRC) {
      moveRight();
    } else {
      moveFront();
    }
  }
}