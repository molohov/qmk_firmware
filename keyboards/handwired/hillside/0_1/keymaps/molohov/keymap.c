#include "molohov.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
    NUMPAD,     KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,       RESET,
    KC_Z,       KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,       KC_J,
    KC_HOME,    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,       CAPSWD,     KC_UNDS,    KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,       KC_END,
                            KC_MPLY,    PC_SCSH,    GUIDEL,     BSPSYM,     ENTSFT,     TABSFT,     SPCNAV,     ESCBYO,     ON_TODO,    PC_SLACK
    ),
    [_SYM_NUM] = LAYOUT(
    _______,    PC_EXIT,    SW_TAB,     PC_FIND,    PC_SALL,    SLKFPS,                             KC_GRV,     KC_QUES,    KC_EXLM,    KC_EQL,     KC_TILD,    _______,
    _______,    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   SLKCPS,                             KC_DQT,     KC_0,       KC_1,       KC_2,       KC_3,       _______,
    _______,    KC_SLSH,    KC_QUES,    SW_WIN,     PC_CLIP,    VIM_RSP,    _______,    _______,    KC_PIPE,    LPRNS,      LBRCS,      LCBRS,      KC_LABK,    _______,
                            _______,    _______,    _______,    _______,    _______,    KC_UNDS,    _______,    KC_COLN,    _______,    _______
    ),
    [_NAV] = LAYOUT(
    _______,    _______,    KC_HOME,    VIM_LIND,   KC_END,     VIM_RIND,                           _______,    _______,    _______,    _______,    _______,    _______,
    _______,    VS_TERM,    KC_LEFT,    KC_UP,      KC_RGHT,    VS_EDIT,                            _______,    _______,    _______,    _______,    _______,    _______,
    _______,    Q_ENTER,    VS_PEDT,    KC_DOWN,    VS_NEDT,    VS_EGRP,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                            _______,    _______,    VS_COMT,    SHIFTV,     _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NUMPAD] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_7,       KC_8,       KC_9,       _______,    _______,
    _______,    _______,    KC_EQL,     KC_PAST,    KC_PPLS,    _______,                            _______,    KC_0,       KC_1,       KC_2,       KC_3,       _______,
    _______,    _______,    _______,    KC_PSLS,    KC_PMNS,    _______,    _______,    _______,    _______,    KC_4,       KC_5,       KC_6,       KC_COMM,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_DOT,     _______,    _______
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
