/*
 * Smooth Servo Sweep - Gradual Movement Using For Loops
 * 
 * Description: This program creates smooth servo movement by incrementing
 * the angle one degree at a time with small delays.
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
 * Features:
 * - Smooth movement from 0° to 180° and back
 * - Adjustable speed via delay parameter
 * - Serial output shows current angle
 * 
 * Author: Arduino Servo Tutorial
 * Date: 2025
 */

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  Serial.println("Smooth Servo Sweep Started!");
  Serial.println("Watch the servo sweep smoothly back and forth...");
  
  // Start at 0 degrees
  myServo.write(0);
  delay(500);
}

void loop() {
  // Sweep from 0 to 180 degrees
  Serial.println("Sweeping from 0 to 180 degrees...");
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(15);  // Small delay for smooth movement
  }
  
  // Wait at 180 degrees
  Serial.println("Reached 180°, pausing...");
  delay(500);
  
  // Sweep from 180 to 0 degrees
  Serial.println("Sweeping from 180 to 0 degrees...");
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.println("°");
    delay(15);  // Small delay for smooth movement
  }
  
  // Wait at 0 degrees
  Serial.println("Reached 0°, pausing...");
  delay(500);
  
  Serial.println("Sweep cycle complete! Starting again...");
  Serial.println("==========================================");
}

/*
 * EXPERIMENT IDEAS:
 * 
 * 1. Change delay(15) to delay(50) for slower movement
 * 2. Change delay(15) to delay(5) for faster movement
 * 3. Try different angle increments:
 *    - for (int angle = 0; angle <= 180; angle += 2)  // Move 2 degrees at a time
 *    - for (int angle = 0; angle <= 180; angle += 5)  // Move 5 degrees at a time
 * 4. Change the range:
 *    - for (int angle = 45; angle <= 135; angle++)    // Limited range sweep
 */