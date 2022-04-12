#include "molohov.h"
#include "swapper.h"
#include "caps_word.h"

// COMBOS
enum combo_events {
    COMBO_VIM_WRITE,
    COMBO_VIM_WRITEQUIT,
    COMBO_VIM_QUIT,
    COMBO_VIM_QUITALL,
    COMBO_VIM_SHIFTV,
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
    COMBO_LNX_LAST,
    COMBO_SLACK_CODE,
    COMBO_SLACK_CODE_PASTE,
    // COMBO_KU_QU,
    // COMBO_EXCLAMATION,
    COMBO_AT,
    COMBO_DOLLAR,
    COMBO_ASTERISK,
    COMBO_HASH,
    COMBO_SEMICOLON,
    COMBO_PLUS,
    // COMBO_DEL_WORD,
    // COMBO_ESC,
    COMBO_DLSIM,
    // COMBO_NEWTAB,
    // COMBO_OS_SFT,
    // COMBO_OS_LGUI,
    COMBO_OS_LCTL,
    COMBO_OS_LALT,
    COMBO_OS_RCTL,
    COMBO_OS_RALT,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// LEFT HAND
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
// keep shift+V on the left side
const uint16_t PROGMEM vimshiftv[]  = {HRM_N, KC_D, COMBO_END};
const uint16_t PROGMEM slack_code[] = {KC_F, KC_M, COMBO_END};
const uint16_t PROGMEM slack_code_paste[] = {KC_F, KC_M, KC_P, COMBO_END};
const uint16_t PROGMEM dlsim[]      = {KC_D, KC_L, COMBO_END};
// const uint16_t PROGMEM escape[]     = {KC_S, KC_M, COMBO_END};
// const uint16_t PROGMEM newtab[]     = {HRM_T, KC_G, COMBO_END};
const uint16_t PROGMEM asterisk[] = {KC_S, KC_N, COMBO_END};
const uint16_t PROGMEM hash[] = {HRM_S, KC_M, COMBO_END};

// RIGHT HAND
// vim combos rooted from right home row middle finger
const uint16_t PROGMEM vimwrite[]     = {HRM_E, HRM_A, COMBO_END};
const uint16_t PROGMEM vimwritequit[] = {HRM_E, KC_U, COMBO_END};
const uint16_t PROGMEM vimquit[]      = {HRM_E, KC_QUOT, COMBO_END};
const uint16_t PROGMEM vimquitall[]   = {HRM_E, KC_COLN, COMBO_END};
// linux combos
// const uint16_t PROGMEM lnx_cls[]  = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM lnx_last[] = {HRM_I, KC_SLSH, COMBO_END};

// const uint16_t PROGMEM ku_qu[]    = {KC_U, KC_K, COMBO_END};
// punctuation
const uint16_t PROGMEM at[]     = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM dollar[] = {KC_MINS, KC_SLSH, COMBO_END};
const uint16_t PROGMEM plus[]   = {KC_COMM, KC_SLSH, COMBO_END};
// const uint16_t PROGMEM asterisk[] = {KC_SLSH, KC_A, COMBO_END};
// . + , = ;
const uint16_t PROGMEM semicolon[]     = {KC_DOT, KC_COMM, COMBO_END};

// const uint16_t PROGMEM win_bluetooth[] = {KC_K, KC_Y, COMBO_END};

// one shot mods
// const uint16_t PROGMEM oneshotsft[]     = {HRM_E, HRM_A, COMBO_END};
// const uint16_t PROGMEM oneshot_lgui[]     = {HRM_N, HRM_T, COMBO_END};
const uint16_t PROGMEM oneshot_lctl[]     = {HRM_N, HRM_S, COMBO_END};
const uint16_t PROGMEM oneshot_lalt[]     = {KC_L, KC_C, COMBO_END};
const uint16_t PROGMEM oneshot_rctl[]     = {HRM_E, HRM_I, COMBO_END};
const uint16_t PROGMEM oneshot_ralt[]     = {KC_O, KC_Y, COMBO_END};

combo_t key_combos[] = {
    [COMBO_VIM_WRITE]       = COMBO(vimwrite,       VIMWRITE),
    [COMBO_VIM_WRITEQUIT]   = COMBO(vimwritequit,   VIMWRITEQUIT),
    [COMBO_VIM_QUIT]        = COMBO(vimquit,        VIMQUIT),
    [COMBO_VIM_QUITALL]     = COMBO(vimquitall,     VIMQUITALL),
    [COMBO_VIM_SHIFTV]      = COMBO(vimshiftv,      S(KC_V)),
    // [COMBO_PC_COPY]         = COMBO(pc_copy,        PC_COPY),
    // [COMBO_PC_CUT]          = COMBO(pc_cut,         PC_CUT),
    // [COMBO_PC_PASTE]        = COMBO(pc_paste,       PC_PASTE),
    // [COMBO_PC_UNDO]         = COMBO(pc_undo,        PC_UNDO),
    // [COMBO_PC_COPYPASTE]    = COMBO(pc_copypaste,   COPY_PASTE),
    // [COMBO_WIN_CLIP]        = COMBO(pc_clip,        PC_CLIP),
    // [COMBO_PC_FIND]         = COMBO(pc_find,        PC_FIND),
    // [COMBO_PC_SELECTALL]    = COMBO(pc_selectall,   PC_SALL),
    // [COMBO_WIN_BLUETOOTH]   = COMBO(win_bluetooth,  G(KC_K)),
    [COMBO_LNX_LAST]        = COMBO(lnx_last,       LNX_LAST),
    // [COMBO_LNX_CLS]         = COMBO(lnx_cls,        C(KC_L)),
    // [COMBO_KU_QU]           = COMBO(ku_qu,          KU_QU),
    [COMBO_AT]              = COMBO(at,             KC_AT),
    [COMBO_DOLLAR]          = COMBO(dollar,         KC_DLR),
    [COMBO_SEMICOLON]       = COMBO(semicolon,      KC_SCLN),
    [COMBO_ASTERISK]        = COMBO(asterisk,       KC_PAST),
    [COMBO_HASH]           = COMBO(hash,          KC_HASH),
    [COMBO_PLUS]            = COMBO(plus,           KC_PPLS),
    // [COMBO_DEL_WORD]        = COMBO(del_word,       C(KC_DEL)),
    // [COMBO_ESC]             = COMBO(escape,         KC_ESC),
    [COMBO_DLSIM]           = COMBO(dlsim,          DLSIM),
    [COMBO_SLACK_CODE]      = COMBO(slack_code,     SLACK_CODE),
    [COMBO_SLACK_CODE_PASTE] = COMBO(slack_code_paste, SLACK_CODE_PASTE),
    // [COMBO_NEWTAB]          = COMBO(newtab,         C(KC_T)),
    // [COMBO_OS_SFT]             = COMBO(oneshotsft,     OS_SFT),
    // [COMBO_OS_LGUI]             = COMBO(oneshot_lgui,     OS_GUI),
    [COMBO_OS_LCTL]             = COMBO(oneshot_lctl,     OS_CTL),
    [COMBO_OS_LALT]             = COMBO(oneshot_lalt,     OS_ALT),
    [COMBO_OS_RCTL]             = COMBO(oneshot_rctl,     OS_CTL),
    [COMBO_OS_RALT]             = COMBO(oneshot_ralt,     OS_ALT),
};

// CUSTOM MODIFIER OVERRIDES
// shift () gives {}
// const key_override_t left_paran_override  = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LCBR);
// const key_override_t right_paran_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RCBR);
// // shift [] gives <>
// const key_override_t left_squarebracket_override  = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LABK);
// const key_override_t right_squarebracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_RABK);
// shift * gives #
// const key_override_t asterisk_override = ko_make_basic(MOD_MASK_SHIFT, KC_PAST, KC_HASH);
// shift space gives _
// const key_override_t shift_space_underscore = ko_make_basic(MOD_MASK_SHIFT, SPCNAV, KC_UNDS);
// shift _ gives !
// const key_override_t underscore_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_EXLM);
// shift . gives ?
const key_override_t period_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);
// shift , gives :
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EQL);
// shift : gives ;
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
// shift / gives -
const key_override_t slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_EXLM);
// shift - gives ;
const key_override_t dash_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_GRV);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    // &left_paran_override,
    // &right_paran_override,
    // &left_squarebracket_override,
    // &right_squarebracket_override,
    // &asterisk_override,
    // &shift_space_underscore,
    // &underscore_override,
    &period_override,
    &comma_override,
    &colon_override,
    &slash_override,
    &dash_override,
    NULL // Null terminate the array of overrides!
};

// CUSTOM KEYSTROKES
bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.
    static uint16_t prior_keycode = KC_NO; // for process_adaptive_key
    static uint16_t prior_keydown = 0;

    if (record->event.pressed) {
        keycode = keycode & 0xFF; // ignore all mods? or just shift?
        if ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
            switch (keycode) {
                case KC_M:
                    switch (prior_keycode) {
                        case KC_F: // FM -> FL
                        case KC_P: // PM -> PL
                        case KC_B: // BM -> BL
                        case KC_X: // XM -> XL
                            tap_code(KC_L);
                            return_state = false; // done.
                    }
                    break;
                case KC_F:
                    switch (prior_keycode) {
                        case KC_X: //XF -> XC
                            tap_code(KC_C);
                            return_state = false; // done.
                    }
                    break;
                case KC_C:
                    switch (prior_keycode) {
                        case KC_L: //LC -> LF
                            tap_code(KC_F);
                            return_state = false; // done.
                    }
                    break;
                case KC_DOT:
                    switch (prior_keycode) {
                        case KC_Q: //Q. -> QU
                            tap_code(KC_U);
                            return_state = false; // done.
                    }
                    break;
                // case KC_A:
                //     switch (prior_keycode) {
                //         case KC_K: // KA -> CA
                //             SEND_STRING(SS_TAP(X_BSPC)"ca");
                //             return_state = false; // done.
                //     }
                //     break;
                // case KC_O:
                //     switch (prior_keycode) {
                //         case KC_K: // KO -> CO
                //             SEND_STRING(SS_TAP(X_BSPC)"co");
                //             return_state = false; // done.
                //     }
                //     break;
                // case KC_U:
                //     switch (prior_keycode) {
                //         case KC_K: // KU -> CU
                //             SEND_STRING(SS_TAP(X_BSPC)"qu");
                //             return_state = false; // done.
                //     }
                //     break;
            }
        }
        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior_key timing
    }
    return return_state; //
}

bool sw_win_active = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Do we handle an adaptive key?
    if (!process_adaptive_key(keycode, record)) {
        return false; // took care of that key
    }
    if (!process_caps_word(keycode, record)) {
        return false; // took care of that key
    }
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
        keycode, record
    );
    switch (keycode) {
        case VIMWRITE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;

        case VIMWRITEQUIT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_X) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;

        case VIMQUIT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_LSFT(SS_TAP(X_1)) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;

        case VIMQUITALL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;

        case VIPASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_V) SS_DELAY(100) SS_TAP(X_SPACE) SS_DELAY(100) SS_LCTL(SS_LSFT(SS_TAP(X_V))) SS_DELAY(100) SS_TAP(X_ENTER));
            }
        case LNX_LAST:
            if (record->event.pressed) {
              SEND_STRING(SS_LSFT(SS_TAP(X_1)) SS_DELAY(100) SS_LSFT(SS_TAP(X_4)) SS_DELAY(100) SS_TAP(X_SPACE));
            }
            break;
        case KU_QU:
            if (record->event.pressed) {
                SEND_CAP_STRING("qu", "Qu");
            }
            break;
        case DLSIM:
            if (record->event.pressed) {
                SEND_CAP_STRING("dlsim", "DLSim")
            }
            break;
        case SLACK_CODE:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case SLACK_CODE_PASTE:
            if (record->event.pressed) {
                SEND_STRING("```" SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));
            }
            break;
        case SLACK_FUNC_PASTE:
            if (record->event.pressed) {
                SEND_STRING("`" SS_DELAY(100) SS_LCTL(SS_TAP(X_V)) "`");
            }
            break;
        case COPY_PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_C)) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));
            }
            break;
        case VIM_FSEARCH_PASTE:
            if (record->event.pressed) {
                SEND_STRING("/" SS_DELAY(100) SS_LCTL(SS_TAP(X_V)) SS_TAP(X_ENTER));
            }
            break;
        case VIM_RSEARCH_PASTE:
            if (record->event.pressed) {
                SEND_STRING("?" SS_DELAY(100) SS_LCTL(SS_TAP(X_V)) SS_TAP(X_ENTER));
            }
            break;
        case Q_ENTER:
            if (record->event.pressed) {
                SEND_STRING("q" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;
        case IMPORT_PDB:
            if (record->event.pressed) {
                SEND_STRING("import pdb; pdb.set_trace()");
            }
            break;
        case CAPSWD:
            if (record->event.pressed) {
                caps_word_set(true);  // Activate Caps Word!
            }
            break;
    }
    return true;
}

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case HRM_N:
//         case HRM_E:
//         case SPCNUM:
//         case BSPNAV:
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         default:
//             // Do not select the hold action when another key is tapped.
//             return false;
//     }
// }

void print_layers(void) {
    switch (get_highest_layer(layer_state)) {
        case _HANDS_DOWN:
            oled_write_P(PSTR("Hands"), false);
            oled_write_ln_P(PSTR("Down"), false);
            oled_write_ln_P(PSTR("Neu"), false);
            break;
        case _QWERTY_GAME:
            oled_write_P(PSTR("QWERT"), false);
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _SYM_NUM:
            oled_write_P(PSTR("Symbs"), false);
            oled_write_P(PSTR("Numbs"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpd"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navig"), false);
            break;
        case _BYO_ONOTE_VSC:
            oled_write_P(PSTR("Byobu"), false);
            oled_write_P(PSTR("ONote"), false);
            oled_write_P(PSTR("VCode"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

void print_mods(void) {
    oled_write_P(PSTR("-----\nMods\n-----\n"), false);
    int current_mods = get_mods();
    if (current_mods & MOD_MASK_SHIFT) {
        oled_write_P(PSTR("SHIFT"), false);
    }
    if (current_mods & MOD_MASK_CTRL) {
        oled_write_ln_P(PSTR("CTRL"), false);
    }
    if (current_mods & MOD_MASK_GUI) {
        oled_write_ln_P(PSTR("GUI"), false);
    }
    if (current_mods & MOD_MASK_ALT) {
        oled_write_ln_P(PSTR("ALT"), false);
    }

    int oneshot_mods = get_oneshot_mods();
    if (oneshot_mods & MOD_MASK_CTRL) {
        oled_write_P(PSTR("OSCTL"), false);
    }
    if (oneshot_mods & MOD_MASK_GUI) {
        oled_write_P(PSTR("OSGUI"), false);
    }
    if (oneshot_mods & MOD_MASK_ALT) {
        oled_write_P(PSTR("OSALT"), false);
    }
}


void my_custom_function(void) {

}
