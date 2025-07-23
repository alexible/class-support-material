/*
 * PROJECT 2: Solar Panel Tracker
 * Difficulty: Medium
 * 
 * Description: A servo-controlled solar panel that automatically follows
 * the brightest light source using Light Dependent Resistors (LDRs).
 * 
 * Hardware Required:
 * - Arduino Uno
 * - Servo motor (SG90 or similar)
 * - 2x Light Dependent Resistors (LDR/Photoresistors)
 * - 2x 10kΩ resistors
 * - Small solar panel or cardboard mock-up
 * - Breadboard and jumper wires
 * - Cardboard base for mounting
 * 
 * Circuit Connections:
 * Servo:
 * - Red wire    -> Arduino 5V
 * - Brown wire  -> Arduino GND
 * - Orange wire -> Arduino Pin 9
 * 
 * Left LDR Circuit:
 * - One leg -> Arduino 5V
 * - Other leg -> Arduino A0 and 10kΩ resistor
 * - 10kΩ resistor other end -> Arduino GND
 * 
 * Right LDR Circuit:
 * - One leg -> Arduino 5V
 * - Other leg -> Arduino A1 and 10kΩ resistor
 * - 10kΩ resistor other end -> Arduino GND
 * 
 * How It Works:
 * 1. Two LDRs act as "light sensors" on left and right sides
 * 2. Arduino compares light levels between sensors
 * 3. Servo rotates panel toward the brighter side
 * 4. System continuously adjusts to track moving light
 * 
 * Assembly Instructions:
 * 1. Mount servo on a stable base
 * 2. Attach panel (or cardboard) to servo horn
 * 3. Position LDRs on either side of the panel
 * 4. Connect circuit according to diagram above
 * 5. Upload code and test with flashlight
 * 
 * Author: Arduino Solar Tracker Project
 * Date: 2025
 */

#include <Servo.h>

Servo solarServo;

// Pin definitions
const int LEFT_LDR = A0;
const int RIGHT_LDR = A1;
const int SERVO_PIN = 9;

// Servo position variables
int currentAngle = 90;  // Start facing forward
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;
const int STEP_SIZE = 2;  // Degrees to move per adjustment

// Sensitivity and timing
const int SENSITIVITY = 30;  // Minimum light difference to trigger movement
const int SAMPLE_DELAY = 200;  // Delay between readings (milliseconds)
const int MOVEMENT_DELAY = 50;  // Delay after servo movement

// Calibration variables
int leftBaseline = 0;
int rightBaseline = 0;
bool calibrated = false;

void setup() {
  solarServo.attach(SERVO_PIN);
  Serial.begin(9600);
  
  Serial.println("☀️========================================☀️");
  Serial.println("      SOLAR PANEL TRACKER SYSTEM READY     ");
  Serial.println("☀️========================================☀️");
  Serial.println();
  Serial.println("This system will automatically track light sources!");
  Serial.println("Use a flashlight to test the tracking behavior.");
  Serial.println();
  
  // Initialize servo position
  solarServo.write(currentAngle);
  delay(1000);
  
  Serial.println("🔧 Starting calibration...");
  calibrateSensors();
  
  Serial.println("✅ Calibration complete!");
  Serial.println("🔍 Starting light tracking...");
  Serial.println();
  Serial.println("Real-time data (Left | Right | Diff | Angle | Action):");
  Serial.println("=======================================================");
}

void loop() {
  // Read light levels from both sensors
  int leftLight = analogRead(LEFT_LDR);
  int rightLight = analogRead(RIGHT_LDR);
  
  // Apply calibration offset
  leftLight -= leftBaseline;
  rightLight -= rightBaseline;
  
  // Ensure non-negative values
  if (leftLight < 0) leftLight = 0;
  if (rightLight < 0) rightLight = 0;
  
  // Calculate the difference
  int lightDifference = leftLight - rightLight;
  
  // Display readings in a formatted way
  printSensorData(leftLight, rightLight, lightDifference);
  
  // Determine movement based on light difference
  String action = trackLight(lightDifference);
  
  // Print action taken
  Serial.print(" | ");
  Serial.println(action);
  
  delay(SAMPLE_DELAY);
}

void calibrateSensors() {
  Serial.println("Please ensure even lighting or darkness for calibration...");
  delay(2000);
  
  // Take multiple readings for baseline
  long leftSum = 0;
  long rightSum = 0;
  int samples = 20;
  
  for (int i = 0; i < samples; i++) {
    leftSum += analogRead(LEFT_LDR);
    rightSum += analogRead(RIGHT_LDR);
    delay(50);
    
    if (i % 5 == 0) {
      Serial.print(".");
    }
  }
  
  leftBaseline = leftSum / samples;
  rightBaseline = rightSum / samples;
  
  Serial.println();
  Serial.print("Left baseline: ");
  Serial.println(leftBaseline);
  Serial.print("Right baseline: ");
  Serial.println(rightBaseline);
  
  calibrated = true;
}

String trackLight(int lightDifference) {
  String action = "No movement";
  
  // Check if difference is significant enough to warrant movement
  if (abs(lightDifference) > SENSITIVITY) {
    
    if (lightDifference > 0 && currentAngle > MIN_ANGLE) {
      // Left side is brighter, turn left
      currentAngle -= STEP_SIZE;
      if (currentAngle < MIN_ANGLE) currentAngle = MIN_ANGLE;
      
      solarServo.write(currentAngle);
      action = "↰ Turning LEFT";
      delay(MOVEMENT_DELAY);
    }
    else if (lightDifference < 0 && currentAngle < MAX_ANGLE) {
      // Right side is brighter, turn right
      currentAngle += STEP_SIZE;
      if (currentAngle > MAX_ANGLE) currentAngle = MAX_ANGLE;
      
      solarServo.write(currentAngle);
      action = "↱ Turning RIGHT";
      delay(MOVEMENT_DELAY);
    }
    else if (currentAngle <= MIN_ANGLE) {
      action = "⚠️ Left limit reached";
    }
    else if (currentAngle >= MAX_ANGLE) {
      action = "⚠️ Right limit reached";
    }
  }
  else {
    action = "✓ Optimal position";
  }
  
  return action;
}

void printSensorData(int left, int right, int difference) {
  // Format output for easy reading
  Serial.print(String(left).substring(0, 4));
  Serial.print("  | ");
  Serial.print(String(right).substring(0, 4));
  Serial.print("  | ");
  
  // Show difference with sign
  if (difference >= 0) {
    Serial.print("+");
  }
  Serial.print(String(difference).substring(0, 4));
  Serial.print(" | ");
  Serial.print(String(currentAngle).substring(0, 3));
  Serial.print("°");
}

/*
 * ADVANCED FEATURES TO ADD:
 * 
 * 1. AUTOMATIC RESET:
 *    - Return to center position at night
 *    - Resume tracking when light returns
 * 
 * 2. SPEED CONTROL:
 *    - Faster movement for large differences
 *    - Slower movement for fine adjustments
 * 
 * 3. HYSTERESIS:
 *    - Prevent oscillation around optimal position
 *    - Different thresholds for start/stop movement
 * 
 * 4. DATA LOGGING:
 *    - Record light levels over time
 *    - Track efficiency improvements
 * 
 * 5. WEATHER PROTECTION:
 *    - Detect cloudy conditions
 *    - Park panel in safe position during storms
 */

// Additional utility functions for advanced features

void performSystemTest() {
  Serial.println("\n🧪 PERFORMING SYSTEM TEST 🧪");
  
  // Test full range movement
  Serial.println("Testing full range movement...");
  for (int angle = 90; angle <= MAX_ANGLE; angle += 10) {
    solarServo.write(angle);
    Serial.print("Position: ");
    Serial.print(angle);
    Serial.println("°");
    delay(500);
  }
  
  for (int angle = MAX_ANGLE; angle >= MIN_ANGLE; angle -= 10) {
    solarServo.write(angle);
    Serial.print("Position: ");
    Serial.print(angle);
    Serial.println("°");
    delay(500);
  }
  
  // Return to center
  solarServo.write(90);
  currentAngle = 90;
  Serial.println("✅ System test complete - returned to center");
}

void emergencyStop() {
  // Emergency function to stop all movement
  Serial.println("🛑 EMERGENCY STOP ACTIVATED 🛑");
  solarServo.write(90);  // Return to safe center position
  currentAngle = 90;
  delay(1000);
  
  // Wait for user confirmation to resume
  Serial.println("Type 'resume' to continue tracking...");
  while (true) {
    if (Serial.available() > 0) {
      String command = Serial.readString();
      command.trim();
      if (command.equalsIgnoreCase("resume")) {
        Serial.println("✅ Resuming normal operation");
        break;
      }
    }
    delay(100);
  }
}

/*
 * TROUBLESHOOTING GUIDE:
 * 
 * Problem: Servo constantly moving/jittering
 * Solution: Increase SENSITIVITY value or check wiring
 * 
 * Problem: No response to light changes
 * Solution: Check LDR connections and calibration
 * 
 * Problem: Moves in wrong direction
 * Solution: Swap LDR connections or modify tracking logic
 * 
 * Problem: Erratic behavior
 * Solution: Add filtering/averaging to sensor readings
 * 
 * TESTING TIPS:
 * 
 * - Use a bright flashlight for initial testing
 * - Cover one LDR to force movement
 * - Monitor Serial output to understand sensor readings
 * - Test in different lighting conditions
 * - Verify mechanical assembly is smooth and secure
 */
 