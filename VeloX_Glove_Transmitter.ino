#include <Wire.h>

const int MPU_addr = 0x68; // I2C address of MPU6050
int16_t AcX, AcY;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); // Wake up the MPU-6050
  Wire.write(0);    
  Wire.endTransmission(true);
  
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // Safety Button on Pin 2
}

void loop() {
  // Read the acceleration data directly from MPU6050 registers
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B); // Starting register for Accelerometer (AcX)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 4, true); // Request 4 registers (2 for X, 2 for Y)
  
  AcX = Wire.read() << 8 | Wire.read(); // Combine high and low byte for X
  AcY = Wire.read() << 8 | Wire.read(); // Combine high and low byte for Y
  
  // Map raw accelerometer values (-16384 to 16384 for 2g) to angles
  int tiltX = map(AcX, -16384, 16384, -90, 90);
  int tiltY = map(AcY, -16384, 16384, -90, 90);
  
  // Print the mapped tilt angles to the Serial Monitor
  Serial.print("Tilt X: ");
  Serial.print(tiltX);
  Serial.print(" | Tilt Y: ");
  Serial.println(tiltY);
  
  delay(200); // Small delay to make the serial stream readable
}
