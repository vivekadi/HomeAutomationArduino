#include <SoftwareSerial.h>
SoftwareSerial net(9, 10);
String msg;
char call;
char inchar;
String Target="+919483658134";
int led1=5;

void setup()
{
  net.begin(9600);   
  Serial.begin(9600);    
  
  Serial.println("Awake");
  Serial.println("Control Char");
  Serial.println("h : hang call");
  Serial.println("i : receive call");
  Serial.println("c : call");  
  Serial.println("e : redial");
  Serial.println("s : send message");
  Serial.println("r : receive message");
  Serial.println();
  
  pinMode(5,OUTPUT);
  delay(100);
}

void loop()
{  
  if (Serial.available())
 {  switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      ReceiveMessage();
      break;
    case 'c':
      Call();
      break;
    case 'h':
      HangCall();
      break;
    case 'e':
      RedialCall();
      break;
    case 'i':
      ReceiveCall();
      break;
  } 
 }
 // if (net.available()>0)
  // Serial.write(net.read()); 
 
}

void SendMessage()
{
  net.println("AT+CMGF=1");    //AT to set the GSM Module in Text Mode
  delay(1000); 
  net.println("AT+CMGS=\""+Target+"\"\r"); 
  delay(1000);
  net.println("Hello, This is GSM Module, This is a test message, do not reply");
  delay(100);
   net.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
   Serial.println("Sending message");
}

void ReceiveMessage()
{
  Serial.println("AT+CMGF=1");    //AT to set the GSM Module in Text Mode
  delay(200);
    Serial.println("AT+CSMS=1\r"); 
 delay(200);
  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(200);

  inchar=Serial.read(); 
 if (inchar=='#')
   {
   delay(10);
   inchar=Serial.read(); 

 //first led
   if (inchar=='a')
     {
   delay(10);
   inchar=Serial.read();

 if (inchar=='0')
   {
   digitalWrite(5, LOW);
   } 
 else if (inchar=='1')
   {
   digitalWrite(5, HIGH);
   }
 delay(10);
     }
   }
   Serial.println("AT+CMGD=1,4"); // delete all SMS
}

void Call()
{
  net.println("ATD"+Target+";"); //watch out here for semicolon at the end
  Serial.println("Calling"); 
  delay(1000);
}


void HangCall()
{
 net.println("ATH");
   Serial.println("Hangup Call");
  delay(1000);
   //if (net.available()>0)
 //Serial.write(net.read());
}

void ReceiveCall()
{
   net.println("ATA");
  delay(1000);
  {
    call=net.read();
    net.print(call);
  }
}

void RedialCall()
{
  net.println("ATDL");
   Serial.println("Redialing");
  delay(1000);
}


