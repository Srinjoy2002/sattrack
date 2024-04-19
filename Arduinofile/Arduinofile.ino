#include <Servo.h>

Servo azimuthServo;
Servo elevationServo;

// Pin definitions
const int azimuthServoPin = 9; // Change as per your wiring
const int elevationServoPin = 10; // Change as per your wiring

void setup() {
    // Attach servos to pins
    azimuthServo.attach(azimuthServoPin);
    elevationServo.attach(elevationServoPin);
  
    // Initialize serial communication
    Serial.begin(9600);
}

void loop() {
    // Check if data is available from the serial port
    if (Serial.available() > 0) {
        // Read data from serial port
        String data = Serial.readStringUntil('\n');
        
        // Parse the received data
        // Assuming data format: "azimuth elevation"
        int delimiterIndex = data.indexOf(' ');
        if (delimiterIndex != -1) {
            // Parse azimuth and elevation
            float azimuth = data.substring(0, delimiterIndex).toFloat();
            float elevation = data.substring(delimiterIndex + 1).toFloat();
            
            // Convert azimuth and elevation to servo angles
            int azimuthAngle = map(azimuth, 0, 360, 0, 180); // Map azimuth from 0-360 to 0-180 degrees
            int elevationAngle = map(elevation, 0, 90, 0, 180); // Map elevation from 0-90 to 0-180 degrees
            
            // Set servo positions
            azimuthServo.write(azimuthAngle);
            elevationServo.write(elevationAngle);
        }
    }
}
