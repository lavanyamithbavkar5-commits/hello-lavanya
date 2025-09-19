const int sensorPin = A0; // Analog pin for the MQ-3 sensor
const int eyeSensorPin = 2; // Digital pin for the eye blink sensor
const int relayPin = 9;   // Digital pin for the relay
const int buzzerPin = 8;  // Digital pin for the buzzer
const int ledPin = 7;     // Digital pin for the LED
const int threshold = 500; // Alcohol threshold value 
const int closedEyeDuration = 3000; // Duration for closed eyes in milliseconds (3 seconds)
unsigned long lastClosedTime = 0;
bool eyeClosed = false;
bool alcoholDetected = false;
bool drowsinessDetected = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(eyeSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the analog value from MQ-3 sensor
  Serial.print("Alcohol Level: ");
  Serial.println(sensorValue);

  int eyeState = digitalRead(eyeSensorPin); // Read eye sensor state
  Serial.print("Eye Sensor State: ");
  Serial.println(eyeState);
  
  // Check alcohol level
  alcoholDetected = (sensorValue > threshold);
  if (alcoholDetected) {
    digitalWrite(relayPin, LOW); // Lock the engine
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Alcohol detected! Engaging safety measures.");
  } else {
    digitalWrite(relayPin, HIGH); // Unlock the engine
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
  
  // Check for closed eyes
  if (eyeState == HIGH && !eyeClosed) { // Eyes are closed
    eyeClosed = true;
    lastClosedTime = millis(); // Record the time when eyes were detected as closed
  } 
  if (eyeState == LOW && eyeClosed) { // Eyes are opened again
    eyeClosed = false;
    Serial.println("Eyes opened.");
  }

  // Check if eyes have been closed for more than 3 seconds
  drowsinessDetected = (eyeClosed && (millis() - lastClosedTime > closedEyeDuration));
  if (drowsinessDetected) {
    digitalWrite(relayPin, LOW); // Lock the engine
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Eyes closed for more than 3 seconds! Engaging safety measures.");
  }

  // Check if both alcohol and drowsiness are detected
  if (alcoholDetected && drowsinessDetected) {
    Serial.println("Both alcohol and drowsiness detected! Engaging all safety measures.");
  }

  delay(50); // Adjust debounce delay for faster response
}
