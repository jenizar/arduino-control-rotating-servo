#include <Servo.h>
Servo myservo1, myservo2;
unsigned long exe1, exe2, interval;
int SV1 = 0;
int SV2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  myservo1.attach(8);
  myservo2.attach(9);
  myservo1.write(0);
  myservo2.write(0);
  exe1 = 0;
  exe2 = 0;
  interval = 2000;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current = millis();
  if(digitalRead(2) == 0) 
  {
   SV1 = 1;
   exe1 = current;
   myservo1.write(90); 
  }
  if ((current - exe1) >= interval & SV1 == 1) 
  {
    myservo1.write(0);
    SV1 = 0;
  }

  if(digitalRead(3) == 0) 
  {
   SV2 = 1;
   exe2 = current;
   myservo2.write(90); 
  }
  if ((current - exe2) >= interval & SV2 == 1) 
  {
    myservo2.write(0);
    SV2 = 0;
  }

}
