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
int cur_dance (qk_tap_dance_state_t *state);  

//Keycode for encoder
enum my_keycodes {
  ENABLE_SELECTOR1 = SAFE_RANGE,
  ENABLE_SELECTOR2,
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

//layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( //qwerty
        KC_GESC,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
        TD(TABCAP),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        ENABLE_SELECTOR1, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,   KC_NO, KC_NO, KC_NO,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENABLE_SELECTOR2,
            TD(X_CTL), TD(C_CTL),TD(V_CTL) , TD(L_SHFT), LT(_LOWER, KC_ENTER),            LT(_RAISE, KC_SPC), TD(R_SHFT), TD(BCK_CTL),  z , KC_RCTL

),
	[1] = LAYOUT( //lower
        KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NONUS_BSLASH,
        KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, KC_VOLD,                                    TD(LA_CTL), TD(DA_CTL), TD(UA_CTL),TD(RA_CTL), KC_TRNS, KC_TRNS,
        KC_WWW_REFRESH, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_NO,   KC_NO, KC_NO, KC_NO,TD(HOME_CTL), TD(PDWN_CTL), TD(PUP_CTL),TD(END_CTL), KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, TD(DEL_CTL), KC_TRNS, KC_TRNS

),

	[2] = LAYOUT( //raise
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                                 KC_F7,    KC_F8,  KC_F9,    KC_F10, KC_F11,   KC_F12, 
        KC_TRNS, KC_TILDE,  KC_AT, KC_HASH, KC_PIPE, KC_CIRCUMFLEX,                                        KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_QUOTE, KC_GRAVE, 
        KC_WWW_REFRESH, KC_MAIL, KC_CALC,KC_MYCM, KC_WSTP, KC_WFWD,  KC_NO, KC_NO, KC_NO, KC_NO,  KC_WWW_BACK, KC_WWW_STOP, KC_WWW_REFRESH, KC_WWW_FORWARD, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [3] = LAYOUT( //tab
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                                 KC_F7,    KC_F8,  KC_F9,    KC_F10, KC_F11,   KC_F12, 
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_WWW_REFRESH, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO, KC_NO, KC_NO, KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [4] = LAYOUT( //rgb
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                                 KC_F7,    KC_F8,  KC_F9,    KC_F10, KC_F11,   KC_F12, 
        KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_WWW_REFRESH, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_NO, KC_NO, KC_NO, KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

//give me my layer 
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _QWERTY);
}

//change the RGB underglow colour based on encoder
static void setmyrgb(bool clockwise) {
  if (!is_rgb_active) {
    is_rgb_active = true;
  } 
  rgb_timer = timer_read();

rgblight_set_clipping_range(10, 10); //set it to cover both sides
rgblight_set_effect_range(0,20);
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
        rgblight_sethsv_noeeprom(HSV_WHITE);
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
        rgblight_sethsv_noeeprom(HSV_TURQUOISE);
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
		  rgblight_mode_noeeprom(8);
        break;
   case 20: 
		  rgblight_mode_noeeprom(12);
        break;
}
rgblight_set();
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}
static void render_kyria_logo(void) {                                                                          
    static const char PROGMEM cul_logo[] = {
// 'cthulhu', 128x64px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 
0x60, 0x70, 0xf0, 0xf8, 0xf8, 0xf8, 0xfc, 0x7c, 0x7c, 0x3e, 0x3e, 0x1e, 0x1e, 0x1e, 0x0e, 0x1e, 
0x0e, 0x0e, 0x1e, 0x1e, 0x3e, 0x3e, 0x3e, 0x7c, 0x7c, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0x70, 0x60, 
0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x38, 0x1c, 0x1e, 0x1f, 0x1f, 0x3f, 0x7d, 0xbe, 
0x1e, 0x80, 0xc0, 0xe0, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0xf1, 0xc0, 0x8c, 0x3e, 
0x7c, 0x39, 0xbf, 0x1f, 0x1f, 0x1e, 0x3c, 0x38, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xe0, 0xf8, 0xfe, 0xff, 0x38, 0x1e, 0x0f, 0x87, 0xc3, 0xe1, 0xf1, 0xfa, 0x78, 0x00, 
0x01, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf9, 0xff, 0xff, 0x01, 
0x02, 0xfc, 0xf8, 0xf1, 0xe3, 0xc3, 0x87, 0x0e, 0x1c, 0x39, 0xff, 0xfe, 0xf8, 0xe0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0xfe, 0xff, 0x7f, 0x3f, 0x0f, 0x87, 0xc1, 0xf0, 0xf8, 
0xc7, 0x01, 0x00, 0x00, 0x83, 0x83, 0x02, 0x01, 0x20, 0x68, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x64, 0x02, 0x01, 0x00, 0x83, 0x83, 0x00, 0x00, 0x01, 0xfe, 
0xf8, 0xe0, 0xc3, 0x0f, 0x1f, 0x3f, 0xff, 0xff, 0x7c, 0x00, 0x00, 0xc3, 0xff, 0xff, 0xfe, 0xe0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0c, 0x08, 0x81, 0xf2, 0xe2, 0xe2, 0x67, 0x67, 0x67, 0x67, 
0xe7, 0xe7, 0xe7, 0xe3, 0x63, 0x23, 0x20, 0x20, 0x20, 0xa0, 0xc0, 0x81, 0x01, 0x03, 0x0c, 0xfc, 
0x3c, 0x06, 0x01, 0x01, 0x80, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x23, 0x63, 0xe3, 0xe6, 0xe7, 0xe7, 
0x67, 0x67, 0x67, 0x63, 0xe2, 0xf8, 0xe0, 0x01, 0x04, 0x1c, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x07, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x07, 0x1f, 0x7f, 0xff, 0xe0, 0xc0, 0x81, 0x0f, 0x3f, 0x78, 0x7c, 0xbe, 0x8e, 0x84, 
0x80, 0xa1, 0x11, 0x18, 0xf8, 0x7c, 0x3e, 0x1f, 0x07, 0x80, 0xc0, 0xe1, 0x7c, 0x00, 0x00, 0xff, 
0xc0, 0x00, 0x00, 0xfe, 0xe0, 0xc0, 0x83, 0x0f, 0x1e, 0x3e, 0x7c, 0x78, 0x88, 0x83, 0xe0, 0x84, 
0x0e, 0x1e, 0x3e, 0xf8, 0x3d, 0x1f, 0x0f, 0x80, 0xc0, 0xf0, 0xff, 0x7f, 0x1f, 0x07, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x3f, 0x7e, 0xfe, 0xe0, 0x84, 0x04, 0x08, 
0x18, 0x3f, 0x20, 0x20, 0x01, 0x9e, 0x8e, 0xc6, 0xe7, 0xe3, 0x23, 0x0f, 0x00, 0xc0, 0x1c, 0xff, 
0x7f, 0x08, 0xc0, 0x25, 0x23, 0x63, 0xe3, 0xc7, 0xc7, 0x8e, 0x6c, 0x04, 0x04, 0x64, 0x38, 0x18, 
0x0e, 0x80, 0xc0, 0xf9, 0xfe, 0x7e, 0x3f, 0x1f, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 
0x06, 0x0e, 0x0e, 0x1f, 0x1d, 0x38, 0x38, 0x38, 0x38, 0x78, 0x7c, 0x7e, 0x77, 0x73, 0x78, 0x7f, 
0x7f, 0x78, 0x73, 0x77, 0x7c, 0x7c, 0x78, 0x38, 0x38, 0x38, 0x1c, 0x1c, 0x1f, 0x0e, 0x0e, 0x07, 
0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
oled_write_raw_P(cul_logo, sizeof(cul_logo)); //write it raw as it not in the font file

}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = { //render the logo from the font file
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // tenticle and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

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
       case _TAB:
            oled_write_P(PSTR("Tab\n"), false);
            break;
       case _RGB:
            oled_write_P(PSTR("RGB\n"), false);
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
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
          } else {
        render_kyria_logo(); //Renders the big logo
   }
};
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
        setmyrgb(clockwise);
      		break; 
      case _RGB: //RGB underglow select
        setmyrgb(clockwise);
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

void keyboard_post_init_user(void) {
  rgblight_set_clipping_range(10, 10);
  rgblight_set_effect_range(0,20);
  rgblight_sethsv_noeeprom(HSV_WHITE);
  rgblight_set();
};