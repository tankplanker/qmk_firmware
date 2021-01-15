#include QMK_KEYBOARD_H
#include "tankplanker.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_2x2u(
		KC_GESC,    KC_Q,       KC_W,       KC_E,   KC_R,           KC_T,   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_SLSH,
		KC_TAB,     KC_A,       KC_S,       KC_D,   KC_F,           KC_G,   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    TD(BCK_CTL),
		KC_QUOTE,   KC_Z,       KC_X,       KC_C,   KC_V,           KC_B,   KC_N,       KC_M,       KC_COMM,    KC_DOT,     TD(UA_CTL), KC_BSLS,
		TD(X_CTL),  TD(V_CTL),  TD(X_CTL),  TD(L_SHFT), LT(_LOWER, KC_ENTER),   LT(_RAISE, KC_SPC), TD(R_SHFT), TD(LA_CTL), TD(DA_CTL), TD(RA_CTL)),
	[1] = LAYOUT_planck_2x2u(
		RESET,      KC_1,       KC_2,       KC_3,   KC_4,   		KC_5,   KC_6,   	KC_7,       KC_8,     	KC_9,       KC_0,       KC_BSLS,
        KC_TRNS,    KC_MINS,    KC_EQL,     KC_QUOT,KC_SCLN,        KC_TRNS,KC_MINS,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    TD(DEL_CTL),
		KC_TILDE,   KC_AT,      KC_HASH,    KC_PIPE,KC_CIRCUMFLEX,  KC_EQUAL,KC_QUOTE,  KC_NONUS_HASH,KC_LBRC	,KC_RBRC,	TD(PUP_CTL),KC_TRNS,
		KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 				KC_TRNS, 			KC_TRNS, 	TD(HOME_CTL),TD(PDWN_CTL),TD(END_CTL)),
	[2] = LAYOUT_planck_2x2u(
		RGB_TOG, 	KC_F2, 		KC_F3, 		KC_F4, 	KC_F5, 			KC_F6, 	KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_NONUS_BSLASH,
		RGB_MOD,	KC_PPLS, 	KC_UNDS, 	KC_BSLS,COLON,          KC_MINS,KC_EQL,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_GRV,     KC_TRNS,
		RGB_M_G,    KC_TILDE,   KC_AT,      KC_HASH,KC_PIPE,        KC_CIRC,KC_EQUAL,   KC_QUOTE,   KC_LBRACKET,KC_RBRACKET,KC_GRAVE,   KC_TRNS,
		RGB_M_SW,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,            KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY),
};

void keyboard_post_init_user(void) {
 // rgblight_set_clipping_range(10, 10);
  rgblight_set_effect_range(0,8);
  rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
//  rgblight_set_effect_range(5,10);
 // rgblight_sethsv_noeeprom(HSV_AZURE);
  //RGBLIGHT_RAINBOW_SWIRL_RANGE(50);
   rgblight_set_effect_range(0,8);
  rgblight_mode(25);
  rgblight_set();
};
