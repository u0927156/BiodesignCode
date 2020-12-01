
int inputPin = 7; // Input will be connected to pin 7 
int outPin = 2; // The voltage output will be to pin 13
int ledPin = 12; // Indicator LED will be connected to pin 12
int voltIn = 0; // variable for reading voltage
int StimulationTime = 2.75; // seconds of stimulation time
unsigned long timeOn; // variable for time stimulation has been on
unsigned long StimulationTimeInMillis; // Variable for how long to stimulate
unsigned long shutOffTime; // variable for time to shut off

// Variables to prevent random fluctuations from turning device on.
int TimesNecessaryToStimulate = 10;
int ReceivedOnSignals = 0;

int wasOn = 0;
int isOn = 0;
unsigned long currTime; // variable for reading time

void setup() {
  // set up pins
  pinMode(inputPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // serial for debugging
  Serial.begin(9600);
  // figure out the stimulation time in milliseconds. 
  StimulationTimeInMillis = StimulationTime * 1000; 
}

void loop() {
  // Read the inputs
  
  voltIn = digitalRead(inputPin);


  if(voltIn == LOW)
  {
    ReceivedOnSignals = 0;
  }

  // if the input is on, and the output isn't on already
  if(voltIn == 1 && isOn == 0) 
  {
    ReceivedOnSignals = ReceivedOnSignals + 1;

    //Serial.println(ReceivedOnSignals);
    if(ReceivedOnSignals >= TimesNecessaryToStimulate)
    {
      isOn = 1;
      timeOn = millis();
      digitalWrite(outPin, HIGH);
      digitalWrite(ledPin, HIGH);
  
      // get the current time and calculate when to shut off.    
      shutOffTime = timeOn + StimulationTimeInMillis;
      Serial.println(timeOn);
     // Serial.println(shutOffTime);
    }
    
  }
 

  // Turn of the input when the time has elapsed
  currTime = millis();
  if(isOn == 1 && currTime >= shutOffTime)
  {
    ReceivedOnSignals = 0;
    //Serial.println(currTime);
    digitalWrite(outPin, LOW);
    digitalWrite(ledPin, LOW); 
    isOn = 0; 
  }
}
