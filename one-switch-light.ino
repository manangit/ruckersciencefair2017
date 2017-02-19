/*
  My Science Fair Project
  The one switch light project
*/

int porchLight = 2;
int coachLights = 4;
int backyardLight = 8;
int switchPin = 12;
boolean switchState = LOW;
boolean lastSwitchState = LOW;
boolean isPorchLightOn = false;

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if (last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void setup()
{
  pinMode(porchLight, OUTPUT);
  pinMode(coachLights, OUTPUT);
  pinMode(backyardLight, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop()
{
  switchState = debounce(lastSwitchState);
  if (switchState == HIGH)
  {
    isPorchLightOn = !isPorchLightOn;
    digitalWrite(porchLight, isPorchLightOn);
  }
  lastSwitchState = !lastSwitchState;
}
