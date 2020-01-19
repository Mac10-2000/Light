#define button 2
#define red 3
#define yellow 4
#define green 5


uint32_t shutoffTimer = millis();
uint32_t lightTimer = 0;
uint32_t flashTimer = 0;
uint32_t interruptTimer = 0;

uint32_t shutoffTime = 15  * 1000;
uint32_t lightPhase = 1000;
uint32_t flashPhase = 500;

bool idleMode = true;
bool stopLight = false;
bool shutoffBool = false;
bool interruptRunning = false;
int lightMode = 0;


void setup() {


  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

  delay(500);



  idleMode = true;
  stopLight = false;
  shutoffBool = false;

  delay(500);

}

void loop() {
  if (!digitalRead(button)) {//reads the buutton and input length
    if (!shutoffBool) {
      interruptTimer = millis();
    }

    while (!digitalRead(button)) {
      delay(100);
    }
    if (!shutoffBool && interruptTimer != 0) {// processing the input
      if (millis() - interruptTimer > 2000) {
        idleMode = true;
        lightMode = 0;
        stopLight = false;
      } else {
        idleMode = false;
        stopLight =  !stopLight;
        
      }
    } else {
      stopLight = false;
      idleMode = true;
    }
    interruptTimer = 0;
    shutoffBool = false;
    shutoffTimer = millis();
    lightTimer = millis();
    flashTimer = millis();
  }
  if (idleMode) {                               //activates the stanbymode yellowFlash() or goes through the light cicles
    if (millis() - flashTimer > flashPhase) {
      yellowFlash();
    }
  } else {
    if (millis() - lightTimer > lightPhase) {
      light();
    }

  }
  if (millis() - shutoffTimer > shutoffTime) {    // changes from standby to off after a certain timeframe
    shutoffBool = true;
  }

  if (shutoffBool) {
    shutoff();
  }
}

inline void invert(byte pin)// inverts the pinstate of the pin used
{
  digitalWrite(pin, !digitalRead(pin));
}
void light() {  // executes the light phases

  if (stopLight) {

    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    switch (lightMode) {

      case 0 :
        digitalWrite(red, HIGH);
        lightMode++;
        break;
      case 1 :
        digitalWrite(red, HIGH);
        digitalWrite(yellow, HIGH);
        lightMode++;
        break;
      case 2 :
      case 3:
        digitalWrite(green, HIGH);
        lightMode++;
        break;
      case 4 :
        digitalWrite(yellow, HIGH);
        lightMode++;
        break;
      case 5 :
        digitalWrite(red, HIGH);
        lightMode++;
        break;
      default :
        digitalWrite(red, HIGH);
        lightMode = 0;
 
        break;
    }
    shutoffTimer = millis();
    lightTimer = millis();
  }
}

void yellowFlash() {   // lets the yellow light flash in a 0.5 second interval (on-off 1 second)
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  invert(yellow);
  flashTimer = millis();
}

void shutoff() {  // stopps the execution of the looptill the button is pressed
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  while (shutoffBool && digitalRead(button)) {
    delay(100);
  }
  while(!digitalRead(button)) {
    delay(100);
  }
  shutoffBool = false;
  shutoffTimer = millis();
}
