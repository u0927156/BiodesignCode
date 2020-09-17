
int inputPin = 7; // Input will be connected to pin 7 
int outPin = 13; // The voltage output will be to pin 13
int ledPin = 14; // Indicator LED will be connected to pin 14
int voltIn = 0;
int StimulationTime = 3; // seconds of stimulation time
unsigned long timeOn; 
unsigned long StimulationTimeInMillis;
unsigned long shutOffTime;

int wasOn = 0;
int isOn = 0;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(ledPin, INPUT);
  // figure out the stimulation time in milliseconds. 
  StimulationTimeInMillis = StimulationTime * 1000; 
}

void loop() {
  // Read the inputs
  voltIn = analogRead(inputPin);

  // If the input is on, and the output isn't on already
  if(voltIn == HIGH && isOn != 0) 
  {
    isOn = 1;
    digitalWrite(outPin, HIGH);
    digitalWrite(ledPIN, HIGH);

    // get the current time and calculate when to shut off.
    timeOn = millis();
    shutOffTime = timeOn + StimulationTimeInMillis;
  }

  // Turn of the input when the time has elapsed
  if(millis() >= shutOffTime)
  {
    digitalWrite(outPin, LOW);
    digitalWrite(ledPIN, LOW); 
    isOn = 0; 
  }
}
