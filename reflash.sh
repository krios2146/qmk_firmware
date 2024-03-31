# bin/bash.sh

qmk compile -km krios2146

sudo ./tkg-toolkit/linux/bin/hid_bootloader_cli -mmcu=atmega32u4 ~/qmk_firmware/ktec_ergodone_krios2146.hex
