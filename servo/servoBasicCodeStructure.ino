#include <Servo.h> // Include servo library Servo myServo; // Create servo object 

void setup() { 
  myServo.attach(9); // Attach servo to pin 9 
  } 
  
  void loop() { 
    myServo.write(90); // Move to 90 degrees delay(1000); // Wait 1 second 
    }
