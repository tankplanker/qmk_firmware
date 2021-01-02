61#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  KANA,
  EISU,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//for tap dance
typedef struct {
  bool is_press_action;
  int state;
} tap;

//consts for tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

//Tap dance keys
enum tapdance {
    ENT_CTL = 0,
    TABCAP,
    BCK_CTL,
    DEL_CTL,
    L_SHFT,
    R_SHFT,
    END_CTL,
    HOME_CTL,
    PUP_CTL,
    PDWN_CTL,
    RA_CTL,
    LA_CTL,
    DA_CTL,
    UA_CTL,
    X_CTL,
    C_CTL,
    V_CTL
};

//for the x tap dance. Put it here so it can be used in any keymap
void tab_finished (qk_tap_dance_state_t *state, void *user_data);
void tab_reset (qk_tap_dance_state_t *state, void *user_data);
void ent_finished (qk_tap_dance_state_t *state, void *user_data);
void ent_reset (qk_tap_dance_state_t *state, void *user_data);
void ls_finished (qk_tap_dance_state_t *state, void *user_data);
void ls_reset (qk_tap_dance_state_t *state, void *user_data);
void bck_finished (qk_tap_dance_state_t *state, void *user_data);
void bck_reset (qk_tap_dance_state_t *state, void *user_data);
void del_finished (qk_tap_dance_state_t *state, void *user_data);
void del_reset (qk_tap_dance_state_t *state, void *user_data);
void rs_finished (qk_tap_dance_state_t *state, void *user_data);
void rs_reset (qk_tap_dance_state_t *state, void *user_data);
void end_finished (qk_tap_dance_state_t *state, void *user_data);
void end_reset (qk_tap_dance_state_t *state, void *user_data);
void home_finished (qk_tap_dance_state_t *state, void *user_data);
void home_reset (qk_tap_dance_state_t *state, void *user_data);
void pup_finished (qk_tap_dance_state_t *state, void *user_data);
void pup_reset (qk_tap_dance_state_t *state, void *user_data);
void pdown_finished (qk_tap_dance_state_t *state, void *user_data);
void down_reset (qk_tap_dance_state_t *state, void *user_data);
void ra_finished (qk_tap_dance_state_t *state, void *user_data);
void ra_reset (qk_tap_dance_state_t *state, void *user_data);
void la_finished (qk_tap_dance_state_t *state, void *user_data);
void la_reset (qk_tap_dance_state_t *state, void *user_data);
void ua_finished (qk_tap_dance_state_t *state, void *user_data);
void ua_reset (qk_tap_dance_state_t *state, void *user_data);
void da_finished (qk_tap_dance_state_t *state, void *user_data);
void da_reset (qk_tap_dance_state_t *state, void *user_data);
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);
void c_finished (qk_tap_dance_state_t *state, void *user_data);
void c_reset (qk_tap_dance_state_t *state, void *user_data);
void v_finished (qk_tap_dance_state_t *state, void *user_data);
void v_reset (qk_tap_dance_state_t *state, void *user_data);

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |ctrl  | alt  | win  |shift |Enter |             | Space| shift|backsp| alt  | ctrl | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
[_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      TD(TABCAP), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      KC_ESC,TD(X_CTL),TD(C_CTL),TD(V_CTL),TD(L_SHFT),LT(_LOWER, KC_ENTER),   LT(_RAISE, KC_SPC),TD(R_SHFT),TD(BCK_CTL),KC_RALT,KC_RCTL,KC_UP \
      ),

  /* Colemak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |ADJUST| Alt  | Win  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_COLEMAK] = LAYOUT_ortho_4x12( \
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      KC_ESC,  ADJUST,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,                    KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Dvorak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |ADJUST| Alt  | Win  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_DVORAK] = LAYOUT_ortho_4x12( \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL, \
      KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
      KC_ESC,  ADJUST,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,                    KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |   -  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      | Home | End  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
      _______, _______, _______, _______, _______, _______,                   KC_MINS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_HOME, KC_END,  _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|RGBRST|Aud on|Audoff|      |             |      |Qwerty|Colemk|Dvorak|      | Ins  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RGB ON| HUE+ | SAT+ | VAL+ | Mac  |             | Win  |  -   |   =  |Print |ScLock|Pause |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | MODE | HUE- | SAT- | VAL- |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      | EISU | EISU | EISU |             | KANA | KANA | Home |PageDn|PageUp| End  |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] =  LAYOUT_ortho_4x12( \
      _______, RESET,   RGBRST,  _______, _______, _______,                   _______, QWERTY,  COLEMAK, DVORAK,  _______, KC_INS, \
      _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, AG_NORM,                   AG_SWAP, KC_MINS, KC_EQL,  KC_PSCR, KC_SLCK, KC_PAUS,\
      _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,                   _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, EISU,    EISU,    EISU,                      KANA,    KANA,    KC_HOME, KC_PGDN, KC_PGUP, KC_END\
      )
};

// define variables for reactive RGB
bool TOG_STATUS = false;  

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
 /* if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode_noeeprom(RGB_current_config.mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }*/
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
          /* rgblight_mode_noeeprom(16);*/
          #endif
        }
        layer_on(_LOWER);
     //   update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
        //  rgblight_mode_noeeprom(RGB_current_config.mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
      // update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
         //   rgblight_mode_noeeprom(15);
          #endif
        }
        layer_on(_RAISE);
     //  update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
       //   rgblight_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
     //   update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
    /*  #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step();
          RGB_current_config.mode = rgblight_config.mode;
        }
      #endif*/
      return false;
      break;

    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
         SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;

    case RGBRST:
    /*  #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_config = rgblight_config;
        }
      #endif*/
      break;
  }
  return true;
}

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

//tab and caps lock
void tab_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_TAB); 
        };
    case SINGLE_HOLD: register_code(KC_TAB); break;
    case DOUBLE_TAP: {
        register_code(KC_CAPSLOCK); 
        };
  }
}

void tab_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_TAB); 
        };
    case SINGLE_HOLD: unregister_code(KC_TAB); break;
    case DOUBLE_TAP: {
        unregister_code(KC_CAPSLOCK); 
        };
  }
  xtap_state.state = 0;
}

//cut
void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_LCTRL);
        register_code(KC_X); 
        };
    case SINGLE_HOLD: register_code(KC_LCTRL); break;
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LCTRL);
        unregister_code(KC_X);
        };
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
  }
  xtap_state.state = 0;
}

//copy
void c_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_LCTRL);
        register_code(KC_C); 
        };
    case SINGLE_HOLD: register_code(KC_LALT); break;
  }
}

void c_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LCTRL);
        unregister_code(KC_C);
        };
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
  }
  xtap_state.state = 0;
}

//paste
void v_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_LCTRL);
        register_code(KC_V); 
        };
    case SINGLE_HOLD: register_code(KC_LGUI); break;
  }
}

void v_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LCTRL);
        unregister_code(KC_V);
        };
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
  }
  xtap_state.state = 0;
}

//right arrow
void ra_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_RIGHT); 
        };
    case SINGLE_HOLD: register_code(KC_RIGHT); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_RIGHT); 
        };
 }
}

void ra_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_RIGHT);
        };
    case SINGLE_HOLD: unregister_code(KC_RIGHT); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_RIGHT); 
        };
  }
  xtap_state.state = 0;
}

//left arrow
void la_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_LEFT); 
        };
    case SINGLE_HOLD: register_code(KC_LEFT); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_LEFT); 
        };
  }
}

void la_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LEFT);
        };
    case SINGLE_HOLD: unregister_code(KC_LEFT); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_LEFT); 
        };
  }
  xtap_state.state = 0;
}

//UP arrow
void ua_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_UP); 
        };
    case SINGLE_HOLD: register_code(KC_UP); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_UP); 
        };
  }
}

void ua_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_UP);
        };
    case SINGLE_HOLD: unregister_code(KC_UP); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_UP); 
        };
  }
  xtap_state.state = 0;
}

//DOWN arrow
void da_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_DOWN); 
        };
    case SINGLE_HOLD: register_code(KC_DOWN); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_DOWN); 
        };
  }
}

void da_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_DOWN);
        };
    case SINGLE_HOLD: unregister_code(KC_DOWN); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_DOWN); 
        };
 }
  xtap_state.state = 0;
}

//home
void home_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_HOME); 
        };
    case SINGLE_HOLD: register_code(KC_HOME); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_HOME); 
        };
  }
}

void home_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_HOME);
        };
    case SINGLE_HOLD: unregister_code(KC_HOME); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_HOME); 
        };
  }
  xtap_state.state = 0;
}

//end 
void end_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_END); 
        };
    case SINGLE_HOLD: register_code(KC_END); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_END); 
        };
  }
}

void end_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_END);
        };
    case SINGLE_HOLD: unregister_code(KC_END); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_END); 
        };
  }
  xtap_state.state = 0;
}

//page down
void pdwn_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_PGDOWN); 
        };
    case SINGLE_HOLD: register_code(KC_PGDOWN); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_PGDOWN); 
        };
  }
}

void pdwn_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_PGDOWN);
        };
    case SINGLE_HOLD: unregister_code(KC_PGDOWN); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_PGDOWN); 
        };
  }
  xtap_state.state = 0;
}

//page up
void pup_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_PGUP); 
        };
    case SINGLE_HOLD: register_code(KC_PGUP); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_PGUP); 
        };
 }
}

void pup_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_PGUP);
        };
    case SINGLE_HOLD: unregister_code(KC_PGUP); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_PGUP); 
        };
  }
  xtap_state.state = 0;
}


//lshift
void ls_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_LSHIFT);
        register_code(KC_9); 
        };
    case SINGLE_HOLD: register_code(KC_LSHIFT); break;
    case DOUBLE_TAP:{
        register_code(KC_LSHIFT);
        register_code(KC_LBRACKET); 
        };
    case TRIPLE_TAP:{
        register_code(KC_LBRACKET); 
        };
  }
}

void ls_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_9); 
        };
    case SINGLE_HOLD: unregister_code(KC_LSHIFT); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LBRACKET); 
        };
    case TRIPLE_TAP:{
        unregister_code(KC_LBRACKET); 
    };
  }
  xtap_state.state = 0;
}

//rshfit
void rs_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_RSHIFT);
        register_code(KC_0); 
        };
    case SINGLE_HOLD: register_code(KC_RSHIFT); break;
    case DOUBLE_TAP:{
        register_code(KC_LSHIFT);
        register_code(KC_RBRACKET); 
        };
    case TRIPLE_TAP:{
        register_code(KC_RBRACKET); 
        };
  }
}

void rs_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_RSHIFT);
        unregister_code(KC_0); 
        };
    case SINGLE_HOLD: unregister_code(KC_RSHIFT); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LSHIFT);
        unregister_code(KC_RBRACKET); 
        };
    case TRIPLE_TAP:{
        unregister_code(KC_RBRACKET); 
    };
  
  }
  xtap_state.state = 0;
}

//delete
void del_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_DEL); 
        };
    case SINGLE_HOLD: register_code(KC_DEL); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        tap_code(KC_DEL); 
        };
  }
}

void del_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_DEL);
       unregister_code(KC_DEL);
        };
    case SINGLE_HOLD: unregister_code(KC_DEL); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL); 
        };
  }
  xtap_state.state = 0;
}

//backspace
void bck_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_BSPACE); 
        };
    case SINGLE_HOLD: register_code(KC_BSPACE); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        tap_code(KC_BSPACE); 
        };
  }
}

void bck_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_BSPACE);
        };
    case SINGLE_HOLD: unregister_code(KC_BSPACE); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_BSPACE);
        };
  }
  xtap_state.state = 0;
}

//enter
void ent_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_ENT); 
        };
    case SINGLE_HOLD: layer_on(_LOWER ); break;
    case DOUBLE_TAP:{
        register_code(KC_LCTRL);
        register_code(KC_ENT); 
        };
  }
}

void ent_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_ENT);
        };
    case SINGLE_HOLD: layer_off(_LOWER ); break;
    case DOUBLE_TAP:{
        unregister_code(KC_LCTRL);
        unregister_code(KC_ENT); 
        };
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [ENT_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ent_finished, ent_reset),
    [TABCAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,tab_finished, tab_reset),
    [L_SHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ls_finished, ls_reset),
    [R_SHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,rs_finished, rs_reset),
    [BCK_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,bck_finished, bck_reset),
    [DEL_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,del_finished, del_reset),
    [HOME_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,home_finished, home_reset),
    [END_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,end_finished, end_reset),
    [PDWN_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,pdwn_finished, pdwn_reset),
    [PUP_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,pup_finished, pup_reset),
    [UA_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ua_finished, ua_reset),
    [DA_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,da_finished, da_reset),
    [LA_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,la_finished, la_reset),
    [RA_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ra_finished, ra_reset),
    [X_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset),
    [C_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,c_finished, c_reset),
    [V_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,v_finished, v_reset)
};

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
     RGB_current_config = rgblight_config;
 // rgblight_set_clipping_range(10, 10);
rgblight_sethsv_noeeprom(HSV_YELLOW);
rgblight_sethsv_range(HSV_CYAN,0,6);
rgblight_sethsv_range(HSV_BLUE,6,12);
rgblight_sethsv_range(HSV_PURPLE,12,18);
rgblight_sethsv_range(HSV_PINK,18,24);
rgblight_sethsv_range(HSV_GREEN,24,40);
rgblight_set();
    #endif
}

void keyboard_post_init_user(void) {
//rgblight_sethsv_range(HSV_WHITE, 0, 88);
 //rgblight_set_clipping_range(30, 30);
 // rgblight_sethsv_noeeprom(HSV_WHITE);
 // rgblight_set();
};