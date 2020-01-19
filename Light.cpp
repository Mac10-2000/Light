#include <Light.h>


Light::Light(int pin1, int pin2) 
{
	_pin1=pin1;
	pinMode(_pin1,OUTPUT);
	digitalWrite(_pin1, LOW);
	_pin2=pin2;
	pinMode(_pin2,OUTPUT);
	digitalWrite(_pin2, LOW);
}
Light::Light() 
{
	_pin1=-1;
	_pin2=-1;
}
 void Light::invert(void)// inverts the pinstate of the pin used
{
	if(_pin1>=0){
		digitalWrite(_pin1, !digitalRead(_pin1));
		if(_pin2>=0){
			digitalWrite(_pin2, !digitalRead(_pin1)); //invert after _pin1 in order to not allow possible desyncronisation
		}
	}
}

void Light::low(void)
{
	if(_pin1>=0){
		digitalWrite(_pin1, LOW);
		if(_pin2>=0){
			digitalWrite(_pin2, LOW);
		}
	}
}
void Light::high(void)
{
	if(_pin1>=0){
		digitalWrite(_pin1, HIGH);
		if(_pin2>=0){
			digitalWrite(_pin2, HIGH);
		}
	}
}
bool Light::empty(void){
	return _pin1<0;
}






