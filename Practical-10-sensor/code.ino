int sensorPin = A0;
int relayPin = 7;
int moistureValue = 0;

int threshold = 500;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
}

void loop() {
  moistureValue = analogRead(sensorPin);

  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue > threshold) {
    digitalWrite(relayPin, LOW);
    Serial.println("Soil is Dry - Pump ON");
  }
  else {
    digitalWrite(relayPin, HIGH);
    Serial.println("Soil is Wet - Pump OFF");
  }

  delay(1000);
}
