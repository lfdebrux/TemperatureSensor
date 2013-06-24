/*
	Demonstrates use of temperature library.
	Here we print the temperature over serial
	with the Sprite developer kit
*/

#include <temp.h>

void setup()
{
	Serial.begin(9600);

	readTemp(); // first reading is usually spurious
}

void loop()
{
	temp = readTempX10();
	Serial.print(temp / 10);
	Serial.print('.');
	Serial.print(temp % 10);
	Serial.println("degrees Celsius");

	delay(1000);
}
