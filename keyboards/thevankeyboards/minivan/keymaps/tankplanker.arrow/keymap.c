#include QMK_KEYBOARD_H


extern keymap_config_t keymap_config;

//Setup consts for LED modes
#define LEDMODE_ON 1 //always on
#define LEDMODE_OFF 0 //always off
#define LEDMODE_MODS 2 //On with modifiers
#define LEDMODE_BLINKIN 3 //blinkinlights - % chance toggle on keypress
#define LEDMODE_KEY 4 //On with any keypress, off with key release
#define LEDMODE_ENTER 5 // On with enter key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_arrow(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_F5, LT(1,KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSPC, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, LT(2,KC_QUOT), KC_LCTL, KC_LALT, KC_LGUI, KC_ENT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT_arrow(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_TAB, KC_QUOT, KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_DOWN, KC_UP, KC_LEFT, KC_RGHT, KC_DEL, KC_LSFT, KC_NUBS, KC_SLSH, KC_BSLS, KC_JYEN, KC_QUOT, KC_NUHS, KC_NO, KC_NO, KC_INS, KC_PGUP, KC_PSCR, KC_LCTL, KC_LALT, KC_APP, KC_ENT, KC_SPC, KC_RALT, KC_HOME, KC_PGDN, KC_END),
	[2] = LAYOUT_arrow(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MSTP, KC_MFFD)
};



void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    // Set up RGB effects on _only_ the third LED (index 2)
    rgblight_set_effect_range(0, 13);
    // Set LED effects to breathing mode in a tealish blue color
    rgblight_sethsv_noeeprom(0, 255, 255);
 //   rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);

    // Init the first two LEDs to a static color
    setrgb(RGB_WHITE, (LED_TYPE *)&led[14]);
    setrgb(RGB_WHITE, (LED_TYPE *)&led[15]);
    rgblight_set();
  //  backlight_enable();
  #endif //RGBLIGHT_ENABLE

  backlight_enable();
  backlight_level(1);
  breathing_enable();
}

uint32_t layer_state_set_user(uint32_t state){



  #ifdef RGBLIGHT_ENABLE
	uint8_t led0r = 0; uint8_t led0g = 0; uint8_t led0b = 0;
	uint8_t led1r = 0; uint8_t led1g = 0; uint8_t led1b = 0;
	if (layer_state_cmp(state, 0)) {
	led0b = 255;	
	led1b = 255;
   }
	if (layer_state_cmp(state, 1)) {
	led0r = 255;	
	led1r = 255;
   }
  if (layer_state_cmp(state, 2)) {
     led0g = 255;
     led1g = 255;
    }

    if (layer_state_cmp(state, 3)) {
      led1b = 255;
    }
    if (layer_state_cmp(state, 4)) {
     led1r = 255;
    }

    setrgb(led0r, led0g, led0b, (LED_TYPE *)&led[14]);
    setrgb(led1r, led1g, led1b, (LED_TYPE *)&led[15]);
    rgblight_set();
 	 #endif //RGBLIGHT_ENABLE
  return state;
}
