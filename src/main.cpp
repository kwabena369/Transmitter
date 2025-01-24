#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(2, 3);  // CE, CSN pins
const byte address[6] = "00001";

// Joystick Pins
const int X_Input = A0;
const int Y_Input = A1;

// Thresholds
const int Left_threshold = 400;
const int Right_threshold = 800;
const int Up_threshold = 400;
const int Down_threshold = 800;

// LED Pin
const int LED_Pin = 9;

struct ControlData {
  byte moveDirection;
};

void setup() {
  Serial.begin(9600);
  pinMode(LED_Pin, OUTPUT);

  // Check if radio initializes properly
  if (!radio.begin()) {
    Serial.println("Radio hardware is not responding.");
    // Blink LED to indicate error
    while (1) {
      digitalWrite(LED_Pin, HIGH);
      delay(500);
      digitalWrite(LED_Pin, LOW);
      delay(500);
    }
  }

  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  Serial.println("Radio hardware is ready.");

  // Turn on the LED to indicate the module is ready
  digitalWrite(LED_Pin, HIGH);
}

void loop() {
  int X_value = analogRead(X_Input);
  int Y_value = analogRead(Y_Input);

  ControlData data;

  if (Y_value < Up_threshold) {
    data.moveDirection = 1;  // Forward
  } else if (Y_value > Down_threshold) {
    data.moveDirection = 2;  // Backward
  } else if (X_value < Left_threshold) {
    data.moveDirection = 3;  // Left
  } else if (X_value > Right_threshold) {
    data.moveDirection = 4;  // Right
  } else {
    data.moveDirection = 0;  // Stop
  }

  // Send the data to the receiver
  if (!radio.write(&data, sizeof(ControlData))) {
    Serial.println("Transmission failed.");
    // Blink LED to indicate transmission failure
    digitalWrite(LED_Pin, LOW);
    delay(100);
    digitalWrite(LED_Pin, HIGH);
    delay(100);
  }
}
