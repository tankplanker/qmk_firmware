#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_7, KC_8, KC_9, \
		KC_4, KC_5, KC_6, \
		KC_1, KC_2, KC_3, \
		LT(1,KC_BSPC), KC_0, KC_DOT \
	),

	[_FN1] = LAYOUT(KC_HOME, KC_UP, KC_PGUP, KC_LEFT, KC_PENT, KC_RGHT, KC_END, KC_DOWN, KC_PGDN, KC_TRNS, KC_INS, KC_DEL)
};
