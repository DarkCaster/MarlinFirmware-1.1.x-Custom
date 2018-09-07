/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

// Noname crappy 100K thermistor that I use for hotend
const short temptable_98[][2] PROGMEM = {
  // safety
  { OV( 1), 500 },
  { OV( 10), 400 },
  // measurements ends here
  { OV( 34), 272 },
  { OV( 37), 268 },
  { OV( 39), 265 },
  { OV( 42), 260 },
  { OV( 45), 257 },
  { OV( 50), 250 },
  { OV( 55), 245 },
  { OV( 60), 240 },
  { OV( 65), 235 },
  { OV( 71), 231 },
  { OV( 78), 225 },
  { OV( 86), 220 },
  { OV( 94), 215 },
  { OV( 103), 210 },
  { OV( 114), 205 },
  { OV( 125), 200 },
  { OV( 137), 195 },
  { OV( 150), 190 },
  { OV( 165), 185 },
  { OV( 181), 180 },
  { OV( 199), 175 },
  { OV( 217), 170 },
  { OV( 238), 165 },
  { OV( 260), 160 },
  { OV( 281), 155 },
  { OV( 311), 150 },
  { OV( 365), 140 },
  { OV( 427), 130 },
  { OV( 491), 120 },
  { OV( 558), 110 },
  { OV( 629), 100 },
  { OV( 699),  90 },
  { OV( 762),  80 },
  { OV( 820),  70 },
  { OV( 871),  60 },
  { OV( 912),  50 },
  { OV( 944),  40 },
  { OV( 968),  30 },
  // measurements begins here, values below - inaccurate
  { OV( 981),  23 },
  { OV( 991),  17 },
  { OV(1001),   9 },
  { OV(1021), -27 }
};
