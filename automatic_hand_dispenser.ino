int redLed = D8;
int greenLed = D3;
int pirSensor = D6;
int trigPin = D1;
int echoPin =D2;
int pump=D5;
int whiteLeds = D7;
long duration;
float distance;

//battery green wire positive
void setup() {
  Serial.begin(115200);
 Serial.println(5);
 pinMode(redLed, OUTPUT);
 pinMode(greenLed, OUTPUT);
  pinMode(whiteLeds, OUTPUT);
  pinMode(pump, OUTPUT);

  pinMode(pirSensor, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int val = digitalRead(pirSensor);

   static unsigned long motionDetectedAt = 0;
   Serial.println(val);
   if (val == 1) {
    digitalWrite(whiteLeds, HIGH);
     motionDetectedAt = millis();
   }

    if (millis() - motionDetectedAt > 5000) {
      digitalWrite(whiteLeds, LOW);
    }

  // Ultrasonic measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.0343 * duration / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance >= 0 && distance <= 20) {
    digitalWrite(pump, HIGH);
   digitalWrite(greenLed, LOW);
   digitalWrite(redLed, HIGH);
  } else {
    digitalWrite(pump, LOW);
   digitalWrite(redLed, LOW);
   digitalWrite(greenLed, HIGH);
  };
  delay(300);
}
