#include "molohov.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  F5  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F2  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  F6  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F3  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  F7  |
 * |------+------+------+------+------+------+------.     ,-------|------+------+------+------+------+------|
 * |  F4  |   Z  |   X  |   C  |   V  |   B  |  F9  |     | F10   |   N  |   M  |   ,  |   .  |   /  |  F8  |
 * `-------------+------+------+------+------+------|     |-------+------+------+------+------+-------------'
 *               |      |      | LCTL | BSpc | Esc  |     | Ent   | Spc  | LAlt |      |      |
 *               `----------------------------------'     `-----------------------------------'
 */

    [_HANDS_DOWN] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    KC_MPLY,    KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_MINS,    KC_DOT,     KC_SLSH,    KC_COMM,    KC_Q,       QK_BOOT,
    KC_Z,       KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,                               KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,       KC_J,
    KC_HOME,    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,       PC_SLACK,   CAPSWD,     KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,       KC_END,
                            PC_CTLW,    KC_ESC,     GUIDEL,     BSPSYM,     ENTSFT,     TABSFT,     SPCNAV,     ESCBYO,     WINRUN,     PC_LOCK
    ),
    [_SYM_NUM] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    _______,    PC_EXIT,    KC_QUES,    PC_FIND,    PC_SALL,    SLKFPS,                             KC_AT,      KC_GRV,     KC_BSLS,    KC_EQL,     KC_TILD,    _______,
    _______,    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   SLKCPS,                             KC_9,       KC_0,       KC_1,       KC_2,       KC_3,       KC_4,
    _______,    KC_SLSH,    SW_TAB,     SW_WIN,     PC_CLIP,    VIM_RSP,    _______,    _______,    KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    KC_UNDS,    KC_DOT,     _______,    _______
    ),
    [_NAV] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    VIM_LIND,   VS_COMT,    VIM_RIND,   _______,                            BY_MVWL,    BY_MVWR,    ON_QUES,    BY_VSPL,    BY_KPNE,    _______,
    _______,    VS_TERM,    KC_LEFT,    KC_UP,      KC_RGHT,    VS_EDIT,                            _______,    PY_IPDB,    OB_TODO,    BY_HSPL,    BY_FPNE,    _______,
    _______,    Q_ENTER,    KC_HOME,    KC_DOWN,    KC_END,     VS_EGRP,    VS_COMT,    _______,    BY_FSWL,    BY_FSWR,    ON_IMPT,    BY_NWIN,    BY_CLYT,    _______,
                            _______,    VS_COMT,    PC_DLWD,    PC_BSWD,    SHIFTV,     _______,    _______,    _______,    _______,    _______
    ),
    [_NUMPAD] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_7,       KC_8,       KC_9,       _______,    _______,
    _______,    _______,    KC_EQL,     KC_PAST,    KC_PPLS,    _______,                            _______,    KC_4,       KC_5,       KC_6,       KC_DOT,     _______,
    _______,    _______,    _______,    KC_PSLS,    KC_PMNS,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,       KC_COMM,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,       _______,    _______
    ),
    [_BYO_ONOTE_VSC] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,
    BY_FPNE,    ON_QUES,    ON_IMPT,    ON_TODO,    BY_FSWL,    PY_IPDB,                            BY_MVWL,    BY_MVWR,    BY_VSPL,    BY_DISF,    BY_KPNE,    _______,
    BY_CLYT,    BY_RNWN,    BY_NWIN,    BY_HSPL,    BY_FSWR,    BY_VSPL,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                            _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
};
