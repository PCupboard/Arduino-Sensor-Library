//
// Created by Poteten on 14.11.2025.
//

#ifndef ARDUINO_SENSOR_LIBRARY_RFID_RC522_TEMPLATE_H
#define ARDUINO_SENSOR_LIBRARY_RFID_RC522_TEMPLATE_H

#include <Arduino.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

extern HardwareSerial Serial;

class RFID_reader : MFRC522 {
public:
    RFID_reader();
    void begin();
    void read();

    [[nodiscard]] bool cardDetected() const {
        return cardPresent;
    }
    [[nodiscard]] String getUID() const;
    bool getUIDBytes(byte* destination, byte maxLength, byte& outLength) const;

private:
    bool cardPresent;
    byte uidBuffer[10];   // plass til UID (opptil 10 byte)
    byte uidLength;        // faktisk lengde på UID
};

#endif //ARDUINO_SENSOR_LIBRARY_RFID_RC522_TEMPLATE_H