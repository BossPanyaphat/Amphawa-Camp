int motor1pin1 = 4;
int motor1pin2 = 5;

int motor2pin1 = 6;
int motor2pin2 = 7;

void forward(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, HIGH);
}
void turnLeft(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, HIGH);
}
void turnRight(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
void backward(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}