#include "molohov.h"
#include "swapper.h"
#include "caps_word.h"
// #include "combos.h"
#include "overrides.h"

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
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_F:
                    switch (prior_keycode) {
                        case KC_X: //XF -> XC
                            tap_code(KC_C);
                            return_state = false; // done.
                            break;
                        case KC_M: // MF -> LF
                            SEND_STRING(SS_TAP(X_BSPC)"lf");
                            return_state = false; // done.
                            break;
                    }
                    break;
                // case KC_C:
                //     switch (prior_keycode) {
                //         case KC_L: //LC -> LF
                //             tap_code(KC_F);
                //             return_state = false; // done.
                //     }
                //     break;
                case KC_DOT:
                    switch (prior_keycode) {
                        case KC_Q: //Q. -> QU
                            tap_code(KC_U);
                            return_state = false; // done.
                            break;
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
                // SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_ENTER));
                tap_code(KC_ESC);
                SEND_STRING(":w");
                tap_code(KC_ENT);

            }
            break;

        case VIMWRITEQUIT:
            if (record->event.pressed) {
                // SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_X) SS_DELAY(100) SS_TAP(X_ENTER));
                tap_code(KC_ESC);
                SEND_STRING(":x");
                tap_code(KC_ENT);
            }
            break;

        case VIMQUIT:
            if (record->event.pressed) {
                // SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_LSFT(SS_TAP(X_1)) SS_DELAY(100) SS_TAP(X_ENTER));
                tap_code(KC_ESC);
                SEND_STRING(":q!");
                tap_code(KC_ENT);
            }
            break;

        case VIMQUITALL:
            if (record->event.pressed) {
                // SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(200) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_TAP(X_Q) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_ENTER));
                tap_code(KC_ESC);
                SEND_STRING(":qa");
                tap_code(KC_ENT);
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
        case TRTLLM:
            if (record->event.pressed) {
                SEND_CAP_STRING("trt-llm", "TRT-LLM")
            }
            break;
        case HOMEDIR:
            if (record->event.pressed) {
                SEND_STRING("~/");
            }
            break;
        // case SEND3D:
        //     if (record->event.pressed) {
        //         SEND_CAP_STRING("3d", "3D")
        //     }
        //     break;
        // case SENDXLA:
        //     if (record->event.pressed) {
        //         SEND_CAP_STRING("xla", "XLA")
        //     }
        //     break;
        // case SENDONNX:
        //     if (record->event.pressed) {
        //         SEND_CAP_STRING("onnx", "ONNX")
        //     }
        //     break;
        case SENDSMILE:
            if (record->event.pressed) {
                SEND_CAP_STRING(":)", ":(")
            }
            break;
        case SENDARROW:
            if (record->event.pressed) {
                SEND_CAP_STRING("->", "<-")
            }
            break;
        case SLACK_CODE:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            break;
        case SLACK_CODE_PASTE:
            if (record->event.pressed) {
                SEND_STRING("```" SS_DELAY(400) SS_TAP(X_ENTER) SS_LCTL(SS_TAP(X_V)));
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
        case VIM_LIND:
            if (record->event.pressed) {
                SEND_STRING("<<");
            }
            break;
        case VIM_RIND:
            if (record->event.pressed) {
                SEND_STRING(">>");
            }
            break;
        case QUOTS:
            if (record->event.pressed) {
                SEND_CAP_STRING("''", "\"\"");
                tap_code(KC_LEFT);
            }
            break;
        case GRVS:
            if (record->event.pressed) {
                SEND_STRING("``");
                tap_code(KC_LEFT);
            }
            break;
        case PRNS:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            break;
        case BRCS:
            if (record->event.pressed) {
                SEND_STRING("[]");
                tap_code(KC_LEFT);
            }
            break;
        case CBRS:
            if (record->event.pressed) {
                SEND_STRING("{}");
                tap_code(KC_LEFT);
            }
            break;
        case IMPORT_PDB:
            if (record->event.pressed) {
                SEND_STRING("import pdb; pdb.set_trace()");
            }
            break;
        case CAPSWD:
            if (record->event.pressed) {
                // caps_word_set(true);  // Activate Caps Word!
                caps_word_on();
            }
            break;
        case ONEHUNDRED:
            if (record->event.pressed) {
                SEND_STRING("100");
            }
            break;
        case DTYPE:
            if (record->event.pressed) {
                SEND_CAP_STRING("dtype", "DTYPE");
            }
            break;
        case SENDE2E:
            if (record->event.pressed) {
                SEND_CAP_STRING("e2e", "E2E");
            }
            break;
        case SENDYTSENG:
            if (record->event.pressed) {
                SEND_CAP_STRING("yu-hsuan", "Yu-Hsuan");
            }
            break;
        case SENDVLLM:
            if (record->event.pressed) {
                SEND_CAP_STRING("vllm", "vLLM");
            }
            break;
        case PC_SLACK:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("q") SS_DELAY(50) "< slack" SS_DELAY(50) SS_TAP(X_ENTER));
            }
            break;
        case MD_TODO:
            if (record->event.pressed) {
                SEND_STRING("- [ ] ");
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
        case _OTHER:
            oled_write_P(PSTR("Other"), false);
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPCNAV:
            return TAPPING_TERM + 50;
        case ENTSFT:
        case TABSFT:
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}

// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SPCNAV:
//             return true;
//         default:
//             return false;
//     }
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//    return update_tri_layer_state(state, _SYM_NUM, _NAV, _BYO_ONOTE_VSC);
// }
