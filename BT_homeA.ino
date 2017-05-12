
int val;

void setup()
{
  Serial.begin(38400);//Change the baud rate value depending on the default baud rate of your bluetooth module

  pinMode(2, OUTPUT);//Light1 pin
  pinMode(3, OUTPUT);//Light2 pin
  pinMode(4, OUTPUT);//Light3 pin
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
}

void loop()
{
  if (Serial.available())
  {

    val = Serial.read();
    Serial.println((val));//Display received value on Serial Monitor
    
    if (val == 49) //Turn Light1 ON
      digitalWrite(2, HIGH);

    else if (val==50)//Turn Light1 OFF
            digitalWrite(2,LOW);

     if(val==51)//Turn Light2 ON
      digitalWrite(3,HIGH);

      else if(val==52)//Turn Light2 OFF
         digitalWrite(3,LOW);

      if(val==53)//Turn Light3 ON
      digitalWrite(4,HIGH);

      else if(val==54)//Turn Light3 OFF
          digitalWrite(4,LOW);


  }
}

