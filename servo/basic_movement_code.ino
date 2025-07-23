/*
 * Basic Servo Movement - Simple Back and Forth Motion
 * 
 * Description: This program moves a servo motor back and forth between
 * 0°, 90°, and 180° positions with 1-second delays.
 * 
 * Hardware Required:
 * - Arduino Uno
 * - Servo motor (SG90 or similar)
 * - Jumper wires
 * 
 * Connections:
 * - Servo Red wire    -> Arduino 5V
 * - Servo Brown wire  -> Arduino GND
 * - Servo Orange wire -> Arduino Pin 9
 * 
 * Author: Arduino Servo Tutorial
 * Date: 2025
 */

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
  Serial.println("Watch the servo move back and forth...");
  
  // Move to center position initially
  myServo.write(90);
  delay(1000);
}

void loop() {
  // Move to 0 degrees
  Serial.println("Moving to 0 degrees");
  myServo.write(0);
  delay(1000);  // Wait 1 second
  
  // Move to 90 degrees (center)
  Serial.println("Moving to 90 degrees");
  myServo.write(90);
  delay(1000);  // Wait 1 second
  
  // Move to 180 degrees
  Serial.println("Moving to 180 degrees");
  myServo.write(180);
  delay(1000);  // Wait 1 second
  
  // Move back to center
  Serial.println("Moving back to 90 degrees");
  myServo.write(90);
  delay(1000);  // Wait 1 second
  
  Serial.println("Cycle complete! Starting again...");
  Serial.println("-----------------------------------");
}