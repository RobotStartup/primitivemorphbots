 #define enA 9
#define in1 6
#define in2 7
#define button 4
int rotDirection = 0;
int pressed = false;
int forward_control = 22;
int backward_control = 19;
int forward = 0;
int backward = 0;

const long maxencoder1pos = 4120;
const long minencoder1pos = 0;

class Motor{
  private:
    int pin1, pin2;
      
  public:
    volatile long encoder1pos = 0;
    int flag=0;
    Motor(int pinA, int pinB)
    { 
      pin1 = pinA;
      pin2 = pinB;
      pinMode(pinA, INPUT);
      pinMode(pinB, INPUT);
      
    }
    
    void move_forward()
    {
      digitalWrite(2, LOW);                         // start with forward
      digitalWrite(3, HIGH);
    }

    void move_backward()
    {
      digitalWrite(2, HIGH);                        
      digitalWrite(3, LOW);
    }
    void motor_stop(){
      digitalWrite(pin1, HIGH);                         // start with forward
      digitalWrite(pin2, HIGH);
    }
  
};

Motor m1(2, 3);

void setup() {
  delay(6000);
  Serial.begin(115000);
   
  pinMode(0, INPUT);
  pinMode(1, INPUT);

  pinMode(forward_control, INPUT);
  pinMode(backward_control, INPUT);

  attachInterrupt( 0, doEncoderA0, CHANGE);
  attachInterrupt( 1, doEncoderB1, CHANGE);
  Serial.print(m1.encoder1pos);
  Serial.print('\n');
  
  m1.move_forward();
  
  
}
void loop() {
 
  forward = digitalRead(forward_control);
  backward = digitalRead(backward_control);
  if(forward==HIGH){
    m1.move_forward();
    Serial.print("high");
  }
  else if(backward==HIGH){
    m1.move_backward();
  }
  else{
    m1.motor_stop();
    Serial.print("low");
    
  }
  
  
  
}

void doEncoderA0()
    {
      if (digitalRead(0) == HIGH)
      {
        if (digitalRead(1) == LOW){
          m1.encoder1pos = m1.encoder1pos + 1;
        }
        else{
          m1.encoder1pos = m1.encoder1pos - 1;
        }
      }
      else{
        if (digitalRead(1) == HIGH){
          m1.encoder1pos = m1.encoder1pos + 1;
        }
        else{
          m1.encoder1pos = m1.encoder1pos - 1;
        }
      }
    }

void doEncoderB1(){
  if (digitalRead(1) == HIGH){
    if (digitalRead(0) == HIGH){
      m1.encoder1pos = m1.encoder1pos + 1; 
    }
    else{
      m1.encoder1pos = m1.encoder1pos - 1;
    }
  }
  else{
    if  (digitalRead(0) == LOW){
      m1.encoder1pos = m1.encoder1pos + 1;
    }
    else{
      m1.encoder1pos = m1.encoder1pos - 1;
    }
      
  }
}

  //Serial.println (encoder0Pos, DEC);
  // use for debugging - remember to comment out
