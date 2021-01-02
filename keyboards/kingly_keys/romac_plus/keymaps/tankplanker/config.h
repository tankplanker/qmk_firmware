
#undef RGBLED_NUM
#define RGBLED_NUM 99    // Number of LEDs

//#define RGBLIGHT_ANIMATIONS

//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
//#define NO_ACTION_TAPPING