# custom matrix setup
CUSTOM_MATRIX = lite
COMBO_ENABLE = yes

VPATH += drivers/gpio
SRC += mcp23018.c matrix.c
I2C_DRIVER_REQUIRED = yes
