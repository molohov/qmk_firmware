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
#include "molohov.h"


// for HD Platinum
#define  SPCSFT         SFT_T(KC_SPC)
#define  L_NAV          LT(_NAV, KC_L)
#define  CTLBSP         CTL_T(KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
    NUMPAD,     KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,       RESET,
    KC_Z,       KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,       KC_J,
    KC_HOME,    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,                               KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,       KC_END,
                            KC_MPLY,    KC_ESC,     GUIDEL,     BSPNAV,     TABSFT,     ENTSFT,     SPCNUM,     ESCBYO,     ON_TODO,    PC_LOCK,
                                        WINRUN,     PC_SCSH,    VS_COMT,    CAPSWD,     KC_UNDS,    PC_SLACK,   VS_CTLP,    PY_IPDB
    ),
    // [_HANDS_DOWN_PLAT] = LAYOUT(
    // RESET,      KC_Z,       KC_F,       KC_M,       KC_P,       KC_K,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,       _______,
    // KC_Z,       HRM_R,      HRM_S,      HRM_N,      HRM_T,      KC_B,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_C,       KC_J,
    // KC_HOME,    KC_X,       KC_G,       KC_H,       KC_D,       KC_V,                               KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_W,       KC_END,
    //                         PC_LOCK,    ALT_UP,     GUIDEL,     L_NAV,      CTLBSP,     ENTBYO,     SPCSFT,     KC_ESC,     VS_COMT,    KC_MPLY,
    //                                     PC_SCSH,    VS_CTLP,    PC_BSWD,    KC_TAB,     VS_TERM,    PC_SLACK,   VS_NEDT,    LNX_RSR
    // ),
    [_SYM_NUM] = LAYOUT(
    _______,    _______,    KC_PERC,    KC_HASH,    KC_LCBR,    KC_LABK,                            KC_RABK,    KC_RCBR,    KC_PIPE,    KC_AMPR,    _______,    _______,
    KC_DLR,     KC_COLN,    HRM_MINS,   HRM_PAST,   HRM_LPRN,   KC_LBRC,                            KC_RBRC,    HRM_RPRN,   HRM_BSLS,   HRM_GRV,    KC_EQL,     KC_AT,
    KC_DOT,     KC_9,       KC_3,       KC_1,       KC_5,       KC_7,                               KC_8,       KC_2,       KC_0,       KC_4,       KC_6,       _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NAV] = LAYOUT(
    _______,    OS_GUI,     OS_ALT,     PC_FIND,    OS_CTL,     VIM_RSP,                            _______,    OS_CTL,     OS_ALT,     OS_GUI,     OS_SFT,     _______,
    PC_SALL,    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   VIM_FSP,                            VS_EDIT,    KC_LEFT,    KC_UP,      KC_RGHT,    VS_TERM,    _______,
    PC_EXIT,    KC_SLSH,    KC_QUES,    SW_WIN,     PC_CLIP,    SLKFPS,                             VS_EGRP,    VS_PEDT,    KC_DOWN,    VS_NEDT,    _______,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NUMPAD] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_7,       KC_8,       KC_9,       _______,    _______,
    _______,    _______,    KC_EQL,     KC_PAST,    KC_PPLS,    _______,                            _______,    KC_4,       KC_5,       KC_6,       KC_DOT,     _______,
    _______,    _______,    _______,    KC_PSLS,    KC_PMNS,    _______,                            _______,    KC_1,       KC_2,       KC_3,       KC_COMM,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,       _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_BYO_ONOTE_VSC] = LAYOUT(
    KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,
    BY_FPNE,    ON_QUES,    ON_IMPT,    ON_TODO,    BY_FSWL,    PY_IPDB,                            BY_MVWL,    BY_MVWR,    BY_VSPL,    BY_DISF,    BY_KPNE,    _______,
    BY_CLYT,    BY_RNWN,    BY_HSPL,    BY_NWIN,    BY_FSWR,    BY_VSPL,                            _______,    _______,    _______,    _______,    _______,    _______,
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
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!is_keyboard_master()) {
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//   }
  return OLED_ROTATION_270;
}

// static void render_named_logo(void) {
//   static const char PROGMEM raw_logo[] = {
//     12, 60,252,252,252,236,236,140, 12, 28,248,192,  0,192,248,252,252,252,108, 12, 12,140,236, 60, 12,  0,  0,  0,248,252,252,252,236,204,204,204,204,204,204,204,204,204,204,204,204,140, 12,252,248,  0,  0,  0,252,252,252,252,236,236,236,204, 12, 60,240,192,  0,  0,  0,252,252,252,236,236, 12, 12, 12,252,248,  0,  0,192,224, 96, 48, 24, 24,140,140,132,196,196,196,196,132,140,140, 12, 24, 48, 48, 96,192,128,  0,  0,252,252,252,236,236,236,236,140, 28,120,224,128,  0,  0,252,252,252,252,236,236, 12, 12, 12,252,
//     0,  0,  0,  3, 15,255,255,255,254,248,192,195,223,255,255, 63, 15,  1,224,248, 30,  7,  1,  0,  0,  0,  0,  0,255,255,255,255,255,255,  0,  0,  1, 63, 63, 51, 51, 51, 51, 51, 51, 51,243,  3,  1,  0,  0,  0,255,255,255,255,255,  1, 15,127,255,252,240,195, 15, 60,240,255,255,255,255,255,  0,  0,  0,255,255,254,255,255,255,127, 14,  2,195,247, 63, 31, 15, 15, 15, 15, 31, 63,255,255,254,252,248,224,  1,  3, 30,252,255,255,255,255,255,  3, 31,255,254,248,225,135, 30,120,255,255,255,255,255,255,  0,  0,  0,255,
//     0,  0,128,240,252,255,255,255, 63,  7,  1,227,127,255,255,255,248,224,  1,  7, 62,240,192,  0,  0,  0,  0,  0,255,255,255,255,255,255,  1,  3,  7,255,255,207,207,207,207,207,206,204,207,192,128,  0,  0,  0,255,255,255,255,255,  0,  0,  0,255,255, 15,127,255,252,240,227,143,127,255,255,  0,  0,  0,255,255, 63,255,255,255,254,240,192,131,135, 12, 24, 48, 48, 48, 48, 24, 28, 15,159,255, 63, 31,  7,128,192,120, 31,255,255,255,255,255,  0,  0,  0,255,255, 31,127,255,252,241,199, 31,127,255,255,  0,  0,  0,255,
//     48, 62, 63, 63, 63, 63, 63, 56, 48, 60, 31,  3,  0,  3, 31, 63, 63, 63, 63, 60, 60, 56, 59, 63, 56,  0,  0,  0, 31, 63, 63, 63, 63, 63, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 56, 63, 31,  0,  0,  0, 63, 63, 63, 63, 63, 60, 56, 48, 63, 63,  0,  0,  0,  3, 31, 63, 63, 62, 61, 63, 60, 56, 48, 63, 31,  0,  0,  1,  7,  7, 15, 31, 31, 63, 63, 63, 62, 62, 62, 62, 63, 63, 63, 31, 31, 15, 14,  6,  3,  1,  0,  0, 63, 63, 63, 63, 63, 60, 56, 56, 63, 31,  0,  0,  1,  7, 31, 63, 63, 60, 63, 63, 60, 56, 48, 63
//   };
//   oled_write_raw_P(raw_logo, sizeof(raw_logo));
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
