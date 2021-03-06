#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X32
#endif

#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 200
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 4
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_STATIC_LIGHT
// #define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_BREATHE_MAX 125
// #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.7
#define RGBLIGHT_SLEEP
#define MASTER_RIGHT

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
