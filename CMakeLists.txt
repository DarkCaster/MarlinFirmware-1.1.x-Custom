cmake_minimum_required(VERSION 3.0)

# overrides for Arduino Mega 2560 board
set(ARDUINO_AVRDUDE_BAUD "115200" CACHE STRING "avrdude baud-rate (for optiboot)")
set(ARDUINO_AVRDUDE_MCU "atmega2560" CACHE STRING "avrdude mcu")
set(ARDUINO_MCU "atmega2560" CACHE STRING "-mmcu define for avr-gcc compiler")
set(ARDUINO_F_CPU "16000000L" CACHE STRING "-DF_CPU define")
set(ARDUINO_MODEL "ARDUINO_AVR_MEGA2560" CACHE STRING "-DARDUINO_* define")
set(ARDUINO_VARIANT "mega" CACHE STRING "arduino variant")
set(ARDUINO_VER "10807" CACHE STRING "arduino version")

set(CMAKE_TOOLCHAIN_FILE ArduinoCmakeBuilder/arduino-avr-toolchain.cmake)

if((${CMAKE_GENERATOR} STREQUAL "NMake Makefiles JOM") AND (NOT EXISTS "${CMAKE_MAKE_PROGRAM}"))
    set(CMAKE_MAKE_PROGRAM "${CMAKE_SOURCE_DIR}/Jom_Win32/jom.exe" CACHE INTERNAL "CMAKE_MAKE_PROGRAM")
endif()

project(MarlinFirmware C CXX ASM)

include(ArduinoCmakeBuilder/arduino-build-helper.cmake)

set_avr_compiler_flags()

add_arduino_library(LiquidCrystal ${CMAKE_SOURCE_DIR})
add_arduino_library(U8glib ${CMAKE_SOURCE_DIR})

# fix warnings when compiling U8glib
target_compile_options(U8glib PRIVATE "-Wno-unused-parameter" "-Wno-sign-compare" "$<$<COMPILE_LANGUAGE:C>:-Wno-old-style-declaration>")

add_arduino_sketch(Marlin ${CMAKE_SOURCE_DIR} U8glib)
add_arduino_post_target(Marlin)
add_arduino_upload_target(Marlin)
