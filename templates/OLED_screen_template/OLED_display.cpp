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

void OLED_display::printLine(const signed int line, const String& text, const signed int textSize = 1) {
    lineHeight = 8 * textSize;   // base font height * size
    y = line * lineHeight;
    setTextSize(textSize);
    setCursor(0, y);
    print(text);
    // no display() here -> call show() after drawing everything
}

void OLED_display::drawOnScreen(const String& printText, const int printValue) {
    print(printText);
    print(": ");
    println(printValue);
}

void OLED_display::updateDisplay()
{
    display();
}


