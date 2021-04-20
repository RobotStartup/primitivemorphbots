
byte IN1pin[7] = { 2,  4,  8, 12, 14, 18, 22 };
byte IN2pin[7] = { 3,  5,  9, 13, 15, 19, 23 };
byte CHApin[7] = { 0,  6, 10, 16, 20, 24, 26 };
byte CHBpin[7] = { 1,  7, 11, 17, 21, 25, 27 };

// C:\Users\new user\Documents\SGMB\Arduino\Motor_Control_Board_97_Teensy_4-0.ino partially working

// arduino.exe
// C:\Users\new user\Documents\SGMB\arduino-1.8.13-windows\arduino-1.8.13

int axisNum = 0;
int instrNum = 0;
const int instrTotal = 5;                 // total number of instructions
const int axisTotal = 7;

const int LEDpin17 = 17;
//volatile int cpuPos = 0;
//volatile unsigned int encoderPos[7] = { 0 };

long currentMillis = millis();

// 5 is instruction number. 7 is number of axes.
//volatile unsigned  int arrXYZ[5][7] = { {1000, 1000, 300, 0, 0, 0, 0}, {500, 100, 500, 0, 0, 0, 0}, {5000, 300, 300, 0, 0, 0, 0}, {300, 400, 300, 0, 0, 0, 0}, {800, 800, 500, 0, 0, 0, 0} };
//volatile  int arrXYZ[5][7] = { {1001, 1002, 1003, 1004, 1005, 1006, 1007}, {3001, 2002, 2003, 2004, 2005, 2006, 2007}, {2000, 3002, 3003, 3004, 3005, 3006, 3007}, {4001, 4002, 4003, 4004, 4005, 4006, 4007}, {3500, 5002, 5003, 5004, 5005, 5006, 5007} };
//volatile  int arrXYZ[5][7] = { {1001, 1002, 1003, 1004, 1005, 1006, 1007}, {3001, 2002, 2003, 2004, 2005, 2006, 2007}, {2000, 3002, 3003, 3004, 3005, 3006, 3007}, {5001, 4002, 4003, 4004, 4005, 4006, 4007}, {2500, 5002, 5003, 5004, 5005, 5006, 5007} };
volatile  int arrXYZ[5][7] = { {1001, 1002, 1003, 1004, 1005, 1006, 1007}, {3001, 3012, 2003, 2004, 2005, 2006, 2007}, {2000, 2002, 3003, 3004, 3005, 3006, 3007}, {5001, 5002, 4003, 4004, 4005, 4006, 4007}, {2500, 2500, 5003, 5004, 5005, 5006, 5007} };

const int ledPin =  LED_BUILTIN;// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
const long interval1 = 1000;           // interval at which to blink (milliseconds)

volatile long encoderPosA0B1 = 0;
volatile long encoderPosA7B8 = 0;
volatile long encoderPosA14B15 = 0;
volatile long encoderPosA16B17 = 0;

bool flag1F = HIGH;
bool flag1R = HIGH;
bool flag1Z = HIGH;
bool flag1  = HIGH;
bool flag2F = HIGH;
bool flag2R = HIGH;
bool flag2Z = HIGH;
bool flag2  = HIGH;
bool flag3F = HIGH;
bool flag3R = HIGH;
bool flag3Z = HIGH;
bool flag3  = HIGH;
bool flag4F = HIGH;
bool flag4R = HIGH;
bool flag4Z = HIGH;
bool flag4  = HIGH;
bool flag14 = HIGH;

bool dir = HIGH;
long count1 = 0;
long count2 = 0;
long count3 = 0;
long count4 = 0;
long count5 = 0;
long timeNew = 0;
long timeOld = 0;
bool flagTime = HIGH;

long encNew = 0;
long encOld = 0;
long encNet = 0;

bool netFlag = HIGH;
long encoderPosA0B1new = 0;
long encoderPosA0B1old = 0;

bool a = LOW;



void setup() 
{
//Serial.begin(9600); 
  Serial.begin(115000); 
  pinMode(ledPin, OUTPUT);
 
  pinMode(0, INPUT);      // IN1
  pinMode(1, INPUT);      // IN2
  
  pinMode(2, OUTPUT);        // CHA
  pinMode(3, OUTPUT);        // CHB
  pinMode(4, OUTPUT);      // IN1
  pinMode(5, OUTPUT);      // IN2
  pinMode(6, OUTPUT);        // CHA
  
  pinMode(7, INPUT);        // CHB
  pinMode(8, INPUT);      // IN1
  
  pinMode(9, OUTPUT);      // IN2
  pinMode(10, OUTPUT);        // CHA
  pinMode(11, OUTPUT);        // CHB
  pinMode(12, OUTPUT);     // IN1

  pinMode(14, INPUT);      // IN1
  pinMode(15, INPUT);      // IN2
  pinMode(16, INPUT);      // IN2
  pinMode(17, INPUT);      // IN2

  pinMode(18, OUTPUT);      // IN1
  pinMode(19, OUTPUT);      // IN2
  pinMode(20, INPUT);      // IN1
  pinMode(21, INPUT);      // IN1
  pinMode(22, OUTPUT);      // IN1
  pinMode(23, OUTPUT);      // IN2
          
  attachInterrupt( 0, doEncoderA0, CHANGE);
  attachInterrupt( 1, doEncoderB1, CHANGE);
  attachInterrupt( 7, doEncoderA7, CHANGE);
  attachInterrupt( 8, doEncoderB8, CHANGE);
  attachInterrupt(14, doEncoderA14, CHANGE);
  attachInterrupt(15, doEncoderB15, CHANGE);
  attachInterrupt(18, doEncoderA16, CHANGE);
  attachInterrupt(19, doEncoderB17, CHANGE);
}

//*************************************************************
// digitalWrite(2, HIGH);       // IN2   forward direction
// digitalWrite(3, LOW);        // IN1     forward direction
// digitalWrite(1, LOW);        // IN2   reverse direction
// digitalWrite(0, HIGH);       // IN1  reverse direction
//    digitalWrite(2, HIGH);      // forward
//    digitalWrite(3, LOW);       // forward 

//*************************************************************

void loop() 
{
 // dirTest();
  //  runTest5();
 //runTest4();
  //runMotor();
  //dirTest();
inTest();
  
}

void inTest()
{
  do
  {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(18, HIGH);
      digitalWrite(19, HIGH);
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);

      delay(30000);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      digitalWrite(22, LOW);
      digitalWrite(23, LOW);
      delay(30000);

      a = digitalRead(0);
      Serial.print(a);
      Serial.print(" ");
      a = digitalRead(1);
      Serial.print(a);
      Serial.print(" ");

      a = digitalRead(7);
      Serial.print(a);
      Serial.print(" ");
      a = digitalRead(8);
      Serial.print(a);
      Serial.print(" ");

      a = digitalRead(14);
      Serial.print(a);
      Serial.print(" ");
      a = digitalRead(15);
      Serial.print(a);
      Serial.print(" ");

      a = digitalRead(16);
      Serial.print(a);
      Serial.print(" ");
      a = digitalRead(17);
      Serial.print(a);
      Serial.print(" ");
      
   
      count1++;  
      delay(1000);
      Serial.print(" a ");
      Serial.print(a);
      if (0 == count1 % 10)
      {
        Serial.println("  ");
      }
   }
   while(1 == 1);
}

void dirTest()
{
  while(1 == 1)
  {
    {
      count1++;  
      digitalWrite(14, HIGH);    // backward
      digitalWrite(15, LOW);     // backward

      delay(4000);
      digitalWrite(14, LOW);       // forward/increase
      digitalWrite(15, HIGH);        // forward/increase
      delay(4000);

      //Serial.print(" encoderPosA0B1 ");
      //Serial.println(encoderPosA0B1);      
    }
  }
}


void runMotor()
{
  while (1 == 1)
  {
  count1 = 0;
  //encoderPosA0B1 = 0;
  for (instrNum = 0; instrNum < instrTotal; instrNum++)
  {
    // check when encoder count is equal to or crosses over instruction value        
    //while (! flag1)
    do
    {
      //if (1000000 < encoderPosA0B1)
      //{
      //  encoderPosA0B1 = 0;
      //}
      count1++;
      
      /*
      if (0 == (count1 % 1000000))
      {
        Serial.print(encoderPosA0B1new);
        Serial.print("  ");
        Serial.print(encoderPosA0B1);
        Serial.print("  ");
        Serial.print(count1);
        Serial.println(" test");
        //printList();
      }
      */
      if (encoderPosA0B1 < arrXYZ[instrNum][1])   // 
      {         
        digitalWrite(2, LOW);        // IN2  forward 
        digitalWrite(3, HIGH);         // IN1                                    // decrease enc count
        if ((arrXYZ[instrNum][1] - encoderPosA0B1) < 10)
        { 
          flag1F = HIGH;
            count5++;
            if (0 == (count5 % 1000))
            {
              Serial.print(" Forward ");
              Serial.print("  ");
              Serial.print(" count5 ");
              Serial.print("  ");
              Serial.print(count5);
              Serial.print("  ");
              Serial.print(" flag1F ");
              Serial.print(flag1F);
              Serial.print(" encoderPosA0B1 ");
              Serial.print(encoderPosA0B1);
              Serial.print(" instrNum ");
              Serial.print(instrNum);
              Serial.print(" arrXYZ[instrNum][1] ");
              Serial.println(arrXYZ[instrNum][1]);
            }
        
          //if (HIGH == flag1F)
        }
            count3++;
            if (0 == (count3 % 100000))
            {
              /*
              Serial.print(" Forward ");
              Serial.print(" flag1 ");
              Serial.print(flag1);
              Serial.print(" flag1R ");//
              Serial.print(flag1R);
              Serial.print(" flag1F ");
              Serial.print(flag1F);
              Serial.print(" flag1Z ");
              Serial.print(flag1Z);
              Serial.print(" encoderPosA0B1 ");
              Serial.print(encoderPosA0B1);
              Serial.print(" arrXYZ[instrNum][1] ");
              Serial.println(arrXYZ[instrNum][1]);
              */
            }
      }
      if (encoderPosA0B1 > arrXYZ[instrNum][1])   // 
      {
           count4++;
           if (0 == (count4 % 100000))
           {
              Serial.print(" Reverse ");
              Serial.print("  ");
              Serial.print(" count4 ");
              Serial.print("  ");
              Serial.print(count4);
              Serial.print("  ");
              Serial.print(" flag1R ");
              Serial.print(flag1R);
              Serial.print(" encoderPosA0B1 ");
              Serial.print(encoderPosA0B1);
              Serial.print(" instrNum ");
              Serial.print(instrNum);
              Serial.print(" arrXYZ[instrNum][1] ");
              Serial.println(arrXYZ[instrNum][1]);
           }
        digitalWrite(2, HIGH);        // IN2  change to  
        digitalWrite(3, LOW);         // IN1                                     // decrease enc count
        //flag1R = ((encoderPosA0B1 - arrXYZ[instrNum][1]) < 20);                    // indicates equivalence
        if ((encoderPosA0B1 - arrXYZ[instrNum][1]) < 10)
        {
          flag1R = HIGH;
          if (HIGH == flag1R)
          {
            /*
            Serial.print(" Reverse ");
            Serial.print(" flag1 ");
            Serial.print(flag1);
            Serial.print(" flag1R ");
            Serial.print(flag1R);
            Serial.print(" flag1F ");
            Serial.print(flag1F);
            Serial.print(" flag1Z ");
            Serial.println(flag1Z);
            */
          }
        }
      }    
      if (encoderPosA0B1 == arrXYZ[instrNum][1])
      {
        digitalWrite(2, LOW);        // IN2  change to forward direction 
        digitalWrite(3, LOW);         // IN1    
        flag1Z = HIGH;      
              Serial.print(flag1Z);
      }
      flag1 = flag1Z; //|| (flag1F || flag1R);
      if ((encoderPosA0B1new != encoderPosA0B1) && (min((encoderPosA0B1new - encoderPosA0B1), (encoderPosA0B1 - encoderPosA0B1new)) > 100))
      {
        //printList();
        count2++;
        //Serial.print("  ");
        //Serial.print(count2);
        //Serial.print("  ");
        if (0 == count2 % 2)
        {
         /*
          Serial.print(" count2 ");
          Serial.print(count2);
          Serial.print("  ");
          Serial.print(instrNum);
          Serial.print("  ");
          Serial.print(encoderPosA0B1new);          
          Serial.print("  ");
          Serial.print(encoderPosA0B1);          
          Serial.print("  ");
          Serial.print(encoderPosA0B1new - encoderPosA0B1);          
          Serial.print("  ");          
          Serial.print(flag1);          
          Serial.print("  ");          
          Serial.print(flag1R);          
          Serial.print("  ");          
          Serial.print(flag1F);          
          Serial.print("  ");          
          Serial.print(flag1Z);          
          Serial.println("  ");
           */         
        }
        if (0 == count2 % 10000)
        {
          //Serial.print(count2);
          //Serial.println("  ");          
        }
        encoderPosA0B1new = encoderPosA0B1;
      }
      if (encoderPosA7B8 < arrXYZ[instrNum][2])   // 
      {  
        digitalWrite(9, LOW);        // IN2   change to backward direction 
        digitalWrite(10, HIGH);         // IN1    
        flag2F = HIGH;                    // indicates forward condition met
      }
      if (encoderPosA7B8 > arrXYZ[instrNum][2])   // 
      {
        digitalWrite(9, HIGH);        // IN2  change to forward direction 
        digitalWrite(10, LOW);         // IN1    
        flag2R = HIGH;                    // indicates reverse condition met 
      }          
      if (0 == encoderPosA7B8)
      {
        digitalWrite(9, LOW);        // IN2  change to forward direction 
        digitalWrite(10, LOW);         // IN1    
        flag2Z = HIGH;      
        flag2 = flag2Z || (flag2F && flag2R); 
      }
      if (encoderPosA14B15 < arrXYZ[instrNum][3])   // 
      {  
        digitalWrite(18, LOW);        // IN2   change to backward direction 
        digitalWrite(19, HIGH);         // IN1    
        flag3F = HIGH;                    // indicates forward condition met 
      }
      if (encoderPosA14B15 > arrXYZ[instrNum][3])   // 
      {
        digitalWrite(18, HIGH);        // IN2  change to forward direction 
        digitalWrite(19, LOW);         // IN1    
        flag3R = HIGH;                    // indicates reverse condition met
      }          
      if (encoderPosA14B15 == arrXYZ[instrNum][3])
      {
        digitalWrite(18, LOW);        // IN2  change to forward direction 
        digitalWrite(19, LOW);         // IN1    
        flag3Z = HIGH;      
        flag3 = flag3Z || (flag3F && flag3R);
      }
      if (encoderPosA16B17 < arrXYZ[instrNum][4])   // 
      {  
        digitalWrite(22, LOW);        // IN2   change to backward direction 
        digitalWrite(23, HIGH);         // IN1    
        flag4F = HIGH;                    // indicates forward condition met 
      }
      if (encoderPosA16B17 > arrXYZ[instrNum][4])   // 
      {
        digitalWrite(22, HIGH);        // IN2  change to forward direction 
        digitalWrite(23, LOW);         // IN1    
        flag4R = HIGH;                    // indicates reverse condition met
      }       
      if (encoderPosA16B17 == arrXYZ[instrNum][4])
      {
        digitalWrite(22, LOW);        // IN2  change to forward direction 
        digitalWrite(23, LOW);         // IN1    
        flag4Z = HIGH;      
        flag4 = flag4Z || (flag4F && flag4R);
      }
      flag14 = flag1 || flag2 || flag3 || flag4;  
      if (0 == count1 % 1000000)
      {
         
      //   Serial.print(" flag1 ");
      //   Serial.print(flag1);
         //Serial.print(" flag1R ");
         //Serial.print(flag1R);
         //Serial.print(" flag1F ");
         //Serial.print(flag1F);
         //Serial.print(" flag1Z ");
         //Serial.println(flag1Z);
         
      }
      
    }  while (LOW == flag1);
    
    flag1R = LOW;   
    flag1F = LOW;   
    flag1Z = LOW;   
    flag1 = LOW;
    flag2R = LOW;   
    flag2F = LOW;   
    flag2Z = LOW;   
    flag2 = LOW;
    flag3R = LOW;   
    flag3F = LOW;   
    flag3Z = LOW;   
    flag3 = LOW;
    flag4R = LOW;   
    flag4F = LOW;   
    flag4Z = LOW;   
    flag4 = LOW;
  }
  } 
}

void printList()
{
           Serial.print("encoderPosA0B1 ");
           Serial.print(encoderPosA0B1);
           Serial.print("        ");
           Serial.print("instrNum ");
           Serial.print(instrNum);
           Serial.print(" count1 ");
           Serial.print(count1);
           Serial.print("  ");
           Serial.print(" arrXYZ[instrNum][1] ");
           Serial.println(arrXYZ[instrNum][1]);
           Serial.print(" flag1 ");
         Serial.println(flag1);
}



// DOENCODER A0 ********************************************
// DOENCODER B1 ********************************************

void doEncoderA0()
{
  // look for a low-to-high on channel A
  if (digitalRead(0) == HIGH) 
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(1) == LOW) 
    {
      encoderPosA0B1 = encoderPosA0B1 + 1;
    }
    else 
    {
      encoderPosA0B1 = encoderPosA0B1 - 1;
    }
  }
  else       // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(1) == HIGH) 
    {
      encoderPosA0B1 = encoderPosA0B1 + 1;
    }
    else 
    {
      encoderPosA0B1 = encoderPosA0B1 - 1;
    }
  }
  //Serial.println (encoder0Pos, DEC);
  // use for debugging - remember to comment out
}

void doEncoderB1() 
{
  // look for a low-to-high on channel B
  if (digitalRead(1) == HIGH) 
  {
    // check channel A to see which way encoder is turning
    if (digitalRead(0) == HIGH) 
    {
      encoderPosA0B1 = encoderPosA0B1 + 1;
    }
    else 
    {
      encoderPosA0B1 = encoderPosA0B1 - 1;
    }
  }
  // Look for a high-to-low on channel B
  else {
    // check channel A to see which way encoder is turning
    if  (digitalRead(0) == LOW)             
    {
      encoderPosA0B1 = encoderPosA0B1 + 1;
    }
    else 
    {
      encoderPosA0B1 = encoderPosA0B1 - 1;
    }
  }
}

// DOENCODER A7 ********************************************
// DOENCODER B8 ********************************************

void doEncoderA7()
{
  // look for a low-to-high on channel A
  if (digitalRead(7) == HIGH) 
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(8) == LOW) 
    {
      encoderPosA7B8 = encoderPosA7B8 + 1;
    }
    else {
      encoderPosA7B8 = encoderPosA7B8 - 1;
    }
  }
  else       // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(8) == HIGH) {
      encoderPosA7B8 = encoderPosA7B8 + 1;
    }
    else 
    {
      encoderPosA7B8 = encoderPosA7B8 - 1;

    }
  }
}

void doEncoderB8() 
{
  // look for a low-to-high on channel B
  if (digitalRead(8) == HIGH) 
  {
    // check channel A to see which way encoder is turning
    if (digitalRead(7) == HIGH) 
    {
      encoderPosA7B8 = encoderPosA7B8 + 1;
    }
    else 
    {
      encoderPosA7B8 = encoderPosA7B8 - 1;
    }
  }
  // Look for a high-to-low on channel B
  else {
    // check channel A to see which way encoder is turning
    if  (digitalRead(7) == LOW) 
    {
      encoderPosA7B8 = encoderPosA7B8 + 1;
    }
    else 
    {
      encoderPosA7B8 = encoderPosA7B8 - 1;
    }
  }
}

// DOENCODER A14 ********************************************
// DOENCODER B15 ********************************************

void doEncoderA14()
{
  // look for a low-to-high on channel A
  if (digitalRead(14) == HIGH) 
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(15) == LOW) 
    {
      encoderPosA14B15 = encoderPosA14B15 + 1;
    }
    else 
    {
      encoderPosA14B15 = encoderPosA14B15 - 1;
    }
  }
  else       // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(15) == HIGH) 
    {
      encoderPosA14B15 = encoderPosA14B15 + 1;
    }
    else 
    {
      encoderPosA14B15 = encoderPosA14B15 - 1;
    }
  }
}

void doEncoderB15() 
{
  // look for a low-to-high on channel B
  if (digitalRead(15) == HIGH) 
  {
    // check channel A to see which way encoder is turning
    if (digitalRead(14) == HIGH) 
    {
      encoderPosA14B15 = encoderPosA14B15 + 1;
    }
    else 
    {
      encoderPosA14B15 = encoderPosA14B15 - 1;
    }
  }
  // Look for a high-to-low on channel B
  else {
    // check channel A to see which way encoder is turning
    //if (digitalRead(CHApin[axisNum] == LOW)) {
    if  (digitalRead(14) == LOW) 
    {
      encoderPosA14B15 = encoderPosA14B15 + 1;
    }
    else 
    {
      encoderPosA14B15 = encoderPosA14B15 - 1;
    }
  }
}

// DOENCODER A16 ********************************************
// DOENCODER B17 ********************************************

void doEncoderA16()
{
  // look for a low-to-high on channel A
  if (digitalRead(16) == HIGH) 
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(17) == LOW) 
    {
      encoderPosA16B17 = encoderPosA16B17 + 1;
    }
    else {
      encoderPosA16B17 = encoderPosA16B17 - 1;
    }
  }
  else       // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(17) == HIGH) {
      encoderPosA16B17 = encoderPosA16B17 + 1;
    }
    else 
    {
      encoderPosA16B17 = encoderPosA16B17 - 1;

    }
  }
}

void doEncoderB17() 
{
  // look for a low-to-high on channel B
  if (digitalRead(17) == HIGH) 
  {
    // check channel A to see which way encoder is turning
    if (digitalRead(16) == HIGH) 
    {
      encoderPosA16B17 = encoderPosA16B17 + 1;
    }
    else 
    {
      encoderPosA16B17 = encoderPosA16B17 - 1;
    }
  }
  // Look for a high-to-low on channel B
  else 
  {
    // check channel A to see which way encoder is turning
    if  (digitalRead(18) == LOW) 
    {
      encoderPosA16B17 = encoderPosA16B17 + 1;
    }
    else 
    {
      encoderPosA16B17 = encoderPosA16B17 - 1;
    }
  }
}

//************************************************



void loopSub()
{ 
  while(1 == 1)
  {
    if (currentMillis - previousMillis >= interval1) 
    {
      previousMillis = currentMillis;
      if (ledState == LOW) 
      {
        ledState = HIGH;
      } 
      else 
      {
        ledState = LOW;
      }
      digitalWrite(ledPin, ledState);    
    }
  }
}


/*
const int ledPin =  LED_BUILTIN;// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)
void setup() 
{
  pinMode(ledPin, OUTPUT);
}
void loop() 
{
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    if (ledState == LOW) 
    {
      ledState = HIGH;
    } else 
      {
        ledState = LOW;
      }
      digitalWrite(ledPin, ledState);
    }
  }
}
*/
