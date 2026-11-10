// #include <Wire.h>

// const int MPU = 0x68;

// void setup() {
//   Wire.begin();
//   Serial.begin(9600);

//   // Wake up MPU6050
//   Wire.beginTransmission(MPU);
//   Wire.write(0x6B);
//   Wire.write(0);
//   Wire.endTransmission(true);

//   Serial.println("MPU6050 Human Readable Test");
// }

// void loop() {

//   Wire.beginTransmission(MPU);
//   Wire.write(0x3B);
//   Wire.endTransmission(false);

//   Wire.requestFrom(MPU, 14, true);

//   int16_t AcX = Wire.read() << 8 | Wire.read();
//   int16_t AcY = Wire.read() << 8 | Wire.read();
//   int16_t AcZ = Wire.read() << 8 | Wire.read();

//   int16_t Temp = Wire.read() << 8 | Wire.read();

//   int16_t GyX = Wire.read() << 8 | Wire.read();
//   int16_t GyY = Wire.read() << 8 | Wire.read();
//   int16_t GyZ = Wire.read() << 8 | Wire.read();

//   // Convert accelerometer values to g
//   float ax = AcX / 16384.0;
//   float ay = AcY / 16384.0;
//   float az = AcZ / 16384.0;

//   // Convert gyroscope values to degrees/second
//   float gx = GyX / 131.0;
//   float gy = GyY / 131.0;
//   float gz = GyZ / 131.0;

//   // Convert temperature
//   float temperature = Temp / 340.0 + 36.53;

//   Serial.println("------ MPU6050 ------");

//   Serial.print("Acceleration (g): ");
//   Serial.print("X = ");
//   Serial.print(ax, 2);
//   Serial.print(" | Y = ");
//   Serial.print(ay, 2);
//   Serial.print(" | Z = ");
//   Serial.println(az, 2);

//   Serial.print("Gyroscope (deg/s): ");
//   Serial.print("X = ");
//   Serial.print(gx, 2);
//   Serial.print(" | Y = ");
//   Serial.print(gy, 2);
//   Serial.print(" | Z = ");
//   Serial.println(gz, 2);

//   Serial.print("Temperature: ");
//   Serial.print(temperature, 2);
//   Serial.println(" C");

//   Serial.println("---------------------");

//   delay(500);
// }


// // #include <Wire.h>
// // #include <math.h>

// // const int MPU = 0x68;

// // // 7 LEDs
// // const int leds[] = {2, 3, 4, 5, 6, 7, 8};
// // const int NUM_LEDS = 7;

// // void setup() {
// //   Wire.begin();
// //   Serial.begin(9600);

// //   // Set LED pins as outputs
// //   for (int i = 0; i < NUM_LEDS; i++) {
// //     pinMode(leds[i], OUTPUT);
// //     digitalWrite(leds[i], LOW);
// //   }

// //   // Wake up MPU6050
// //   Wire.beginTransmission(MPU);
// //   Wire.write(0x6B);
// //   Wire.write(0);
// //   Wire.endTransmission(true);

// //   Serial.println("MPU6050 7-LED Tilt Indicator");
// // }

// // void loop() {

// //   // Read accelerometer
// //   Wire.beginTransmission(MPU);
// //   Wire.write(0x3B);
// //   Wire.endTransmission(false);

// //   Wire.requestFrom(MPU, 6, true);

// //   int16_t AcX = Wire.read() << 8 | Wire.read();
// //   int16_t AcY = Wire.read() << 8 | Wire.read();
// //   int16_t AcZ = Wire.read() << 8 | Wire.read();

// //   // Convert raw values to g
// //   float ax = AcX / 16384.0;
// //   float az = AcZ / 16384.0;

// //   // Calculate tilt angle
// //   float angle = atan2(ax, az) * 180.0 / PI;

// //   Serial.print("Tilt angle: ");
// //   Serial.print(angle, 1);
// //   Serial.println(" degrees");

// //   // Turn all LEDs OFF
// //   for (int i = 0; i < NUM_LEDS; i++) {
// //     digitalWrite(leds[i], LOW);
// //   }

// //   // -------------------------
// //   // LEFT SIDE
// //   // -------------------------

// //   if (angle < -30) {
// //     digitalWrite(2, HIGH);
// //     digitalWrite(3, HIGH);
// //     digitalWrite(4, HIGH);
// //   }
// //   else if (angle < -15) {
// //     digitalWrite(3, HIGH);
// //     digitalWrite(4, HIGH);
// //   }
// //   else if (angle < -5) {
// //     digitalWrite(4, HIGH);
// //   }

// //   // -------------------------
// //   // CENTER
// //   // -------------------------

// //   else if (angle >= -5 && angle <= 5) {
// //     digitalWrite(5, HIGH);
// //   }

// //   // -------------------------
// //   // RIGHT SIDE
// //   // -------------------------

// //   else if (angle <= 15) {
// //     digitalWrite(6, HIGH);
// //   }
// //   else if (angle <= 30) {
// //     digitalWrite(6, HIGH);
// //     digitalWrite(7, HIGH);
// //   }
// //   else {
// //     digitalWrite(6, HIGH);
// //     digitalWrite(7, HIGH);
// //     digitalWrite(8, HIGH);
// //   }

// //   delay(100);
// // }



// #include <Wire.h>
// #include <math.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// // =========================
// // OLED
// // =========================

// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64

// #define OLED_RESET -1
// #define OLED_ADDRESS 0x3C

// Adafruit_SSD1306 display(
//   SCREEN_WIDTH,
//   SCREEN_HEIGHT,
//   &Wire,
//   OLED_RESET
// );

// // =========================
// // MPU6050
// // =========================

// const int MPU = 0x68;

// // =========================
// // LEDs
// // =========================

// const int leds[] = {2, 3, 4, 5, 6, 7, 8};
// const int NUM_LEDS = 7;

// // =========================
// // SETUP
// // =========================

// void setup() {

//   Wire.begin();
//   Serial.begin(9600);

//   // -------------------------
//   // LED setup
//   // -------------------------

//   for (int i = 0; i < NUM_LEDS; i++) {
//     pinMode(leds[i], OUTPUT);
//     digitalWrite(leds[i], LOW);
//   }

//   // -------------------------
//   // Wake MPU6050
//   // -------------------------

//   Wire.beginTransmission(MPU);
//   Wire.write(0x6B);
//   Wire.write(0);
//   Wire.endTransmission(true);

//   // -------------------------
//   // OLED setup
//   // -------------------------

//   if (!display.begin(
//         SSD1306_SWITCHCAPVCC,
//         OLED_ADDRESS
//       )) {

//     Serial.println("OLED NOT FOUND!");

//     while (true);
//   }

//   display.clearDisplay();

//   display.setTextColor(SSD1306_WHITE);

//   display.setTextSize(2);
//   display.setCursor(20, 10);
//   display.println("MPU6050");

//   display.setTextSize(1);
//   display.setCursor(25, 40);
//   display.println("Starting...");

//   display.display();

//   delay(2000);
// }

// // =========================
// // READ MPU6050
// // =========================

// void readMPU6050(
//   int16_t &AcX,
//   int16_t &AcY,
//   int16_t &AcZ
// ) {

//   Wire.beginTransmission(MPU);
//   Wire.write(0x3B);
//   Wire.endTransmission(false);

//   Wire.requestFrom(MPU, 6, true);

//   AcX = Wire.read() << 8 | Wire.read();
//   AcY = Wire.read() << 8 | Wire.read();
//   AcZ = Wire.read() << 8 | Wire.read();
// }

// // =========================
// // LED CONTROL
// // =========================

// void updateLEDs(float angle) {

//   // Turn everything OFF
//   for (int i = 0; i < NUM_LEDS; i++) {
//     digitalWrite(leds[i], LOW);
//   }

//   // -------------------------
//   // FAR LEFT
//   // -------------------------

//   if (angle < -30) {

//     digitalWrite(2, HIGH);
//     digitalWrite(3, HIGH);
//     digitalWrite(4, HIGH);
//   }

//   // -------------------------
//   // LEFT
//   // -------------------------

//   else if (angle < -15) {

//     digitalWrite(3, HIGH);
//     digitalWrite(4, HIGH);
//   }

//   // -------------------------
//   // SLIGHT LEFT
//   // -------------------------

//   else if (angle < -5) {

//     digitalWrite(4, HIGH);
//   }

//   // -------------------------
//   // CENTER
//   // -------------------------

//   else if (angle >= -5 && angle <= 5) {

//     digitalWrite(5, HIGH);
//   }

//   // -------------------------
//   // SLIGHT RIGHT
//   // -------------------------

//   else if (angle <= 15) {

//     digitalWrite(6, HIGH);
//   }

//   // -------------------------
//   // RIGHT
//   // -------------------------

//   else if (angle <= 30) {

//     digitalWrite(6, HIGH);
//     digitalWrite(7, HIGH);
//   }

//   // -------------------------
//   // FAR RIGHT
//   // -------------------------

//   else {

//     digitalWrite(6, HIGH);
//     digitalWrite(7, HIGH);
//     digitalWrite(8, HIGH);
//   }
// }

// // =========================
// // OLED DISPLAY
// // =========================

// void updateOLED(
//   float ax,
//   float ay,
//   float az,
//   float angle
// ) {

//   display.clearDisplay();

//   display.setTextColor(SSD1306_WHITE);

//   // Title
//   display.setTextSize(1);
//   display.setCursor(0, 0);
//   display.println("MPU6050 TILT");

//   // Divider
//   display.drawLine(
//     0,
//     10,
//     127,
//     10,
//     SSD1306_WHITE
//   );

//   // Angle
//   display.setTextSize(2);
//   display.setCursor(0, 15);

//   display.print(angle, 1);
//   display.print((char)247);

//   // Acceleration
//   display.setTextSize(1);

//   display.setCursor(0, 39);
//   display.print("X:");
//   display.print(ax, 2);
//   display.print("g");

//   display.setCursor(64, 39);
//   display.print("Y:");
//   display.print(ay, 2);
//   display.print("g");

//   display.setCursor(0, 51);
//   display.print("Z:");
//   display.print(az, 2);
//   display.print("g");

//   // Direction
//   display.setCursor(64, 51);

//   if (angle < -5) {
//     display.print("LEFT");
//   }
//   else if (angle > 5) {
//     display.print("RIGHT");
//   }
//   else {
//     display.print("CENTER");
//   }

//   display.display();
// }

// // =========================
// // MAIN LOOP
// // =========================

// void loop() {

//   int16_t AcX;
//   int16_t AcY;
//   int16_t AcZ;

//   // Read sensor
//   readMPU6050(AcX, AcY, AcZ);

//   // Convert raw values to g
//   float ax = AcX / 16384.0;
//   float ay = AcY / 16384.0;
//   float az = AcZ / 16384.0;

//   // Calculate tilt angle
//   float angle =
//     atan2(ax, az)
//     * 180.0
//     / PI;

//   // Update LEDs
//   updateLEDs(angle);

//   // Update OLED
//   updateOLED(
//     ax,
//     ay,
//     az,
//     angle
//   );

//   // Serial monitor
//   Serial.print("Angle: ");
//   Serial.print(angle, 1);

//   Serial.print(" | X: ");
//   Serial.print(ax, 2);

//   Serial.print(" | Y: ");
//   Serial.print(ay, 2);

//   Serial.print(" | Z: ");
//   Serial.println(az, 2);

//   delay(100);
// }









// #include <Wire.h>

// void setup() {
//   Serial.begin(9600);

//   Wire.begin();

//   Serial.println("I2C Scanner");
// }

// void loop() {

//   byte error;
//   int address;

//   Serial.println("Scanning...");

//   for (address = 1; address < 127; address++) {

//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0) {

//       Serial.print("I2C device found at 0x");

//       if (address < 16) {
//         Serial.print("0");
//       }

//       Serial.println(address, HEX);
//     }
//   }

//   Serial.println("Scan complete");
//   Serial.println();

//   delay(3000);
// }







// #include <Wire.h>

// #define MPU_ADDR 0x69

// void setup() {
//   Serial.begin(9600);
//   Wire.begin();

//   // Wake up MPU6050
//   Wire.beginTransmission(MPU_ADDR);
//   Wire.write(0x6B);
//   Wire.write(0);
//   Wire.endTransmission();

//   Serial.println("MPU6050 started");
// }

// void loop() {

//   // Request 14 bytes starting from ACCEL_XOUT_H
//   Wire.beginTransmission(MPU_ADDR);
//   Wire.write(0x3B);
//   Wire.endTransmission(false);

//   Wire.requestFrom(MPU_ADDR, 14, true);

//   int16_t AcX = Wire.read() << 8 | Wire.read();
//   int16_t AcY = Wire.read() << 8 | Wire.read();
//   int16_t AcZ = Wire.read() << 8 | Wire.read();

//   int16_t Temp = Wire.read() << 8 | Wire.read();

//   int16_t GyX = Wire.read() << 8 | Wire.read();
//   int16_t GyY = Wire.read() << 8 | Wire.read();
//   int16_t GyZ = Wire.read() << 8 | Wire.read();

//   Serial.print("ACC: ");
//   Serial.print(AcX);
//   Serial.print(" | ");
//   Serial.print(AcY);
//   Serial.print(" | ");
//   Serial.print(AcZ);

//   Serial.print("    GYRO: ");
//   Serial.print(GyX);
//   Serial.print(" | ");
//   Serial.print(GyY);
//   Serial.print(" | ");
//   Serial.println(GyZ);

//   delay(500);
// }



#include <Wire.h>

#define MPU_ADDR 0x69

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("MPU6050 diagnostic");

  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  byte error = Wire.endTransmission();

  Serial.print("Wake-up write result: ");
  Serial.println(error);

  delay(100);

  // Read WHO_AM_I register
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x75);
  error = Wire.endTransmission(false);

  Serial.print("Register request result: ");
  Serial.println(error);

  Wire.requestFrom(MPU_ADDR, 1);

  if (Wire.available()) {
    byte whoAmI = Wire.read();

    Serial.print("WHO_AM_I = 0x");
    Serial.println(whoAmI, HEX);
  } else {
    Serial.println("No data received!");
  }
}

void loop() {
}