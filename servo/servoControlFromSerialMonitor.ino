#include <Servo.h> Servo myServo; 

int currentAngle = 90; // Start at center position 

void setup() { 
  myServo.attach(9); 
  Serial.begin(9600); 
  myServo.write(currentAngle); // Move to starting position 
  Serial.println("Servo Control Ready!"); 
  Serial.println("Enter angle (0-180) and press Enter:"); 
  Serial.print("Current angle: "); 
  Serial.println(currentAngle); 
  } 
  
  void loop() { 
    // Check if data is available to read 
    if (Serial.available() > 0) { 
      // Read the incoming angle 
      int newAngle = Serial.parseInt(); 
      // Check if angle is valid (0-180) 
      if (newAngle >= 0 && newAngle <= 180) { 
        currentAngle = newAngle; 
        myServo.write(currentAngle); 
        Serial.print("Moved to angle: "); 
        Serial.println(currentAngle); 
        } 
        else { 
          Serial.println("Error: Please enter angle between 0 and 180"); 
          
          } Serial.println("Enter next angle:"); 
          
  } 
          
}
