#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define GAME 1
#define SYMB 2
#define ARRW 3

enum custom_keycodes {
    COPY = SAFE_RANGE,
    PASTE
};

const uint16_t PROGMEM fj_menu[] = {KC_F, KC_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(fj_menu, KC_APP),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base Layer
 *
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
 * │  Esc   │  1  │  2  │  3  │  4  │  5  │     │       │     │  6  │  7  │  8  │  9  │  0  │   `~   │
 * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
 * │  Tab   │  Q  │  W  │  E  │  R  │  T  │ GA  │       │  [  │  Y  │  U  │  I  │  O  │  P  │   ─_   │
 * ├────────┼─────┼─────┼─────┼─────┼─────┤ ME  │       │  {  ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │ Cpswrd │  A  │  S  │  D  │  F  │  G  ├─────┤       ├─────┤  H  │  J  │  K  │  L  │ :;  │   =+   │
 * ├────────┼─────┼─────┼─────┼─────┼─────┤     │       │  ]  ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │ LShift │ Z ^ │  X  │  C  │  V  │  B  │     │       │  }  │  N  │  M  │  <, │ >.^ │ /?⇧ │   \│   │
 * └─┬──────┼─────┼─────┼─────┼─────┼─────┴─────┘       └─────┴─────┼─────┼─────┼─────┼─────┼──────┬─┘
 *   │ SYMB │ Win │     │     │ Alt │                               │  "' │     │     │SYMB │      │
 *   └──────┴─────┴─────┴─────┴─────┘                               └─────┴─────┴─────┴─────┴──────┘
 *                                  ┌─────┬─────┐       ┌─────┬─────┐
 *                                  │Copy │Print│       │ Ins │Paste│
 *                            ┌─────┼─────┼─────┤       ├─────┼─────┼─────┐
 *                            │     │     │ Home│       │PgUp │     │     │
 *                            │Back │ Del ├─────┤       ├─────│Enter│Space│
 *                            │     │     │ End │       │PgDn │     │     │
 *                            └─────┴─────┴─────┘       └─────┴─────┴─────┘
 */
[BASE] = LAYOUT_ergodox(
        // Left hand
        KC_ESC,    KC_1,          KC_2,   KC_3,   KC_4,     KC_5,    KC_NO,
        KC_TAB,    KC_Q,          KC_W,   KC_E,   KC_R,     KC_T,    TG(GAME),
        CW_TOGG,   KC_A,          KC_S,   KC_D,   KC_F,     KC_G,
        KC_LSFT,   LCTL_T(KC_Z),  KC_X,   KC_C,   KC_V,     KC_B,    KC_NO,
        TT(SYMB),  KC_LEFT_GUI,   KC_NO,  TT(ARRW),  KC_LALT,

                                                            // Thumb cluster
                                                            COPY,    KC_PRINT_SCREEN,
                                                                     KC_HOME,
                                                  KC_BSPC,  KC_DEL,  KC_END,

        // Right hand
        KC_NO,    KC_6,      KC_7,      KC_8,     KC_9,            KC_0,              KC_GRV,
        KC_LBRC,  KC_Y,      KC_U,      KC_I,     KC_O,            KC_P,              KC_MINS,
                  KC_H,      KC_J,      KC_K,     KC_L,            KC_SCLN,           KC_EQL,
        KC_RBRC,  KC_N,      KC_M,      KC_COMM,  LCTL_T(KC_DOT),  RSFT_T(KC_SLASH),  KC_BSLS,
                             KC_QUOTE,  KC_NO,    KC_NO,           TT(SYMB),          KC_NO,

        // Thumb cluster
        KC_INS,   PASTE,
        KC_PGUP,
        KC_PGDN,  KC_ENT,    KC_SPC
),
/* Keymap 1: Gaming Layer
 *
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
 * │  Esc   │  1  │  2  │  3  │  4  │  5  │     │       │     │  6  │  7  │  8  │  9  │  0  │   `~   │
 * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
 * │  Tab   │  Q  │  W  │  E  │  R  │  T  │ GA  │       │  [  │  Y  │  U  │  I  │  O  │  P  │   ─_   │
 * ├────────┼─────┼─────┼─────┼─────┼─────┤ ME  │       │  {  ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │  Caps  │  A  │  S  │  D  │  F  │  G  ├─────┤       ├─────┤  H  │  J  │  K  │  L  │ :;  │   =+   │
 * ├────────┼─────┼─────┼─────┼─────┼─────┤     │       │  ]  ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │ LShift │ Z ^ │  X  │  C  │  V  │  B  │     │       │  }  │  N  │  M  │  <, │ >.^ │ /?⇧ │   \│   │
 * └─┬──────┼─────┼─────┼─────┼─────┼─────┴─────┘       └─────┴─────┼─────┼─────┼─────┼─────┼──────┬─┘
 *   │ SYMB │ Win │     │     │ Alt │                               │  "' │     │     │SYMB │      │
 *   └──────┴─────┴─────┴─────┴─────┘                               └─────┴─────┴─────┴─────┴──────┘
 *                                  ┌─────┬─────┐       ┌─────┬─────┐
 *                                  │Copy │Print│       │ Ins │Paste│
 *                            ┌─────┼─────┼─────┤       ├─────┼─────┼─────┐
 *                            │     │     │ Home│       │PgUp │     │     │
 *                            │Space│ Del ├─────┤       ├─────│Enter│ Back│
 *                            │     │     │ End │       │PgDn │     │     │
 *                            └─────┴─────┴─────┘       └─────┴─────┴─────┘
 */
[GAME] = LAYOUT_ergodox(
        // Left hand
        KC_ESC,    KC_1,          KC_2,   KC_3,   KC_4,     KC_5,    KC_NO,
        KC_TAB,    KC_Q,          KC_W,   KC_E,   KC_R,     KC_T,    TG(GAME),
        KC_CAPS,   KC_A,          KC_S,   KC_D,   KC_F,     KC_G,
        KC_LSFT,   LCTL_T(KC_Z),  KC_X,   KC_C,   KC_V,     KC_B,    KC_NO,
        TT(SYMB),  KC_LEFT_GUI,   KC_NO,  TT(ARRW),  KC_LALT,

                                                            // Thumb cluster
                                                            COPY,    KC_PRINT_SCREEN,
                                                                     KC_HOME,
                                                  KC_SPC,   KC_DEL,  KC_END,

        // Right hand
        KC_NO,    KC_6,      KC_7,      KC_8,     KC_9,            KC_0,              KC_GRV,
        KC_LBRC,  KC_Y,      KC_U,      KC_I,     KC_O,            KC_P,              KC_MINS,
                  KC_H,      KC_J,      KC_K,     KC_L,            KC_SCLN,           KC_EQL,
        KC_RBRC,  KC_N,      KC_M,      KC_COMM,  LCTL_T(KC_DOT),  RSFT_T(KC_SLASH),  KC_BSLS,
                             KC_QUOTE,  KC_NO,    KC_NO,           TT(SYMB),          KC_NO,

        // Thumb cluster
        KC_INS,   PASTE,
        KC_PGUP,
        KC_PGDN,  KC_ENT,   KC_BSPC
),
/* Keymap 2: Symbol Layer
 *
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
 * │        │ F1  │ F2  │ F3  │ F4  │ F5  │     │       │     │ F6  │ F7  │ F8  │ F9  │ F10 │  F11   │
 * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
 * │        │  `  │  ~  │  {  │  }  │     │     │       │     │     │  7  │  8  │  9  │  0  │  F12   │
 * ├────────┼─────┼─────┼─────┼─────┼─────│     │       │     ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │        │  @  │  %  │  (  │  )  │  &  ├─────┤       ├─────┤  |  │  4  │  5  │  6  │  *  │ LED_TG │
 * ├────────┼─────┼─────┼─────┼─────┼─────┤     │       │     ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │        │  #  │     │  [  │  ]  │  !  │     │       │     │     │  1  │  2  │  3  │  \  │        │
 * └─┬──────┼─────┼─────┼─────┼─────┼─────┴─────┘       └─────┴─────┼─────┼─────┼─────┼─────┼──────┬─┘
 *   │      │     │     │     │     │                               │     │     │     │     │      │
 *   └──────┴─────┴─────┴─────┴─────┘                               └─────┴─────┴─────┴─────┴──────┘
 *                                  ┌─────┬─────┐       ┌─────┬─────┐
 *                                  │     │     │       │     │     │
 *                            ┌─────┼─────┼─────│       ├─────┼─────┼─────┐
 *                            │     │     │     │       │     │     │     │
 *                            │   ^ │     ├─────┤       ├─────┤     │  $  │
 *                            │     │     │     │       │     │     │     │
 *                            └─────┴─────┴─────┘       └─────┴─────┴─────┘
 */
[SYMB] = LAYOUT_ergodox(
       // Left hand
       KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
       KC_TRNS,  KC_GRV,   KC_TILD,  KC_LCBR,  KC_RCBR,  KC_DLR,   KC_TRNS,
       KC_TRNS,  KC_AT,    KC_PERC,  KC_LPRN,  KC_RPRN,  KC_AMPR,
       KC_TRNS,  KC_HASH,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_EXLM,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                         // Thumb cluster
                                                         KC_TRNS,  KC_TRNS,
                                                                   KC_TRNS,
                                               KC_TRNS,  KC_NO,    KC_TRNS,
       // Right hand
       KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
       KC_TRNS,  KC_NO,    KC_7,     KC_8,     KC_9,     KC_0,     KC_F12,
                 KC_PIPE,  KC_4,     KC_5,     KC_6,     KC_ASTR,  KC_TRNS,
       KC_TRNS,  KC_NO,    KC_1,     KC_2,     KC_3,     KC_BSLS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

       // Thumb cluster
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_NO,    KC_TRNS
),
/* Keymap 3: Arrow Layer
 *
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┬─────┬────────┐
 * │        │     │     │     │     │     │     │       │     │     │     │     │     │     │        │
 * ├────────┼─────┼─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┼─────┼────────┤
 * │        │     │     │     │     │     │     │       │     │     │     │     │     │     │        │
 * ├────────┼─────┼─────┼─────┼─────│     │     │       │     ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │        │     │     │     │     │     ├─────┤       ├─────┤ <-  │  ↓  │  ↑  │ ->  │     │        │
 * ├────────┼─────┼─────┼─────┼─────┼─────┤     │       │     ├─────┼─────┼─────┼─────┼─────┼────────┤
 * │        │     │     │     │     │     │     │       │     │     │     │     │     │     │        │
 * └─┬──────┼─────┼─────┼─────┼─────┼─────┴─────┘       └─────┴─────┼─────┼─────┼─────┼─────┼──────┬─┘
 *   │      │     │     │     │     │                               │     │     │     │     │      │
 *   └──────┴─────┴─────┴─────┴─────┘                               └─────┴─────┴─────┴─────┴──────┘
 *                                  ┌─────┬─────┐       ┌─────┬─────┐
 *                                  │     │     │       │     │     │
 *                            ┌─────┼─────┼─────│       ├─────┼─────┼─────┐
 *                            │     │     │     │       │     │     │     │
 *                            │     │     ├─────┤       ├─────┤     │     │
 *                            │     │     │     │       │     │     │     │
 *                            └─────┴─────┴─────┘       └─────┴─────┴─────┘
 */
[ARRW] = LAYOUT_ergodox(
       // Left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                         // Thumb cluster
                                                         KC_TRNS,  KC_TRNS,
                                                                   KC_TRNS,
                                               KC_TRNS,  KC_TRNS,  KC_TRNS,
       // Right hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                 KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

       // Thumb cluster
       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Ctrl - Ins
    case COPY:
      if (record->event.pressed) {
        register_code(KC_LEFT_CTRL);
        tap_code(KC_INSERT);
        unregister_code(KC_LEFT_CTRL);
        return false;
      }

    // Shift - Ins
    case PASTE:
      if (record->event.pressed) {
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_INSERT);
        unregister_code(KC_LEFT_SHIFT);
        return false;
      }

    // Alt - J = Down
    case KC_J:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_ALT) {
            unregister_code(KC_LEFT_ALT);
            tap_code(KC_DOWN);
            register_code(KC_LEFT_ALT);
            return false;
        }
      }

    // Alt - K = Up
    case KC_K:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_ALT) {
            unregister_code(KC_LEFT_ALT);
            tap_code(KC_UP);
            register_code(KC_LEFT_ALT);
            return false;
        }
      }

    // Alt - H = Left
    case KC_H:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_ALT) {
            unregister_code(KC_LEFT_ALT);
            tap_code(KC_LEFT);
            register_code(KC_LEFT_ALT);
            return false;
        }
      }

    // Alt - L = Right
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
