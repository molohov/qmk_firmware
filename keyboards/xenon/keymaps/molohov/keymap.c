#include "molohov.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
    KC_MPLY,    KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_J,       QK_BOOT,
    KC_Z,       KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,       KC_Q,
    KC_HOME,    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,                               KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,       KC_END,
                            KC_MPLY,    KC_ESC,     GUIDEL,     BSPSYM,     ENTSFT,     TABSFT,     SPCNAV,     KC_ESC,     ON_TODO,    PC_LOCK,
                                        _______,    PC_SCSH,    CW_TOGG,    KC_F5,      KC_UNDS,    TL_BENCH,   TL_SERVE,   TRT_LLM
    ),
    [_SYM_NUM] = LAYOUT(
    _______,    PC_EXIT,    _______,    PC_FIND,    PC_SALL,    SLKFPS,                             KC_MINS,    KC_7,       KC_8,       KC_9,       KC_PERC,    _______,
    _______,    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   SLKCPS,                             KC_SLSH,    KC_1,       KC_2,       KC_3,       KC_DOT,     KC_COMM,
    _______,    WIN_MIN,    SW_TAB,     SW_WIN,     PC_CLIP,    CW_TOGG,                            KC_COLN,    KC_4,       KC_5,       KC_6,       _______,    _______,
                            _______,    _______,    _______,    _______,    _______,    BSPSFT,     KC_UNDS,    KC_0,       _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NAV] = LAYOUT(
    _______,    VS_EDIT,    VIM_LIND,   VS_COMT,    VIM_RIND,   WINRUN,                             BY_FSWL,    BY_FSWR,    VIM_Q,      MD_TODO,    QK_BOOT,    _______,
    _______,    VS_TERM,    KC_LEFT,    KC_UP,      KC_RGHT,    SHIFTV,                             BY_RNWN,    BY_NWIN,    VIM_W,      GRVS,       CW_TOGG,    _______,
    _______,    KC_HOME,    PC_LWRD,    KC_DOWN,    PC_RWRD,    KC_END,                             BY_KSRV,    BY_HSPL,    VIM_X,      MD_CODE,    PY_IPDB,    _______,
                            _______,    VS_COMT,    PC_DLWD,    PC_BSWD,    SHIFTV,     _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    // [_QWERTY_GAME] = LAYOUT(
    // KC_ESC,     KC_T,       KC_Q,       KC_W,       KC_E,       KC_R,                               XXXXXXX,    KC_7,       KC_8,       KC_9,       XXXXXXX,    QK_BOOT,
    // KC_TAB,     KC_G,       KC_A,       KC_S,       KC_D,       KC_F,                               XXXXXXX,    KC_1,       KC_2,       KC_3,       XXXXXXX,    KC_J,
    // KC_LCTL,    KC_V,       KC_Z,       KC_X,       KC_C,       KC_V,                               XXXXXXX,    KC_4,       KC_5,       KC_6,       XXXXXXX,    KC_END,
    //                         XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_SPC,     KC_LSFT,    HANDSD,     CM_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //                                     KC_4,       KC_3,       KC_2,       KC_1,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
    // ),
    [_OTHER] = LAYOUT(
    KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,
    BY_FPNE,    ON_QUES,    ON_IMPT,    ON_TODO,    BY_FSWL,    PY_IPDB,                            BY_MVWL,    BY_MVWR,    BY_VSPL,    BY_DISF,    BY_KPNE,    _______,
    BY_CLYT,    BY_RNWN,    BY_NWIN,    BY_HSPL,    BY_FSWR,    BY_VSPL,                            _______,    _______,    _______,    _______,    _______,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//   uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
// #endif
//   return true;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

#ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
// //   if (!is_keyboard_master()) {
// //     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
// //   }
// return OLED_ROTATION_270;
// }

bool oled_task_user(void) {
    oled_clear();
    if (is_keyboard_master()) {
        oled_write_P(PSTR("-----\nXENON\n-----\n"), false);
        print_layers();
    } else {
        print_mods();
    }
    return true;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_HANDS_DOWN]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_SYM_NUM]      = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_NAV]          = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_QWERTY_GAME]  = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_OTHER]        = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif
