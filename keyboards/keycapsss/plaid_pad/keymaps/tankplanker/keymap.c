#include QMK_KEYBOARD_H
//layers
enum layers {
    _QWERTY = 0,
    _LOWER = 1,
    _RAISE = 2,
    _RGB   = 4,
    _TAB   = 5,    
};

#define _QWERTY 0
#define _LOWER 1

//variables for macros
bool is_alt_tab_active = false;    
bool selector1_enabled = false;
bool is_rgb_active = false;    
bool selector2_enabled = false;
bool is_ctrl_active = false;    

uint16_t alt_tab_timer = 0;       
uint16_t ctrl_timer = 0;   
uint16_t rgb_timer = 0;     
int rgbcnt = 8;   
 

//Keycode for encoder
enum my_keycodes {
  ENABLE_SELECTOR1 = SAFE_RANGE,
  ENABLE_SELECTOR2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ,-----------------------,
 * |  7  |  8  |  9  |  /  |
 * |-----+-----+-----+-----|
 * |  4  |  5  |  6  |  *  |
 * |-----+-----+-----+-----|
 * |  1  |  2  |  3  |  -  |
 * |-----+-----+-----+-----|
 * |  0  |  .  |  =  |  +  |
 * `-----------------------'
 */
[0] = LAYOUT_ortho_4x4(
		ENABLE_SELECTOR1, TG(1),   KC_NONUS_BSLASH,      ENABLE_SELECTOR2,
		KC_P7, KC_P8,   KC_P9,      KC_PDOT,
		KC_P4, KC_P5,   KC_P6,      KC_P0,
		KC_P1,KC_P2 , KC_P3,    KC_ENTER
),

[1] = LAYOUT_ortho_4x4(
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_HOME, KC_UP, KC_PGUP,KC_TRNS , 
   KC_LEFT,KC_DEL, KC_RGHT, KC_TRNS,  
   KC_END, KC_DOWN, KC_PGDN, KC_TRNS ),

};

// Set led state during powerup
void keyboard_post_init_user(void) {
    writePinHigh(LED_RED);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _QWERTY);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
  switch (keycode) {
    case ENABLE_SELECTOR1: //push down action for the encoder for alt tab
      if (record->event.pressed) {
        selector1_enabled = true;
        is_alt_tab_active = true;
        register_code16(KC_LALT);
        tap_code(KC_TAB);
        tap_code16(LSFT(KC_TAB));
        layer_on(_TAB);
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
        layer_on(_RGB);
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

void winarr(bool clockwise){ //windows and arrows on the rotary
  if (!is_rgb_active) {
    is_rgb_active = true;
  } 
  rgb_timer = timer_read();
  if (clockwise){
    tap_code16(LGUI(KC_RIGHT));
  } else {
    tap_code16(LGUI(KC_LEFT));
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
      layer_off(_TAB);
      is_alt_tab_active = false;
    }
  }

  if (is_rgb_active) {
    if (!selector2_enabled &&  (timer_elapsed(rgb_timer) > 1000)) {
      layer_off(_RGB);
      is_rgb_active = false;
    }
  }
}

#ifdef ENCODER_ENABLE //master encoder section
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { //left encoder
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
    	case _RAISE: //RGB underglow select
        //setmyrgb(clockwise);
      		break; 
      case _RGB: //RGB underglow select
        //setmyrgb(clockwise);
      		break; 
      case  _TAB: // alt tab
          tabalt(clockwise);
      	break;
	    default:  //mouse wheel left right
          if (clockwise) {
	          tap_code16(KC_MS_WH_RIGHT);
    			} else {
      			tap_code16(KC_MS_WH_LEFT);
      			break;
          }              
        }
    } else if (index == 1) { //right encoder
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
            		tap_code(KC_VOLU);
    					} else {
      					tap_code(KC_VOLD);
    					}
      					break;  
    		case _RAISE:
          bakdel(clockwise); 
      					break; 
      case _RGB: //RGB underglow select
        winarr(clockwise);
      		break; 
      case  _TAB: // alt tab
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
}
#endif