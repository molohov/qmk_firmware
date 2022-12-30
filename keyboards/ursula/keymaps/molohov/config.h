#pragma once

#define SPLIT_USB_DETECT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { 4U, 5U, 6U, 7U, 8U }

#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { 29U, 28U, 27U, 26U, 18U, 20U, 19U }
#undef ENCODERS_PAD_A
#define ENCODERS_PAD_A { 9U }
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_B { 10U }

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN 1U

#undef RBG_DI_PIN

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
