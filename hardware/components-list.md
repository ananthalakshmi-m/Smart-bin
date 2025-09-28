# Components List – Smart IoT Dustbin

This document lists all the hardware components used in the Smart IoT Dustbin project along with their quantities and descriptions.

| Component Name        | Quantity | Description |
|----------------------|----------|-------------|
| Arduino Uno R3       | 1        | Microcontroller board used to process sensor data and control the system. |
| Ultrasonic Sensor (HC-SR04) | 1 | Measures the distance to the waste level inside the bin to calculate fill percentage. |
| Buzzer               | 1        | Provides an audible alert when the bin reaches 80% capacity. |
| LCD Display 16x2 (I2C, MCP23008-based) | 1 | Displays the real-time waste level percentage for local monitoring. |

## Notes:

- The Arduino Uno acts as the brain of the system, receiving data from the ultrasonic sensor and controlling the buzzer and LCD.  
- The Ultrasonic Sensor has 4 pins: VCC, GND, Trig, and Echo.  
- The Buzzer can be connected to a digital pin on the Arduino.  
- The LCD Display uses I2C communication (SDA, SCL, VCC, GND). Ensure the correct I2C address (usually `0x27`) is used in code.  
