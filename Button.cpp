#include <Button.h>


 Button::Button(int pin, bool pullUp) {
	_pin=pin;
	_pullUp = pullUp;
	pinMode(_pin,_pullUp ? INPUT_PULLUP : INPUT);
}
 Button::Button(int pin) {
	_pin=pin;
	_pullUp = true;
	pinMode(_pin,INPUT_PULLUP);
}
Button::Button() {
	_pin=0;
	_pullUp = true;
}
 bool Button::read(void)// inverts the pinstate of the pin used
{
	bool mode = digitalRead(_pin);
	//Serial.println("aa");
	//Serial.println(_pullUp ? !mode :mode);
  return _pullUp ? !mode :mode;
}