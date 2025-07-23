// Include the servo library 
#include <Servo.h> 

// Create a servo object 

Servo myServo; 

void setup() { 
  // Attach the servo to pin 9 
  myServo.attach(9); 
  // Initialize serial communication for debugging 
  Serial.begin(9600); 
  Serial.println("Servo Test Started!"); 
} 

void loop() { 
  // Move to 0 degrees 
  Serial.println("Moving to 0 degrees"); 
  myServo.write(0); 
  delay(1000); // Wait 1 second 
  // Move to 90 degrees (center) 
  Serial.println("Moving to 90 degrees"); 
  myServo.write(90); 
  delay(1000); // Wait 1 second 
  // Move to 180 degrees 
  Serial.println("Moving to 180 degrees"); 
  myServo.write(180); 
  delay(1000); // Wait 1 second 
  // Move back to center 
  Serial.println("Moving back to 90 degrees"); 
  myServo.write(90); 
  delay(1000); // Wait 1 second 
}
