/*
 * User Control Servo - Serial Monitor Input for Interactive Control
 * 
 * Description: This program allows users to control a servo motor by
 * typing angles (0-180) in the Serial Monitor.
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
 * How to Use:
 * 1. Upload this code to Arduino
 * 2. Open Serial Monitor (Tools -> Serial Monitor)
 * 3. Set baud rate to 9600
 * 4. Type any number from 0 to 180
 * 5. Press Enter
 * 6. Watch the servo move to that angle!
 * 
 * Special Commands:
 * - "center" : Move to 90 degrees
 * - "left"   : Move to 0 degrees
 * - "right"  : Move to 180 degrees
 * - "sweep"  : Perform one sweep cycle
 * - "status" : Show current position
 * 
 * Author: Arduino Servo Tutorial
 * Date: 2025
 */

#include <Servo.h>

Servo myServo;
int currentAngle = 90;  // Start at center position

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  
  // Move to starting position
  myServo.write(currentAngle);
  delay(500);
  
  Serial.println("=================================");
  Serial.println("    SERVO CONTROL SYSTEM READY   ");
  Serial.println("=================================");
  Serial.println();
  Serial.println("Commands you can use:");
  Serial.println("• Enter angle (0-180) and press Enter");
  Serial.println("• Type 'center' for 90°");
  Serial.println("• Type 'left' for 0°");
  Serial.println("• Type 'right' for 180°");
  Serial.println("• Type 'sweep' for one sweep cycle");
  Serial.println("• Type 'status' to see current position");
  Serial.println();
  Serial.print("Current angle: ");
  Serial.println(currentAngle);
  Serial.println("Enter your command:");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming string
    String input = Serial.readString();
    input.trim();  // Remove any whitespace
    
    // Convert to lowercase for easier comparison
    input.toLowerCase();
    
    // Handle special commands
    if (input == "center") {
      moveToAngle(90);
    }
    else if (input == "left") {
      moveToAngle(0);
    }
    else if (input == "right") {
      moveToAngle(180);
    }
    else if (input == "sweep") {
      performSweep();
    }
    else if (input == "status") {
      Serial.print("Current position: ");
      Serial.print(currentAngle);
      Serial.println("°");
    }
    else {
      // Try to parse as a number
      int newAngle = input.toInt();
      
      // Check if it's a valid number and within range
      if (newAngle >= 0 && newAngle <= 180) {
        moveToAngle(newAngle);
      } else {
        Serial.println("❌ Error: Please enter a number between 0 and 180");
        Serial.println("   Or use commands: center, left, right, sweep, status");
      }
    }
    
    Serial.println();
    Serial.println("Enter next command:");
  }
}

void moveToAngle(int angle) {
  currentAngle = angle;
  myServo.write(currentAngle);
  
  Serial.print("✅ Moved to ");
  Serial.print(currentAngle);
  Serial.println("°");
  
  // Visual indicator
  if (angle == 0) {
    Serial.println("   (Far Left Position)");
  } else if (angle == 90) {
    Serial.println("   (Center Position)");
  } else if (angle == 180) {
    Serial.println("   (Far Right Position)");
  }
}

void performSweep() {
  Serial.println("🔄 Performing sweep...");
  
  // Sweep to 0
  for (int angle = currentAngle; angle >= 0; angle -= 2) {
    myServo.write(angle);
    delay(20);
  }
  
  // Sweep to 180
  for (int angle = 0; angle <= 180; angle += 2) {
    myServo.write(angle);
    delay(20);
  }
  
  // Return to center
  for (int angle = 180; angle >= 90; angle -= 2) {
    myServo.write(angle);
    delay(20);
  }
  
  currentAngle = 90;
  Serial.println("✅ Sweep complete! Returned to center position.");
}

/*
 * ENHANCEMENT IDEAS:
 * 
 * 1. Add more commands like "dance" for a fun movement pattern
 * 2. Save favorite positions and recall them by name
 * 3. Add speed control for movements
 * 4. Create preset sequences of movements
 * 5. Add boundaries to prevent damage to connected mechanisms
 */