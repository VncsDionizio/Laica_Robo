void first_steps() {
  if (statusSensorCL <= curveValue && statusSensorCR <= curveValue) {
    moveFront();
  } else if (statusSensorCL <= curveValue && statusSensorCR >= curveValue) {
    moveLeft();
  } else if (statusSensorCL >= curveValue && statusSensorCR <= curveValue) {
    moveRight();
  } else {
    moveFront();
  }
}