#include "molohov.h"
#include "swapper.h"
#include "caps_word.h"
#include "combos.h"

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
const key_override_t period_override = ko_make_basic(MOD_BIT(KC_LSFT), KC_DOT, KC_QUES);
const key_override_t r_period_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_DOT, KC_EXLM);
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
    &r_period_override,
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
bool sw_tab_active = false;


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
    update_swapper(
        &sw_tab_active, KC_LCTL, KC_TAB, SW_TAB,
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
        case SEND3D:
            if (record->event.pressed) {
                SEND_CAP_STRING("3d", "3D")
            }
            break;
        case SENDXLA:
            if (record->event.pressed) {
                SEND_CAP_STRING("xla", "XLA")
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

#ifdef OLED_ENABLE
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

    // bool caps_word_active = caps_word_get();
    // if (caps_word_active) {
    //     oled_write_P(PSTR("CAPS"), false);
    // }

}
#endif

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPCNUM:
            return true;
        default:
            return false;
    }
}
