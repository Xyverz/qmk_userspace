/* Copyright 2020 Eye Oh! Designs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Adding macros to make the keymaps below much easier to read.
#define DELGUI GUI_T(KC_DEL)
#define ALTENT ALT_T(KC_ENT)
#define SCLNCTL CTL_T(KC_SCLN)
#define QUEALT ALT_T(KC_Q)
#define VEEALT ALT_T(KC_V)
#define ZEDCTL CTL_T(KC_Z)
#define ADJUST MO(_ADJUST)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MACLOCK LGUI(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_DVORAK] = LAYOUT_1u(
        KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT, SCLNCTL, QUEALT,  KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    VEEALT,  ZEDCTL,  KC_RSFT,
        KC_LCTL,                   LOWER,   KC_BSPC, DELGUI,      KC_ENT,  KC_SPC,  RAISE,                     KC_RALT
    ),
   [_LOWER] = LAYOUT_1u(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_HOME,     KC_PGUP, XXXXXXX, KC_PLUS, KC_LCBR, KC_RCBR, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,      KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
        _______,                   _______, KC_DEL,  MACLOCK,     _______, KC_INS,  ADJUST,                    _______
    ),

   [_RAISE] = LAYOUT_1u(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_HOME,     KC_PGUP, XXXXXXX, KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,      KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
        _______,                   ADJUST,  KC_DEL,  MACLOCK,     _______, KC_INS,  _______,                   _______
  ),

   [_ADJUST] = LAYOUT_1u(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        _______,                   _______, _______, _______,     _______, _______, _______,                   _______
  )
};
