//
// Created by PCUpboard on 10.11.2025.
// Header file for OLED screen.
//
#ifndef ARDUINO_SENSOR_LIBRARY_OLED_TEMPLATE_H
#define ARDUINO_SENSOR_LIBRARY_OLED_TEMPLATE_H

#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_ADDR     0x3C // I2C address
#define OLED_RESET    (-1)
extern HardwareSerial Serial;
extern Adafruit_SSD1306 display();

class OLED_display : public Adafruit_SSD1306 {
    public:
        OLED_display();
        void initializeDisplay();
        static void updateDisplay();
        void drawOnScreen(const String& printText, int printValue);
        void printLine(signed int line, const String& text, signed int textSize);
        void clear();
        int colorWhite = SSD1306_WHITE;

        private:
            int lineHeight{};
            int y{};
};



#endif //ARDUINO_SENSOR_LIBRARY_OLED_TEMPLATE_H