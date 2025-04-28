#include "molohov.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
    KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,
    KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,
    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,                               KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,
                                        GUIDEL,     BSPSYM,     ENTSFT,     TABSFT,     SPCNAV,     ESCOTH
    ),
    [_SYM_NUM] = LAYOUT(
    PC_EXIT,    WINRUN,     PC_FIND,    PC_SALL,    SLKFPS,                             KC_MINS,    KC_7,       KC_8,       KC_9,       KC_PERC,
    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   SLKCPS,                             KC_SLSH,    KC_1,       KC_2,       KC_3,       KC_DOT,
    WIN_MIN,    SW_TAB,     SW_WIN,     PC_CLIP,    CW_TOGG,                            KC_COLN,    KC_4,       KC_5,       KC_6,       _______,
                                        _______,    _______,    _______,    BSPSFT,     KC_UNDS,    KC_0
    ),
    [_NAV] = LAYOUT(
    VS_EDIT,    VIM_LIND,   VS_COMT,    VIM_RIND,   WINRUN,                             BY_FSWL,    BY_FSWR,    VIM_Q,      MD_TODO,    QK_BOOT,
    VS_TERM,    KC_LEFT,    KC_UP,      KC_RGHT,    SHIFTV,                             BY_RNWN,    BY_NWIN,    VIM_W,      GRVS,       CW_TOGG,
    KC_HOME,    PC_LWRD,    KC_DOWN,    PC_RWRD,    KC_END,                             BY_KSRV,    BY_HSPL,    VIM_X,      MD_CODE,    PY_IPDB,
                                        PC_DLWD,    PC_BSWD,    _______,    _______,    _______,    _______
    ),
    [_OTHER] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,                            _______,    KC_F7,      KC_F8,      KC_F9,      KC_F10,
    _______,    _______,    _______,    _______,    _______,                            _______,    KC_F1,      KC_F2,      KC_F3,      KC_F11,
    _______,    _______,    _______,    _______,    _______,                            _______,    KC_F4,      KC_F5,      KC_F6,      KC_F12,
                                        _______,    _______,    _______,    _______,    _______,    _______
    ),
};
