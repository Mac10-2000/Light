#include <Light.h>

Light::Light(int pin) 
{
	_pin=pin;
	pinMode(_pin,OUTPUT);
	digitalWrite(_pin, LOW);
}
Light::Light() 
{
	_pin=-1;
}
 void Light::invert(void)// inverts the pinstate of the pin used
{
	if(_pin>=0)
	digitalWrite(_pin, !digitalRead(_pin));
}

void Light::low(void)
{
	if(_pin>=0)
  digitalWrite(_pin, LOW);
}
void Light::high(void)
{
	if(_pin>=0)
  digitalWrite(_pin, HIGH);
}
bool Light::empty(void){
	return _pin<0;
}






