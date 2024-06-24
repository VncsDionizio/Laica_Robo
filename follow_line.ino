// void followLine(int readL, int readLC, int readC, int readRC, int readR) {
//   if (readL && readLC && readRC && readR) {
//     moveFront();
//    } else if (readL == HIGH && readLC > 500 && readR == LOW) {
//     move90Left(readL, readLC, readC, readRC, readR);
//    } else if (readR == HIGH && readRC > 500 && readL == LOW) {
//     move90Right(readL, readLC, readC, readRC, readR); 
//   } else if (readL == HIGH || readLC > 500) {  
//     moveLeft();
//   } else if (readR == HIGH || readRC > 500) {  
//     moveRight();
//   } else if (readC == HIGH) {  
//     moveFront();
//   } else {
//     moveFront();
//   }
// }