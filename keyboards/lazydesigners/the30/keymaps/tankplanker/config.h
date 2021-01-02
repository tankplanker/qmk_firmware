/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPO
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
 #define OLED_FONT_H "font_gmk_bad.h"
#endif

#ifdef RGBLIGHT_ENABLE
 // #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 255
//#define RGBLIGHT_SPLIT
#define RGBLED_NUM 20
#define RGBLED_SPLIT { 10, 10 }
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
 // #define  RGB_DI_PIN D3
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
//#define SPLIT_USB_DETECT
//#define NO_USB_STARTUP_CHECK

//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT

//#define ENCODER_RESOLUTION 2
#define TAPPING_TERM 200
// #define TAP_CODE_DELAY 30
 //#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
 //#define PREVENT_STUCK_MODIFIERS

