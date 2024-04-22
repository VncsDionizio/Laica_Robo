void frente (){
  digitalWrite(dirF, HIGH);
  digitalWrite(dirT, LOW);
  digitalWrite(esqF, HIGH);
  digitalWrite(esqT, LOW);
  analogWrite (ENB, 185 ); //esquerda
  analogWrite (ENA, 185 ); //direita
}

void tras (){
  digitalWrite(dirF, LOW);
  digitalWrite(dirT, HIGH);
  digitalWrite(esqF, LOW);
  digitalWrite(esqT, HIGH);
  analogWrite (ENB, 185 ); //esquerda
  analogWrite (ENA, 185 ); //direita
}
 
void direita (){
  digitalWrite(dirF, LOW);
  digitalWrite(dirT, HIGH);
  digitalWrite(esqF, HIGH);
  digitalWrite(esqT, LOW);
  analogWrite (ENB, 185 ); //esquerda
  analogWrite (ENA, 185 ); //direita
}

void esquerda (){
  digitalWrite(dirF, HIGH);
  digitalWrite(dirT, LOW);
  digitalWrite(esqF, LOW);
  digitalWrite(esqT, HIGH);
  analogWrite (ENB, 185 ); //esquerda
  analogWrite (ENA, 185 ); //direita
}

void devagar (){
  digitalWrite(dirF, HIGH);
  digitalWrite(dirT, LOW);
  digitalWrite(esqF, HIGH);
  digitalWrite(esqT, LOW);
  analogWrite (ENB, 150 ); //esquerda
  analogWrite (ENA, 150 ); //direita
} 

void parar(){
  digitalWrite(dirF, LOW);
  digitalWrite(dirT, LOW);
  digitalWrite(esqF, LOW);
  digitalWrite(esqT, LOW);
  analogWrite (ENB, 150 ); //esquerda
  analogWrite (ENA, 150 ); //direita
}

void devagar_direita (){
  digitalWrite(dirF, HIGH);
  digitalWrite(dirT, LOW);
  digitalWrite(esqF, HIGH);
  digitalWrite(esqT, LOW);
  analogWrite (ENB, 185 ); //esquerda
  analogWrite (ENA, 150 ); //direita
}

void devagar_esquerda (){
  digitalWrite(dirF, HIGH);
  digitalWrite(dirT, LOW);
  digitalWrite(esqF, HIGH);
  digitalWrite(esqT, LOW );
  analogWrite (ENB, 150 ); //esquerda
  analogWrite (ENA, 185 ); //direita
}
