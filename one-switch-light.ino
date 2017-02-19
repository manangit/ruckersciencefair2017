/*
  My Science Fair Project
  The one switch light project
*/


int porchLight = 2;
int coachLights = 4;
int backyardLight = 8;
int switchPin = 12;
boolean switchState = LOW;

void setup()
{
  pinMode(porchLight, OUTPUT);
  pinMode(coachLights, OUTPUT);
  pinMode(backyardLight, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop()
{
  switchState = digitalRead(switchPin);

  if (switchState == HIGH)
  {
    digitalWrite(porchLight, HIGH);
  }
  else
  {
    digitalWrite(porchLight, LOW);
  }
}
