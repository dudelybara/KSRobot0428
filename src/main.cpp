#include <Arduino.h>
#include <TM1640.h>
#include <TM16xxMatrix.h>

#if !defined(LED_BUILTIN)
  #define LED_BUILTIN 4
#endif
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include "ksr_pinout.h"
#include "turtle_chassis.h"

enum class controll_state {AUTONOMOUS, BLUETOOTH};
controll_state state = controll_state::AUTONOMOUS;

//set up front LED matrix
TM1640 module(SDA, SCL);
#define MATRIX_NUMCOLUMNS 16
#define MATRIX_NUMROWS 8
TM16xxMatrix matrix(&module, MATRIX_NUMCOLUMNS, MATRIX_NUMROWS); 

// store signals fro LED matrix
enum {FWD, RIGHT, LEFT, BACK};
unsigned char led_direction_signals[4][16] = {
 {0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x7E,0x7E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00},
 {0x18,0x24,0x42,0x81,0x18,0x24,0x42,0x81,0x18,0x24,0x42,0x81,0x18,0x24,0x42,0x81},
 {0x81,0x42,0x24,0x18,0x81,0x42,0x24,0x18,0x81,0x42,0x24,0x18,0x81,0x42,0x24,0x18},                           
 {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xFF,0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18}};

TurtleChassis t;

void bt_controll()
{
  if (GamePad.isUpPressed())
  {
    Serial.print("UP");
    t.forward(500);
    matrix.setImage(led_direction_signals[FWD]);
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("DOWN");
    t.backward(500);
    matrix.setImage(led_direction_signals[BACK]);
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    t.turn_left();
    matrix.setImage(led_direction_signals[LEFT]);
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    t.turn_right();
    matrix.setImage(led_direction_signals[RIGHT]);
  }
}

void setup() {

  Serial.begin(9600);      
  Dabble.begin(9600, 0, 1);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.

}

void loop() {
  Dabble.processInput();         //this function is used to refresh data obtained from smartphone.
  if (Dabble.isAppConnected())
  {
    if (GamePad.isSelectPressed()) // Press Select to toggle AUTO / BT controll 
    { 
      Serial.write("Toggling controll state");
      state = state == controll_state::AUTONOMOUS ? controll_state::BLUETOOTH : controll_state::AUTONOMOUS; // toggle state
      delay(100); // avoid single press multiple toggles
    }
  }
  else
  {
    state = controll_state::AUTONOMOUS;
  }

  if (state == controll_state::AUTONOMOUS)
  {
    t.autonomous();
  }
  else
  {
    bt_controll();
  }

}