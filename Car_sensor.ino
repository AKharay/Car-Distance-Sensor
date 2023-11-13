// Abhay Kharay
//Car Sensor Project Code


const int trigPin = 7;          //Inputs for different pins
const int echoPin = 6;
const int greenPin = 8;
const int yellowPin = 9;
const int redPin = 10;
const int buzzerPin = 13;

void setup() {
  pinMode(trigPin, OUTPUT);           
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);                //Range 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 25) {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    digitalWrite(buzzerPin, HIGH);  // Activate the buzzer
  } else if (distance <= 50) {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(buzzerPin, LOW);  // Deactivate the buzzer
  } else {
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(buzzerPin, LOW);  // Deactivate the buzzer
  }
  
  delay(100);  // Delay
}
