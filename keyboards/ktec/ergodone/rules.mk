# custom matrix setup
CUSTOM_MATRIX = lite
TAP_DANCE_ENABLE = yes

VPATH += drivers/gpio
SRC += mcp23018.c matrix.c
I2C_DRIVER_REQUIRED = yes
