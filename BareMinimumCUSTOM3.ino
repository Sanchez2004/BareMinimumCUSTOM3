
/*
*
* deprecated! Use BareMinimumCUSTOM4.
*
*/
//Vars for timing leds, regurdless of the number of leds.
unsigned long signalShort = 200;
unsigned long signalLong = 500;
unsigned long shortDelay = 200;
unsigned long longDelay = 1000;
unsigned long currentRunningTime;

//class TODO document
class powerLED{

  public: 
    powerLED( int physicalPin, unsigned long timeKeeper );
    int physicalPin;
    bool isPowered;
    unsigned long powerOffTime;
    unsigned long powerOnTime;
    unsigned long timeKeeper;
    void blinkLED( unsigned long powerOffTime, unsigned long powerOnTime );
};

powerLED::powerLED( int physicalPin, unsigned long timeKeeper ){
      this->physicalPin = physicalPin;
      //this->powerOffTime = powerOffTime;
      //this->powerOnTime = powerOnTime;
      isPowered = false;
      this->timeKeeper = timeKeeper;
}

void powerLED::blinkLED(unsigned long powerOffTime, unsigned long powerOnTime){

  if( isPowered == true && timeKeeper <= currentRunningTime ){
    digitalWrite(physicalPin, LOW);
    isPowered = false;
    timeKeeper = currentRunningTime + powerOffTime;
  };
  
  if( isPowered == false && timeKeeper <= currentRunningTime ){
    digitalWrite(physicalPin, HIGH);
    isPowered = true;
    timeKeeper = currentRunningTime + powerOnTime;
  };
}

//Vars for each LED conneted.
unsigned long timeMark1;
unsigned long timeMark2;
int pinToPower1 = 8;
int pinToPower2 = 12;
powerLED ledOne = powerLED(pinToPower1, timeMark1);
powerLED ledTwo = powerLED(timeMark2, timeMark2);

//TODO document
void setup() {
  
  timeMark1 = millis();
  timeMark2 = millis();
  pinMode(pinToPower1, OUTPUT);
  pinMode(timeMark2, OUTPUT);
}

void loop() {
  
  currentRunningTime = millis();
  ledOne.blinkLED(signalShort, signalShort);
  ledTwo.blinkLED(signalLong, signalLong);
}
