#define greenLed  10
#define yellowLed  6

void setup()
{
  pinMode(greenLed, INPUT);
  pinMode(yellowLed, INPUT);
  Serial.begin(9600);
}

float energyCal()
{
  
}

void loop()
{
  unsigned long currenttime1, currenttime2,delaytime;
  float Energy;
  if ((digitalRead(greenLed)==HIGH)&&(digitalRead(yellowLed)==LOW))
  {
    Serial.println('G');
    currenttime1 = millis();
    while (1)
    {
      if (digitalRead(greenLed) == LOW)
      {
        currenttime2 = millis();
        delaytime = currenttime2 - currenttime1;
        Energy = 24*delaytime/1000;          //the unit of Energy is mw.
        Serial.print("Energy: ");
        Serial.println(Energy);
        break;
      }
    }
  }
  else if ((digitalRead(greenLed)==LOW)&&(digitalRead(yellowLed)==HIGH))
  {
    Serial.println('Y');
    currenttime1 = millis();
    while (1)
    {
      if (digitalRead(yellowLed) == LOW)
      {
        currenttime2 = millis();
        delaytime = currenttime2 - currenttime1;
        Energy = 24*delaytime/1000;          //the unit of Energy is mw.
        Serial.print("Energy: ");
        Serial.println(Energy);
        break;
      }
    }
  }
  else if ((digitalRead(greenLed)==HIGH)&&(digitalRead(yellowLed)==HIGH))
  {
    Serial.println("YG");
    currenttime1 = millis();
    while (1)
    {
      if ((digitalRead(greenLed)==LOW)&&(digitalRead(yellowLed)==LOW))
      {
        currenttime2 = millis();
        delaytime = currenttime2 - currenttime1;
        Energy = 2*24*delaytime/1000;          //the unit of Energy is mw.
        Serial.print("Energy: ");
        Serial.println(Energy);
        break;
      }
    }
  }
}
