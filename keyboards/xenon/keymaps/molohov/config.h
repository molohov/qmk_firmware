/* Copyright 2020 Kyrre Havik Eriksen
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

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X32
#endif
#define MASTER_RIGHT

// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// #undef MATRIX_ROW_PINS
// #define MATRIX_ROW_PINS { 4U, 5U, 6U, 7U, 8U }

// #undef MATRIX_COL_PINS
// #define MATRIX_COL_PINS { 19U, 20U, 18U, 26U, 27U, 28U, 29U }
// #undef ENCODERS_PAD_A
// #define ENCODERS_PAD_A { 10U }
// #undef ENCODERS_PAD_B
// #define ENCODERS_PAD_B { 9U }

// #undef SOFT_SERIAL_PIN
// #define SOFT_SERIAL_PIN 1U

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
