/* Copyright 2021 Carlos Martins
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  // 12 13 22 23 32 33       33 32 23 22 13 12  0
  //    02    03    04       04    03    02
  // 11 14 21 24 31 34       34 31 24 21 14 11  1
  //                01       01
  // 10 15 20 25 30 35       35 30 25 20 15 10  2
  //
  // 09 16 19 26 29 36       36 29 26 19 16 09  3
  //
  //     08 17 18 27 28     28 27 18 17 08      4
  //    07    06    05       05    06    07

led_config_t g_led_config = {
    {
        {  4,  5,  14,  15,  24,  25 },
        {  3,  6,  13,  16,  23,  26 },
        {  2,  7,  12,  17,  22,  27},
        {  1,   8,  11,  18,  21,  28},
        {  0,   9,  10,  19,  20,  NO_LED },
        { 36+ 4, 36+  5, 36+  14, 36+  15, 36+  24,  36+ 25 },
        { 36+ 3, 36+  6, 36+  13, 36+  16, 36+  23,  36+ 26 },
        { 36+ 2, 36+  7, 36+  12, 36+  17, 36+  22,  36+ 27},
        { 36+ 1, 36+   8,36+   11,36+   18,36+   21, 36+  28},
        { 36+ 0, 36+   9,36+   10,36+   19,36+   20, NO_LED },

        // {  11,  12,  21,  22,  31,  32 },
        // {  10,  13,  20,  23,  30,  33 },
        // {  9,   14,  19,  24,  29,  34},
        // {  8,   15,  18,  25,  28,  35},
        // {  7,   16,  17,  26,  27,  NO_LED },
        // {  47,  48,  57,  58,  67,  68},
        // {  46,  49,  56,  59,  66,  69},
        // {  45,  50,  55,  60,  65,  70},
        // {  44,  51,  54,  61,  64,  71},
        // {  43,  52,  53,  62,  63,  NO_LED }
    },
    {
       // Left side underglow
        {96, 40}, {16, 20}, {48, 10}, {80, 18}, {88, 60}, {56, 57}, {24,60},
        // Left side Matrix
        {32, 57-7}, { 0, 48-7}, { 0, 36-7}, { 0, 24-7}, { 0, 12-7},
        {16, 12-7}, {16, 24-7}, {16, 36-7}, {16, 48-7}, {48, 55-7},
        {64, 57-7}, {32, 45-7}, {32, 33-7}, {32, 21-7}, {32,  9-7},
        {48,  7-7}, {48, 19-7}, {48, 31-7}, {48, 43-7}, {80, 59-7},
        {96, 64-7}, {64, 45-7}, {64, 33-7}, {64, 21-7}, {64,  9-7},
        {80, 10-7}, {80, 22-7}, {80, 34-7}, {80, 47-7},


      // Right side underglow
        {128, 40}, {208, 20}, {176, 10}, {144, 18}, {136, 60}, {168, 57}, {200,60},
        // Right side Matrix
        {192, 57-7}, {224, 48-7}, {224, 36-7}, {224, 24-7}, {224, 12-7},
        {208, 12-7}, {208, 24-7}, {208, 36-7}, {208, 48-7}, {176, 55-7},
        {160, 57-7}, {192, 45-7}, {192, 33-7}, {192, 21-7}, {192,  9-7},
        {176,  7-7}, {176, 19-7}, {176, 31-7}, {176, 43-7}, {144, 59-7},
        {128, 64-7}, {160, 45-7}, {160, 33-7}, {160, 21-7}, {160,  9-7},
        {144, 10-7}, {144, 22-7}, {144, 34-7}, {144, 47-7},
    },
    {
        LED_FLAG_NONE, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_NONE, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};
#endif
