#include <Wire.h>
#include <MPU6050.h>
#include <BluetoothSerial.h> // Add the Bluetooth library

BluetoothSerial SerialBT; // Create an instance of BluetoothSerial

MPU6050 mpu; // Communication with the sensor

#define SENDING_INTERVAL 1000 
#define SENSOR_READ_INTERVAL 50
unsigned long prevSensoredTime = 0;
unsigned long curSensoredTime = 0;

#define ACCEL_BUFFER_COUNT 125
byte aAccelBuffer[ACCEL_BUFFER_COUNT];
int iAccelIndex = 2; 

void setup() {
  Serial.begin(921600);
  Wire.begin();
  mpu.initialize();
  SerialBT.begin("ESP32"); // Start Bluetooth with the name "ESP32"
  initBuffer();
}

void loop() {
  curSensoredTime = millis();

  if (curSensoredTime - prevSensoredTime > SENSOR_READ_INTERVAL) {
    readFromSensor();
    prevSensoredTime = curSensoredTime;

    if (iAccelIndex >= ACCEL_BUFFER_COUNT - 3) {
      sendToBluetooth(); // Changed the function name
      initBuffer();
      Serial.println("------------- Send 20 accel data to Bluetooth");
    }
  }
}

void sendToBluetooth() {
  SerialBT.write((uint8_t*)"accel", 5); // Convert "accel" to an array of bytes
  SerialBT.write(aAccelBuffer, ACCEL_BUFFER_COUNT);
}

void readFromSensor() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  if (iAccelIndex < ACCEL_BUFFER_COUNT && iAccelIndex > 1) {
    aAccelBuffer[iAccelIndex++] = highByte(ax);
    aAccelBuffer[iAccelIndex++] = lowByte(ax);
    aAccelBuffer[iAccelIndex++] = highByte(ay);
    aAccelBuffer[iAccelIndex++] = lowByte(ay);
    aAccelBuffer[iAccelIndex++] = highByte(az);
    aAccelBuffer[iAccelIndex++] = lowByte(az);
  }
}

void initBuffer() {
  iAccelIndex = 2;
  for (int i = iAccelIndex; i < ACCEL_BUFFER_COUNT; i++) {
    aAccelBuffer[i] = 0x00;
  }
  aAccelBuffer[0] = 0xfe;
  aAccelBuffer[1] = 0xfd;
  aAccelBuffer[122] = 0xfd;
  aAccelBuffer[123] = 0xfe;
  aAccelBuffer[124] = 0x00;
}

