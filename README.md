# Arduino Car Control with Ultrasonic Sensors

This repository contains an Arduino project for a simple car control system with two ultrasonic sensors and motors. The code is designed for the ATmega328P microcontroller and can be simulated using Proteus.

## Features
- Control a car with two motors using an Arduino.
- Utilizes ultrasonic sensors for distance measurement.
- Test the car's movements with predefined actions.

## Hardware Setup
1. Connect ultrasonic sensors to pins ECHO (receiving sound) and TRIG (sending sound).
   - Ultrasonic Sensor 1: ECHO - 0, TRIG - 1
   - Ultrasonic Sensor 2: ECHO - 2, TRIG - 3
2. Connect motors to pins ENA (speed control), IN1, IN2 (Motor A), ENB (speed control), IN3, IN4 (Motor B).
   - Motor A: ENA - 9, IN1 - 8, IN2 - 7
   - Motor B: ENB - 10, IN3 - 11, IN4 - 12

## Testing the Car
The car's mobility can be tested with predefined movements by adjusting the duration values in the `setup()` function.

## Usage
Feel free to explore and modify the provided Arduino code (`car_control.ino`) based on your specific hardware setup and requirements.

Happy coding!
