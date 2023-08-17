# Smartbandesp32Mpu6050
Smart band to measure steps and calories using an ESP32 and Mpu6050
# ESP32 MPU6050 Bluetooth Data Transfer

This project demonstrates how to collect accelerometer data from an MPU6050 sensor using an ESP32 board and send it to a mobile device over Bluetooth using the BluetoothSerial library. The data can be visualized using the RetroBand mobile application.

## Overview

The code reads accelerometer data from the MPU6050 sensor, which combines an accelerometer and a gyroscope. The data collected is the X, Y, and Z-axis acceleration values. The code samples the sensor at a specific interval and stores the data in a buffer.

The ESP32 board connects to a mobile device using Bluetooth. It advertises itself as "ESP32" for pairing. Once the Bluetooth connection is established, the code sends the stored accelerometer data to the mobile device.

## How to Use

1. Upload the code to your ESP32 board using the Arduino IDE.

2. Pair your mobile device with the ESP32 over Bluetooth. The ESP32 will be visible as "ESP32" for pairing.

3. Download and install the RetroBand mobile application from [RetroBand GitHub](https://github.com/godstale/retroband).

4. Open the RetroBand app and connect to the paired ESP32 device. You should be able to view the collected accelerometer data, including step counts and estimated calories burned based on weight.

## Dependencies

- Wire library: Used for I2C communication with the MPU6050 sensor.
- MPU6050 library: Provides functions to interact with the MPU6050 sensor.
- BluetoothSerial library: Enables Bluetooth communication on the ESP32.

## Hardware Setup

- Connect VCC to 3.3V, GND to ground, SCL to D21, and SDA to D22.

## Acknowledgements

Special thanks to the [RetroBand project](https://github.com/godstale/retroband) for providing the mobile application for data visualization.

## Notes

- Make sure to install the required libraries before uploading the code to your ESP32 board.

- Adjust the sending and reading intervals according to your requirements.

- This code is for educational purposes and can be extended for various applications involving collecting sensor data and sending it over Bluetooth.

