/* Copyright 2019 Ryota Goto
 *
 * This program is free software: you can redistribute it and/or modify`
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
#include "tankplanker.h"
/*
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
    K300, K301, K302,     K304,       K306,       K308,   K309, K310, K311  \
*/

#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)
#define COLON LSFT(KC_SCLN)
#define DB_QUOTE LSFT(KC_QUOTE)
#define UNDERSCORE LSFT(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Base */
    KC_GESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH,
    TD(TABCAP),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TD(BCK_CTL),
    TD(L_SHFT), KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(R_SHFT),
    KC_LCTL, KC_NO, KC_LALT,LT(1, KC_ENT),KC_LWIN,LT(2, KC_SPC),      KC_RALT,  KC_NO, KC_RCTL
  ),
  [1] = LAYOUT_all( /* Extra Keys */
    RESET, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
    KC_TRNS, KC_MINS, KC_EQL, KC_QUOT, KC_SCLN, KC_PAST, TD(LA_CTL), TD(DA_CTL), TD(UA_CTL),TD(RA_CTL) , KC_TRNS,TD(DEL_CTL),
    KC_TRNS, KC_TILDE,  KC_AT, KC_HASH, KC_PIPE, KC_CIRCUMFLEX, KC_EQUAL,  KC_GRAVE, KC_QUOTE,KC_LBRACKET, KC_RBRACKET,  KC_TRNS,
    KC_TRNS, KC_NO, KC_TRNS,          KC_TRNS,          KC_TRNS,     KC_TRNS,      KC_TRNS, KC_NO, KC_TRNS
  ),
  [2] = LAYOUT_all( /* Num and FN */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  KC_NONUS_BSLASH,
    KC_TRNS, KC_PPLS,  UNDERSCORE, KC_HASH, COLON, KC_CIRCUMFLEX,   TD(HOME_CTL), TD(PDWN_CTL), TD(PUP_CTL),TD(END_CTL), KC_TRNS,KC_TRNS,
    KC_TRNS, KC_TILDE, KC_AT,KC_BSLASH, KC_PIPE,  KC_PIPE, KC_CIRCUMFLEX,   KC_TRNS,  DB_QUOTE,   L_CURBR,    R_CURBR,   KC_TRNS,
    KC_TRNS, KC_NO, KC_TRNS,          KC_TRNS,          KC_TRNS,     KC_TRNS,      KC_TRNS, KC_NO, KC_TRNS
  )
};

