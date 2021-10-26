/* Copyright 2021 Jane Bernhardt
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
    _ALPHA,   // default
    _SPECIAL, // special characters
    _NUMBERS  // numbers/function/motion
};

#define KC_CTL_A  MT(MOD_LCTL, KC_A)     // Tap for A, hold for Control
#define KC_SFT_Z  MT(MOD_RSFT, KC_Z)     // Tap for Z, hold for Shift
#define KC_SFT_SL MT(MOD_RSFT, KC_SLSH)  // Tap for slash, hold for Shift

#define KC_ALT_ENT MT(MOD_LALT, KC_ENT)  // Tap for Enter, hold for Alt (Option)
#define KC_SPE_SPC LT(_SPECIAL, KC_SPC)  // Tap for Space, hold for Special layer
#define KC_NUM_SPC LT(_NUMBERS, KC_SPC)  // Tap for Space, hold for Numbers layer

    /* Combomap
     *
     * ,-------------------------------.      ,-------------------------------.
     * |       |     |     |     |     |      |     |     |     |     |       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-DEL-+-BSPC--|
     * |       |     |     |    ESC    |      |    ENT    |     |     |       |
     * |-------+-----+-----+-RMB-+-LMB-|      |-----+-----+-----+-----+-------|
     * |       |     |     |     |     |      |     |     |     |     |       |
     * `-------------------------------'      `-------------------------------'
     *            .-----------------.            .-----------------.
     *            |     |     |     |            |     |     |     |
     *            '-----------------'            '-----------------'
     */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Alpha layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |     Q |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |   P   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | CTRL A|  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  |   ;   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * | SHFT Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  ,  |  .  |SHFT / |
     * `-------------------------------'      `-------------------------------'
     *   .--------------------------.           .----------------------.
     *   | META | ENT ALT | SPC SPE |           | SPC NUM | TAB | SHFT |
     *   '--------------------------'           '----------------------'
     */
    [_ALPHA] = LAYOUT_split_3x5_3(
         KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,          KC_Y,   KC_U,   KC_I,     KC_O,   KC_P,
         KC_CTL_A, KC_S,   KC_D,   KC_F,   KC_G,          KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN,
         KC_SFT_Z, KC_X,   KC_C,   KC_V,   KC_B,          KC_N,   KC_M,   KC_COMMA, KC_DOT, KC_SFT_SL,
                KC_LGUI, KC_ALT_ENT, KC_SPE_SPC,          KC_NUM_SPC, KC_TAB, KC_RSFT),

    /* Keymap 1: Special characters layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |    !  |  @  |  {  |  }  |  |  |      |  `  |  -  |  =  |  /  |   \   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |    #  |  $  |  (  |  )  |     |      | LFT | DWN | UP  | RGT |   '   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |    %  |  ^  |  [  |  ]  |     |      |  &  |  ~  |  +  |  *  |       |
     * `-------------------------------'      `-------------------------------'
     *           .-------------------.          .-----------------.
     *           |       |     |     |          |     |     |     |
     *           '-------------------'          '-----------------'
     */
    [_SPECIAL] = LAYOUT_split_3x5_3(
         KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,          KC_GRV,  KC_MINS, KC_EQL , KC_SLSH, KC_BSLS,
         KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TRNS,          KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_QUOT,
         KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TRNS,          KC_AMPR, KC_TILD, KC_PLUS, KC_ASTR, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS),

    /* Keymap 2: Numbers/Function/Motion layer
     *
     * ,-------------------------------.      ,-------------------------------.
     * |   1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |  F1   | F2  | F3  | F4  | F5  |      |     |     |     |     |       |
     * |-------+-----+-----+-----+-----|      |-----+-----+-----+-----+-------|
     * |  F6   | F7  | F8  | F9  | F10 |      | MLFT| MDWN| MUP | MRGT|       |
     * `-------------------------------'      `-------------------------------'
     *             .-----------------.          .-----------------.
     *             | F11 | F12 |     |          |     |     |     |
     *             '-----------------'          '-----------------'
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
         KC_1,  KC_2,  KC_3,  KC_4,  KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
                    KC_F11, KC_F12, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS)
};