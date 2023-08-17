# Smartbandesp32Mpu6050
Smart band to measure steps and calories using an ESP32 and Mpu6050
# ESP32 MPU6050 Bluetooth Data Transfer

This project demonstrates how to collect accelerometer data from an MPU6050 sensor using an ESP32 board and send it to a mobile device over Bluetooth using the BluetoothSerial library.

## Overview

The code reads accelerometer data from the MPU6050 sensor, which is a device that combines an accelerometer and a gyroscope. The data collected is the X, Y, and Z-axis acceleration values. The code samples the sensor at a specific interval and stores the data in a buffer.

The ESP32 board is connected to a mobile device using Bluetooth. It advertises itself as "ESP32" for pairing. Once the Bluetooth connection is established, the code sends the stored accelerometer data to the mobile device.

## Code Structure

- `setup()`: Initializes the serial communication, the MPU6050 sensor, and Bluetooth using the BluetoothSerial library. Also, initializes the data buffer.

- `loop()`: Repeatedly reads accelerometer data from the sensor, stores it in the buffer, and checks if the buffer is full. If the buffer is full, it sends the data over Bluetooth and initializes the buffer again.

- `sendToBluetooth()`: Sends the stored accelerometer data over Bluetooth. It sends the string "accel" followed by the data buffer.

- `readFromSensor()`: Reads accelerometer data from the MPU6050 sensor and stores it in the data buffer.

- `initBuffer()`: Initializes the data buffer with appropriate markers.

## How to Use

1. Upload the code to your ESP32 board using the Arduino IDE.

2. Pair your mobile device with the ESP32 over Bluetooth. The ESP32 will be visible as "ESP32" for pairing.

3. Once the connection is established, the ESP32 will start sending accelerometer data to your mobile device.

## Dependencies

- Wire library: Used for I2C communication with the MPU6050 sensor.
- MPU6050 library: Provides functions to interact with the MPU6050 sensor.
- BluetoothSerial library: Enables Bluetooth communication on the ESP32.

## Hardware Setup

- Connect VCC to 3.3V, GND to ground, SCL to D21, and SDA to D22.

## Notes

- Make sure to install the required libraries before uploading the code to your ESP32 board.

- Adjust the sending and reading intervals according to your requirements.

- This code is for educational purposes and can be extended for various applications that involve collecting sensor data and sending it over Bluetooth.
