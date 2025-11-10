cmake_minimum_required(VERSION 4.0)

set(HOME_DIR $ENV{USERPROFILE})

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER "${HOME_DIR}/AppData/Local/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc.exe")
set(CMAKE_CXX_COMPILER "${HOME_DIR}/AppData/Local/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++.exe")

project(Arduino_Sensor_Library)

set(CMAKE_CXX_STANDARD 17)

# Defining path variables for Arduino install
set(ARDUINO_PATH "${HOME_DIR}/AppData/Local/Arduino15")
set(ARDUINO_AVR_PATH "${ARDUINO_PATH}/packages/arduino/hardware/avr/1.8.6")
set(ARDUINO_VARIANTS_PATH "${ARDUINO_AVR_PATH}/variants/standard")
set(ARDUINO_CORES_PATH "${ARDUINO_AVR_PATH}/cores/arduino")
set(ARDUINO_CORE_LIBRARIES_PATH "${ARDUINO_AVR_PATH}/libraries")
set(SPI_PATH "${ARDUINO_CORE_LIBRARIES_PATH}/SPI/src")

# Defining path variables for libraries
set(WIRE_PATH "${ARDUINO_CORE_LIBRARIES_PATH}/Wire/src")
set(BUSIO_PATH "libraries/Adafruit_BusIO")
set(SSD1306_PATH "libraries/Adafruit_SSD1306")
set(GFX_PATH "libraries/Adafruit_GFX_Library")

include_directories(
        "${WIRE_PATH}"
        "${SPI_PATH}"
        "${BUSIO_PATH}"
        "${SSD1306_PATH}"
        "${GFX_PATH}"

        "${ARDUINO_CORES_PATH}"
        "${ARDUINO_CORES_PATH}"
        "${ARDUINO_VARIANTS_PATH}"

        "templates/OLED_screen_template"
        )

add_executable(Arduino_Sensor_Library
        templates/OLED_screen_template/OLED_display.cpp
        )

target_compile_definitions(Arduino_Sensor_Library PRIVATE
        ARDUINO=10805
        ARDUINO_AVR_UNO
        ARDUINO_ARCH_AVR
        F_CPU=16000000L
)
