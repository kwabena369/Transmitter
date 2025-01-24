# Joystick Controlled Robot with nRF24L01

This project allows you to control a minibot using a joystick and an nRF24L01 wireless module. The joystick's X and Y axis inputs are used to send directional commands, while the nRF24L01 handles communication between the controller and the robot.

## Hardware Requirements

- **nRF24L01 Module** (for wireless communication)
- **Joystick Module** (to send movement inputs)
- **Arduino (any compatible board)**
- **LED (optional, for status indication)**
- **Wires for connections**

## Wiring

- **Joystick X-Axis** → A0 (Analog pin)
- **Joystick Y-Axis** → A1 (Analog pin)
- **nRF24L01 CE Pin** → Pin 2
- **nRF24L01 CSN Pin** → Pin 3
- **LED Pin** → Pin 9 (optional, for status)

## Code Overview

This code is designed to read the joystick's X and Y axis values and send commands to the receiver using the nRF24L01 module. Depending on the position of the joystick, the robot will move forward, backward, left, right, or stop.

### Control Logic

- **Forward**: When the Y-axis value is below a certain threshold.
- **Backward**: When the Y-axis value is above a certain threshold.
- **Left**: When the X-axis value is below a threshold.
- **Right**: When the X-axis value is above a threshold.
- **Stop**: When the joystick is within a neutral range.

### LED Indicator

An LED is connected to pin 9, and it is used to indicate the following:

- **Solid LED**: Indicates that the system is ready and communicating.
- **Flashing LED**: Indicates an error or communication failure.

## Threshold Values

- **Left Threshold**: 400
- **Right Threshold**: 800
- **Up Threshold**: 400
- **Down Threshold**: 800

These values determine the movement of the robot based on joystick input.

## How to Use

1. Connect your joystick and nRF24L01 modules to the Arduino as described in the wiring section.
2. Upload the code to your Arduino.
3. Once powered on, the system will initialize, and the LED will turn on to indicate that everything is working.
4. Move the joystick to control the robot's movement:
   - **Up/Down** for forward/backward movement
   - **Left/Right** for left/right movement
   - Center position will stop the robot.

## Troubleshooting

- If you see the LED blinking continuously, there might be a communication issue. Ensure that the nRF24L01 module is properly connected and powered.
- If the joystick isn't working as expected, check the analog input pins for proper wiring.

## Future Improvements

- Add more control features, such as speed control or additional sensors.
- Implement receiver code to handle movement commands and drive the robot accordingly.
