//
// Created by Poteten on 14.11.2025.
//

#include <RFID_reader.h>
#include <SPI.h>

RFID_reader::RFID_reader() :
    MFRC522(SS_PIN, RST_PIN),
        cardPresent(false),
        uidBuffer{},
        uidLength(0) {
}

void RFID_reader::begin() {
    SPI.begin();
    PCD_Init();
    Serial.println("RFID-leser initialisert. Klar for kort.");
}

void RFID_reader::read() {
    if (!PICC_IsNewCardPresent() || !PICC_ReadCardSerial()) {
        cardPresent = false;
    }
    else {
        cardPresent = true;
        uidLength = uid.size;
        memcpy(uidBuffer, uid.uidByte, uidLength);

        PICC_HaltA();
    }
}

String RFID_reader::getUID() const
{
    if (!cardPresent || uid.size <= 0) {
        return {"Ingen UID tilgjengelig"};
    }

    String uidString;
    for (byte byte = 0; byte < uid.size; ++byte) {
        if (byte > 0) {
            uidString += ":";
        }
        if (uid.uidByte[byte] < 0x10) {
            uidString += "0";
        }
        uidString += String(uid.uidByte[byte], HEX);
    }
    uidString.toUpperCase();
    return uidString;
}

