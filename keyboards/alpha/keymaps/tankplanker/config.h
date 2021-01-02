

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_TAPPING


#define RGB_DI_PIN F4
#ifdef RGB_DI_PIN
//#define RGBLIGHT_ANIMATIONS

#undef RGBLED_NUM 
#define RGBLED_NUM 99
#endif
