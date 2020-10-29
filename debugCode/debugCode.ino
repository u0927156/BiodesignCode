

int ledPin = 13; // Indicator LED will be connected to pin 12
int ledPinOther = 12;
void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledPinOther,HIGH);
  delay(500);
  digitalWrite(ledPin,LOW);
   digitalWrite(ledPinOther,LOW);
  delay(500);
}
