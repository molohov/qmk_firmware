#include "molohov.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
    KC_MPLY,    KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,       QK_BOOT,
    KC_Z,       KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,       KC_J,
    KC_HOME,    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,                               KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,       KC_END,
                            KC_MPLY,    KC_ESC,     GUIDEL,     BSPSYM,     ENTSFT,     TABSFT,     SPCNAV,     KC_ESC,     ON_TODO,    PC_LOCK,
                                        WINRUN,     PC_SCSH,    VS_COMT,    CW_TOGG,    KC_UNDS,    PC_BLTH,    PC_HDR,     KC_INS
    ),
    [_SYM_NUM] = LAYOUT(
    _______,    PC_EXIT,    PC_OBSD,    PC_FIND,    PC_SALL,    SLKFPS,                             KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_DLR,     _______,
    _______,    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   SLKCPS,                             KC_PERC,    KC_1,       KC_2,       KC_3,       KC_DOT,     _______,
    _______,    WIN_MIN,    SW_TAB,     SW_WIN,     PC_CLIP,    VIM_RSP,                            _______,    KC_4,       KC_5,       KC_6,       KC_COMM,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    KC_UNDS,    KC_0,       _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NAV] = LAYOUT(
    _______,    VS_EDIT,    VIM_LIND,   VS_COMT,    VIM_RIND,   KC_HOME,                            BY_DISF,    BY_MVWL,    BY_MVWR,    BY_VSPL,    BY_KPNE,    _______,
    _______,    VS_TERM,    KC_LEFT,    KC_UP,      KC_RGHT,    SHIFTV,                             BY_RNWN,    GRVS,       MD_TODO,    BY_HSPL,    BY_NWIN,    _______,
    _______,    VS_EGRP,    PC_LWRD,    KC_DOWN,    PC_RWRD,    KC_END,                             PY_IPDB,    BY_FSWL,    BY_FSWR,    BY_FPNE,    BY_CLYT,    _______,
                            _______,    VS_COMT,    PC_DLWD,    PC_BSWD,    SHIFTV,     _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_QWERTY_GAME] = LAYOUT(
    KC_ESC,     KC_T,       KC_Q,       KC_W,       KC_E,       KC_R,                               XXXXXXX,    KC_7,       KC_8,       KC_9,       XXXXXXX,    QK_BOOT,
    KC_TAB,     KC_G,       KC_A,       KC_S,       KC_D,       KC_F,                               XXXXXXX,    KC_1,       KC_2,       KC_3,       XXXXXXX,    KC_J,
    KC_LCTL,    KC_V,       KC_Z,       KC_X,       KC_C,       KC_V,                               XXXXXXX,    KC_4,       KC_5,       KC_6,       XXXXXXX,    KC_END,
                            XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_SPC,     KC_LSFT,    HANDSD,     CM_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                        KC_4,       KC_3,       KC_2,       KC_1,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
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

// bool is_alt_tab_active = false;
// uint16_t alt_tab_timer = 0;
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // left side
        switch(biton32(layer_state)) {
        case _HANDS_DOWN:
            // alt_tab_timer = timer_read();
            // if (!is_alt_tab_active) {
            //     is_alt_tab_active = true;
            //     register_code(KC_LALT);
            // }
            // volume rocker
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
            break;
        case _NAV:
            // same hand as toggle, hard to use
            break;
        case _SYM_NUM:
            // TODO
            break;
        }

    } else if (index == 1) {
        // right side
        switch(biton32(layer_state)) {
        case _HANDS_DOWN:
            // vscode tab switching
            if (clockwise) {
                tap_code16(VS_NEDT);
            } else {
                tap_code16(VS_PEDT);
            }
            break;
        case _NAV:
            // virtual desktop switching
            if (clockwise) {
                tap_code16(C(G(KC_RIGHT)));
            } else {
                tap_code16(C(G(KC_LEFT)));
            }
            break;
        case _SYM_NUM:
            // same hand as layer toggle, hard to use
            break;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
    }
    // if (is_alt_tab_active) {
    //   if (timer_elapsed(alt_tab_timer) > 1000) {
    //     unregister_code(KC_LALT);
    //     is_alt_tab_active = false;
    //   }
    // }
};
