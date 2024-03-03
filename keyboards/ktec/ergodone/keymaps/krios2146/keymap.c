#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define KRIOS2146 1 // krios2146 layer
#define SYMB 2 // symbols layer

enum custom_keycodes {
  VRSN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | Layer|           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| KRIOS|           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Layer|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  | SYMB |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_DEL,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(KRIOS2146),
        KC_BSPC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   TG(SYMB),
        LT(KRIOS2146,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
         KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
         TG(KRIOS2146),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                      KC_H,   KC_J,  KC_K,   KC_L,   LT(SYMB, KC_SCLN),GUI_T(KC_QUOT),
         MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                              KC_UP, KC_DOWN,KC_LBRC,KC_RBRC,          TT(KRIOS2146),
         KC_LALT,        CTL_T(KC_ESC),
         KC_PGUP,
         KC_PGDN,KC_TAB, KC_ENT
    ),
/* Keymap 1: krios2146 layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |  \   |           |  -_  |   6  |   7  |   8  |   9  |   0  |  Back  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Layer|           |  {   |   Y  |   U  |   I  |   O  |   P  |   -_   |
 * |--------+------+------+------+------+------| KRIOS|           |  [   |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  :;  |   =+   |
 * |--------+------+------+------+------+------| Layer|           |  }   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | SYMB |           |  ]   |   N  |   M  |  <,  |  >.  |  /?  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Win | Left | Right|  Alt |                                       |  "'  |  Up  | Down |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |Print |       | `~   | Ins  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      | IDEA | Home |       | PgUp |        |      |
 *                                 | Enter| Auto |------|       |------| Delete |Space |
 *                                 |      | Cmp  | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[KRIOS2146] = LAYOUT_ergodox(
        // left hand
        KC_ESCAPE,      KC_1,         KC_2,      KC_3,     KC_4,         KC_5,       KC_BACKSLASH,
        KC_TAB,         KC_Q,         KC_W,      KC_E,     KC_R,         KC_T,       TG(KRIOS2146),
        KC_CAPS_LOCK,   KC_A,         KC_S,      KC_D,     KC_F,         KC_G,
        KC_LEFT_SHIFT,  KC_Z,         KC_X,      KC_C,     KC_V,         KC_B,       TG(SYMB),
        KC_LEFT_CTRL,   KC_LEFT_GUI,  KC_LEFT,   KC_RGHT,  KC_LEFT_ALT,

                                                 KC_NO,                 KC_PRINT_SCREEN,
                                                                        KC_HOME,
                                      KC_ENTER,  LCTL(LSFT(KC_ENTER)),  KC_END,

        // right hand
        KC_MINUS,           KC_6,  KC_7,      KC_8,      KC_9,     KC_0,          KC_BACKSPACE,
        KC_LEFT_BRACKET,    KC_Y,  KC_U,      KC_I,      KC_O,     KC_P,          KC_MINUS,
                            KC_H,  KC_J,      KC_K,      KC_L,     KC_SEMICOLON,  KC_EQUAL,
        KC_RIGHT_BRACKET,   KC_N,  KC_M,      KC_COMMA,  KC_DOT,   KC_SLASH,      KC_NO,
                                   KC_QUOTE,  KC_UP,     KC_DOWN,  KC_NO,         KC_NO,

        KC_GRAVE,           KC_INSERT,
        KC_PGUP,
        KC_PGDN,            KC_DELETE,  KC_SPACE
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
