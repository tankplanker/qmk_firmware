// tankplanker.h
#pragma once
#include QMK_KEYBOARD_H
// end
//for tap dance
typedef struct {
  bool is_press_action;
  int state;
} tap;

//layers
enum layers {
    _QWERTY = 0,
    _LOWER = 1,
    _RAISE = 2,
};

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

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)
#define COLON LSFT(KC_SCLN)
#define DB_QUOTE LSFT(KC_QUOTE)
#define UNDERSCORE LSFT(KC_MINS)

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  KC_PASTA1,
  KC_PASTA2,
  KC_PASTA3,
  KC_PASTA4,
  KC_PASTA5,
  KC_PASTA6,
  KC_PASTA7,
  KC_PASTA8,
  KC_PASTA9,
  KC_PASTA10
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


