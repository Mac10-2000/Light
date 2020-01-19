//test sketch for hardware functionality


#define red 3
#define yellow 4
#define green 5
#define button 2

void setup() {
  
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
pinMode(button,INPUT_PULLUP);

digitalWrite(red,HIGH);
digitalWrite(yellow,HIGH);
digitalWrite(green,HIGH);
}

void loop() {

  //inverts the pinstate eachtime the button is pressed

  if(!digitalRead(button)){
    invert(red);
  invert(yellow);
  invert(green);
  delay(1000);
  }
  

}

inline void invert(byte pin)// inverts the pinstate of the pin used
{
  digitalWrite(pin, !digitalRead(pin));
}
