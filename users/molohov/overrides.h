#pragma once

#include QMK_KEYBOARD_H

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
// const key_override_t r_period_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_DOT, KC_EXLM);
const key_override_t mins_override          = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_PIPE);
// const key_override_t underscore_override    = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_PIPE);
const key_override_t colon_override         = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t period_override        = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_QUES);
const key_override_t slash_override         = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_EXLM);
const key_override_t comma_override         = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_BSLS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    // &left_paran_override,
    // &right_paran_override,
    // &left_squarebracket_override,
    // &right_squarebracket_override,
    // &asterisk_override,
    // &shift_space_underscore,
    // &underscore_override,
    // &r_period_override,
    &period_override,
    &comma_override,
    &colon_override,
    &slash_override,
    &mins_override,
    // &underscore_override,
    NULL // Null terminate the array of overrides!
};
