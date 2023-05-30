// Copyright 2021 Brian Low
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Helpful links:
// - QMK Keycodes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
// - Repo: https://github.com/zachwilson-sofle-choc/qmk_firmware/tree/choc2

#include QMK_KEYBOARD_H

enum sofle_layers {
  _BASE,
  _SYM,
  _NAV,
};

#define NAV MO(_NAV)  // Momentarily turn on layer when pressed
#define SYM MO(_SYM)  // Momentarily turn on layer when pressed
#define MAC AG_SWAP   // Swap Alt/Opt and Gui/Cmd to work for Mac
#define NIX AG_NORM   // Unswap Alt/Opt and Gui/Cmd to work for Linux (default)

#define PRV_WS LCTL(LWIN(KC_LEFT))   // Previous workspace (formerly M2)
#define NXT_WS LCTL(LWIN(KC_RIGHT))  // Next workspace (formerly M3)
#define C_SLSH LCTL(KC_SLSH)         // Ctrl+Slash (formerly M6)

#define MUTE_S LCTL(LSFT(KC_SPC))    // Mute Slack
#define MUTE_T LCTL(LSFT(KC_M))      // Mute Teams

#ifdef COMBO_ENABLE

/*
 * Combomap (vertical)
 *
 * ,----------------------------------------.                         ,-----------------------------------------.
 * |      |      |      |      |      |      |                        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                        |      |      |      |      |      |      |
 * |------+-- ! -+-- @ -+-- # -+-- $ -+-- % -|                        |-- ^ -+-- & -+-- * -+---(--+---)--+------|
 * |      |      |      |      |      |      |-------.        ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|        |-------|      |      |      |      |      |      |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               |      |      |      |      | /      /      \      \ |      |      |      |      |
 *               `----------------------------/------/        \------\----------------------------'
 */
/*
 * Combomap (horizontal)
 *
 * ,----------------------------------------.                         ,-----------------------------------------.
 * |      |      |      |      |      |      |                        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |      |      |      |     Del     |                        |     Del     |      |      |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |      |      |      |     Bspc    |-------.        ,-------|     Bspc    |      |      |      |      |
 * |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
 * |      |      |   S(Tab)   Tab     |      |-------|        |-------|      |     Ent     |      |      |      |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               |      |      |      |      | /      /      \      \ |      |      |      |      |
 *               `----------------------------/------/        \------\----------------------------'
 */
enum combos {
  Q_A__EXLM,
  W_S__AT,
  E_D__HASH,
  R_F_DLR,
  T_G__PERC,
  Y_H__CIRC,
  U_J__AMPR,
  I_K__ASTR,
  O_L__LPRN,
  P_SCLN__RPRN,
  R_T__DEL,
  Y_U__DEL,
  F_G__BSPC,
  H_K__BSPC,
  X_C__S_TAB,
  C_V__TAB,
  M_COMM__ENT,
};

const uint16_t PROGMEM qa_combo[]    = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM ws_combo[]    = {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM ed_combo[]    = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM rf_combo[]    = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM tg_combo[]    = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM yh_combo[]    = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM uj_combo[]    = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM ik_combo[]    = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM ol_combo[]    = {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM pscln_combo[] = {KC_P, KC_SCLN, COMBO_END};
const uint16_t PROGMEM rt_combo[]    = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM yu_combo[]    = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM fg_combo[]    = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM hk_combo[]    = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM xc_combo[]    = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [Q_A__EXLM]    = COMBO(qa_combo, KC_EXLM),
  [W_S__AT]      = COMBO(ws_combo, KC_AT),
  [E_D__HASH]    = COMBO(ed_combo, KC_HASH),
  [R_F_DLR]      = COMBO(rf_combo, KC_DLR),
  [T_G__PERC]    = COMBO(tg_combo, KC_PERC),
  [Y_H__CIRC]    = COMBO(yh_combo, KC_CIRC),
  [U_J__AMPR]    = COMBO(uj_combo, KC_AMPR),
  [I_K__ASTR]    = COMBO(ik_combo, KC_ASTR),
  [O_L__LPRN]    = COMBO(ol_combo, KC_LPRN),
  [P_SCLN__RPRN] = COMBO(pscln_combo, KC_RPRN),
  [R_T__DEL]     = COMBO(rt_combo, KC_DEL),
  [Y_U__DEL]     = COMBO(yu_combo, KC_DEL),
  [F_G__BSPC]    = COMBO(fg_combo, KC_BSPC),
  [H_K__BSPC]    = COMBO(hk_combo, KC_BSPC),
  [X_C__S_TAB]   = COMBO(xc_combo, S(KC_TAB)),
  [C_V__TAB]     = COMBO(cv_combo, KC_TAB),
  [M_COMM__ENT]  = COMBO(mcomm_combo, KC_ENT),
};

#endif // COMBO_ENABLE


// Template
// ,----------------------------------------.                         ,-----------------------------------------.
// |      |      |      |      |      |      |                        |      |      |      |      |      |      |
// |------+------+------+------+------+------|                        |------+------+------+------+------+------|
// |      |      |      |      |      |      |                        |      |      |      |      |      |      |
// |------+------+------+------+------+------|                        |------+------+------+------+------+------|
// |      |      |      |      |      |      |-------.        ,-------|      |      |      |      |      |      |
// |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
// |      |      |      |      |      |      |-------|        |-------|      |      |      |      |      |      |
// `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
//               |      |      |      |      | /      /      \      \ |      |      |      |      |
//               `----------------------------/------/        \------\----------------------------'
//
//[_TEMPLATE] = LAYOUT(
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * BASE
 * ,-----------------------------------------.                        ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                        |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.        ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |        | Mute  |------+------+------+------+------+------|
 * | LCtrl|   Z  |   X  |   C  |   V  |   B  |-------'        `-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               | LAlt | Shft | SYM  | Spc  | / Bspc /      \ Ent  \ | Shft | SYM  | NAV  | LWin |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_BASE] = LAYOUT(
      KC_GRV,  KC_1, KC_2,    KC_3,    KC_4, KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
      KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R, KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_MINS,
      KC_ESC,  KC_A, KC_S,    KC_D,    KC_F, KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
      KC_LCTL, KC_Z, KC_X,    KC_C,    KC_V, KC_B,    MUTE_S,    MUTE_T, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                     KC_LALT, KC_LSFT, SYM,  KC_SPC, KC_BSPC,    KC_ENT,  KC_LSFT, SYM,     NAV,     KC_LWIN),

/* SYM
 * ,----------------------------------------.                         ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                        |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |  F12 |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.        ,-------|   ^  |   &  |   *  |   (  |   )  |   `  |
 * |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
 * |      |   ~  |   =  |   +  |   {  |   [  |-------|        |-------|   ]  |   }  |   <  |   >  |   |  |   |  |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               |      |      |      |      | /      /      \      \ |      |      |*TRNS*|      |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_SYM] = LAYOUT(
      _______, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      _______, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
      _______, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
      _______, KC_TILD, KC_EQL, KC_PLUS, KC_LCBR, KC_LBRC, _______,    _______, KC_RBRC, KC_RCBR, KC_LT,   KC_GT,   KC_PIPE, KC_PIPE,
                       _______, _______, _______, _______, _______,    _______, _______, _______, KC_TRNS, _______),

/* NAV
 * ,----------------------------------------.                         ,-----------------------------------------.
 * |      |      |      |      |      |      |                        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |      |                        |      |      |  Up  |      | Print|      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------|------|
 * |      |      |   4  |   5  |   6  |      |-------.        ,-------|      | Right| Down | Right|      | Home |
 * |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
 * |      |      |   7  |   8  |   9  |   0  |-------|        |-------|      |      | PrvWS| NxtWS| CSlsh| End  |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               |      |      |*TRNS*|      | /      /      \      \ |      |*TRNS*|      |      |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,     MAC,
      _______,    KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_PSCR,     NIX,
      _______, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_HOME,
      _______, XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0, _______,    _______, XXXXXXX, XXXXXXX,  PRV_WS,  NXT_WS,  C_SLSH, KC_END,
                        _______, _______, KC_TRNS, _______, _______,    _______, _______, KC_TRNS, _______, _______),
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Left encoder
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { // Right encoder
    if (clockwise) {
      tap_code(KC_WH_R);
    } else {
      tap_code(KC_WH_L);
    }
  }
  return false;
}

#endif // ENCODER_ENABLE

#ifdef OLED_ENABLE

static void render_logo(void) {
  static const char PROGMEM rocket[] = {
      // 'rocket', 128x32px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0c, 0x24, 0x46, 0x86, 0x06, 0x02, 0x02,
      0x02, 0x02, 0x02, 0x04, 0x0c, 0x1c, 0x18, 0x38, 0x70, 0x60, 0x40, 0xc0, 0x80, 0x80, 0x80, 0xc0,
      0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0xc0,
      0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x48, 0x3c, 0x3c, 0x06, 0x06, 0x02, 0x03, 0x03,
      0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0x0c, 0x04, 0x06, 0x03, 0x03, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0xc0, 0xe0, 0x60, 0x30, 0x30, 0x11, 0x31, 0x61, 0xe1, 0xc1, 0x03, 0x03, 0x02, 0x02, 0x06, 0x06,
      0x04, 0x0c, 0x0c, 0x08, 0x18, 0x38, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x0c, 0x0e, 0x0f, 0x0f, 0x09, 0x08, 0x08, 0x0c, 0x0c, 0x04, 0x36, 0x3e, 0x6f, 0x63, 0x20,
      0x20, 0x30, 0x10, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0c, 0x08, 0xd0, 0x70, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x03, 0x03, 0x06, 0x06, 0x04, 0x04, 0x06, 0x07, 0x03, 0x01, 0x00, 0x80, 0x80, 0x80, 0xc0, 0x40,
      0x40, 0x60, 0x20, 0x30, 0x30, 0x10, 0x18, 0x0c, 0x0c, 0x04, 0x06, 0x03, 0x03, 0x03, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1e, 0x13, 0x01, 0x20, 0x20, 0x20, 0x20,
      0x20, 0x60, 0x60, 0x60, 0x30, 0x18, 0x0e, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03,
      0x02, 0x02, 0x02, 0x02, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
      0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(rocket, sizeof(rocket));
}

static void print_status_narrow(void) {
  // Print current mode
  oled_write_P(PSTR("\n\n"), false);
  oled_write_ln_P(PSTR("MODE"), false);
  oled_write_ln_P(PSTR(""), false);
  if (keymap_config.swap_lalt_lgui) {
    oled_write_ln_P(PSTR("Mac  "), false);
  } else {
    oled_write_ln_P(PSTR("Nix  "), false);
  }

  oled_write_P(PSTR("\n\n"), false);
  // Print current layer
  oled_write_ln_P(PSTR("LAYER"), false);
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("Sym\n"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("Nav\n"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undef"), false);
  }
  oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    render_logo();
  }

  return false;
}

#endif // OLED_ENABLE
