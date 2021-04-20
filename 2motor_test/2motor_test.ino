#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define enA 14
#define enB 15
//#define button 4


int forward_control1 = 23;
int backward_control1 = 21;
int forward_control2 = 20;
int backward_control2 = 18;
int forward1 = 0;
int backward1 = 0;
int forward2 = 0;
int backward2 = 0;
int encoder_rot = 4227;
int for_flag = 0;
int bac_flag = 0;

const long maxencoder1pos = 4120;
const long minencoder1pos = 0;

class Motor{
  private:
    int pin1, pin2, enabler;
      
  public:
    volatile long encoderpos = 21;
    int for_flag = 0;
    int bac_flag = 0;
    Motor(int pinA, int pinB, int pinC)
    { 
      pin1 = pinA;
      pin2 = pinB;
      enabler = pinC;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      pinMode(enabler, OUTPUT);
      
    }
    
    void move_backward()
    {
      digitalWrite(enabler, HIGH);
      
      while(true){
        digitalWrite(pin1, LOW);                         // start with forward
        digitalWrite(pin2, HIGH);
        if (abs(encoderpos%encoder_rot) < 2){
          
          break;
        }
    }
    }
    

    void move_forward()
    {
      digitalWrite(enabler, HIGH);
      while (true){
        digitalWrite(pin1, HIGH);                        
        digitalWrite(pin2, LOW);
        if (abs(encoderpos%encoder_rot) < 2){
          motor_stop();
          break;
        }
      }
    }
    void motor_stop(){
      digitalWrite(enabler, HIGH);
      digitalWrite(pin1, HIGH);                         // start with forward
      digitalWrite(pin2, HIGH);
    }
  
};

Motor m1(in1, in2, enA);
Motor m2(in3, in4, enB);

void setup() {
  //delay(6000);
  Serial.begin(115000);
   
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  pinMode(forward_control1, INPUT);
  pinMode(backward_control1, INPUT);
  pinMode(forward_control2, INPUT);
  pinMode(backward_control2, INPUT);

  attachInterrupt( 0, doEncoderA0, CHANGE);
  attachInterrupt( 1, doEncoderA1, CHANGE);
  attachInterrupt( 7, doEncoderB0, CHANGE);
  attachInterrupt( 8, doEncoderB1, CHANGE);
  
  Serial.print('\n');
  
  //m1.move_forward();
  
  
}
void loop() {
 
  forward1 = digitalRead(forward_control1);
  backward1 = digitalRead(backward_control1);
  forward2 = digitalRead(forward_control2);
  backward2 = digitalRead(backward_control2);

  if(forward1==HIGH){
    
    m1.move_forward();
  
  }
  else if(backward1 == HIGH){
    m1.move_backward();
  }

  else if(forward2 == HIGH){
    m2.move_forward();
  }

  else if(backward2 == HIGH){
    m2.move_backward();
  }

  else{
    m1.motor_stop();
    m2.motor_stop();
  }
  
  
  //else if(backward==HIGH){
    //m1.move_backward();
    //bac_flag=1;
  //}
  //else{
    //m1.motor_stop();
    //Serial.print("low");
    
}
  


void doEncoderA0()
    {
      if (digitalRead(0) == HIGH)
      {
        if (digitalRead(1) == LOW){
          m1.encoderpos = m1.encoderpos + 1;
        }
        else{
          m1.encoderpos = m1.encoderpos - 1;
        }
      }
      else{
        if (digitalRead(1) == HIGH){
          m1.encoderpos = m1.encoderpos + 1;
        }
        else{
          m1.encoderpos = m1.encoderpos - 1;
        }
      }
    }

void doEncoderA1(){
  if (digitalRead(1) == HIGH){
    if (digitalRead(0) == HIGH){
      m1.encoderpos = m1.encoderpos + 1; 
    }
    else{
      m1.encoderpos = m1.encoderpos - 1;
    }
  }
  else{
    if  (digitalRead(0) == LOW){
      m1.encoderpos = m1.encoderpos + 1;
    }
    else{
      m1.encoderpos = m1.encoderpos - 1;
    }
      
  }
}

void doEncoderB0()
    {
      if (digitalRead(7) == HIGH)
      {
        if (digitalRead(8) == LOW){
          m2.encoderpos = m2.encoderpos + 1;
        }
        else{
          m2.encoderpos = m2.encoderpos - 1;
        }
      }
      else{
        if (digitalRead(8) == HIGH){
          m2.encoderpos = m2.encoderpos + 1;
        }
        else{
          m2.encoderpos = m2.encoderpos - 1;
        }
      }
    }

void doEncoderB1(){
  if (digitalRead(8) == HIGH){
    if (digitalRead(7) == HIGH){
      m2.encoderpos = m2.encoderpos + 1; 
    }
    else{
      m2.encoderpos = m2.encoderpos - 1;
    }
  }
  else{
    if  (digitalRead(7) == LOW){
      m2.encoderpos = m2.encoderpos + 1;
    }
    else{
      m2.encoderpos = m2.encoderpos - 1;
    }
      
  }
}

  //Serial.println (encoder0Pos, DEC);
  // use for debugging - remember to comment out
