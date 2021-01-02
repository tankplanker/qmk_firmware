/*
This is the c configuration file for the keymap

Copyright 2018 monksoffunk
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
// if you need more program area, try uncomment follow line
//#include "serial_config_simpleapi.h"

// place overrides here
// Selection of RGBLIGHT MODE to use.
  //#define RGBLIGHT_ANIMATIONS
//#if defined(LED_ANIMATIONS)
 //  #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  // #define RGBLIGHT_EFFECT_SNAKE
 //  #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
 //  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   //#define RGBLIGHT_EFFECT_RGB_TEST
   //#define RGBLIGHT_EFFECT_ALTERNATING
//#endif
   #undef RGBLIGHT_LIMIT_VAL
   #define RGBLIGHT_LIMIT_VAL 255
   #define PERMISSIVE_HOLD
   #define TAPPING_TERM 220
   #define OLED_FONT_H "font_gmk_bad.h"
   #define OLED_DISPLAY_128X64
   #define IGNORE_MOD_TAP_INTERRUPT

#ifndef NO_DEBUG
   #define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
   #define NO_PRINT
#endif // !NO_PRINT
#define NO_ACTION_ONESHOT
#define ENCODER_RESOLUTION 2