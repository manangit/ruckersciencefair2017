/*
  My Science Fair Project
  The one switch Smart House
*/
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo doorOpener;
LiquidCrystal_I2C lcd(0x3F, 2,1,0,4,5,6,7,3,POSITIVE);
int porchLight = 2;
int coachLights = 4;
int backyardLight = 8;
int lightSwitch = 12;
int servoMotor = 6;
int doorOpenerSwitch = 9;
bool switchState = LOW;
bool lastSwitchState = LOW;
bool isPorchLightOn = false;
bool isCoachLightOn = false;
bool isBackyardLightOn = false;
bool isDoorOpen = false;

int timer = 0;

void setup()
{
  pinMode(porchLight, OUTPUT);
  pinMode(coachLights, OUTPUT);
  pinMode(backyardLight, OUTPUT);
  pinMode(lightSwitch, INPUT);
  
  doorOpener.attach(servoMotor);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("start");
  Serial.begin(9600);
}


boolean debounce(boolean last)
{
  boolean current = digitalRead(doorOpenerSwitch);
  if (last != current)
  {
    delay(50);
    current = digitalRead(doorOpenerSwitch);
  }
  return current;
}


void loop()
{
//  doorOpener.write (0);
//  switchState = ;
  while (debounce(lastSwitchState) == HIGH)
  {
    if(isDoorOpen){
      doorOpener.write(0);
      isDoorOpen = false;
    }
    else{
      doorOpener.write(150);
      isDoorOpen = true;
    }
    Serial.println(isDoorOpen);
  }
  lastSwitchState = !lastSwitchState;
  
  while (digitalRead(lightSwitch) == HIGH)
  {
    delay (100);
    timer = timer + 100;
    lcd.print(timer/100);
    lcd.clear();
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
//  lcd.clear();
  
}
