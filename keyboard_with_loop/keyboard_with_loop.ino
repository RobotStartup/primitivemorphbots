#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define enA 14
#define enB 15
//#define button 4


int forward_control1 = 21;
int backward_control1 = 20;
int forward_control2 = 18;
int backward_control2 = 13;
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
    volatile long encoderpos;
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
      encoderpos = 21;
    }
    
    void move_backward(int rot)
    {
      int bac_flag = 0;
      digitalWrite(enabler, HIGH);
      while(true){
        digitalWrite(pin1, LOW);                         // start with forward
        digitalWrite(pin2, HIGH);
        if(bac_flag==0){
          delay(200);
          bac_flag=1;
        }
        if (abs(encoderpos%(encoder_rot*rot)) < 2){
          encoderpos=21;
          motor_stop(); 
          break;
        }
    }
    return;
    }
    

    void move_forward(int rot)
    { 
      int for_flag = 0;
      digitalWrite(enabler, HIGH);
      while (true){
        digitalWrite(pin1, HIGH);                        
        digitalWrite(pin2, LOW);
        if(for_flag==0){
          delay(200);
          for_flag=1;
        }
        if (abs(encoderpos%(encoder_rot*rot)) < 2){
          encoderpos=21;
          motor_stop();
          break;
        }
      }
    }
    void motor_stop(){
      digitalWrite(enabler, LOW);
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

  pinMode(forward_control1, INPUT_PULLUP);
  pinMode(backward_control1, INPUT_PULLUP);
  pinMode(forward_control2, INPUT_PULLUP);
  pinMode(backward_control2, INPUT_PULLUP);

  attachInterrupt( 0, doEncoderA0, CHANGE);
  attachInterrupt( 1, doEncoderA1, CHANGE);
  attachInterrupt( 7, doEncoderB0, CHANGE);
  attachInterrupt( 8, doEncoderB1, CHANGE);
  
  Serial.print('\n');
  
  //m1.move_forward();
  
  
}
void loop() {

 if (Serial.available()>0){
  //char c[2];
  String c = Serial.readString();
  int rot = c[1] - '0';

  if(c[0] == 'w'){
    Serial.print("motor1_forward");
    Serial.print('\n');
    m1.move_forward(rot);
  
  }
  if(c[0] == 's'){
    //Serial.print("motor1_backward");
    Serial.print('\n');
    m1.move_backward(rot);
  }

  if(c[0] == 'a'){
    Serial.print("motor2_forward");
    Serial.print('\n');
    m2.move_forward(rot);
  }

  if(c[0] == 'd'){ 
    Serial.print("motor2_backward");
    Serial.print('\n');
    m2.move_backward(rot);
  }

  if(c[0] == 'e'){ 
    Serial.print("motor2_backward");
    Serial.print('\n');
    m2.motor_stop();
    m1.motor_stop();
  }

  if(c[0] == 'l'){ 
    Serial.print("going in a loop");
    Serial.print('\n');
    m1.move_forward(rot);
    m2.move_forward(rot);
    m1.move_backward(rot);
    m2.move_backward(rot);
  }
   /*else{
    m1.motor_stop();
    m2.motor_stop();
  }*/
 }
   
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
