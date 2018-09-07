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
  { OV( 30), 270 },
  { OV( 35), 260 },
  { OV( 42), 250 },
  { OV( 50), 240 },
  { OV( 60), 230 },
  { OV( 72), 220 },
  { OV( 88), 210 },
  { OV( 108), 200 },
  { OV( 131), 190 },
  { OV( 160), 180 },
  { OV( 194), 170 },
  { OV( 234), 160 },
  { OV( 281), 150 },
  { OV( 427), 125 },
  { OV( 608), 100 },
  { OV( 780),  75 },
  { OV( 905),  50 },
  // measurements begins here, values below - inaccurate
  { OV( 981),  23 },
  { OV( 991),  17 },
  { OV(1001),   9 },
  { OV(1021), -27 }
};
