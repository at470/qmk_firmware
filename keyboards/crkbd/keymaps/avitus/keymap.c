/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

//AT NOTES
//https://docs.qmk.fm/#/keycodes
// GESC - ESC, Hold down SHIFT for backtick (`)
// TG - toggle to layer, need to toggle back
// MO - momentary shift

// edit 13th may 2021
// define the layer names
#define _BASE 0
#define _NUM1 1
#define _SYM2 2
#define _FNC3 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
   *,-----------------------------------------.                 ,-----------------------------------------.
   *| GESC |   Q  |   W  |   E  |   R  |   T  |                 |   Y  |   U  |   I  |   O  |   P  | Bksp |
   *|------+------+------+------+------+------|                 |------+------+------+------+------+------|
   *| LCMD |   A  |   S  |   D  |   F  |   G  |                 |   H  |   J  |   K  |   L  |; / : |' / " |
   *|------+------+------+------+------+------+                 +------+------+------+------+------+------|
   *| Shift|   Z  |   X  |   C  |   V  |   B  |                 |   N  |   M  |   ,  |   .  |   /  |Shift |
   *|------+------+------+------+------+------+------.    ,-----+------+------+------+------+------+------|
   *                            | TG2  | TG1  | Ent  |    |Space|   !  | TG3  |
   *                            `---------------------    --------------------'
   */
//  [0] = LAYOUT_split_3x6_3( // original
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TG(2),   TG(1),  KC_ENT,     KC_SPC, KC_EXLM,    TG(3)
                                      //`--------------------------'  `--------------------------'
  ),

    /* Layer 1 - NUM
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  TAB   |    1   |    2   |    3   |    4   |    5   |                    |    6   |    7   |    8   |    9   |    0   |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |    *   |    @   |    !   |        |        |                    |        |  LEFT  |   UP   |  RIGHT | ; / :  | ' / "  |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift |        |        |        |        |        |                    |    £   |        |  DOWN  |    .   |    ?   |  Shift |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |  TG(2) |  BASE  | KC_ENT |  | KC_SPC |  R Alt |  TG(3) |
   *                                    +--------------------------+  +--------------------------'
   * ALT+3 - #
   * ALT+2 - €
   */
//  [1] = LAYOUT_split_3x6_3(
  [_NUM1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_ASTR,   KC_AT, KC_EXLM, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT,   KC_UP,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HASH, XXXXXXX, KC_DOWN, _______, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, KC_RALT,    TG(3)
                                      //`--------------------------'  `--------------------------'
  ),

    /* Layer 2 - SYM
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|   TAB  |    !   |    @   |    £   |    $   |    %   |                    |    ^   |    &   |    *   |    (   |    )   |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |  LCTRL |  GESC  | # and ~|        |        |                    |- and _ |= and + |[ and { |] and } |\ and | |` and ~ |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift |        |        |        |        |        |                    |    _   |    +   |    {   |    }   |    |   |    ~   |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |  BASE  |LAYER_1 | KC_ENT |  | KC_SPC |  R Alt |LAYER_3 |
   *                                    +--------------------------+  +--------------------------'
   */
//  [2] = LAYOUT_split_3x6_3(
    [_SYM2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, KC_GESC, KC_NUHS, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   TG(1), _______,    _______, KC_RALT,    TG(3)
                                      //`--------------------------'  `--------------------------'
  ),

    /* Layer 3 - FN
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  RESET |  UNDO  |        |        |        |   CUT  |                    |   DEL  |        |   UP   |        |        |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |  LCTRL |        |        |        |  COPY  |                    |        |  LEFT  |  DOWN  |  RIGHT |        |        |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift |  CAPS  |        |        |        |  PASTE |                    |        |        |        |        |        |  GESC  |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |  TG(2) | LAYER_2| KC_ENT |  | KC_SPC |  R ALT |  BASE  |
   *                                    +--------------------------+  +--------------------------'
   */
//  [3] = LAYOUT_split_3x6_3(
    [_FNC3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, KC_UNDO, XXXXXXX, XXXXXXX, XXXXXXX,  KC_CUT,                       KC_DEL, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_COPY,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSTE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_ENT,     KC_SPC, KC_RALT, _______
                                      //`--------------------------'  `--------------------------'
  )

};

// FOR OLED SCREENS
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _NUM1:
            oled_write_ln_P(PSTR("1 NUM"), false);
            break;
        case _SYM2:
            oled_write_ln_P(PSTR("2 SYMB"), false);
            break;
        case _FNC3:
            oled_write_ln_P(PSTR("3 FUNC"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[208] = {
  #include "keycodes.h" 
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';

    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX))
    {
        keycode = keycode & 0xFF;
    }

    if (keycode < 208)
    {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(
        keylog_str,
        sizeof(keylog_str),
        "%dx%d, k%2d : %c",
        record->event.key.row,
        record->event.key.col,
        keycode,
        name
    );
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
