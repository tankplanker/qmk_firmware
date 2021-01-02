#include QMK_KEYBOARD_H

#define FN1_Q LT(1, KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    FN1_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_BSPC, KC_SPC,  KC_B,    KC_N,    KC_M,    KC_ENT
  ),

  [1] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, BL_INC,
    _______, _______, _______, _______, _______, _______, RESET,   _______, _______, BL_DEC
  ),

};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    // Set up RGB effects on _only_ the third LED (index 2)
    rgblight_set_effect_range(0, 13);
    // Set LED effects to breathing mode in a tealish blue color
    rgblight_sethsv_noeeprom(0, 255, 255);
 //   rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);

    // Init the first two LEDs to a static color
rgblight_sethsv_range(HSV_RED , 0, 11);
    rgblight_set();
  //  backlight_enable();
  #endif //RGBLIGHT_ENABLE

  backlight_enable();
  backlight_level(3);
 // breathing_enable();
}
