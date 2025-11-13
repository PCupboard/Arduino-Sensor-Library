//
// Created by Poteten on 10.11.2025.
//

#include <Arduino.h>
#include <OLED_display.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

OLED_display::OLED_display() :

    Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {
}
/*
Adafruit_SSD1306 OLED_display::getDisplay() {
    return display;
}*/

void OLED_display::initializeDisplay() {

    if (!begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        // 0x3C er standard I2C-adresse
        Serial.println(F("Could not find a OLED screen with the I2C protocol"));
        while (true);
    }
    Wire.beginTransmission(OLED_ADDR);
    Serial.println(F("OLED is operational!"));
    setTextColor(colorWhite);
    setTextSize(1);
    clearDisplay();
}


void OLED_display::clear() {
    clearDisplay();
    setCursor(0, 0);
}

