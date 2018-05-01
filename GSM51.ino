char inchar; //Will hold the incoming character from the Serial Port.


 int led1 = 5;
 int led2 = 10;
 int led3 = 11;
 int led4 = 12;

 void setup()
 {
 // prepare the digital output pins
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 //Initialize GSM module serial port for communication.


 Serial.begin(9600);
 delay(3000); // give time for GSM module to register on network etc.
 Serial.println("AT+CMGF=1"); // set SMS mode to text
 delay(200);
  Serial.println("AT+CSMS=1\r"); 
 delay(200);
 Serial.println("AT+CNMI=2,2,0,0,0"); // set module to send SMS data to serial out upon receipt 
 delay(200);
 }

 void loop() 
 {
 //If #a1b1c1d1 comes as sms, all led's should light up.
 if(Serial.available())
 {
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
   digitalWrite(led1, LOW);
   } 
 else if (inchar=='1')
   {
   digitalWrite(led1, HIGH);
   }
 delay(10);


 //Second led
 inchar=Serial.read(); 

 if (inchar=='b')
   {
   inchar=Serial.read();
 if (inchar=='0')
 {
 digitalWrite(led2, LOW);
 } 

 else if (inchar=='1')
 {
 digitalWrite(led2, HIGH);
 }
 delay(10);

 // Third led
 inchar=Serial.read(); 
 if (inchar=='c')
 {
 inchar=Serial.read();
 if (inchar=='0')
 {
 digitalWrite(led3, LOW);
 } 
 else if (inchar=='1')
 {
 digitalWrite(led3, HIGH);
 }
 delay(10);

 //Fourth led

 inchar=Serial.read(); 
 if (inchar=='d')
 {
 delay(10);
 inchar=Serial.read();
 if (inchar=='0')
 {
 digitalWrite(led4, LOW);
 } 
 else if (inchar=='1')
 {
 digitalWrite(led4, HIGH);
 }
 delay(10);
 }
 }
 Serial.println("AT+CMGD=1,4"); // delete all SMS
 }
 }
 }
 }
 }
