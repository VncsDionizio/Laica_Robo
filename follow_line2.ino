void followLine2(bool readSenL, int readSenLC, bool readSenC, int readSenRC, bool readSenR) {
  bool bReadLC;
  bool bReadRC;

  reading();

  if (readC) {
    moveFront();
  } else {
    char lastCurve;

    while (!readC) {
      reading();
      bReadLC = (readLC < curveValue ? false : true);
      bReadRC = (readRC < curveValue ? false : true);

      if (readL || bReadLC) {
        lastCurve = "L";
        moveLeft();
      } else if (readR || bReadRC) {
        lastCurve = "R";
        moveRight();
      } else if (readC) {
        if (lastCurve == "L") {
          moveLeft();
          delay(120);
        } else {
          moveRight();
          delay(120);
        }
      } else {
        moveFront();
      }
    }
  }
}