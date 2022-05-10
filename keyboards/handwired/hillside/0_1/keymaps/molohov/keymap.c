#include "molohov.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
    NUMPAD,     KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,       RESET,
    KC_Z,       KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,       KC_J,
    KC_HOME,    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,       CAPSWD,     KC_UNDS,    KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,       KC_END,
                            KC_MPLY,    KC_ESC,     GUIDEL,     BSPNAV,     TABSFT,     ENTSFT,     SPCNUM,     ESCBYO,     ON_TODO,    PC_LOCK
    ),
    [_SYM_NUM] = LAYOUT(
    _______,    KC_TILD,    KC_PIPE,    KC_COLN,    KC_PERC,    KC_PPLS,                            KC_MINS,    KC_DOT,     KC_BSLS,    KC_AMPR,    _______,    _______,
    _______,    KC_9,       KC_3,       KC_1,       KC_5,       KC_EQL,                             KC_QUOT,    KC_2,       KC_0,       KC_4,       KC_8,       _______,
    _______,    KC_7,       KC_LBRC,    KC_LCBR,    KC_LPRN,    KC_LABK,    _______,    _______,    KC_RABK,    KC_RPRN,    KC_RCBR,    KC_RBRC,    KC_6,       _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NAV] = LAYOUT(
    _______,    PC_EXIT,    SW_TAB,     PC_FIND,    PC_SALL,    VIM_RSP,                            _______,    KC_HOME,    KC_UNDS,    KC_END,     RESET,      _______,
    _______,    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   VIM_FSP,                            VS_EDIT,    KC_LEFT,    KC_UP,      KC_RGHT,    VS_TERM,    _______,
    _______,    KC_SLSH,    KC_QUES,    SW_WIN,     PC_CLIP,    SLKFPS,     _______,    _______,    VS_EGRP,    VS_PEDT,    KC_DOWN,    VS_NEDT,    Q_ENTER,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    KC_UNDS,    _______,    _______,    _______
    ),
    [_NUMPAD] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_7,       KC_8,       KC_9,       _______,    _______,
    _______,    _______,    KC_EQL,     KC_PAST,    KC_PPLS,    _______,                            _______,    KC_4,       KC_5,       KC_6,       KC_DOT,     _______,
    _______,    _______,    _______,    KC_PSLS,    KC_PMNS,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,       KC_COMM,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,       _______,    _______
    ),
    [_BYO_ONOTE_VSC] = LAYOUT(
    KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,
    BY_FPNE,    ON_QUES,    ON_IMPT,    ON_TODO,    BY_FSWL,    PY_IPDB,                            BY_MVWL,    BY_MVWR,    BY_VSPL,    BY_DISF,    BY_KPNE,    _______,
    BY_CLYT,    BY_RNWN,    BY_NWIN,    BY_HSPL,    BY_FSWR,    BY_VSPL,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3);
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_PURPLE);
    }
};
