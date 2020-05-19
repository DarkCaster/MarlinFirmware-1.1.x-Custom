cmake_minimum_required(VERSION 3.0)

# overrides for Anet board v1.0
set(ARDUINO_AVRDUDE_BAUD "250000" CACHE STRING "avrdude baud-rate (for optiboot)")
set(ARDUINO_AVRDUDE_MCU "atmega1284p" CACHE STRING "avrdude mcu")
set(ARDUINO_MCU "atmega1284p" CACHE STRING "-mmcu define for avr-gcc compiler")
set(ARDUINO_F_CPU "16000000L" CACHE STRING "-DF_CPU define")
set(ARDUINO_MODEL "ARDUINO_AVR_SANGUINO" CACHE STRING "-DARDUINO_* define")
set(ARDUINO_VARIANT "sanguino" CACHE STRING "arduino variant")

set(CMAKE_TOOLCHAIN_FILE ArduinoCmakeBuilder/arduino-avr-toolchain.cmake)

if((${CMAKE_GENERATOR} STREQUAL "NMake Makefiles JOM") AND (NOT EXISTS "${CMAKE_MAKE_PROGRAM}"))
    set(CMAKE_MAKE_PROGRAM "${CMAKE_SOURCE_DIR}/Jom_Win32/jom.exe" CACHE INTERNAL "CMAKE_MAKE_PROGRAM")
endif()

project(MarlinFirmware C CXX ASM)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	file(TO_CMAKE_PATH "$ENV{LOCALAPPDATA}" LOCALAPPDATA)
	set(ARDUINO_VARIANTS_SEARCH_PATH "${LOCALAPPDATA}/Arduino*/packages/custom_boards/hardware/${ARDUINO_ARCH}/*/variants" CACHE PATH "Custom arduino-variant search path")
elseif(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
	file(TO_CMAKE_PATH "$ENV{HOME}" HOME)
	set(ARDUINO_VARIANTS_SEARCH_PATH "${HOME}/.arduino*/packages/custom_boards/hardware/${ARDUINO_ARCH}/*/variants" CACHE PATH "Custom arduino-variant search path")
endif()

include(ArduinoCmakeBuilder/arduino-build-helper.cmake)

set_avr_compiler_flags()

add_arduino_library(U8glib ${CMAKE_SOURCE_DIR})

# fix warnings when compiling U8glib
target_compile_options(U8glib PRIVATE "-Wno-unused-parameter" "-Wno-sign-compare" "$<$<COMPILE_LANGUAGE:C>:-Wno-old-style-declaration>")

add_arduino_sketch(Marlin ${CMAKE_SOURCE_DIR} U8glib)
target_compile_options(Marlin PRIVATE "-Wno-expansion-to-defined" "-Wno-implicit-fallthrough")
add_arduino_post_target(Marlin)
add_arduino_upload_target(Marlin)
