#pragma once

#ifndef USERSPACE
#define USERSPACE
#endif

#include QMK_KEYBOARD_H

enum layer {
    _HANDS_DOWN,
    _HANDS_DOWN_PLAT,
    _NUMPAD,
    _SYM_NUM,
    _NAV,
    _BYO_ONOTE_VSC,
    _QWERTY_GAME,
};

enum custom_keycodes {
    KC_HANDS_DOWN = SAFE_RANGE,
    KC_QWERTY_GAME,
    VIMWRITE,
    VIMWRITEQUIT,
    VIMQUIT,
    VIMQUITALL,
    VIPASTE,
    LNX_LAST,
    KU_QU,
    DLSIM,
    SLACK_CODE,
    SLACK_CODE_PASTE,
    SLACK_FUNC_PASTE,
    COPY_PASTE,
    VIM_FSEARCH_PASTE,
    VIM_RSEARCH_PASTE,
    VIM_LIND,
    VIM_RIND,
    QUOTS,
    PRNS,
    BRCS,
    CBRS,
    Q_ENTER,
    IMPORT_PDB,
    CAPSWD,
    SW_WIN,
    SW_TAB,
    SEND3D,
    SENDXLA,
    SENDONNX,
    SENDSMILE,
    SENDARROW,
};

#ifdef HRM
#define  HRM_R          GUI_T(KC_R)
#define  HRM_S          ALT_T(KC_S)
#define  HRM_N          LSFT_T(KC_N)
#define  HRM_T          CTL_T(KC_T)
#define  HRM_H          GUI_T(KC_H)
#define  HRM_I          ALT_T(KC_I)
#define  HRM_E          RSFT_T(KC_E)
#define  HRM_A          CTL_T(KC_A)
#define  HRM_COLN       GUI_T(KC_COLN)
#define  HRM_MINS       ALT_T(KC_MINS)
#define  HRM_PAST       LSFT_T(KC_PAST)
#define  HRM_LPRN       KC_LSPO
#define  HRM_EQL        GUI_T(KC_EQL)
#define  HRM_GRV        ALT_T(KC_GRV)
#define  HRM_BSLS       RSFT_T(KC_BSLS)
#define  HRM_RPRN       KC_RSPC
#else
#define  HRM_R          KC_R
#define  HRM_S          KC_S
#define  HRM_N          KC_N
#define  HRM_T          KC_T
#define  HRM_H          KC_H
#define  HRM_I          KC_I
#define  HRM_E          KC_E
#define  HRM_A          KC_A
#define  HRM_COLN       KC_COLN
#define  HRM_MINS       KC_MINS
#define  HRM_PAST       KC_PAST
#define  HRM_LPRN       KC_LPRN
#define  HRM_EQL        KC_EQL
#define  HRM_GRV        KC_GRV
#define  HRM_BSLS       KC_BSLS
#define  HRM_RPRN       KC_RPRN
#endif

// #define  HRM_LPRN       ALT_T(KC_LPRN)
#define  BSPSYM         LT(_SYM_NUM, KC_BSPC)
#define  SPCNAV         LT(_NAV, KC_SPC)
#define  ENTSFT         LSFT_T(KC_ENT)
#define  TABSFT         RSFT_T(KC_TAB)
#define  SPCSFT         RSFT_T(KC_SPC)

#define  BSPNAV         LT(_NAV, KC_BSPC)
#define  ENTBYO         LT(_BYO_ONOTE_VSC, KC_ENT)
#define  TABNUM         LT(_NUMPAD, KC_TAB)
#define  SPCNUM         LT(_SYM_NUM, KC_SPC)

#define  BSPSFT         SFT_T(KC_BSPC)
#define  TABNAV         LT(_NAV, KC_TAB)

#define  ESCBYO         LT(_BYO_ONOTE_VSC, KC_ESC)
// #define  SPCNAV         LT(_NAV_SYM_NUM, KC_SPC)

#define  DELSFT         LSFT_T(KC_DEL)
#define  ESCSFT         RSFT_T(KC_ESC)
#define  ENTBYO         LT(_BYO_ONOTE_VSC, KC_ENT)
#define  TABGUI         GUI_T(KC_TAB)

#define  CTLTAB         CTL_T(KC_TAB)
#define  ALTENT         ALT_T(KC_ENT)

#define  GUIDEL         GUI_T(KC_DEL)
#define  ALTESC         ALT_T(KC_ESC)

#define  ALT_UP         ALT_T(KC_UP)
#define  NUMPAD         TG(_NUMPAD)

#define  PC_UNDO        C(KC_Z)
#define  PC_SALL        C(KC_A)
#define  PC_CUT         C(KC_X)
#define  PC_COPY        C(KC_C)
#define  PC_PASTE       C(KC_V)
#define  PC_FIND        C(KC_F)
#define  PC_LOCK        G(KC_L)
#define  PC_BSWD        C(KC_BSPC)
#define  PC_DLWD        C(KC_DEL)
#define  PC_SLACK       A(KC_Q)
#define  PC_OBSD        A(KC_Z)
#define  PC_SCSH        G(S(KC_S))
#define  PC_LWRD        C(KC_LEFT)
#define  PC_RWRD        C(KC_RIGHT)
#define  PC_EXIT        A(KC_F4)
#define  PC_CLIP        G(KC_V)
#define  WIN_MIN        G(KC_DOWN)
#define  SLKCPS         SLACK_CODE_PASTE
#define  SLKFPS         SLACK_FUNC_PASTE
#define  WINRUN         A(KC_SPC)
#define  PC_CTLW        C(KC_W)

#define  LNX_PASTE      S(C(KC_V))
#define  LNX_LWD        A(KC_B)
#define  LNX_RWD        A(KC_F)
// reverse search
#define  LNX_RSR        C(KC_R)

// byobu macros
// vertical split
#define  BY_VSPL        C(KC_F2)
// horizontal split
#define  BY_HSPL        S(KC_F2)
// change layout
#define  BY_CLYT        S(KC_F8)
// fullscreen pane
#define  BY_FPNE        S(KC_F11)
// kill pane
#define  BY_KPNE        C(KC_F6)
// disable function keys
#define  BY_DISF        S(KC_F12)
// move window left
#define  BY_MVWL        S(C(KC_F3))
// move window right
#define  BY_MVWR        S(C(KC_F4))
// shift pane focus left
#define  BY_FSPL        S(KC_F3)
// shift pane focus right
#define  BY_FSPR        S(KC_F4)
// new pane
#define  BY_NWIN        KC_F2
// focus on left window
#define  BY_FSWL        KC_F3
// focus on right window
#define  BY_FSWR        KC_F4
// refresh settings
#define  BY_RFSH        KC_F5
// exit server
#define  BY_KSRV        KC_F6
// rename window
#define  BY_RNWN        KC_F8

// vscode macros
#define  VS_CTLP        C(KC_P)
#define  VS_SCTP        S(C(KC_P))
#define  VS_COMT        C(KC_SLSH)
// focus on terminal
#define  VS_TERM        C(KC_GRV)
// focus on code area
#define  VS_EDIT        C(KC_1)
// go to next editor
#define  VS_NEDT        C(KC_PGDN)
// go to prev editor
#define  VS_PEDT        C(KC_PGUP)
// change editor group (must be set as a shortcut in VSCode first)
#define  VS_EGRP        C(A(KC_PGUP))
// go to next change
#define  VS_NCHG        A(KC_F3)
// go to prev change
#define  VS_PCHG        S(A(KC_F3))

// vim forward/reverse search, paste, then enter
#define  VIM_FSP        VIM_FSEARCH_PASTE
#define  VIM_RSP        VIM_RSEARCH_PASTE
#define  SHIFTV         S(KC_V)

// to-do
#define ON_TODO         C(KC_1)
#define OB_TODO         C(KC_ENT)
// important
#define ON_IMPT         C(KC_2)
// question
#define ON_QUES         C(KC_3)

#define PY_IPDB         IMPORT_PDB
#define SLK_CDP         SLACK_CODE_PASTE
#define OS_SFT          OSM(MOD_LSFT)
#define OS_CTL          OSM(MOD_LCTL)
#define OS_ALT          OSM(MOD_LALT)
#define OS_GUI          OSM(MOD_LGUI)


#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define SEND_CAP_STRING(str, capitalized) if (MODS_SHIFT) { \
                                            clear_mods(); \
                                            SEND_STRING(capitalized); \
                                          } else { \
                                            SEND_STRING(str); \
                                          }

// #define _________________HANDSDOWNNEU_R1___________        KC_X , KC_F , KC_M,  KC_P,  KC_B,
// #define _________________HANDSDOWNNEU_R2___________        KC_R , KC_S , KC_N,  KC_T,  KC_G,
// #define _________________HANDSDOWNNEU_R3___________        KC_W , KC_C , KC_L,  KC_D,  KC_V,

// #define _________________NAVNUMSYM_LEFT_R1___________      _______,    KC_AMPR,    KC_PERC,    KC_BSLS,    KC_LBRC,    KC_RBRC
// #define _________________NAVNUMSYM_LEFT_R2___________      KC_SLSH,    KC_COLN,    KC_GRV,     KC_PAST,    KC_LPRN,    KC_RPRN
// #define _________________NAVNUMSYM_LEFT_R3___________      _______,    KC_7,       KC_3,       KC_1,       KC_5,       KC_9

// KC_F11,     KC_F12,     KC_8,       KC_2,       KC_0,       KC_4,       KC_6,       _______,
//     _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_EQL,     _______,    _______,
//                             _______,    _______,    KC_UP,      _______,    _______,    _______,

void my_custom_function(void);

void print_layers(void);
void print_mods(void);
