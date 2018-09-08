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

// Noname crappy 100K thermistor that I use for heated bed
const short temptable_99[][2] PROGMEM = {
  //safety
  { OV(   1), 500 },
  { OV( 400), 400 },
  { OV( 426), 125 },
  //measurements ends here
  { OV( 448), 120 },
  { OV( 484), 115 },
  { OV( 520), 110 },
  { OV( 556), 105 },
  { OV( 592), 100 },
  { OV( 628),  95 },
  { OV( 662),  90 },
  { OV( 697),  85 },
  { OV( 733),  80 },
  { OV( 765),  75 },
  { OV( 798),  70 },
  { OV( 825),  65 },
  { OV( 851),  60 },
  { OV( 876),  55 },
  { OV( 900),  50 },
  { OV( 919),  45 },
  { OV( 938),  40 },
  { OV( 955),  35 },
  { OV( 967),  30 },
  { OV( 979),  25 },
  //measurements starts here
  { OV( 991),  17 },
  { OV(1001),   9 },
  { OV(1021), -27 }
};
