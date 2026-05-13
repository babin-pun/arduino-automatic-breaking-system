# arduino-automatic-breaking-system
Arduino based automatic breaking prototype using ultrasonic sensor and motor control.

Arduino Automatic Breaking System

This project is a low-speed automatic breaking prototype built by using Arduino UNO.

The vehicle is continuously scans for obstacles using an HC-SR04 ultrasonic sensor and automatically stops to avoid collision.

Features:
- Automatic obstacle detection
- low-speed motor control
- automatic stopping
- buzzer alert system

Components Used:
- Arduino UNO
- L298N Motor Driver
- HC-SR04 Ultrasonic Sensor
- 4WD Chassis with DC motors
- Buzzer Module
- Lithium-ion Battery Pack

How it works:
The ultrasonic sensor continuously measures distance infront of the vehicle. If an obstacle is detected within a predefined distance:
- The vehicle stops
- The buzzer activates
If the path is clear, the vehicle continues moving forward.
