// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _BASE,
    _GAME,
    _NUM,
    _BRACK,
    _ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
  KC_1,              KC_2,   KC_3,    KC_4,    KC_5,    KC_6,                              KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_GRV,
  LT(_ARROW,KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  LCTL_T(KC_ESC),    KC_A,   KC_S,    KC_D,    KC_F,    LT(_NUM,KC_G),                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,           KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,        XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
        DF(_GAME), KC_LALT, LCTL(KC_LSFT), LT(_BRACK, KC_SPC), KC_LGUI,              KC_ENT,  KC_SPC, KC_EQL, KC_BSLS, LCTL(KC_SPC)
),

[_GAME] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,
  KC_TAB,  KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                            KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,
  KC_LSFT, KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,      _______,  _______, _______, _______, _______,  _______, _______,
                DF(_BASE), KC_LALT, KC_LALT, KC_SPC, KC_M,              KC_MPRV, KC_MNXT, _______, _______, _______
),

[_NUM] = LAYOUT(
  _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                    _______,KC_7,   KC_8,   KC_9,   KC_PMNS, _______,
  _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,                    _______,KC_4,   KC_5,   KC_6,   KC_PPLS,  KC_BSPC,
  _______, _______, _______,KC_F11,KC_F12,_______,                    _______,KC_1,   KC_2,   KC_3,   KC_PPLS, _______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,KC_0,   KC_0,   KC_DOT,   KC_PENT, _______,
                  _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______
),

[_BRACK] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LPRN,KC_RPRN,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LCBR,KC_RCBR,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,KC_LBRC,KC_RBRC,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
              _______,_______,_______,_______,_______,           _______,_______,_______,_______,_______
),

[_ARROW] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                    KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT, _______,_______,
  _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
              _______,_______,_______,KC_MPRV,KC_MNXT,            _______,_______,_______,_______,_______
),

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_clear();
    if (is_keyboard_master()) {
        uint8_t active_layer = get_highest_layer(layer_state | default_layer_state);

        // Show overlay layer if active, otherwise show base layer
        switch (active_layer) {
            case _BASE:
                oled_write_P(PSTR("BASE\n\nBASE\n\nBASE"), false);
                break;
            case _GAME:
                oled_write_P(PSTR("GAME\n\nGAME\n\nGAME"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("NUM\n\nNUM\n\nNUM"), false);
                break;
            case _BRACK:
                oled_write_P(PSTR("BRACK\n\nBRACK\n\nBRACK"), false);
                break;
            case _ARROW:
                oled_write_P(PSTR("ARROW\n\nARROW\n\nARROW"), false);
                break;
            default:
                oled_write_P(PSTR("???\n\n???\n\n???"), false);
                break;
        }
    } else {
        // Slave side - show a simple message
        oled_write_P(PSTR("Sofle\nKeyboard"), false);
    }
    return false;
}
#endif
