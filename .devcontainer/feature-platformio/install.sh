#/bin/sh

# https://docs.platformio.org/en/latest/core/installation/methods/pypi.html
python3 -m pip install -U platformio

curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/develop/platformio/assets/system/99-platformio-udev.rules | tee /etc/udev/rules.d/99-platformio-udev.rules

service udev restart

# chmod a+rw /dev/ttyUSB0
