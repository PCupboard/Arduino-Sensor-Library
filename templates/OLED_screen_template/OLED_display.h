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

class OLED_display {
    public:
        OLED_display();
        bool begin();
        void clear();
        Adafruit_SSD1306 display;

    private:
};



#endif //ARDUINO_SENSOR_LIBRARY_OLED_TEMPLATE_H