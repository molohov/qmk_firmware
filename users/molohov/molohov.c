#include "molohov.h"
#include "caps_word.h"

// COMBOS
enum combo_events {
    COMBO_VIM_WRITE,
    COMBO_VIM_WRITEQUIT,
    COMBO_VIM_QUIT,
    COMBO_VIM_QUITALL,
    COMBO_VIM_SHIFTV,
    COMBO_PC_COPY,
    COMBO_PC_CUT,
    COMBO_PC_PASTE,
    COMBO_PC_FIND,
    COMBO_PC_UNDO,
    COMBO_PC_SELECTALL,
    COMBO_PC_COPYPASTE,
    COMBO_WIN_BLUETOOTH,
    COMBO_WIN_CLIP,
    COMBO_LNX_CLS,
    COMBO_LNX_LAST,
    COMBO_SLACK_CODE,
    COMBO_SLACK_CODE_PASTE,
    COMBO_KU_QU,
    // COMBO_EXCLAMATION,
    COMBO_AT,
    COMBO_DOLLAR,
    COMBO_DEL_WORD,
    COMBO_SEMICOLON,
    // COMBO_ESC,
    COMBO_DLSIM,
    COMBO_NEWTAB,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// vim combos rooted from left home row middle finger
// const uint16_t PROGMEM vimwrite[] =     {HRM_N, HRM_T, COMBO_END};
// const uint16_t PROGMEM vimwritequit[] = {HRM_N, KC_D, COMBO_END};
// const uint16_t PROGMEM vimquit[] =      {HRM_N, KC_G, COMBO_END};
// const uint16_t PROGMEM vimquitall[] =   {HRM_N, KC_B, COMBO_END};
// const uint16_t PROGMEM vimshiftv[] =    {HRM_N, KC_P, COMBO_END};

// LEFT HAND
// copy/paste combos on left bottom row
// const uint16_t PROGMEM pc_undo[]      = {KC_W, KC_C, COMBO_END};
// const uint16_t PROGMEM pc_selectall[] = {KC_W, KC_L, COMBO_END};
// const uint16_t PROGMEM pc_copy[]      = {KC_C, KC_L, COMBO_END};
// const uint16_t PROGMEM pc_cut[]       = {KC_C, HRM_N, COMBO_END};
// const uint16_t PROGMEM pc_paste[]     = {KC_L, KC_D, COMBO_END};
// const uint16_t PROGMEM pc_copypaste[] = {KC_C, KC_D, COMBO_END};
// const uint16_t PROGMEM pc_find[]      = {KC_L, HRM_T, COMBO_END};
// const uint16_t PROGMEM pc_clip[]      = {KC_L, HRM_T, COMBO_END};

// this combo mirrors the DW action in vim!
// const uint16_t PROGMEM del_word[] = {KC_W, KC_D, COMBO_END};
// keep shift+V on the left side
const uint16_t PROGMEM vimshiftv[]  = {HRM_N, KC_D, COMBO_END};
const uint16_t PROGMEM slack_code[] = {KC_F, KC_M, COMBO_END};
const uint16_t PROGMEM slack_code_paste[] = {KC_F, KC_M, KC_P, COMBO_END};
// const uint16_t PROGMEM escape[]     = {KC_S, KC_M, COMBO_END};
const uint16_t PROGMEM dlsim[]      = {HRM_N, HRM_T, COMBO_END};
// const uint16_t PROGMEM newtab[]     = {HRM_T, KC_G, COMBO_END};

// RIGHT HAND
// vim combos rooted from right home row middle finger
const uint16_t PROGMEM vimwrite[]     = {HRM_E, HRM_A, COMBO_END};
const uint16_t PROGMEM vimwritequit[] = {HRM_E, KC_U, COMBO_END};
const uint16_t PROGMEM vimquit[]      = {HRM_E, KC_QUOT, COMBO_END};
const uint16_t PROGMEM vimquitall[]   = {HRM_E, KC_SLSH, COMBO_END};
// linux combos
// const uint16_t PROGMEM lnx_cls[]  = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM lnx_last[] = {HRM_I, KC_UNDS, COMBO_END};
// const uint16_t PROGMEM ku_qu[]    = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM at[]     = {KC_DOT, KC_UNDS, COMBO_END};
const uint16_t PROGMEM dollar[] = {KC_UNDS, KC_SLSH, COMBO_END};
// . + , = ;
const uint16_t PROGMEM semicolon[]     = {KC_DOT, KC_COMM, COMBO_END};
// const uint16_t PROGMEM win_bluetooth[] = {KC_K, KC_Y, COMBO_END};

combo_t key_combos[] = {
    [COMBO_VIM_WRITE]       = COMBO(vimwrite,       VIMWRITE),
    [COMBO_VIM_WRITEQUIT]   = COMBO(vimwritequit,   VIMWRITEQUIT),
    [COMBO_VIM_QUIT]        = COMBO(vimquit,        VIMQUIT),
    [COMBO_VIM_QUITALL]     = COMBO(vimquitall,     VIMQUITALL),
    [COMBO_VIM_SHIFTV]      = COMBO(vimshiftv,      S(KC_V)),
    // [COMBO_PC_COPY]         = COMBO(pc_copy,        PC_COPY),
    // [COMBO_PC_CUT]          = COMBO(pc_cut,         PC_CUT),
    // [COMBO_PC_PASTE]        = COMBO(pc_paste,       PC_PASTE),
    // [COMBO_PC_FIND]         = COMBO(pc_find,        PC_FIND),
    // [COMBO_PC_UNDO]         = COMBO(pc_undo,        PC_UNDO),
    // [COMBO_PC_SELECTALL]    = COMBO(pc_selectall,   PC_SALL),
    // [COMBO_PC_COPYPASTE]    = COMBO(pc_copypaste,   COPY_PASTE),
    // [COMBO_WIN_BLUETOOTH]   = COMBO(win_bluetooth,  G(KC_K)),
    // [COMBO_LNX_LAST]        = COMBO(lnx_last,       LNX_LAST),
    // [COMBO_LNX_CLS]         = COMBO(lnx_cls,        C(KC_L)),
    // [COMBO_KU_QU]           = COMBO(ku_qu,          KU_QU),
    [COMBO_AT]              = COMBO(at,             KC_AT),
    [COMBO_DOLLAR]          = COMBO(dollar,         KC_DLR),
    [COMBO_SEMICOLON]       = COMBO(semicolon,      KC_SCLN),
    // [COMBO_DEL_WORD]        = COMBO(del_word,       C(KC_DEL)),
    // [COMBO_ESC]             = COMBO(escape,         KC_ESC),
    [COMBO_DLSIM]           = COMBO(dlsim,          DLSIM),
    [COMBO_SLACK_CODE]      = COMBO(slack_code,     SLACK_CODE),
    [COMBO_SLACK_CODE_PASTE] = COMBO(slack_code_paste, SLACK_CODE_PASTE),
    // [COMBO_NEWTAB]          = COMBO(newtab,         C(KC_T)),
    // [COMBO_WIN_CLIP]        = COMBO(pc_clip,        PC_CLIP),
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
// shift . gives ?
const key_override_t period_to_quesmark = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);
// shift / gives !
const key_override_t underscore_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_EXLM);
// shift , gives :
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EQL);
// shift : gives ;
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
// shift / gives -
const key_override_t slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_MINS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    // &left_paran_override,
    // &right_paran_override,
    // &left_squarebracket_override,
    // &right_squarebracket_override,
    // &asterisk_override,
    // &shift_space_underscore,
    &period_to_quesmark,
    &underscore_override,
    &comma_override,
    &colon_override,
    &slash_override,
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
            }
        }
        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior_key timing
    }
    return return_state; //
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Do we handle an adaptive key?
    if (!process_adaptive_key(keycode, record)) {
        return false; // took care of that key
    }
    if (!process_caps_word(keycode, record)) {
        return false; // took care of that key
    }
    switch (keycode) {
        case VIMWRITE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;

        case VIMWRITEQUIT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_X) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;

        case VIMQUIT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_LSFT(SS_TAP(X_1)) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;

        case VIMQUITALL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_ENTER));
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

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HRM_N:
        case HRM_E:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

void my_custom_function(void) {

}
