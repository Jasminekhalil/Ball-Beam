const int trigPin = 9; // Defining pin number for trigger
const int echoPin = 10; // Defining pin number for echo
#define motorPin 4

// Defining what type of data type each variable is
long duration;
float distance;
float first;
float second;
float third;
float distance_avg;


#include <Servo.h> // Including the Servo Library 
int servoPin = 3; // Declaring the Servo pin
int i=0; // Starting a counter
Servo Servo1; // Creating a servo object

void setup() {

  Servo1.attach(servoPin); // Attatching Servo1 to the Servo Motor's pin
  Serial.begin(9600); // Open the serial port at 9600 bps
  pinMode(trigPin, OUTPUT); // Setting the trigger pin as an output
  pinMode(echoPin, INPUT); // Setting the echo pin as an input


}

void loop() {

  i+=1; // Adding 1 to the counter each iteration 
  // Clearing the trigger pin for 2 microseconds 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

  // Starting the trigger for 10 microseconds 
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); // Stopping the trigger to collect data

  duration = pulseIn(echoPin, HIGH); // Reads the echoPin and returns the sound wave travel time in microseconds

  distance = duration * 0.034/2; // Calculating the distance using the constant value of velocity: 0.034. Dividing by 2 because duration is the total time from the sensor and back. 
  
  // Finding an average distance for accuracy
  first = distance;
  if (i=1) { // If this is the first loop, then all values of distance are the same
    second = first;
    third = first;
  }

  distance_avg = (first+second+third)/2; // Calculating the average distance 

  third = second;
  second = first;

  Serial.print("Distance: ");
  Serial.println(distance_avg);
  Servo1.writeMicroseconds(distance_avg*100);
  Serial.print(i);
}

