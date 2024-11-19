# bin/bash.sh

sudo echo "Reflashing starting"

qmk compile

for i in {15..1}; do
    echo "$i seconds until reflasing"
    sleep 1
done

echo "Reflasing..."

sudo ./tkg-toolkit/linux/bin/hid_bootloader_cli -mmcu=atmega32u4 ktec_ergodone_krios2146.hex
