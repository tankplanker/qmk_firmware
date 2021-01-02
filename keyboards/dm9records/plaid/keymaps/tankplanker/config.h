#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//#define NO_ACTION_TAPPING

#define NO_UART 1
#undef RGB_DI_PIN
 #define RGB_DI_PIN C5
 #ifdef RGB_DI_PIN
	#undef RGBLED_NUM
   #define RGBLED_NUM 99
  #define RGBLIGHT_LIMIT_VAL 255
 #endif

