#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define enA 14
#define enB 15

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(21, INPUT_PULLUP); 
  pinMode(20, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13PU)==LOW){
    motor2_backward ();
    Serial.print("moto1 moving forward");
  }
  else{
    motor2_stop();
  }
  //motor1_forward ();
  //motor2_stop();
}

void motor1_forward(){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

void motor1_backward(){
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}

void motor1_stop(){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
}

void motor2_backward(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void motor2_forward(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void motor2_stop(){
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}
