/* Copyright 2019 Keebio
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LT(1,KC_MPLY), LT(2,KC_MNXT)),
	[1] = LAYOUT(KC_TRNS, KC_SLEP),
	[2] = LAYOUT(LGUI(KC_L), KC_TRNS)
};

void keyboard_post_init_user(void) {
    rgblight_setrgb_range(3,215, 252, 0, 5);
    rgblight_setrgb_range(255,255, 255, 5, 99);
rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    rgblight_set();
}

uint32_t layer_state_set_user(uint32_t state){
	uint8_t led0r = 0; uint8_t led0g = 0; uint8_t led0b = 0;
	uint8_t led1r = 0; uint8_t led1g = 0; uint8_t led1b = 0;
	if (layer_state_cmp(state, 0)) {
	led0r = 3;	
	led1r = 255;	
	led0b = 215;	
	led1b = 255;	
	led0g = 252;	
	led1g = 255;
   }
	if (layer_state_cmp(state, 1)) {
	led0b = 255;	
	led1r = 255;
   }
  if (layer_state_cmp(state, 2)) {
     led0r = 255;
     led1g = 255;
    }

    if (layer_state_cmp(state, 3)) {
      led1b = 255;
    }
    if (layer_state_cmp(state, 4)) {
     led1r = 255;
    }

    rgblight_setrgb_range(led0r, led0g, led0b, 0, 5);
    rgblight_setrgb_range(led1r, led1g, led1b, 5, 99);
    rgblight_set();
  return state;
}
