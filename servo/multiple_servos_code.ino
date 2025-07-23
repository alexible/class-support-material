/*
 * Multiple Servos - Controlling Two Servos Simultaneously
 * 
 * Description: This program demonstrates how to control two servo motors
 * at the same time with different movement patterns.
 * 
 * Hardware Required:
 * - Arduino Uno
 * - 2x Servo motors (SG90 or similar)
 * - Jumper wires
 * - External 5V power supply (recommended for stable operation)
 * 
 * Connections:
 * Servo 1:
 * - Red wire    -> 5V (Arduino or external supply)
 * - Brown wire  -> GND
 * - Orange wire -> Arduino Pin 9
 * 
 * Servo 2:
 * - Red wire    -> 5V (Arduino or external supply)
 * - Brown wire  -> GND
 * - Orange wire -> Arduino Pin 10
 * 
 * Movement Patterns:
 * 1. Synchronized - Both servos move together
 * 2. Mirror - Servos move in opposite directions
 * 3. Wave - One follows the other with a delay
 * 4. Independent - Each servo has its own pattern
 * 
 * Author: Arduino Servo Tutorial
 * Date: 2025
 */

#include <Servo.h>

// Create two servo objects
Servo servo1;
Servo servo2;

void setup() {
  // Attach servos to different pins
  servo1.attach(9);   // First servo on pin 9
  servo2.attach(10);  // Second servo on pin 10
  
  Serial.begin(9600);
  Serial.println("=======================================");
  Serial.println("    DUAL SERVO CONTROL SYSTEM READY   ");
  Serial.println("=======================================");
  Serial.println();
  Serial.println("Movement patterns:");
  Serial.println("1. Synchronized movement");
  Serial.println("2. Mirror movement");
  Serial.println("3. Wave movement");
  Serial.println("4. Independent patterns");
  Serial.println();
  
  // Start both servos at center position
  servo1.write(90);
  servo2.write(90);
  delay(1000);
  
  Serial.println("Starting dual servo dance...");
}

void loop() {
  // Pattern 1: Synchronized movement - both move together
  synchronizedMovement();
  delay(1000);
  
  // Pattern 2: Mirror movement - opposite directions
  mirrorMovement();
  delay(1000);
  
  // Pattern 3: Wave movement - one follows the other
  waveMovement();
  delay(1000);
  
  // Pattern 4: Independent patterns
  independentMovement();
  delay(2000);
  
  Serial.println("All patterns complete! Starting again...");
  Serial.println("=========================================");
}

void synchronizedMovement() {
  Serial.println("🤝 Pattern 1: Synchronized movement");
  
  // Both servos move together from 0 to 180
  for (int angle = 0; angle <= 180; angle += 5) {
    servo1.write(angle);
    servo2.write(angle);
    Serial.print("Both servos at: ");
    Serial.print(angle);
    Serial.println("°");
    delay(50);
  }
  
  // Return to center together
  for (int angle = 180; angle >= 90; angle -= 5) {
    servo1.write(angle);
    servo2.write(angle);
    delay(50);
  }
  
  Serial.println("✅ Synchronized movement complete");
}

void mirrorMovement() {
  Serial.println("🪞 Pattern 2: Mirror movement");
  
  // Servos move in opposite directions
  for (int angle = 0; angle <= 180; angle += 5) {
    servo1.write(angle);
    servo2.write(180 - angle);  // Opposite direction
    Serial.print("Servo1: ");
    Serial.print(angle);
    Serial.print("° | Servo2: ");
    Serial.print(180 - angle);
    Serial.println("°");
    delay(50);
  }
  
  // Return both to center
  for (int angle = 180; angle >= 90; angle -= 5) {
    servo1.write(angle);
    servo2.write(180 - angle);
    delay(50);
  }
  
  Serial.println("✅ Mirror movement complete");
}

void waveMovement() {
  Serial.println("🌊 Pattern 3: Wave movement");
  
  // Servo1 leads, Servo2 follows with delay
  for (int angle = 0; angle <= 180; angle += 3) {
    servo1.write(angle);
    delay(30);
    
    // Servo2 follows 30 degrees behind
    int servo2Angle = angle - 30;
    if (servo2Angle < 0) servo2Angle = 0;
    servo2.write(servo2Angle);
    
    Serial.print("Leader: ");
    Serial.print(angle);
    Serial.print("° | Follower: ");
    Serial.print(servo2Angle);
    Serial.println("°");
    delay(20);
  }
  
  // Return to center with wave effect
  for (int angle = 180; angle >= 90; angle -= 3) {
    servo1.write(angle);
    delay(30);
    servo2.write(angle + 30 > 180 ? 180 : angle + 30);
    delay(20);
  }
  
  Serial.println("✅ Wave movement complete");
}

void independentMovement() {
  Serial.println("🎭 Pattern 4: Independent movement");
  
  // Each servo has its own unique pattern
  for (int i = 0; i < 36; i++) {  // 36 steps for smooth motion
    // Servo1: Sine wave pattern
    int angle1 = 90 + (sin(i * 0.174) * 45);  // 0.174 ≈ 10 degrees in radians
    
    // Servo2: Triangle wave pattern
    int angle2;
    if (i < 18) {
      angle2 = map(i, 0, 17, 45, 135);
    } else {
      angle2 = map(i, 18, 35, 135, 45);
    }
    
    servo1.write(angle1);
    servo2.write(angle2);
    
    Serial.print("Servo1 (sine): ");
    Serial.print(angle1);
    Serial.print("° | Servo2 (triangle): ");
    Serial.print(angle2);
    Serial.println("°");
    
    delay(100);
  }
  
  // Return both to center
  servo1.write(90);
  servo2.write(90);
  
  Serial.println("✅ Independent movement complete");
}

/*
 * POWER SUPPLY NOTES:
 * 
 * For reliable operation with two servos:
 * 1. Use external 5V power supply (2A or higher)
 * 2. Connect Arduino GND to external supply GND
 * 3. Power servos from external supply, not Arduino
 * 4. Arduino USB can still power the board itself
 * 
 * EXPANSION IDEAS:
 * 
 * 1. Add more servos (Arduino Uno can control up to 12)
 * 2. Create robotic arm with coordinated movement
 * 3. Add user input to select movement patterns
 * 4. Create custom choreographed sequences
 * 5. Add sensors to make movements reactive
 */