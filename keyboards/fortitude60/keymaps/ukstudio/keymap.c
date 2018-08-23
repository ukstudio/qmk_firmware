#include QMK_KEYBOARD_H
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------.             ,-----------------------------------------.
 * | Esc  |   1  |   2    |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+--------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W    |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+--------+------+------+------|             |------+------+------+------+------+------|
 * | =    |   A  |   S    |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  ]   |
 * |------+------+--------+------+------+------+-------------+------+------+------+------+------+------|
 * | Shift|   Z  |   X    |   C  |   V  |   B  | Alt  | Bksp |   N  |   M  |   ,  |   .  |   /  |Shift |
 * `-------------+--------+------+------+------+------+------+------+------+------+------+-------------'
 *               |ctrl+alt|  `   | Lower| Ctrl | GUI  |Enter |Space |Raise |  '   |  \   |
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2, KC_3,     KC_4,  KC_5,                       KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINUS, \
  KC_TAB,  KC_Q,    KC_W, KC_E,     KC_R,  KC_T,                       KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC, \
  KC_EQUAL,  KC_A,  KC_S, KC_D,     KC_F,  KC_G,                       KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_RBRC, \
  KC_LSFT, KC_Z,    KC_X, KC_C,     KC_V,  KC_B,    KC_LALT,  KC_BSPC, KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
          LALT(KC_LCTRL), KC_GRAVE, LOWER, KC_LCTL, KC_LGUI,  KC_ENT,  KC_SPC,  RAISE, KC_QUOT, KC_BSLASH\
),

/* Lower
 * ,---------------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @      |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+----------+------+------+------|             |------+------+------+------+------+------|
 * |   ~  |   !  |   @      |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |  \   |
 * |------+------+----------+------+------+------|             |------+------+------+------+------+------|
 * | Del  |  F1  | Alt+Down |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |      |   \  |  '   |
 * |------+------+----------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |  F7  |  F8      |  F9  |  F10 |  F11 |      |      |  F12 |ISO ~ |ISO | |      |      |      |
 * `-------------+----------+------+------+------+------+------+------+------+------+------+-------------'
 *               |          |      |      |      |      |      |      |      |      |      |
 *               `-------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,         KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_TILD, KC_EXLM, KC_AT,         KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLASH,  \
  KC_DEL,  KC_F1,   LALT(KC_DOWN), KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUOT, \
  _______, KC_F7,   KC_F8,         KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,\
                    _______,      _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |   `  |   1  |  up  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * | Del  | left | down |right |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Shift |  F7  |  F8  |  F9  |  F10 |  F11 | Alt  |      |  F12 |ISO # |ISO / |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_GRV,  KC_1,    KC_UP,   KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLASH, \
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_F4,   KC_F5,                      KC_F6,KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,    KC_BSLS, \
  KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_LALT, _______,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_BSPC, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______, \
  QWERTY,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
