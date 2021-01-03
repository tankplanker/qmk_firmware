#userspace rules.mk for tankplanker
SRC += tankplanker.c
TAP_DANCE_ENABLE=yes
LTO_ENABLE =yes
Space_Cadet = no
POINTING_DEVICE_ENABLE = no
EXTRAFLAGS += -flto
MACROS_ENABLED = no
