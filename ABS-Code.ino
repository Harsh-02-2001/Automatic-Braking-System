#include <Servo.h>
Servo myservo;  // Declare the servo object

// Motor Driver Pins
const int IN1 = 10;
const int IN2 = 9;
const int IN3 = 8;
const int IN4 = 7;
// Ultrasonic Sensor Pins
const int trigPin = A4;
const int echoPin = A5;
// Servo Motor Pin
const int ServoPin = 3;
// Create Servo object to control the servo motor Servo myservo;
void setup()
{
// Initialize the Motor Driver Pins
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, INPUT);
pinMode(IN4, INPUT);
// Initialize the Ultrasonic Sensor Pins
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
// Attach the Servo Motor to the ServoPin
myservo.attach(ServoPin);
}
void loop() {
// Read the distance from the Ultrasonic Sensor
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.020 / 2;
// Control the Servo Motor based on the distance
if (distance > 30)
{
myservo.write(90);
delay(500);
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
delay(1000);
} else if (distance > 50) {
myservo.write(45);
delay(500);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
delay(500);
} else {
myservo.write(0);
delay(500);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);
delay(500);
myservo.write(0); //rotate servo to one end
delay(2000); //wait for 1 second
myservo.write(380); //rotate servo to the other end
delay(3000); //wait for 1 second
}
}
