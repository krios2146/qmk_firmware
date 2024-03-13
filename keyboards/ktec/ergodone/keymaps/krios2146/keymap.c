#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols layer

enum custom_keycodes {
  VRSN = SAFE_RANGE,
};

enum {
    TD_ESC_GRV
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc/Grv|   1  |   2  |   3  |   4  |   5  |  \   |           |  -_  |   6  |   7  |   8  |   9  |   0  | Delete |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Layer|           |  {   |   Y  |   U  |   I  |   O  |   P  |   -_   |
 * |--------+------+------+------+------+------| SYMB |           |  [   |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  :;  |   =+   |
 * |--------+------+------+------+------+------|      |           |  }   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |  ]   |   N  |   M  |  <,  |  >.  |  /?  |  F11   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Win | Left | Right|  Alt |                                       |  "'  |  Up  | Down |      |  F5  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |Print |       | `~   | Ins  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Back | Space|------|       |------|  Enter | Space|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        TD(TD_ESC_GRV),      KC_1,         KC_2,      KC_3,     KC_4,         KC_5,       KC_BACKSLASH,
        KC_TAB,         KC_Q,         KC_W,      KC_E,     KC_R,         KC_T,       TG(SYMB),
        KC_CAPS_LOCK,   KC_A,         KC_S,      KC_D,     KC_F,         KC_G,
        KC_LEFT_SHIFT,  KC_Z,         KC_X,      KC_C,     KC_V,         KC_B,       KC_NO,
        KC_LEFT_CTRL,   KC_LEFT_GUI,  KC_LEFT,   KC_RGHT,  KC_LEFT_ALT,

                                                 KC_NO,         KC_PRINT_SCREEN,
                                                                KC_HOME,
                                      KC_BACKSPACE,  KC_SPACE,  KC_END,

        // right hand
        KC_MINUS,           KC_6,  KC_7,      KC_8,      KC_9,     KC_0,          KC_DELETE,
        KC_LEFT_BRACKET,    KC_Y,  KC_U,      KC_I,      KC_O,     KC_P,          KC_MINUS,
                            KC_H,  KC_J,      KC_K,      KC_L,     KC_SEMICOLON,  KC_EQUAL,
        KC_RIGHT_BRACKET,   KC_N,  KC_M,      KC_COMMA,  KC_DOT,   MT(MOD_RSFT, KC_SLASH),      KC_F11,
                                   KC_QUOTE,  KC_UP,     KC_DOWN,  KC_NO,         KC_F5,

        KC_GRAVE,           KC_INSERT,
        KC_PGUP,
        KC_PGDN,            KC_ENTER,  KC_SPACE
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------| Layer|           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  | SYMB |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EE_CLR  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,TG(SYMB),
          EE_CLR,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_M_P,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;

    case KC_J:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_ALT) {
            unregister_code(KC_LEFT_ALT);
            tap_code(KC_DOWN);
            register_code(KC_LEFT_ALT);
            return false;
        }
      }

    case KC_K:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_ALT) {
            unregister_code(KC_LEFT_ALT);
            tap_code(KC_UP);
            register_code(KC_LEFT_ALT);
            return false;
        }
      }

    case KC_H:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_ALT) {
            unregister_code(KC_LEFT_ALT);
            tap_code(KC_LEFT);
            register_code(KC_LEFT_ALT);
            return false;
        }
      }

    case KC_L:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_ALT) {
            unregister_code(KC_LEFT_ALT);
            tap_code(KC_RIGHT);
            register_code(KC_LEFT_ALT);
            return false;
        }
      }
  }
  return true;
}

bool led_update_user(led_t led_state) {
    // stub any kb level behaviour
    return false;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(layer_state)) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
