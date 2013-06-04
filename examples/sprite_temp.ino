/*
	Demonstrates use of temperature library.
	Here we print the temperature over serial
	with the Sprite developer kit
*/

#include <Temperature.h>

Temperature temp;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.print("Temperature is approximately");
	Serial.print(temp.read());
	Serial.println("degrees Celsius");

	delay(1000);
}