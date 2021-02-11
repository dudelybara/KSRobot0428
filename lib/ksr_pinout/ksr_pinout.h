#ifndef KSR_pinout
#define KSR_pinout

#include "Arduino.h"

enum Pin : uint8_t
{ 
      /* KS007 motor shield */
      motor_rb_speed = 11,
      motor_la_speed = 3,
      motor_rb_dir   = 13,
      motor_la_dir   = 12,
      /* KS007 sensor shield v5 */
      ult_sonic_echo = 4,
      ult_sonic_tr1g = 5,
      servo          = 9,
      ir_receiver    = A0,
      photo_res_l    = A1,
      photo_res_r    = A2,
      i2c_sda        = A4,
      i2c_scl        = A5
};

#endif // KSR_pinout