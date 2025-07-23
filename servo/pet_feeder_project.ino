/*
 * PROJECT 1: Automatic Pet Feeder Door
 * Difficulty: Easy
 * 
 * Description: An automatic pet feeding system that opens and closes
 * a door at scheduled intervals. Perfect for dispensing food or treats!
 * 
 * Hardware Required:
 * - Arduino Uno
 * - Servo motor (SG90 or similar)
 * - Small cardboard box for feeder
 * - Jumper wires
 * - Optional: LED for status indication
 * - Optional: Buzzer for feeding alerts
 * 
 * Connections:
 * - Servo Red wire    -> Arduino 5V
 * - Servo Brown wire  -> Arduino GND
 * - Servo Orange wire -> Arduino Pin 9
 * - LED (optional)    -> Arduino Pin 13 (built-in LED)
 * - Buzzer (optional) -> Arduino Pin 8
 * 
 * Features:
 * - Automatic feeding every X seconds (adjustable)
 * - Manual control via Serial Monitor
 * - Door stays open for 3 seconds then closes
 * - Status LED indicates door state
 * - Feeding time announcements
 * 
 * Assembly Instructions:
 * 1. Cut a hole in the side of a cardboard box
 * 2. Mount servo so the horn can block/unblock the hole
 * 3. Attach a small flap to the servo horn as the "door"
 * 4. Fill box with treats or kibble
 * 5. Connect electronics and upload code
 * 
 * Author: Arduino Pet Feeder Project
 * Date: 2025
 */

#include <Servo.h>

Servo feederServo;

// Pin definitions
const int SERVO_PIN = 9;
const int LED_PIN = 13;      // Built-in LED
const int BUZZER_PIN = 8;    // Optional buzzer

// Door positions
const int CLOSED_ANGLE = 0;    // Door closed position
const int OPEN_ANGLE = 90;     // Door open position

// Timing settings
const long FEED_INTERVAL = 10000;  // 10 seconds for demo (change to 3600000 for 1 hour)
const long DOOR_OPEN_TIME = 3000;  // Door stays open for 3 seconds

// State variables
unsigned long lastFeedTime = 0;
unsigned long doorOpenTime = 0;
bool doorOpen = false;
int feedingCount = 0;

void setup() {
  // Initialize pins
  feederServo.attach(SERVO_PIN);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);
  
  // Start with door closed
  feederServo.write(CLOSED_ANGLE);
  digitalWrite(LED_PIN, LOW);  // LED off = door closed
  doorOpen = false;
  
  Serial.println("🐕=======================================🐕");
  Serial.println("     AUTOMATIC PET FEEDER SYSTEM READY    ");
  Serial.println("🐕=======================================🐕");
  Serial.println();
  Serial.println("Features:");
  Serial.println("• Automatic feeding every 10 seconds (demo mode)");
  Serial.println("• Door opens for 3 seconds then closes");
  Serial.println("• Manual control available");
  Serial.println();
  Serial.println("Manual Commands:");
  Serial.println("• 'feed' - Trigger immediate feeding");
  Serial.println("• 'open' - Open door manually");
  Serial.println("• 'close' - Close door manually");
  Serial.println("• 'status' - Show current status");
  Serial.println("• 'reset' - Reset feeding counter");
  Serial.println();
  
  lastFeedTime = millis();  // Record start time
  printStatus();
}

void loop() {
  unsigned long currentTime = millis();
  
  // Check if it's time for automatic feeding
  if (currentTime - lastFeedTime >= FEED_INTERVAL && !doorOpen) {
    triggerFeeding();
  }
  
  // Close door after specified time
  if (doorOpen && currentTime - doorOpenTime >= DOOR_OPEN_TIME) {
    closeDoor();
  }
  
  // Check for manual commands
  handleSerialCommands();
  
  delay(100);  // Small delay for stability
}

void triggerFeeding() {
  feedingCount++;
  Serial.println();
  Serial.println("🍽️ FEEDING TIME! 🍽️");
  Serial.print("Feeding #");
  Serial.println(feedingCount);
  
  playFeedingAlert();
  openDoor();
  
  lastFeedTime = millis();
}

void openDoor() {
  if (!doorOpen) {
    Serial.println("Opening feeder door...");
    feederServo.write(OPEN_ANGLE);
    digitalWrite(LED_PIN, HIGH);  // LED on = door open
    doorOpen = true;
    doorOpenTime = millis();
    
    Serial.println("✅ Door OPEN - Food dispensing!");
  }
}

void closeDoor() {
  if (doorOpen) {
    Serial.println("Closing feeder door...");
    feederServo.write(CLOSED_ANGLE);
    digitalWrite(LED_PIN, LOW);   // LED off = door closed
    doorOpen = false;
    
    Serial.println("✅ Door CLOSED - Feeding complete!");
    printNextFeedingTime();
  }
}

void handleSerialCommands() {
  if (Serial.available() > 0) {
    String command = Serial.readString();
    command.trim();
    command.toLowerCase();
    
    Serial.println();
    Serial.print("Command received: ");
    Serial.println(command);
    
    if (command == "feed") {
      triggerFeeding();
    }
    else if (command == "open") {
      openDoor();
    }
    else if (command == "close") {
      closeDoor();
    }
    else if (command == "status") {
      printStatus();
    }
    else if (command == "reset") {
      feedingCount = 0;
      lastFeedTime = millis();
      Serial.println("✅ Feeding counter reset!");
      printStatus();
    }
    else {
      Serial.println("❌ Unknown command!");
      Serial.println("Available: feed, open, close, status, reset");
    }
  }
}

void printStatus() {
  Serial.println();
  Serial.println("📊 FEEDER STATUS 📊");
  Serial.println("===================");
  Serial.print("Door: ");
  Serial.println(doorOpen ? "🟢 OPEN" : "🔴 CLOSED");
  Serial.print("Total feedings: ");
  Serial.println(feedingCount);
  Serial.print("Feed interval: ");
  Serial.print(FEED_INTERVAL / 1000);
  Serial.println(" seconds");
  
  if (!doorOpen) {
    printNextFeedingTime();
  }
  Serial.println("===================");
}

void printNextFeedingTime() {
  unsigned long timeUntilNext = FEED_INTERVAL - (millis() - lastFeedTime);
  if (timeUntilNext > FEED_INTERVAL) timeUntilNext = 0;  // Handle overflow
  
  Serial.print("Next feeding in: ");
  Serial.print(timeUntilNext / 1000);
  Serial.println(" seconds");
}

void playFeedingAlert() {
  // Play a simple melody if buzzer is connected
  int melody[] = {262, 294, 330, 349};  // C, D, E, F notes
  
  for (int i = 0; i < 4; i++) {
    tone(BUZZER_PIN, melody[i], 200);
    delay(250);
  }
  
  noTone(BUZZER_PIN);
}

/*
 * CUSTOMIZATION IDEAS:
 * 
 * 1. Change FEED_INTERVAL for different schedules:
 *    - 1800000 for 30 minutes
 *    - 3600000 for 1 hour
 *    - 14400000 for 4 hours
 * 
 * 2. Add multiple feeding times per day
 * 3. Include a food level sensor
 * 4. Add WiFi for remote monitoring
 * 5. Create a mobile app interface
 * 6. Add portion control with multiple door openings
 * 7. Include a camera for pet monitoring
 * 
 * SAFETY NOTES:
 * 
 * - Ensure door mechanism cannot harm pets
 * - Use food-safe materials for construction
 * - Test thoroughly before leaving pets unattended
 * - Keep electronics away from water/food spills
 */