//DECLARACION DE PINES DE SWITCHES
const int A = 37;
const int B = 36;
const int C = 35;
const int D = 34;
//DECLARACION DE PINES DE EL SEMAFORO
const int sem1 = 22; //VERDE
const int sem2 = 23; //AMARILLO
const int sem3 = 24; //ROJO

void setup() {
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  pinMode(D,INPUT);
  pinMode(sem1,OUTPUT);
  pinMode(sem2,OUTPUT);
  pinMode(sem3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(((digitalRead(A)== LOW)&&(digitalRead(B)== LOW))||((digitalRead(A)== LOW)&&(digitalRead(C)== LOW))){//(!A*!B + !A*!C)
    digitalWrite(sem1,LOW);
    digitalWrite(sem2,LOW);
    digitalWrite(sem3,HIGH);
  }else if((digitalRead(B) == HIGH)&&(digitalRead(C) == HIGH)){
      digitalWrite(sem1,LOW);
      digitalWrite(sem2,HIGH  );
      digitalWrite(sem3,LOW);
  }else if(((digitalRead(A)== HIGH)&&(digitalRead(B)== LOW))||((digitalRead(A)== HIGH)&&(digitalRead(C)== LOW))){
      digitalWrite(sem1,HIGH);
      digitalWrite(sem2,LOW);
      digitalWrite(sem3,LOW);
  }else{
    digitalWrite(sem3,LOW);
    digitalWrite(sem2,LOW);
    digitalWrite(sem1,LOW);
  }
}
