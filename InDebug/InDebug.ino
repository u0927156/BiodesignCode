
int inputPin = 7; // Input will be connected to pin 7 
int outPin = 13; // The voltage output will be to pin 13
int ledPin = 12; // Indicator LED will be connected to pin 12
int voltIn = 0;
int StimulationTime = 3; // seconds of stimulation time
unsigned long timeOn; 
unsigned long shutOffTime;

int wasOn = 0;
int isOn = 0;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  // figure out the stimulation time in milliseconds. 
}

void loop() {
  // Read the inputs
  voltIn = digitalRead(inputPin);
  Serial.println(voltIn);

  if(voltIn == 1)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
