/* Copyright 2019-2020 DMQ Design
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

enum layers {
    _QWERTY = 0,
    _LOWER = 1,
    _RAISE = 2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */
                KC_7, KC_8, KC_9, KC_MPRV,
                KC_4, KC_5, KC_6, KC_MNXT,
                KC_1, KC_2, KC_3, KC_MPLY,
                KC_0, KC_DOT, TG(1)
                ),
    [1] = LAYOUT(
                KC_HOME,    KC_UP,      KC_PGUP,    KC_TRNS,
                KC_LEFT,    KC_PENT,    KC_RGHT,    KC_TRNS,
                KC_END,     KC_DOWN,    KC_PGDN,    KC_TRNS,
                KC_INS,     KC_DEL,     KC_TRNS)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
 static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}
#endif

void keyboard_post_init_user(void) {
    rgblight_setrgb_range(RGB_MAGENTA, 0, 99);
    rgblight_set();
}

#ifdef ENCODER_ENABLE //master encoder section
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { //top encoder
	switch (get_highest_layer(layer_state)) {
	    case  _QWERTY:  //mouse wheel left right
          if (clockwise) {
	          tap_code16(KC_MS_WH_RIGHT);
    			} else {
      			tap_code16(KC_MS_WH_LEFT);
          }
          break;
    	case _LOWER:  //undo/redo
    			if (clockwise) {
      			tap_code16(LCTL(KC_Z));
    			} else {
      			tap_code16(LCTL(KC_Y));
    			}
      	  break;
	    default:  //mouse wheel left right
          if (clockwise) {
	          tap_code16(KC_MS_WH_RIGHT);
    			} else {
      			tap_code16(KC_MS_WH_LEFT);
      			break;
          }
        }
    } else if (index == 1) { //middle encoder
  	switch (get_highest_layer(layer_state)) {
    		case  _QWERTY:
    		if (clockwise) {
      					tap_code(KC_MS_WH_DOWN);
    					} else {
      					tap_code(KC_MS_WH_UP);
    					}
      					break;
    		case _LOWER:
    			if (clockwise) {
            		tap_code(KC_RIGHT);
    					} else {
      					tap_code(KC_LEFT);
    					}
      					break;
		    default:
			    if (clockwise) {
      			tap_code(KC_MS_WH_DOWN);
          } else{
      			tap_code(KC_MS_WH_UP);
    			}
          break;
    	}
   	}
       else if (index == 2) { //bottom encoder
  	switch (get_highest_layer(layer_state)) {
    		case  _QWERTY:
    		if (clockwise) {
      					tap_code(KC_VOLU);
    					} else {
      					tap_code(KC_VOLD);
    					}
      					break;
    		case _LOWER:
    			if (clockwise) {
            		tap_code(KC_WFWD);
    					} else {
      					tap_code(KC_WBAK);
    					}
      					break;
		    default:
			    if (clockwise) {
      			tap_code(KC_VOLU);
          } else{
      			tap_code(KC_VOLD);
    			}
          break;
    	}
   	}
}
#endif
