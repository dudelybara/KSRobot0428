# Firmware for Keyestudio Tank Robot V2 0428

### Features

  * Obstacle avoiding using ultrasonic sensor
  * Bluetooth controll using `Dabble` (app available for both Android & iOS)
    - Use joystick controller
    - Press `Select` to switch between autonomous obstacle avoiding and Bluetooth controll 
  * Display images on LED matrix

### Build & upload firmware

Build using platformio

`pio run -e uno -t upload`

Always unplug Bluetooth module, otherwise upload will fail