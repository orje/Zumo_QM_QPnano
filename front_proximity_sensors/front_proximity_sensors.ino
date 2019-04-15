// Zeigt die Messwerte der front proximity sensors on the Zumo 32U4

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ProximitySensors proxSensors;

void setup()
{
  proxSensors.initFrontSensor();

  lcd.clear();
  lcd.clear();
}

void loop()
{
  // Read the front proximity sensor and gets its left value (the
  // amount of reflectance detected while using the left LEDs)
  // and right value.
  proxSensors.read();
  uint8_t leftValue = proxSensors.countsFrontWithLeftLeds();
  uint8_t rightValue = proxSensors.countsFrontWithRightLeds();

  lcd.gotoXY(0, 0);
  lcd.print(leftValue);
  lcd.print(' ');
  lcd.print(rightValue);
}
