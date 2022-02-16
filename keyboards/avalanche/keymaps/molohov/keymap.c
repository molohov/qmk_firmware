
/*
qmk compile -kb avalanche/rev2 -km default_rev2
qmk flash -kb avalanche/rev2 -km default_rev2
*/

#include "molohov.h"


/*
 * Base Layer: SAMPLE
 *                                     ╭────────╮                                                                         ╭────────╮
 *                            ╭────────╯        ╰────────╮                                                       ╭────────╯        ╰────────╮
 *                            │        │        │        ╰────────╮                                     ╭────────╯        │        │        │
 *          ╭────────╮────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╭────────╮
 *          │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 *          │        │        │        │        │        ╰────────╯                                     ╰────────╯        │        │        │        │        │
 *          ╰────────╯────────╯        ╰────────╯        │        │                                     │        │        ╰────────╯        ╰────────╰────────╯
 *          │        │        ╰────────╯        ╰────────╯        │                                     │        ╰────────╯        ╰────────╯        │        │
 *          │        │        │        │        │        ╰────────╯ ╭────────╮               ╭────────╮ ╰────────╯        │        │        │        │        │
 * ╭────────╯────────╯────────╯        ╰────────╯        │        │ │        │               │        │ │        │        ╰────────╯        ╰────────╰────────╰────────╮
 * │        │        │        ╰────────╯        ╰────────╯        │ │        │               │        │ │        ╰────────╯        ╰────────╯        │        │        │
 * │        │        │        │        │        │        ╰────────╯ ╰─encodr─╯               ╰─encodr─╯ ╰────────╯        │        │        │        │        │        │
 * ╰────────╮────────╯────────╯        ╰────────╯        │        │  ╭────────╮             ╭────────╮  │        │        ╰────────╯        ╰────────╰────────╭────────╯
 *          │        │        ╰────────╯        ╰────────╯        │  │        │             │        │  │        ╰────────╯        ╰────────╯        │        │
 *          │        │        │                ╭────────╮╰────────╯  │        │             │        │  ╰────────╯╭────────╮                │        │        │
 *          ╰────────╯────────╯      ╭────────╮│        ╰────────╮   ╰────────╯             ╰────────╯   ╭────────╯        │╭────────╮      ╰────────╰────────╯
 *                                   │        ││        │        ╰────────╮                     ╭────────╯        │        ││        │
 *                                   │        │╰────────╯        │        ╰────────╮   ╭────────╯        │        ╰────────╯│        │
 *                                   ╰────────╯         ╰────────╯        │        │   │        │        ╰────────╯         ╰────────╯
 *                                                               ╰────────╯        │   │        ╰────────╯
 *                                                                        ╰────────╯   ╰────────╯
 * [_SAMPLE] = LAYOUT(
                KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
                KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
    XXXXXXX,    KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_LCBR,    KC_RCBR,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,
                KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_BSPC,    KC_EQL,     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
                                        XXXXXXX,    KC_LCTL,    KC_SPC,     KC_LSFT,    KC_ENT,     _______,    _______,    _______,    _______,    KC_MUTE
 * ),
 */
enum layer {
    _HANDS_DOWN,
    _NUM_SYM,
    _NAV,
    _NUMPAD,
    _QWERTY_GAME,
};
#define  QWERTY     TG(_QWERTY_GAME)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HANDS_DOWN] = LAYOUT(
                RESET,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       RESET,
                _______,    KC_X,       KC_F,       KC_M,       KC_P,       KC_B,                               KC_SLSH,    KC_DOT,     KC_UNDS,    KC_COMM,    KC_Q,       _______,
    PC_SCSH,    KC_Z,       KC_R,       HRM_S,      HRM_N,      HRM_T,      KC_G,       PC_LOCK,    KC_MPLY,    KC_QUOT,    HRM_A,      HRM_E,      HRM_I,      KC_H,       KC_J,       _______,
                KC_HOME,    KC_W,       KC_C,       KC_L,       KC_D,       KC_V,       PC_BSWD,    CAPSWD,     KC_COLN,    KC_U,       KC_O,       KC_Y,       KC_K,       KC_END,
                                        QWERTY,     ALTESC,     GUIDEL,     BSPNAV,     TABNUM,     KC_ENT,     SPCNUM,     KC_ESC,     VS_COMT,    WINRUN
    ),

    [_NUM_SYM] = LAYOUT(
                _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
                _______,    _______,    KC_PERC,    KC_HASH,    KC_LCBR,    KC_LABK,                            KC_RABK,    KC_RCBR,    KC_PIPE,    KC_AMPR,    _______,    _______,
    _______,    _______,    KC_COLN,    HRM_MINS,   HRM_PAST,   HRM_LPRN,   KC_LBRC,    _______,    _______,    KC_RBRC,    HRM_RPRN,   HRM_BSLS,   HRM_GRV,    KC_EQL,     _______,    _______,
                _______,    KC_9,       KC_3,       KC_1,       KC_5,       KC_7,       KC_F11,     KC_F12,     KC_8,       KC_2,       KC_0,       KC_4,       KC_6,       _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_NAV] = LAYOUT(
                _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
                _______,    _______,    PC_SALL,    PC_EXIT,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    PC_UNDO,    PC_CUT,     PC_COPY,    PC_PASTE,   _______,    _______,    _______,    VS_EDIT,    KC_LEFT,    KC_UP,      KC_RGHT,    VS_TERM,    _______,    _______,
                _______,    KC_SLSH,    KC_QUES,    PC_FIND,    PC_CLIP,    _______,    _______,    _______,    VS_EGRP,    VS_PEDT,    KC_DOWN,    VS_NEDT,    _______,    _______,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [_NUMPAD] = LAYOUT(
                _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,    _______,                            KC_PSLS,    KC_7,       KC_8,       KC_9,       _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PPLS,    KC_4,       KC_5,       KC_6,       KC_EQL,     KC_COMM,    _______,
                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PAST,    KC_1,       KC_2,       KC_3,       KC_PMNS,    KC_DOT,
                                        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,       _______,    _______
    ),

    [_QWERTY_GAME] = LAYOUT(
                KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
                KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
    XXXXXXX,    KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       _______,    _______,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,
                KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       _______,    _______,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    XXXXXXX,
                                        XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
};


#ifdef OLED_ENABLE

// static void render_logo(void) {

//     static const char PROGMEM gimli_logo[] = {
//         // 'gimli-logo', 128x32px
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0x7c, 0x7c, 0x3c, 0x3c, 0x3c, 0x3c,
//         0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x1c, 0x1c, 0x0c, 0x0c, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x0f, 0x8f, 0x8f, 0xcf, 0xc6,
//         0x02, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x0f, 0x8f, 0x8f, 0xcf, 0xc6, 0x02, 0x00,
//         0x18, 0x18, 0xb8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x78, 0xfc, 0xfe, 0xfe, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0x7f, 0x7b, 0xf9, 0xf9, 0xf9, 0xf8, 0xf8, 0x78, 0xb8, 0x98, 0x18, 0x08,
//         0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
//         0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7e, 0xfc, 0xf8, 0xf8, 0xf0,
//         0xf0, 0xf8, 0xf8, 0xfc, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//         0x00, 0x00, 0xf0, 0xf0, 0xf8, 0xf8, 0x7c, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
//         0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x3f, 0x7f, 0x7f,
//         0xff, 0xff, 0xff, 0xf7, 0xe7, 0xe7, 0xc7, 0x87, 0x87, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06, 0x07, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//         0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0x01,
//         0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf8, 0xf8, 0x7c, 0x7e, 0x3e, 0x3f, 0x1f, 0x0f, 0x00,
//         0x00, 0x00, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0x3e, 0x3e, 0x3c, 0x3c, 0x3c,
//         0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x3f,
//         0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x00
//     };

//     oled_write_raw_P(gimli_logo, sizeof(gimli_logo));
// }

// static void render_face(void) {

//     static const char PROGMEM gimli_face[] = {
//         // 'gimli-face', 32x72px
// 0x3f, 0x3f, 0x1f, 0x1f, 0x8f, 0x8f, 0xcf, 0xc7, 0xc7, 0xc7, 0xc7, 0x01, 0x00, 0x00, 0xf8, 0xf8,
// 0xf8, 0x00, 0x01, 0x41, 0xe7, 0xc7, 0xc7, 0xc7, 0xc7, 0x8f, 0x8f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f,
// 0x1e, 0x1e, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x00, 0x80, 0x30, 0x09, 0x01,
// 0x09, 0x30, 0x80, 0x00, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x1e, 0x1c,
// 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x03, 0x20, 0xcc, 0x11, 0x38, 0x78, 0x44,
// 0xc4, 0x60, 0x01, 0xcc, 0x20, 0x00, 0x0f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
// 0xff, 0xfe, 0xde, 0xce, 0xce, 0x1e, 0x1e, 0xde, 0xde, 0xde, 0x1e, 0x38, 0x31, 0xb2, 0x92, 0x92,
// 0x92, 0xb2, 0x39, 0x7c, 0x3e, 0x9e, 0xde, 0xde, 0x5e, 0x1e, 0x8e, 0xce, 0xce, 0xfe, 0xff, 0xfe,
// 0xf7, 0xef, 0xff, 0xff, 0xff, 0xef, 0xe6, 0xf6, 0xfb, 0xd9, 0x4c, 0x60, 0xff, 0xff, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0xf4, 0x6c, 0xd9, 0xfb, 0xf3, 0xf6, 0xef, 0xef, 0xff, 0xff, 0xff, 0xe7, 0xf3,
// 0xf8, 0xf1, 0x01, 0x03, 0x07, 0xe3, 0xf1, 0x71, 0x31, 0x11, 0x18, 0x00, 0x00, 0x01, 0x01, 0x03,
// 0x03, 0x01, 0x00, 0x00, 0x18, 0x11, 0x31, 0x71, 0xf1, 0xf1, 0xc3, 0x03, 0x01, 0x01, 0xf8, 0xf8,
// 0x1f, 0x3f, 0x20, 0x00, 0x00, 0x3f, 0x03, 0x00, 0x80, 0x00, 0x00, 0x80, 0xc3, 0xc1, 0xc1, 0x01,
// 0x83, 0xc1, 0xc1, 0x83, 0x00, 0x00, 0x80, 0x80, 0x01, 0x1f, 0x3f, 0x00, 0x00, 0x3f, 0x3f, 0x1f,
// 0x1e, 0x00, 0x38, 0x38, 0x9c, 0xc6, 0x60, 0xff, 0xff, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
// 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xfe, 0x62, 0xce, 0x9c, 0x38, 0x18, 0x00, 0x1f,
// 0xfe, 0xf8, 0x07, 0x17, 0x13, 0x08, 0x1c, 0x3f, 0x3f, 0x7f, 0xf3, 0x80, 0x1f, 0x7f, 0xff, 0xff,
// 0xff, 0xff, 0x7f, 0x07, 0xc1, 0x7f, 0x3f, 0x3f, 0x3f, 0x0c, 0x09, 0x17, 0x17, 0x03, 0xfe, 0xfe
//     };

//     oled_write_raw_P(gimli_face, sizeof(gimli_face));
// }

static void print_layers(void) {
    // Print current mode
    // oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    // oled_write_ln_P(PSTR("layer"), false);
    // render_face();
    // oled_set_cursor(0,12);
    // oled_write_P(PSTR("BUH'S"), false);
    // oled_write_P(PSTR("BOARD"), false);
    // oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _HANDS_DOWN:
            // oled_write_P(PSTR("Hands"), false);
            // oled_write_ln_P(PSTR("Down"), false);
            // oled_write_ln_P(PSTR("Neu"), false);
            if (is_keyboard_master()) {
                oled_write_ln_P(PSTR("  VSCP X F M P B"), false);
                oled_write_P(   PSTR("SCRN Z R S N T G LOCK"), false);
                oled_write_P(   PSTR("  HOME W C L D V CBSP"), false);
                oled_write_P(   PSTR("NUM VC GDEL SBSP CTAB"), false);
            } else {
                oled_write_P(   PSTR("        - . / , Q LRS"), false);
                oled_write_P(   PSTR("   PLAY ' A E I H J"), false);
                oled_write_P(   PSTR("   SLCK = U O Y K END"), false);
                oled_write_P(   PSTR("AEN LSPC LESC VCM QWE"), false);
            }
            break;
        case _QWERTY_GAME:
            // oled_write_P(PSTR("QWERT"), false);
            // oled_write_ln_P(PSTR("Game"), false);
            oled_write_ln_P(PSTR("ESC Q W E R T"), false);
            oled_write_ln_P(PSTR("SFT A S D F G"), false);
            oled_write_ln_P(PSTR("CTL Z X C V B"), false);
            oled_write_ln_P(PSTR("XXX CTL SPC SFT ENT"), false);
            break;
        case _NUM_SYM:
            // oled_write_P(PSTR("Navig"), false);
            // oled_write_P(PSTR("Symbs"), false);
            // oled_write_P(PSTR("Numbs"), false);
            oled_write_ln_P(PSTR("  F1 F2 F3 F4 F5"), false);
            oled_write_ln_P(PSTR("  &  \%  \\  [  ]"), false);
            oled_write_ln_P(PSTR("/ :  `  *  (  )"), false);
            oled_write_ln_P(PSTR("  7  3  1  5  9  F11"), false);
            break;
        // case _BYO_ONOTE_VSC:
        //     // oled_write_P(PSTR("Byobu"), false);
        //     // oled_write_P(PSTR("ONote"), false);
        //     // oled_write_P(PSTR("VCode"), false);
        //     oled_write_P(PSTR("      OIM OTO OQS PDB"), false);
        //     oled_write_P(PSTR("KL DSF VSP HSP CL FPN"), false);
        //     break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    // oled_write_P(PSTR("\n"), false);
    // led_t led_usb_state = host_keyboard_led_state();
    // oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

// static void print_mods(void) {
//     int current_mods = get_mods();
//     if (current_mods & MOD_MASK_SHIFT) {
//         oled_write_P(PSTR("SHIFT"), false);
//     }
//     if (current_mods & MOD_MASK_CTRL) {
//         oled_write_ln_P(PSTR("CTRL"), false);
//     }
//     if (current_mods & MOD_MASK_GUI) {
//         oled_write_ln_P(PSTR("GUI"), false);
//     }
//     if (current_mods & MOD_MASK_ALT) {
//         oled_write_ln_P(PSTR("ALT"), false);
//     }
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    oled_clear();
    if (is_keyboard_master()) {
        print_layers();
        // print_mods();
    } else {
        print_layers();
        // render_logo();
        // print_mods();
    }
    return false;
}

#endif



// Lighting layers
// const rgblight_segment_t PROGMEM chewies_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {7, 4, HSV_RED}, // Light 2 LEDs, starting with 35 and ending on 36
//     {44, 4, HSV_RED}  // Light 2 LEDs
// );
// const rgblight_segment_t PROGMEM chewies_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( // default layer
//     {7, 4, HSV_PURPLE}, // Light 2 LEDs
//     {44, 4, HSV_PURPLE}  // Light 2 LEDs
// );
// const rgblight_segment_t PROGMEM chewies_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( // Raise layer
//     {7, 4, HSV_BLUE}, // Light 2 LEDs
//     {44, 4, HSV_BLUE}//,  // Light 2 LEDs
//     //{45, 1, HSV_TEAL},  // Light 1 LED under I
//     //{51, 3, HSV_TEAL}  // Light 3 LEDs under J,K,L
// );


// // The array of lighting layers. Latter layers take precedence.
// const rgblight_segment_t* const PROGMEM chewies_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     chewies_capslock_layer,
//     chewies_layer1_layer, // Overrides caps lock layer
//     chewies_layer2_layer

// );

// // enable the lighting layers
// void keyboard_post_init_user(void) {
//     rgblight_layers = chewies_rgb_layers;
// }

// // turn on caps lock lighting layer
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

// // default state
// // layer_state_t default_layer_state_set_user(layer_state_t state) {
// //     rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY_GAME));
// //     return state;
// // }

// // Raise and Lower states
// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _NAV_NUM_SYM));
//     return state;
// }
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
        case _HANDS_DOWN:
            alt_tab_timer = timer_read();
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
            }
            if (clockwise) {
                tap_code16(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
            break;
        case _NUM_SYM:
            if (clockwise) {
                tap_code16(C(G(KC_RIGHT)));
            } else {
                tap_code16(C(G(KC_LEFT)));
            }
            break;
        }

    } else if (index == 1) {
        switch(biton32(layer_state)) {
        case _HANDS_DOWN:
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break;
        case _NUM_SYM:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_scan_user(void) {
    static bool has_ran_yet = false;
    if (!has_ran_yet) {
        has_ran_yet = true;
        // rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 3);
        // rgblight_mode(RGBLIGHT_MODE_BREATHING + 1);
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv(HSV_WHITE);
    }
    if (is_alt_tab_active) {
      if (timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
      }
    }
};

