#include QMK_KEYBOARD_H
#include "tankplanker.h"

#define WW1 LCTL(KC_1)
#define WW2 LCTL(KC_2)
#define WW3 LCTL(KC_3)
#define WW4 LCTL(KC_4)
#define WW5 LCTL(KC_5)
#define WW6 LCTL(KC_6)
#define WM1 LGUI(KC_1)
#define WM2 LGUI(KC_2)
#define WM3 LGUI(KC_3)
#define WM4 LGUI(KC_4)
#define WM5 LGUI(KC_5)
#define WM6 LGUI(KC_6)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Qwerty */
    KC_1, 	 KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH,
    KC_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TD(BCK_CTL),
    TD(L_SHFT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(UA_CTL), TD(R_SHFT),
    KC_LCTL,KC_LGUI,KC_RGUI,KC_LALT,  LT(1, KC_ENT),  LT(_LOWER, KC_SPC), KC_RALT,TD(LA_CTL), TD(DA_CTL), TD(RA_CTL)
  ),
  [1] = LAYOUT( /* LOWER */
    WW1, 	 WW2,    WW3,    WW4,    WW5,    WW6,
    RESET,  KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS,
    KC_TRNS, KC_MINS, KC_EQL, KC_QUOT, KC_SCLN, KC_PAST, TD(LA_CTL), TD(DA_CTL), TD(UA_CTL),TD(RA_CTL), KC_TRNS, TD(DEL_CTL),
    KC_TRNS,KC_TILDE,  KC_AT, KC_HASH, KC_PIPE, KC_CIRCUMFLEX, KC_EQUAL, KC_QUOTE,KC_LBRACKET, KC_RBRACKET,  KC_TRNS,KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT( /* RAISE */
    WM1, 	 WM2,    WM3,    WM4,    WM5,    WM6,
    KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,  KC_F7,    KC_F8,  KC_F9,    KC_F10, KC_NONUS_BSLASH,
    RESET,  KC_PPLS, UNDERSCORE, KC_BSLS, COLON, KC_TRNS, KC_TRNS,KC_TRNS,  DB_QUOTE,KC_CIRCUMFLEX,   KC_TRNS, KC_ENT,
    KC_TRNS, KC_TILDE, KC_AT,KC_BSLASH, KC_PIPE,  KC_PIPE, KC_CIRCUMFLEX, DB_QUOTE,L_CURBR, R_CURBR,TD(PUP_CTL),KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, TD(HOME_CTL), TD(PDWN_CTL),TD(END_CTL)
  )
};


void matrix_init_user(void) {
  /*set Power LED to output and low*/
 setPinOutput(B6);
  writePinHigh(B6);
  setPinOutput(B5);
  writePinHigh(B5);
  setPinOutput(B4);
  writePinHigh(B4);
}

layer_state_t layer_state_set_user(layer_state_t state)
{ if (layer_state_cmp(state, 1)) {
        writePinLow(B4);
        writePinHigh(B5);
    } else if (state & (1<<2)) {
        writePinLow(B5);
        writePinHigh(B4);
    } else if (state & (1<<3)) {
        writePinHigh(B5);
        writePinHigh(B4);
    } else {
        writePinLow(B5);
        writePinLow(B4);
    }
    return state;
}

