// Nordic layout for Ergodox infinity

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// Layer names
#define BASE 0 // default layer
#define FUNCL 1 // function layer

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   -  |           |   =  |   6  |   7  |   8  |   9  |   0  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   [  |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCtrl |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| Menu |           |   `  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LEFT |RIGHT |LCtrl | LAlt | LGui |                                       | LEFT | DOWN |  UP  |RIGHT |  NO  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |Prscr |  L1  |       |  L1  |  Pause |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| Del  |------|       |------|  Enter | Bkspc|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[BASE] = LAYOUT_ergodox_pretty(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,          KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,          KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_APP,          KC_GRV, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
  KC_LEFT, KC_RGHT, KC_LCTL, KC_LALT, KC_LGUI,            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
  KC_PSCR, MO(1),                                         MO(1), KC_PAUS,
  KC_HOME,                                                KC_PGUP,
  KC_BSPC, KC_DEL, KC_END,                                KC_PGDN, KC_ENT, KC_SPC
),

/* Keymap 1: Basic layer with functions
 *
 * 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | BL+  |           | Vol+ |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| BL-  |           | Vol- |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Mute |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Reset |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        | Play |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */

[FUNCL] = LAYOUT_ergodox_pretty(
  KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11,          KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_INC,          KC__VOLUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_DEC,          KC__VOLDOWN, KC_NO, KC__MUTE, KC_NO, KC_NO, KC_NO, KC_NO,
  RESET, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_TRNS,                                            KC_TRNS, KC_NO,
  KC_NO,                                                     KC_NO,
  KC_NO, KC_NO, KC_NO,                                       KC_NO, KC_NO, KC_MPLY
)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}  

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_led_lower_off();
  ergodox_led_raise_off();
  ergodox_led_adjust_off();

  switch (layer) {
    case BASE:
      ergodox_led_lower_on();
      break;
    case FUNCL:
      ergodox_led_raise_on();
      break;
    // case _ADJUST:
      // ergodox_led_adjust_on();
      // break;
  } 
};
