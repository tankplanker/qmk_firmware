# MCU name
MCU = atmega32u2

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu


# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = lite       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output on port C6
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGBLED_NUM = 99
LAYOUTS_HAS_RGB = yes
Space_Cadet = no
TAP_DANCE_ENABLE=yes
EXTRAFLAGS += -flto
