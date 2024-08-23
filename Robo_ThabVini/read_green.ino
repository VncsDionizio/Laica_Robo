String readGreen() {
  RGBC colors = rgbGetRead(RGBPort1);
  bool rightIsGreen = ((colors.r <= 100) && (colors.g >= 130) && (colors.b <= 100));

  colors = rgbGetRead(RGBPort2);
  bool leftIsGreen = ((colors.r <= 100) && (colors.g >= 130) && (colors.b <= 100));

  if (rightIsGreen && leftIsGreen) {
    return "RL";
  } else if (rightIsGreen && !leftIsGreen) {
    return "R";
  } else if (!rightIsGreen && leftIsGreen) {
    return "L";
  } else {
    return "N";
  }
}

void followGreen() {
  stopMoving();
  reading();
  // Serial.println(readGreen());

  bool bReadLC;
  bool bReadRC;
  bool lastRead = readC;
  char side;

  bReadLC = (readLC < curveValue ? false : true);
  bReadRC = (readRC < curveValue ? false : true);

  if (greenSide == "N") {
    moveFront();
    delay(400);
    reading();
    if (!readC && !bReadLC && !readL) {
      while (!readC) {
        reading();
        moveRight();
      }
      delay(50);
      return;
    } else if (!readC && !bReadRC && !readR) {
      while (!readC) {
        reading();
        moveLeft();
      }
      delay(50);
      return;
    }
    return;
  }

  if (greenSide == "L") {
    goal = 2 + lastRead;
  } else if (greenSide == "RL") {
    goal = 3 + lastRead;
  } else if (greenSide == "R") {
    goal = 2 + lastRead;
  }
  
  changes = 0;
  lastRead = readC;

  moveFront();
  delay(250);
  while (changes < goal) {
    reading();
    Serial.println(changes);
    // greenSide = readGreen();
    // Serial.println(readGreen());
    if (lastRead != readC) {
      changes += 1;
      lastRead = readC;

      if (changes >= goal) {
        break;
      }
    }
    if (greenSide == "R" || greenSide == "RL") {
      moveRight();
      Serial.print("Verde na direita");
    } else if (greenSide == "L") {
      moveLeft();
      Serial.print("Verde na esquerda");
    }
    // Serial.println(changes);
  }

  changes = 0;
  return;
}