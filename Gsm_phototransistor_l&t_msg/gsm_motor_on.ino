#include <SoftwareSerial.h>
SoftwareSerial Serial1(9, 10);
String msg;
String Target="+919880302630";
int x,i=0;

void setup() {
Serial.begin(9600);
Serial1.begin(9600);
}


void SendMessage()
{
  Serial1.println("AT+CMGF=1");    //AT to set the GSM Module in Text Mode
  delay(1000); 
  Serial1.println("AT+CMGS=\""+Target+"\"\r"); 
  delay(1000);
  Serial1.println("Hello, This is GSM Module, Motor is ON in Bettadapura, do not reply");
  delay(100);
   Serial1.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
   Serial.println("Sending message1");
}

void SendMessage2()
{
  Serial1.println("AT+CMGF=1");    //AT to set the GSM Module in Text Mode
  delay(1000); 
  Serial1.println("AT+CMGS=\""+Target+"\"\r"); 
  delay(1000);
  Serial1.println("Hello, This is GSM Module, Motor is OFF in Bettadapura, do not reply");
  delay(100);
   Serial1.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
   Serial.println("Sending message2");
}



void loop() {
  // put your main code here, to run repeatedly:

x= analogRead(A0);
Serial.println(x);
delay(700);

  if(analogRead(A0)>20)
  {
    if(i==0)
    {
      SendMessage();
      i=1;
    }
  }

  else if(analogRead(A0)<2)
  {
    if(i==1)
    {
      SendMessage2();
      i=0;
    }
}
}
