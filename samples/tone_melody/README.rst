.. _blinky-tone-sample:

Tone Melody
############

Overview
********

This Arduino sample Plays a melody.

Requirements
************

Your board must:

#. Have piezo buzzer connected via a GPIO pin.
#. GPIO pin can be selected using CONFIG_TONE_OUT_DIGITAL_PIN_NUMBER.

Building and Running
********************

Build and flash Blinky as follows,

```sh
$> west build  -p -b arduino_nano_33_ble samples/basic/tone_melody/ -DZEPHYR_EXTRA_MODULES=/home/$USER/zephyrproject/modules/lib/Arduino-Core-Zephyr

$> west flash --bossac=/home/$USER/.arduino15/packages/arduino/tools/bossac/1.9.1-arduino2/bossac
```

After flashing, the buzzer starts to play a melody.

Adding board support
********************

To add support for your board, set CONFIG_TONE_OUT_DIGITAL_PIN_NUMBER
according to your connections.
