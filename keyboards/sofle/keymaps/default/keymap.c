// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _NUM,
    _BRACK,
    _ARROW,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

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

[_QWERTY] = LAYOUT(
  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,                            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_GRV,
  LT(_ARROW,KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  LCTL_T(KC_ESC),    KC_A,   KC_S,    KC_D,    KC_F,    LT(_NUM,KC_G),                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,           KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,      XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                KC_LGUI, KC_LALT, LCTL(KC_LSFT), KC_SPC, KC_LGUI,              KC_ENT,  KC_SPC, KC_EQL, KC_BSLS, LCTL(KC_SPC)
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
              _______,_______,_______,_______,_______,            _______,_______,_______,_______,_______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Master side - show layer info
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case 0: oled_write_P(PSTR("QWERTY"), false); break;
            case 1: oled_write_P(PSTR("LOWER"), false); break;
            case 2: oled_write_P(PSTR("RAISE"), false); break;
            default: oled_write_P(PSTR("UNKNOWN"), false);
        }
    } else {
        // Slave side - show a simple message
        oled_write_P(PSTR("Sofle\nKeyboard"), false);
    }
    return false;
}
#endif
