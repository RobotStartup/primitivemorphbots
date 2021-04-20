int ledPin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("serial on/off test 0021"); // so I can keep track
}
   
void loop()
{
  char c = 0;
  if (Serial.available() > 0)
  {
    //Serial.clear();
    c = Serial.read();
    Serial.print(c);
    /*if (c == '1')     // assuming you send character '1', not a byte with value 1
    {
       Serial.print("Hello you pressed 1 key/n");
    }
    if (c == '0')
    {
       Serial.print("Hello you pressed 0 key");
    }*/
  }
}
