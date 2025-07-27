/* Copyright 2022 James White <jamesmnw@gmail.com>
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

#define SYM_ESC LT(_SYMBOLS, KC_ESC)
#define NUM_ESC LT(_NUMBERS, KC_ESC)

enum layers {
    _HOMEROWMOD,
    _NUMBERS,
    _SYMBOLS
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * HOMEROWMOD
 * ,-----------------------------------.     ,----------------------------------.
 * |  Q  |   W  |   E    |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |
 * |-----+------+--------+------+------|     |------+------+------+------+------|
 * |  A  |   S  |   D    |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |
 * |-----+------+--------+------+------|     |------+------+------+------+------|
 * |  Z  |   X  |   C    |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |
 * `------------+--------+------+------|     |------+------+------+-------------'
 *              | Esc+Vi | Tab  | Spc  |     | Ent  | BSpc | MO(num) |
 *              `----------------------'     `-----------------------'
 */
[_HOMEROWMOD] = LAYOUT_split_3x5_3(
  KC_Q,           KC_W,         KC_E,          KC_R,         KC_T,    /*|*/    KC_Y,    KC_U,           KC_I,           KC_O,           KC_P,
  LSFT_T(KC_A),   LOPT_T(KC_S), LCMD_T(KC_D),  LCTL_T(KC_F), KC_G,    /*|*/    KC_H,    RCTL_T(KC_J),   RCMD_T(KC_K),   ROPT_T(KC_L),   RSFT_T(KC_SCLN),
  KC_Z,           KC_X,         KC_C,          KC_V,         KC_B,    /*|*/    KC_N,    KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                SYM_ESC,       KC_TAB,       KC_SPC,  /*|*/    KC_ENT,  KC_BSPC,        MO(_NUMBERS)
),
[_NUMBERS] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,      KC_4,     KC_5,          KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  _______, _______, _______,   _______,  _______,       _______,  _______,  _______,  _______,  _______,
  _______, _______, _______,   _______,  _______,       _______,  _______,  _______,  _______,  _______,
                    _______,   _______,  _______,       _______,  _______,  _______
),
/*
 * SYMBOLS
 * ,---------------------------------.     ,----------------------------------.
 * |     |      |      |      |      |     |      |   [  |   @  |   ]  |   -  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |     |      |      |      |      |     |      |   (  |   $  |   )  |   '  |
 * |-----+------+------+------+------|     ,------+------+------+------+------|
 * |     |      |      |      |      |     |      |   {  |   %  |   }  |   =  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |      |      |      |     |      |      |      |
 *              `--------------------'     `--------------------'
 */
[_SYMBOLS] = LAYOUT_split_3x5_3(
  _______, _______, _______,   _______,  _______,       _______,  KC_LBRC,  KC_AT,     KC_RBRC,  KC_MINUS,
  _______, _______, _______,   _______,  _______,       _______,  KC_LPRN,  KC_DOLLAR, KC_RPRN,  KC_QUOTE,
  _______, _______, _______,   _______,  _______,       _______,  KC_LCBR,  KC_PERC,   KC_RCBR,  KC_EQUAL,
                    _______,   _______,  _______,       _______,  _______,  _______
)
};

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_AZURE);
};

enum combos {
    ESC,
    TMUX,
};

const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM tmux_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [ESC] = COMBO(esc_combo, KC_ESC),
    [TMUX] = COMBO(tmux_combo, LCTL(KC_B)),
};
