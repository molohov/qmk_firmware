#include "molohov.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
    KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,
    KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,
    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,                               KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,
                                        GUIDEL,     BSPNAV,     TABSFT,     ENTSFT,     SPCNUM,     ESCBYO
    ),
    [_SYM_NUM] = LAYOUT(
    KC_PERC,    KC_AMPR,    KC_COLN,    KC_PERC,    KC_PPLS,                            KC_MINS,    KC_DOT,     KC_BSLS,    KC_PIPE,    KC_AMPR,
    KC_9,       KC_3,       KC_1,       KC_5,       KC_TILD,                            KC_QUOT,    KC_2,       KC_0,       KC_4,       KC_8,
    KC_7,       KC_LBRC,    KC_LCBR,    KC_LPRN,    KC_LABK,                            KC_RABK,    KC_RPRN,    KC_RCBR,    KC_RBRC,    KC_6,
                                        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NAV] = LAYOUT(
    PC_EXIT,    SW_TAB,     PC_FIND,    PC_SALL,    VIM_RSP,                            _______,    KC_HOME,    KC_UNDS,    KC_END,     RESET,
    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   VIM_FSP,                            VS_EDIT,    KC_LEFT,    KC_UP,      KC_RGHT,    VS_TERM,
    KC_SLSH,    KC_QUES,    SW_WIN,     PC_CLIP,    SLKFPS,                             VS_EGRP,    VS_PEDT,    KC_DOWN,    VS_NEDT,    Q_ENTER,
                                        _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_NUMPAD] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,                            _______,    KC_7,       KC_8,       KC_9,       _______,
    _______,    KC_EQL,     KC_PAST,    KC_PPLS,    _______,                            _______,    KC_4,       KC_5,       KC_6,       KC_DOT,
    _______,    _______,    KC_PSLS,    KC_PMNS,    _______,                            _______,    KC_1,       KC_2,       KC_3,       KC_COMM,
                                        _______,    _______,    _______,    _______,    _______,    KC_0
    ),
    [_BYO_ONOTE_VSC] = LAYOUT(
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
    ON_QUES,    ON_IMPT,    ON_TODO,    BY_FSWL,    PY_IPDB,                            BY_MVWL,    BY_MVWR,    BY_VSPL,    BY_DISF,    BY_KPNE,
    BY_RNWN,    BY_NWIN,    BY_HSPL,    BY_FSWR,    BY_VSPL,                            _______,    BY_CLYT,    BY_FPNE,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______
    ),
};
