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
#define _LAY3 3
#define _LAY4 4
#define _LAY5 5
#define _LAY6 6
#define _LAY7 7
#define _LAY8 8
#define _LAY9 9
#define _LAY10 10
#define _LAY11 11
#define _LAY12 12
#define _LAY13 13
#define _LAY14 14
#define _LAY15 15


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  GESC  |    Q   |    W   |    E   |    R   |    T   |                    |    Y   |    U   |    I   |    O   |    P   |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |    A   |    S   |    D   |    F   |    G   |                    |    H   |    J   |    K   |    L   | ; / :  | ' / "  |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift |    Z   |    X   |    C   |    V   |    B   |                    |    N   |    M   |    ,   |    .   |    /   |  Shift |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |  TG(2) |  TG(1) | KC_ENT |  | KC_SPC |    !   |  TG(3) |
   *                                    +--------------------------+  +--------------------------'
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
   *|  LCMD  |    *   |    @   |    ?   |    -   |        |                    |        |  LEFT  |        |  RIGHT | ; / :  | ' / "  |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift |        |        |        |        |        |                    |    £   |        |    ,   |    .   |    ?   |  Shift |
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
      KC_LGUI, KC_ASTR,   KC_AT, KC_QUES, KC_MINS, XXXXXXX,                      XXXXXXX, KC_LEFT, XXXXXXX,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HASH, XXXXXXX, _______, _______, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, KC_RALT,    TG(3)
                                      //`--------------------------'  `--------------------------'
  ),

    /* Layer 2 - SYM
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|   TAB  |    !   |    @   |    £   |    $   |    %   |                    |    ^   |    &   |    *   |    (   |    )   |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |  LCTRL |    |   | # and ~|        |        |                    |- and _ |= and + |[ and { |] and } |\ and | |` and ~ |
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
      _______, KC_LCTL, KC_PIPE, KC_NUHS, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   TG(1), _______,    _______, KC_RALT,    TG(3)
                                      //`--------------------------'  `--------------------------'
  ),

    /* Layer 3 - Layers
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  RESET |        |        |        |L_4:*+-/|L_5:()  |                    |        |        |   UP   |        |        |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |L_6:    |L_7:    |L_8:    |L_9:    |L_10:   |                    |        |  LEFT  |  DOWN  |  RIGHT |        |        |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift |L_11:NUM|L_12:SYM|L_13:   |L_14:   |L_15:   |                    |        |        |        |        |        |  ESC   |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |  TG(2) | LAYER_2| KC_ENT |  | KC_SPC |        |  BASE  |
   *                                    +--------------------------+  +--------------------------'
   */
//  [3] = LAYOUT_split_3x6_3(
    [_LAY3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX,   TG(4),   TG(5),                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   TG(6),   TG(7),   TG(8),   TG(9),  TG(10),                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  TG(11),  TG(12),  TG(13),  TG(14),  TG(15),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    /* Layer 4 - Operations
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|        |        |        |        | LAYER_3|        |                    |        |    -   |    +   |    =   |        |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|        |        |        |        |        |        |                    |        |    *   |    /   |        |        |        |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|        |        |        |        |        |        |                    |        |        |        |        |        |  ESC   |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |        |        | KC_ENT |  | KC_SPC |        |        |
   *                                    +--------------------------+  +--------------------------'
   */
  [_LAY4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                      XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_ASTR, KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    /* Layer 5 - Parentheses
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|        |        |        |        |        | LAYER_3|                    |        |    [   |    ]   |        |        |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|        |        |        |        |        |        |                    |        |    (   |    )   |        |        |        |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|        |        |        |        |        |        |                    |        |    {   |    }   |        |        |  ESC   |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |        |        | KC_ENT |  | KC_SPC |        |        |
   *                                    +--------------------------+  +--------------------------'
   */
  [_LAY5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAY6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAY7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAY8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    /* Layer 9 - Right Numpad
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|        |        |        |        |        |        |                    |        |    1   |    2   |    3   |        |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|        |        |        |        | LAYER_3|        |                    |        |    4   |    5   |    6   |    .   |        |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|        |        |        |        |        |        |                    |        |    7   |    8   |    9   |    0   |   ESC  |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |        |        | KC_ENT |  | KC_SPC |        |        |
   *                                    +--------------------------+  +--------------------------'
   */
  [_LAY9] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                      XXXXXXX,    KC_4,    KC_5,    KC_6,  KC_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAY10] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    /* Layer 11 - NUMBERS, same as layer 1
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  TAB   |    1   |    2   |    3   |    4   |    5   |                    |    6   |    7   |    8   |    9   |    0   |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |    *   |    @   |    ?   |    -   |        |                    |        |  LEFT  |        |  RIGHT | ; / :  | ' / "  |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift | LAYER_3|        |        |        |        |                    |    £   |        |    ,   |    .   |    ?   |  Shift |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |        |        | KC_ENT |  | KC_SPC |  R Alt |        |
   *                                    +--------------------------+  +--------------------------'
   */

  [_LAY11] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_ASTR,   KC_AT, KC_QUES, KC_MINS, XXXXXXX,                      XXXXXXX, KC_LEFT, XXXXXXX,KC_RIGHT, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HASH, XXXXXXX, KC_COMM,  KC_DOT, KC_QUES, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, KC_RALT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    /* Layer 12 - SYMBOLS - same as layer 2
   *,--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|   TAB  |    !   |    @   |    £   |    $   |    %   |                    |    ^   |    &   |    *   |    (   |    )   |  Bksp  |
   *|--------+--------+--------+--------+--------+--------+                    |--------+--------+--------+--------+--------+--------+
   *|  LCMD  |  LCTRL |    |   | # and ~|        |    _   |                    |- and _ |= and + |[ and { |] and } |\ and | |` and ~ |
   *|--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------|
   *|  Shift |        | LAYER_3|        |        |        |                    |    _   |    +   |    {   |    }   |    |   |    ~   |
   *|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                    |        |        | KC_ENT |  | KC_SPC |  R Alt |        |
   *                                    +--------------------------+  +--------------------------'
   */

  [_LAY12] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_LCTL, KC_PIPE, KC_NUHS, XXXXXXX, KC_UNDS,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, KC_RALT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAY13] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAY14] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LAY15] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, _______, XXXXXXX
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
    oled_write_P(PSTR("Now: "), false);
    
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
        case _LAY3:
            oled_write_ln_P(PSTR("3 LAYERS"), false);
            break;
        case _LAY4:
            oled_write_ln_P(PSTR("4 MATHS OP"), false);
            break;
        case _LAY5:
            oled_write_ln_P(PSTR("5 PARENTHESIS"), false);
            break;
        case _LAY6:
            oled_write_ln_P(PSTR("6 empty"), false);
            break;
        case _LAY7:
            oled_write_ln_P(PSTR("7 empty"), false);
            break;
        case _LAY8:
            oled_write_ln_P(PSTR("8 empty"), false);
            break;
        case _LAY9:
            oled_write_ln_P(PSTR("9 R_NUMPAD"), false);
            break;
        case _LAY10:
            oled_write_ln_P(PSTR("10 empty"), false);
            break;
        case _LAY11:
            oled_write_ln_P(PSTR("11 Numbers"), false);
            break;
        case _LAY12:
            oled_write_ln_P(PSTR("12 Symbols"), false);
            break;
        case _LAY13:
            oled_write_ln_P(PSTR("13 empty"), false);
            break;
        case _LAY14:
            oled_write_ln_P(PSTR("14 empty"), false);
            break;
        case _LAY15:
            oled_write_ln_P(PSTR("15 empty"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[208] = {
// this file contains what is displayed on OLED on simple keypresses
// uses Usage ID, also visible in Karabiner
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
