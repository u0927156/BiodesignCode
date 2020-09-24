
int inputPin = 7; // Input will be connected to pin 7 
int outPin = 13; // The voltage output will be to pin 13
int ledPin = 12; // Indicator LED will be connected to pin 12
int voltIn = 0;
int StimulationTime = 10; // seconds of stimulation time
unsigned long timeOn; 
unsigned long StimulationTimeInMillis;
unsigned long shutOffTime;

int wasOn = 0;
int isOn = 0;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  // figure out the stimulation time in milliseconds. 
  StimulationTimeInMillis = StimulationTime * 1000; 
}

void loop() {
  // Read the inputs
  voltIn = digitalRead(inputPin);
  //Serial.print(voltIn);
  //Serial.print(" ");
  //Serial.println(isOn);
  // If the input is on, and the output isn't on already
  if(voltIn == 1 && isOn == 0) 
  {
    isOn = 1;
    timeOn = millis();
    digitalWrite(outPin, HIGH);
    digitalWrite(ledPin, HIGH);

    // get the current time and calculate when to shut off.    
    shutOffTime = timeOn + StimulationTimeInMillis;
    Serial.println(timeOn);
    Serial.println(shutOffTime);
    
  }

  // Turn of the input when the time has elapsed
  unsigned long currTime = millis();
  if(isOn == 1 && currTime >= shutOffTime)
  {
    Serial.println(currTime);
    digitalWrite(outPin, LOW);
    digitalWrite(ledPin, LOW); 
    isOn = 0; 
  }
}
