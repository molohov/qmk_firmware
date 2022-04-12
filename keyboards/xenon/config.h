/*
Copyright 2020 Kyrre Havik Eriksen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3404
#define DEVICE_VER      0x0001
#define PRODUCT         Xenon
<<<<<<< HEAD
#define DESCRIPTION     60% columnar staggered keyboard
=======
>>>>>>> upstream/master

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// wiring
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 }

<<<<<<< HEAD
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B6 }
#define ENCODERS_PAD_A_RIGHT { B5 }
#define ENCODERS_PAD_B_RIGHT { B6 }
#define ENCODER_DIRECTION_FLIP
=======
#define ENCODERS_PAD_A { B6 }
#define ENCODERS_PAD_B { B5 }
>>>>>>> upstream/master

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
<<<<<<< HEAD
=======

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X32
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
>>>>>>> upstream/master
