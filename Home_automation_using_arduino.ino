#include <SoftwareSerial.h>

#define RELAY1 2
#define RELAY2 3
#define RELAY3 4


int TX=10;
int RX=11;

SoftwareSerial  bluetooth (TX,RX);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);

  // All relays OFF at start (HIGH for low-triggered)
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);

  Serial.println("Serial Relay Controller Ready");
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();

    if (data == 'U') {
      digitalWrite(RELAY1, LOW);  // ON
      Serial.println("Relay 1 ON");
    }
    else if (data == 'u') {
      digitalWrite(RELAY1, HIGH); // OFF
      Serial.println("Relay 1 OFF");
    }
    else if (data == 'S') {
      digitalWrite(RELAY2, LOW);  // ON
      Serial.println("Relay 2 ON");
    }
    else if (data == 's') {
      digitalWrite(RELAY2, HIGH); // OFF
      Serial.println("Relay 2 OFF");
    }
    else if (data == 'M') {
      digitalWrite(RELAY3, LOW);  // ON
      Serial.println("Relay 3 ON");
    }
    else if (data == 'm') {
      digitalWrite(RELAY3, HIGH); // OFF
      Serial.println("Relay 3 OFF");
    }
    else if (data == 'A') {
      digitalWrite(RELAY1, LOW);
      digitalWrite(RELAY2, LOW);
      digitalWrite(RELAY3, LOW);
      Serial.println("All relays ON");
    }
    else if (data == 'a') {
      digitalWrite(RELAY1, HIGH);
      digitalWrite(RELAY2, HIGH);
      digitalWrite(RELAY3, HIGH);
      Serial.println("All relays OFF");
    }
    else {
      Serial.println("Invalid command");
    }
  }

// Controlling with android app
if (bluetooth.available()) {
    char data = bluetooth.read();

    if (data == 'U') {
      digitalWrite(RELAY1, LOW);  // ON
    }
    else if (data == 'u') {
      digitalWrite(RELAY1, HIGH); // OFF
    }
    else if (data == 'S') {
      digitalWrite(RELAY2, LOW);  // ON
    }
    else if (data == 's') {
      digitalWrite(RELAY2, HIGH); // OFF
    }
    else if (data == 'M') {
      digitalWrite(RELAY3, LOW);  // ON
    }
    else if (data == 'm') {
      digitalWrite(RELAY3, HIGH); // OFF
    }
    else if (data == 'A') {
      digitalWrite(RELAY1, LOW);
      digitalWrite(RELAY2, LOW);
      digitalWrite(RELAY3, LOW);
    }
    else if (data == 'a') {
      digitalWrite(RELAY1, HIGH);
      digitalWrite(RELAY2, HIGH);
      digitalWrite(RELAY3, HIGH);
    }
  }

}
