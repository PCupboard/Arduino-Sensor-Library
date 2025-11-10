//
// Created by Poteten on 10.11.2025.
//

#include <Arduino.h>
#include <OLED_display.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
//extern HardwareSerial Serial;

OLED_display::OLED_display() :

    display(SCREEN_WIDTH, SCREEN_WIDTH, &Wire, OLED_RESET) {
}

bool OLED_display::begin() {

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        // 0x3C er standard I2C-adresse
        Serial.println(F("Could not find a OLED screen with the I2C protocol"));
        while (true);
    }
    Serial.println(F("OLED is operational!"));
    display.setTextColor(SSD1306_WHITE);
    display.clearDisplay();
    return true;
}

void OLED_display::clear()
{
    display.clearDisplay();
    display.setCursor(0, 0);
    delay(100);
}

