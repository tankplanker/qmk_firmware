#include QMK_KEYBOARD_H

//layers
enum layers {
    _QWERTY = 0,
    _LOWER = 1,
    _RAISE = 2,
    _RGB   = 4,
    _TAB   = 5,    
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

int cur_dance (qk_tap_dance_state_t *state);  


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
	COMDOT,
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
void comdot_finished (qk_tap_dance_state_t *state, void *user_data);
void comdot_reset (qk_tap_dance_state_t *state, void *user_data);
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ortho_3x10(
						KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, 
						MT(MOD_LSFT,KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, 
						KC_Z, KC_X, KC_C, KC_V, LT(1,KC_ENT), LT(2,KC_SPC), KC_B, KC_N, KC_M, TD(COMDOT)),
	[1] = LAYOUT_ortho_3x10(
						KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, 
						KC_GRV, KC_NUHS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, TD(LA_CTL), TD(DA_CTL), TD(UA_CTL),TD(RA_CTL),  
						KC_ESC, TD(X_CTL), TD(C_CTL),TD(V_CTL) , KC_TRNS, KC_TRNS, KC_BSLS, KC_SLSH, KC_QUOT, TD(BCK_CTL)),
	[2] = LAYOUT_ortho_3x10(
						KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, TD(L_SHFT), TD(R_SHFT), 
						TD(TABCAP),KC_COMMA, KC_DOT, KC_NUBS, KC_SLSH, KC_HASH,TD(HOME_CTL), TD(PDWN_CTL), TD(PUP_CTL),TD(END_CTL),
						KC_ESC, TD(X_CTL), TD(C_CTL),TD(V_CTL) , KC_TRNS, KC_TRNS, KC_RO, KC_QUOT, KC_NUHS, TD(DEL_CTL))
};

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
    case SINGLE_HOLD: register_code(KC_LCTRL); 
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LCTRL);
        unregister_code(KC_X);
        };
    case SINGLE_HOLD: unregister_code(KC_LCTRL); 
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
    case SINGLE_HOLD: register_code(KC_LALT); 
  }
}

void c_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LCTRL);
        unregister_code(KC_C);
        };
    case SINGLE_HOLD: unregister_code(KC_LALT); 
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
    case SINGLE_HOLD: register_code(KC_LGUI); 
  }
}

void v_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_LCTRL);
        unregister_code(KC_V);
        };
    case SINGLE_HOLD: unregister_code(KC_LGUI); 
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

//comma and dot and shift
void comdot_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        register_code(KC_COMM); 
        };
    case SINGLE_HOLD: register_code(KC_RSHIFT); break;
    case DOUBLE_TAP:{
        register_code(KC_DOT); 
		break;
        };
    case TRIPLE_TAP:{
        register_code(KC_SLSH); 
        };
  }
}

void comdot_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: {
        unregister_code(KC_COMM); 
        };
    case SINGLE_HOLD: unregister_code(KC_RSHIFT); break;
    case DOUBLE_TAP:{
        unregister_code(KC_DOT); 
		break;
        };
    case TRIPLE_TAP:{
        unregister_code(KC_SLSH); 
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
    case SINGLE_HOLD: register_code(KC_LSFT); break;
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
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
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
    case SINGLE_HOLD: register_code(KC_LSFT); break;
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
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
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
	[COMDOT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,comdot_finished,comdot_reset),
    [V_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,v_finished, v_reset)
};
