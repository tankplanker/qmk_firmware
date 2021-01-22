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

//variables for macros
bool is_alt_tab_active = false;
bool selector1_enabled = false;
bool is_rgb_active = false;
bool selector2_enabled = false;
bool is_ctrl_active = false;

uint16_t alt_tab_timer = 0;
uint16_t ctrl_timer = 0;
uint16_t rgb_timer = 0;
int rgbcnt = 1;

enum my_keycodes {
  ENABLE_SELECTOR1 = SAFE_RANGE,
  ENABLE_SELECTOR2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */
                KC_7,       KC_8,       KC_9,       TG(2),
                KC_4,       KC_5,       KC_6,       KC_MNXT,
                KC_1,       KC_2,       KC_3,       KC_MPLY,
                KC_P0,      KC_PDOT,    TG(1)
                ),
    [1] = LAYOUT(
                KC_HOME,    KC_UP,      KC_PGUP,    KC_TRNS,
                KC_LEFT,    KC_PENT,    KC_RGHT,    KC_TRNS,
                KC_END,     KC_DOWN,    KC_PGDN,    KC_TRNS,
                KC_INS,     KC_DEL,     KC_TRNS),
    [2] = LAYOUT(
                KC_WBAK,    KC_WREF,    KC_WFWD,    KC_TRNS,
                KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_TRNS,
                RGB_RMOD,     RGB_TOG,    RGB_MOD,    KC_TRNS,
                RESET ,     KC_MSEL,    KC_TRNS)
};

//give me my layer
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _QWERTY);
}

//change the RGB underglow colour based on encoder
static void setmyrgb(bool clockwise) {
 /* if (!is_rgb_active) {
    is_rgb_active = true;
  }
  rgb_timer = timer_read();*/

rgblight_set_effect_range(0,99);
if (clockwise) { //increment or decrement the count
  if (rgbcnt > 20) {
    rgbcnt = 1;
  } else {
    rgbcnt++;
  }
} else {
  if (rgbcnt <= 1) {
    rgbcnt = 9;
  } else {
    rgbcnt--;
  }
}
switch (rgbcnt) { //pick the colour
  case 1:
  rgblight_sethsv_noeeprom(HSV_GREEN);
  rgblight_setrgb(RGB_PINK);
        break;
  case 2:
  rgblight_sethsv_noeeprom(HSV_RED);
        break;
  case 3:
  rgblight_sethsv_noeeprom(HSV_CORAL);
        break;
  case 4:
  rgblight_sethsv_noeeprom(HSV_ORANGE);
        break;
  case 5:
  rgblight_sethsv_noeeprom(HSV_GOLDENROD);
        break;
  case 6:
  rgblight_sethsv_noeeprom(HSV_GOLD);
        break;
  case 7:
  rgblight_sethsv_noeeprom(HSV_YELLOW);

        break;
  case 8:
  rgblight_sethsv_noeeprom(HSV_CHARTREUSE);

        break;
  case 9:
  rgblight_sethsv_noeeprom(HSV_GREEN);
        break;
  case 10:
  rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
        break;
  case 11:
        rgblight_sethsv_noeeprom(HSV_GREEN);

        break;
  case 12:
        rgblight_sethsv_noeeprom(HSV_TEAL);
        break;
  case 13:
        rgblight_sethsv_noeeprom(HSV_CYAN);
        break;
  case 14:
        rgblight_sethsv_noeeprom(HSV_AZURE);
        break;
  case 15:
        rgblight_sethsv_noeeprom(HSV_BLUE);
        break;
  case 16:
        rgblight_sethsv_noeeprom(HSV_PURPLE);
        break;
  case 17:
        rgblight_sethsv_noeeprom(HSV_MAGENTA);
        break;
  case 18:
		rgblight_sethsv_noeeprom(HSV_PINK);
        break;
  case 19:
		  rgblight_mode(8);
        break;
   case 20:
		  rgblight_mode(12);
        break;
}
rgblight_set();
return;
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

/*static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = { //render the logo from the font file
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}*/

static void render_status(void) {
    // tenticle and version information
    //render_qmk_logo();
    oled_write_P(PSTR("SPIN Macropad 0.9\n\n"), false);

     //Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
       case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();

    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);

}

void oled_task_user(void) {

        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
};

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_MAGENTA);
 //   rgblight_setrgb(RGB_MAGENTA);
    rgblight_set();
}

void bakdel(bool clockwise){ //delete/backspace on the rotary, slow delete letter, fast delete word

    if (!is_ctrl_active && (timer_elapsed(ctrl_timer) < 200)) {
      is_ctrl_active = true;
      register_code(KC_LCTL);
    }
  ctrl_timer = timer_read();
  if (clockwise){
    tap_code(KC_DELETE);
  } else {
    tap_code(KC_BSPACE);
  }
}

void tabalt(bool clockwise){ //alt tab on the rotary
  if (!is_alt_tab_active) {
    is_alt_tab_active = true;
    register_code(KC_LALT);
  }
  alt_tab_timer = timer_read();
  if (clockwise){
    tap_code(KC_TAB);
  } else {
    tap_code16(LSFT(KC_TAB));
  }
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
            case _RAISE:
          bakdel(clockwise);
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
                          case  _RAISE: // alt tab
          tabalt(clockwise);
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
            case _RAISE: //RGB underglow select
                setmyrgb(clockwise);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case ENABLE_SELECTOR1: //push down action for the encoder for alt tab
      if (record->event.pressed) {
        selector1_enabled = true;
        is_alt_tab_active = true;
        register_code16(KC_LALT);
        tap_code(KC_TAB);
        tap_code16(LSFT(KC_TAB));

        alt_tab_timer = timer_read();
      } else {
        selector1_enabled = false;
      }
      return false;
      break;
      case ENABLE_SELECTOR2: //push down action for the encoder for rgb
      if (record->event.pressed) {
        selector2_enabled = true;
        is_rgb_active = true;

        rgb_timer = timer_read();
      } else {
        selector2_enabled = false;
      }
      return false;
      break;
    default:
      return true; // Process all other keycodes normally
  }
}


void matrix_scan_user(void) {     //various timers for delete and alt tab

  if (is_ctrl_active) {
    if ( (timer_elapsed(ctrl_timer) > 200)) {
      unregister_code16(KC_LCTL);
      is_ctrl_active = false;
    }
  }

  if (is_alt_tab_active) {
    if (!selector1_enabled &&  (timer_elapsed(alt_tab_timer) > 1000)) {
      unregister_code16(KC_LALT);

      is_alt_tab_active = false;
    }
  }
if (is_rgb_active) {
    if (!selector2_enabled &&  (timer_elapsed(rgb_timer) > 1000)) {

      is_rgb_active = false;
    }
  }

}
