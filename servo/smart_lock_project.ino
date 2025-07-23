/*
 * PROJECT 3: Smart Door Lock System
 * Difficulty: Medium
 * 
 * Description: A password-protected door lock using a servo motor.
 * Users can unlock the door by entering the correct password via
 * Serial Monitor. Includes security features and status indicators.
 * 
 * Hardware Required:
 * - Arduino Uno
 * - Servo motor (SG90 or similar)
 * - LED (for status indication)
 * - 220Ω resistor (for LED)
 * - Optional: Buzzer for audio alerts
 * - Cardboard or wood for door frame mock-up
 * - Jumper wires
 * 
 * Connections:
 * - Servo Red wire    -> Arduino 5V
 * - Servo Brown wire  -> Arduino GND
 * - Servo Orange wire -> Arduino Pin 9
 * - LED positive      -> Arduino Pin 13 (built-in LED)
 * - LED negative      -> Arduino GND
 * - Buzzer positive   -> Arduino Pin 8 (optional)
 * - Buzzer negative   -> Arduino GND
 * 
 * Features:
 * - Password protection (default: "1234")
 * - Auto-lock after 5 seconds
 * - LED status indicator (on=unlocked, off=locked)
 * - Multiple security attempts tracking
 * - Password change functionality
 * - Manual lock/unlock commands
 * - Lockout after failed attempts
 * - Audio alerts for security events
 * 
 * Commands:
 * - Enter password to unlock
 * - "lock" - Lock door manually
 * - "unlock" - Prompt for password
 * - "changepass" - Change password (requires current password)
 * - "status" - Show current lock status
 * - "reset" - Reset failed attempts counter
 * - "help" - Show all available commands
 * 
 * Assembly Instructions:
 * 1. Create a simple door frame from cardboard
 * 2. Mount servo so horn can act as a deadbolt
 * 3. Attach a small arm to servo horn as the "bolt"
 * 4. Connect electronics according to diagram
 * 5. Upload code and test with Serial Monitor
 * 
 * Author: Arduino Smart Lock Project
 * Date: 2025
 */

#include <Servo.h>

Servo lockServo;

// Pin definitions
const int SERVO_PIN = 9;
const int LED_PIN = 13;      // Built-in LED for status
const int BUZZER_PIN = 8;    // Optional buzzer

// Lock positions
const int LOCKED_ANGLE = 0;    // Door locked position (bolt extended)
const int UNLOCKED_ANGLE = 90; // Door unlocked position (bolt retracted)

// Security settings
String correctPassword = "1234";  // Default password
const int MAX_ATTEMPTS = 3;       // Maximum failed attempts before lockout
const long LOCKOUT_TIME = 30000;  // 30 seconds lockout time
const long AUTO_LOCK_TIME = 5000; // Auto-lock after 5 seconds

// State variables
bool isLocked = true;
int failedAttempts = 0;
unsigned long unlockTime = 0;
unsigned long lockoutStartTime = 0;
bool inLockout = false;

void setup() {
  // Initialize hardware
  lockServo.attach(SERVO_PIN);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);
  
  // Start in locked position
  lockServo.write(LOCKED_ANGLE);
  digitalWrite(LED_PIN, LOW);  // LED off = locked
  
  Serial.println("🔐===========================================🔐");
  Serial.println("        SMART DOOR LOCK SYSTEM v2.0          ");
  Serial.println("🔐===========================================🔐");
  Serial.println();
  Serial.println("🛡️  SECURITY FEATURES:");
  Serial.println("   • Password protection");
  Serial.println("   • Auto-lock after 5 seconds");
  Serial.println("   • Failed attempt tracking");
  Serial.println("   • Temporary lockout protection");
  Serial.println("   • Password change capability");
  Serial.println();
  Serial.println("📋 AVAILABLE COMMANDS:");
  Serial.println("   • [password] - Unlock door");
  Serial.println("   • 'lock' - Lock door manually");
  Serial.println("   • 'unlock' - Prompt for password");
  Serial.println("   • 'changepass' - Change password");
  Serial.println("   • 'status' - Show lock status");
  Serial.println("   • 'reset' - Reset failed attempts");
  Serial.println("   • 'help' - Show this help menu");
  Serial.println();
  
  playStartupSound();
  printStatus();
  
  if (isLocked) {
    Serial.println("🔒 Enter password to unlock:");
  }
}

void loop() {
  unsigned long currentTime = millis();
  
  // Handle lockout timeout
  if (inLockout && currentTime - lockoutStartTime >= LOCKOUT_TIME) {
    inLockout = false;
    failedAttempts = 0;
    Serial.println();
    Serial.println("⏰ Lockout period expired. You may try again.");
    printStatus();
    if (isLocked) {
      Serial.println("🔒 Enter password to unlock:");
    }
  }
  
  // Auto-lock after delay
  if (!isLocked && currentTime - unlockTime >= AUTO_LOCK_TIME) {
    lockDoor();
  }
  
  // Handle serial input
  handleSerialCommands();
  
  delay(100);  // Small delay for stability
}

void handleSerialCommands() {
  if (Serial.available() > 0) {
    String input = Serial.readString();
    input.trim();
    
    // Don't process commands during lockout
    if (inLockout) {
      unsigned long remainingTime = LOCKOUT_TIME - (millis() - lockoutStartTime);
      Serial.println();
      Serial.print("🚫 System locked out. Try again in ");
      Serial.print(remainingTime / 1000);
      Serial.println(" seconds.");
      return;
    }
    
    String command = input;
    command.toLowerCase();
    
    Serial.println();
    Serial.print("📨 Command received: ");
    Serial.println(input);
    
    // Handle commands
    if (command == "lock") {
      lockDoor();
    }
    else if (command == "unlock") {
      Serial.println("🔑 Enter password:");
    }
    else if (command == "status") {
      printDetailedStatus();
    }
    else if (command == "help") {
      printHelpMenu();
    }
    else if (command == "reset") {
      resetSecurity();
    }
    else if (command == "changepass") {
      changePassword();
    }
    else if (isLocked) {
      // Try to unlock with password
      checkPassword(input);
    }
    else {
      Serial.println("❓ Unknown command. Type 'help' for available commands.");
    }
  }
}

void checkPassword(String password) {
  if (password == correctPassword) {
    unlockDoor();
    failedAttempts = 0;  // Reset failed attempts on successful unlock
  } else {
    failedAttempts++;
    Serial.println("❌ INCORRECT PASSWORD!");
    Serial.print("🚨 Failed attempts: ");
    Serial.print(failedAttempts);
    Serial.print("/");
    Serial.println(MAX_ATTEMPTS);
    
    playFailureSound();
    
    if (failedAttempts >= MAX_ATTEMPTS) {
      initiateSecurityLockout();
    } else {
      Serial.println("🔒 Try again:");
    }
  }
}

void unlockDoor() {
  isLocked = false;
  lockServo.write(UNLOCKED_ANGLE);
  digitalWrite(LED_PIN, HIGH);  // LED on = unlocked
  unlockTime = millis();
  
  Serial.println("✅ ACCESS GRANTED!");
  Serial.println("🔓 Door UNLOCKED!");
  Serial.println("⏰ Door will auto-lock in 5 seconds...");
  
  playSuccessSound();
  printStatus();
}

void lockDoor() {
  isLocked = true;
  lockServo.write(LOCKED_ANGLE);
  digitalWrite(LED_PIN, LOW);   // LED off = locked
  
  Serial.println("🔒 Door LOCKED!");
  Serial.println("🔑 Enter password to unlock:");
  
  playLockSound();
  printStatus();
}

void initiateSecurityLockout() {
  inLockout = true;
  lockoutStartTime = millis();
  
  Serial.println();
  Serial.println("🚨🚨🚨 SECURITY ALERT! 🚨🚨🚨");
  Serial.println("Too many failed attempts!");
  Serial.print("System locked for ");
  Serial.print(LOCKOUT_TIME / 1000);
  Serial.println(" seconds.");
  Serial.println("🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨🚨");
  
  playAlarmSound();
}

void changePassword() {
  Serial.println("🔧 PASSWORD CHANGE PROCEDURE");
  Serial.println("Enter current password:");
  
  // Wait for input with timeout
  unsigned long startTime = millis();
  while (!Serial.available() && millis() - startTime < 10000) {
    delay(10);
  }
  
  if (!Serial.available()) {
    Serial.println("⏰ Timeout - password change cancelled.");
    return;
  }
  
  String currentPass = Serial.readString();
  currentPass.trim();
  
  if (currentPass == correctPassword) {
    Serial.println("✅ Current password verified.");
    Serial.println("Enter new password:");
    
    // Wait for new password
    startTime = millis();
    while (!Serial.available() && millis() - startTime < 10000) {
      delay(10);
    }
    
    if (Serial.available()) {
      String newPassword = Serial.readString();
      newPassword.trim();
      
      if (newPassword.length() >= 4) {
        correctPassword = newPassword;
        Serial.println("✅ Password successfully changed!");
        playSuccessSound();
      } else {
        Serial.println("❌ Password must be at least 4 characters long.");
      }
    } else {
      Serial.println("⏰ Timeout - password change cancelled.");
    }
  } else {
    Serial.println("❌ Incorrect current password!");
    failedAttempts++;
  }
  
  printStatus();
}

void resetSecurity() {
  failedAttempts = 0;
  inLockout = false;
  Serial.println("✅ Security counters reset.");
  Serial.println("🔒 Ready for password attempts.");
}

void printStatus() {
  Serial.println();
  Serial.println("📊 LOCK STATUS");
  Serial.println("==============");
  Serial.print("🚪 Door: ");
  if (isLocked) {
    Serial.println("🔴 LOCKED");
  } else {
    Serial.println("🟢 UNLOCKED");
    unsigned long timeLeft = AUTO_LOCK_TIME - (millis() - unlockTime);
    if (timeLeft > AUTO_LOCK_TIME) timeLeft = 0;
    Serial.print("⏰ Auto-lock in: ");
    Serial.print(timeLeft / 1000);
    Serial.println(" seconds");
  }
  Serial.print("🛡️ Security: ");
  if (inLockout) {
    unsigned long timeLeft = LOCKOUT_TIME - (millis() - lockoutStartTime);
    Serial.print("🚨 LOCKED OUT (");
    Serial.print(timeLeft / 1000);
    Serial.println(" sec remaining)");
  } else {
    Serial.println("🟢 NORMAL");
  }
  Serial.println("==============");
}

void printDetailedStatus() {
  printStatus();
  Serial.print("🔢 Failed attempts: ");
  Serial.print(failedAttempts);
  Serial.print("/");
  Serial.println(MAX_ATTEMPTS);
  Serial.print("🔑 Password length: ");
  Serial.print(correctPassword.length());
  Serial.println(" characters");
}

void printHelpMenu() {
  Serial.println();
  Serial.println("📚 HELP MENU");
  Serial.println("=============");
  Serial.println("🔓 UNLOCK COMMANDS:");
  Serial.println("   [your-password] - Enter password to unlock");
  Serial.println("   'unlock' - Prompt for password entry");
  Serial.println();
  Serial.println("🔒 LOCK COMMANDS:");
  Serial.println("   'lock' - Lock door immediately");
  Serial.println();
  Serial.println("⚙️ MANAGEMENT COMMANDS:");
  Serial.println("   'status' - Show detailed lock status");
  Serial.println("   'changepass' - Change password");
  Serial.println("   'reset' - Reset security counters");
  Serial.println("   'help' - Show this menu");
  Serial.println("=============");
}

// Sound functions for audio feedback
void playSuccessSound() {
  for (int i = 0; i < 2; i++) {
    tone(BUZZER_PIN, 1000, 200);
    delay(250);
  }
  noTone(BUZZER_PIN);
}

void playFailureSound() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 300, 150);
    delay(200);
  }
  noTone(BUZZER_PIN);
}

void playLockSound() {
  tone(BUZZER_PIN, 800, 100);
  delay(150);
  tone(BUZZER_PIN, 600, 100);
  noTone(BUZZER_PIN);
}

void playAlarmSound() {
  for (int i = 0; i < 5; i++) {
    tone(BUZZER_PIN, 1500, 200);
    delay(100);
    tone(BUZZER_PIN, 500, 200);
    delay(100);
  }
  noTone(BUZZER_PIN);
}

void playStartupSound() {
  int startup[] = {262, 330, 392, 523};  // C, E, G, C
  for (int i = 0; i < 4; i++) {
    tone(BUZZER_PIN, startup[i], 150);
    delay(200);
  }
  noTone(BUZZER_PIN);
}

/*
 * SECURITY ENHANCEMENTS:
 * 
 * 1. ENCRYPTED PASSWORDS:
 *    - Store password hash instead of plain text
 *    - Use Arduino cryptography libraries
 * 
 * 2. KEYPAD INPUT:
 *    - Add 4x4 matrix keypad for physical input
 *    - Eliminate need for Serial Monitor
 * 
 * 3. RFID/NFC ACCESS:
 *    - Add RFID reader for card-based access
 *    - Support multiple authorized cards
 * 
 * 4. REMOTE ACCESS:
 *    - WiFi connectivity for smartphone control
 *    - Web interface for management
 * 
 * 5. ACCESS LOGGING:
 *    - Record all access attempts with timestamps
 *    - Store logs on SD card or cloud
 * 
 * 6. BIOMETRIC SECURITY:
 *    - Fingerprint sensor integration
 *    - Voice recognition capabilities
 * 
 * PHYSICAL SECURITY NOTES:
 * 
 * - Use metal components for actual security applications
 * - Implement backup mechanical override
 * - Consider power failure scenarios
 * - Ensure servo has sufficient torque for real locks
 * - Add tamper detection sensors
 * - Use secure mounting to prevent bypass
 */