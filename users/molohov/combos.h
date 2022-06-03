#pragma once

#include QMK_KEYBOARD_H

// LEFT HAND
// combos are defined from leftmost key to rightmost key
// upper row
const uint16_t PROGMEM send_xla[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM refresh[]  = {KC_M, KC_B, COMBO_END};
const uint16_t PROGMEM hash[]     = {KC_M, HRM_T, COMBO_END};
// middle row
const uint16_t PROGMEM screenshot[]       = {HRM_S, KC_M, COMBO_END};
const uint16_t PROGMEM lprn[]             = {HRM_S, HRM_T, COMBO_END};
const uint16_t PROGMEM send_3d[]          = {HRM_S, KC_D, COMBO_END};
const uint16_t PROGMEM oneshot_lctl[]     = {HRM_S, HRM_N, COMBO_END};
const uint16_t PROGMEM oneshot_lctl_sym[] = {PC_CUT, PC_COPY, COMBO_END};
const uint16_t PROGMEM asterisk[]         = {HRM_N, HRM_T, COMBO_END};
const uint16_t PROGMEM comboJ[]           = {HRM_N, KC_G, COMBO_END};
const uint16_t PROGMEM comboZ[]           = {HRM_N, KC_V, COMBO_END};
// keep shift+V on the left side
// const uint16_t PROGMEM vimshiftv[]  = {HRM_N, KC_D, COMBO_END};
// lower row
const uint16_t PROGMEM oneshot_lalt[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM dlsim[]        = {KC_L, KC_D, COMBO_END};
// thumbs
const uint16_t PROGMEM underscore[] = {SPCNUM, ENTSFT, COMBO_END};

// vim combos rooted from left home row middle finger
// const uint16_t PROGMEM vimwrite[] =     {HRM_N, HRM_T, COMBO_END};
// const uint16_t PROGMEM vimwritequit[] = {HRM_N, KC_D, COMBO_END};
// const uint16_t PROGMEM vimquit[] =      {HRM_N, KC_G, COMBO_END};
// const uint16_t PROGMEM vimquitall[] =   {HRM_N, KC_B, COMBO_END};
// const uint16_t PROGMEM vimshiftv[] =    {HRM_T, KC_V, COMBO_END};

// copy/paste combos on left bottom row
// const uint16_t PROGMEM pc_undo[]      = {KC_W, KC_D, COMBO_END};
// const uint16_t PROGMEM pc_copy[]      = {KC_C, KC_L, COMBO_END};
// const uint16_t PROGMEM pc_cut[]       = {KC_C, HRM_N, COMBO_END};
// const uint16_t PROGMEM pc_paste[]     = {KC_L, KC_D, COMBO_END};
// const uint16_t PROGMEM pc_copypaste[] = {KC_C, KC_D, COMBO_END};
// const uint16_t PROGMEM pc_clip[]      = {KC_L, HRM_T, COMBO_END};
// const uint16_t PROGMEM pc_find[]      = {KC_L, HRM_T, COMBO_END};
// const uint16_t PROGMEM pc_selectall[] = {KC_W, KC_L, COMBO_END};

// this combo mirrors the DW action in vim!
// const uint16_t PROGMEM del_word[] = {KC_W, KC_D, COMBO_END};
// const uint16_t PROGMEM slack_code[] = {KC_F, KC_M, COMBO_END};
// const uint16_t PROGMEM slack_code_paste[] = {KC_F, KC_M, KC_P, COMBO_END};
// const uint16_t PROGMEM escape[]     = {KC_S, KC_M, COMBO_END};
// const uint16_t PROGMEM newtab[]     = {HRM_T, KC_G, COMBO_END};


// RIGHT HAND
// combos are defined from rightmost key to leftmost key
// upper row
// punctuation
const uint16_t PROGMEM plus[]      = {KC_COMM, KC_SLSH, COMBO_END};
const uint16_t PROGMEM semicolon[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM at[]        = {KC_SLSH, KC_DOT, COMBO_END};
const uint16_t PROGMEM dollar[]    = {KC_SLSH, KC_MINS, COMBO_END};
// . + , = ;
const uint16_t PROGMEM send_ipdb[] = {KC_SLSH, HRM_A, COMBO_END};

// middle row
// vim combos rooted from right home row middle finger
const uint16_t PROGMEM vimwrite[]     = {HRM_E, HRM_A, COMBO_END};
const uint16_t PROGMEM vimwritequit[] = {HRM_E, KC_U, COMBO_END};
const uint16_t PROGMEM vimquit[]      = {HRM_E, KC_QUOT, COMBO_END};
const uint16_t PROGMEM vimquitall[]   = {HRM_E, KC_COLN, COMBO_END};
const uint16_t PROGMEM lnx_last[]     = {HRM_I, KC_SLSH, COMBO_END};
const uint16_t PROGMEM oneshot_rctl[] = {HRM_I, HRM_E, COMBO_END};
const uint16_t PROGMEM rprn[]         = {HRM_I, HRM_A, COMBO_END};

// lower row
const uint16_t PROGMEM oneshot_ralt[] = {KC_Y, KC_O, COMBO_END};

// thumbs
const uint16_t PROGMEM caps_word[] =  {BSPNAV, TABSFT, COMBO_END};

// const uint16_t PROGMEM ku_qu[]    = {KC_U, KC_K, COMBO_END};
// const uint16_t PROGMEM win_bluetooth[] = {KC_K, KC_Y, COMBO_END};
// const uint16_t PROGMEM lnx_cls[]  = {KC_Y, KC_O, COMBO_END};
// const uint16_t PROGMEM oneshotsft[]     = {HRM_E, HRM_A, COMBO_END};
// const uint16_t PROGMEM oneshot_lgui[]     = {HRM_N, HRM_T, COMBO_END};
// const uint16_t PROGMEM asterisk[] = {KC_SLSH, KC_A, COMBO_END};

enum combo_events {
    COMBO_VIM_WRITE,
    COMBO_VIM_WRITEQUIT,
    COMBO_VIM_QUIT,
    COMBO_VIM_QUITALL,
    COMBO_VIM_SHIFTV,
    COMBO_LNX_LAST,
    COMBO_SLACK_CODE,
    COMBO_SLACK_CODE_PASTE,
    COMBO_AT,
    COMBO_DOLLAR,
    COMBO_ASTERISK,
    COMBO_HASH,
    COMBO_SEMICOLON,
    COMBO_PLUS,
    COMBO_DLSIM,
    COMBO_J,
    COMBO_Z,
    COMBO_SCREENSHOT,
    COMBO_REFRESH,
    COMBO_OS_LCTL,
    COMBO_OS_LCTL_SYM,
    COMBO_OS_LALT,
    COMBO_OS_RCTL,
    COMBO_OS_RALT,
    COMBO_LPRN,
    COMBO_RPRN,
    COMBO_SEND3D,
    COMBO_SENDXLA,
    COMBO_IPDB,
    COMBO_UNDS,
    COMBO_CAPS,
    COMBO_LENGTH
    // COMBO_NEWTAB,
    // COMBO_OS_SFT,
    // COMBO_OS_LGUI,
    // COMBO_DEL_WORD,
    // COMBO_ESC,
    // COMBO_KU_QU,
    // COMBO_EXCLAMATION,
    // COMBO_PC_COPY,
    // COMBO_PC_CUT,
    // COMBO_PC_PASTE,
    // COMBO_PC_UNDO,
    // COMBO_PC_COPYPASTE,
    // COMBO_WIN_CLIP,
    // COMBO_PC_FIND,
    // COMBO_PC_SELECTALL,
    // COMBO_WIN_BLUETOOTH,
    // COMBO_LNX_CLS,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
    [COMBO_VIM_WRITE]     = COMBO(vimwrite, VIMWRITE),
    [COMBO_VIM_WRITEQUIT] = COMBO(vimwritequit, VIMWRITEQUIT),
    [COMBO_VIM_QUIT]      = COMBO(vimquit, VIMQUIT),
    [COMBO_VIM_QUITALL]   = COMBO(vimquitall, VIMQUITALL),
    [COMBO_LNX_LAST]      = COMBO(lnx_last, LNX_LAST),
    [COMBO_AT]            = COMBO(at, KC_AT),
    [COMBO_DOLLAR]        = COMBO(dollar, KC_DLR),
    [COMBO_SEMICOLON]     = COMBO(semicolon, KC_SCLN),
    [COMBO_ASTERISK]      = COMBO(asterisk, KC_PAST),
    [COMBO_HASH]          = COMBO(hash, KC_HASH),
    [COMBO_PLUS]          = COMBO(plus, KC_PPLS),
    [COMBO_DLSIM]         = COMBO(dlsim, DLSIM),
    [COMBO_OS_LCTL]       = COMBO(oneshot_lctl, OS_CTL),
    [COMBO_OS_LALT]       = COMBO(oneshot_lalt, OS_ALT),
    [COMBO_OS_LCTL_SYM]   = COMBO(oneshot_lctl_sym, OS_CTL),
    [COMBO_OS_RCTL]       = COMBO(oneshot_rctl, OS_CTL),
    [COMBO_OS_RALT]       = COMBO(oneshot_ralt, OS_ALT),
    [COMBO_J]             = COMBO(comboJ, KC_J),
    [COMBO_Z]             = COMBO(comboZ, KC_Z),
    [COMBO_SCREENSHOT]    = COMBO(screenshot, PC_SCSH),
    [COMBO_REFRESH]       = COMBO(refresh, KC_F5),
    [COMBO_LPRN]          = COMBO(lprn, KC_LPRN),
    [COMBO_RPRN]          = COMBO(rprn, KC_RPRN),
    [COMBO_SEND3D]        = COMBO(send_3d, SEND3D),
    [COMBO_SENDXLA]       = COMBO(send_xla, SENDXLA),
    [COMBO_IPDB]          = COMBO(send_ipdb, PY_IPDB),
    [COMBO_UNDS]          = COMBO(underscore, KC_UNDS),
    [COMBO_CAPS]          = COMBO(caps_word, CAPSWD),
    // [COMBO_LBRC]            = COMBO(lbrc,           KC_LBRC),
    // [COMBO_LCBR]            = COMBO(lcbr,           KC_LCBR),
    // [COMBO_PC_COPY]         = COMBO(pc_copy,        PC_COPY),
    // [COMBO_PC_CUT]          = COMBO(pc_cut,         PC_CUT),
    // [COMBO_PC_PASTE]        = COMBO(pc_paste,       PC_PASTE),
    // [COMBO_PC_UNDO]         = COMBO(pc_undo,        PC_UNDO),
    // [COMBO_PC_COPYPASTE]    = COMBO(pc_copypaste,   COPY_PASTE),
    // [COMBO_WIN_CLIP]        = COMBO(pc_clip,        PC_CLIP),
    // [COMBO_PC_FIND]         = COMBO(pc_find,        PC_FIND),
    // [COMBO_PC_SELECTALL]    = COMBO(pc_selectall,   PC_SALL),
    // [COMBO_WIN_BLUETOOTH]   = COMBO(win_bluetooth,  G(KC_K)),
    // [COMBO_SLACK_CODE]      = COMBO(slack_code,     SLACK_CODE),
    // [COMBO_SLACK_CODE_PASTE] = COMBO(slack_code_paste, SLACK_CODE_PASTE),
    // [COMBO_NEWTAB]          = COMBO(newtab,         C(KC_T)),
    // [COMBO_OS_SFT]             = COMBO(oneshotsft,     OS_SFT),
    // [COMBO_OS_LGUI]             = COMBO(oneshot_lgui,     OS_GUI),
    // [COMBO_DEL_WORD]        = COMBO(del_word,       C(KC_DEL)),
    // [COMBO_ESC]             = COMBO(escape,         KC_ESC),
    // [COMBO_LNX_CLS]         = COMBO(lnx_cls,        C(KC_L)),
    // [COMBO_KU_QU]           = COMBO(ku_qu,          KU_QU),
};
