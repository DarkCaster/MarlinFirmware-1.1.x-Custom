cmake_minimum_required(VERSION 3.0)

# overrides for Arduino Mega 2560 board
set(ARDUINO_AVRDUDE_BAUD "250000")
set(ARDUINO_AVRDUDE_MCU "atmega2560")
set(ARDUINO_MCU "atmega2560")
set(ARDUINO_F_CPU "16000000L")
set(ARDUINO_MODEL "ARDUINO_AVR_MEGA2560")
set(ARDUINO_VARIANT "mega")
set(ARDUINO_VER "10807")

set(CMAKE_TOOLCHAIN_FILE ArduinoCmakeBuilder/arduino-avr-toolchain.cmake)

if((${CMAKE_GENERATOR} STREQUAL "NMake Makefiles JOM") AND (NOT EXISTS "${CMAKE_MAKE_PROGRAM}"))
    set(CMAKE_MAKE_PROGRAM "${CMAKE_SOURCE_DIR}/Jom_Win32/jom.exe" CACHE INTERNAL "CMAKE_MAKE_PROGRAM")
endif()

project(MarlinFirmware C CXX ASM)

include(ArduinoCmakeBuilder/arduino-build-helper.cmake)

add_arduino_library(EEPROM ${ARDUINO_LIBS_PATH})
add_arduino_library(SPI ${ARDUINO_LIBS_PATH})
add_arduino_library(Wire ${ARDUINO_LIBS_PATH})
#add_arduino_library(U8g2_Arduino ${CMAKE_SOURCE_DIR}/Libraries SPI Wire)

add_arduino_sketch(Marlin ${CMAKE_SOURCE_DIR} EEPROM SPI Wire)
add_arduino_post_target(Marlin)
add_arduino_upload_target(Marlin)
