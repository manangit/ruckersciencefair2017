/*
  My Science Fair Project
  The one switch Smart House
*/

int porchLight = 2;
int coachLights = 4;
int backyardLight = 8;
int switchPin = 12;
boolean switchState = LOW;
boolean lastSwitchState = LOW;
boolean isPorchLightOn = false;
boolean isCoachLightOn = false;
boolean isBackyardLightOn = false;

int timer = 0;

void setup()
{
  pinMode(porchLight, OUTPUT);
  pinMode(coachLights, OUTPUT);
  pinMode(backyardLight, OUTPUT);
  pinMode(switchPin, INPUT);

}

void loop()
{
  while (digitalRead(switchPin) == HIGH)
  {
    delay (100);
    timer = timer + 100;
  }

  if (timer > 100 && timer <= 1000)
  {
    isPorchLightOn = !isPorchLightOn;
    digitalWrite(porchLight, isPorchLightOn);
    timer = 0;
  }

  if ( timer > 1000 && timer <= 3000)
  {
    isCoachLightOn = !isCoachLightOn;
    digitalWrite(coachLights, isCoachLightOn);
    timer = 0;
  }

  if (timer > 3000)
  {
    isBackyardLightOn = !isBackyardLightOn;
    digitalWrite(backyardLight, isBackyardLightOn);
    timer = 0;
  }
}
