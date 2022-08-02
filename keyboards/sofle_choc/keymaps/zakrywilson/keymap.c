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
#include QMK_KEYBOARD_H

enum sofle_layers {
  _COLEMAK,
  _QWERTY,
  _SYM,
  _MV,
};

enum custom_keycodes {
  KC_COLEMAK = SAFE_RANGE,
  KC_QWERTY,
  KC_SYM,
  KC_MV,
};

#define MV_SLSH LT(_MV, KC_SLSH) // Turn on layer when held, kc when tapped
#define SYM     TT(_SYM)         // Normally acts like MO unless it's tapped multiple times, which toggles layer on
#define L_S_SPC LSFT_T(KC_SPC)   // Left shift if held, space if tapped
#define R_S_SPC RSFT_T(KC_SPC)   // Right shift if held, space if tapped
#define CLMK DF(_COLEMAK)        // Set the base (default) layer to Colemak (default)
#define QWTY DF(_QWERTY)         // Set the base (default) layer to QWERTY
#define NIX  AG_SWAP             // Swap Alt/Opt and Gui/Cmd to work for Linux
#define MAC  AG_NORM             // Unswap Alt/Opt and Gui/Cmd to work for Mac (default)

#ifdef COMBO_ENABLE

enum combos {
  Q_A__EXLM,
  W_R__AT,
  F_S__HASH,
  P_T_DLR,
  G_G__PERC,
  J_H__CIRC,
  L_N__AMPR,
  U_E__ASTR,
  Y_I__LPRN,
  SCLN_O__RPRN,
  P_G__DEL,
  J_L__DEL,
  T_D__BSPC,
  H_N__BSPC,
  X_C__S_TAB,
  C_V__TAB,
  M_COMM__ENT,
  D_B__SPC,
};

const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM pt_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM gd_combo[] = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM jh_combo[] = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM ln_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM yi_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM sclno_combo[] = {KC_SCLN, KC_O, COMBO_END};
const uint16_t PROGMEM pg_combo[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM td_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM hn_combo[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM db_combo[] = {KC_D, KC_B, COMBO_END};

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
 * |      |      |   S(Tab)   Tab    Spc     |-------|        |-------|      |     Ent     |      |      |      |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               |      |      |      |      | /      /      \      \ |      |      |      |      |
 *               `----------------------------/------/        \------\----------------------------'
 */
combo_t key_combos[COMBO_COUNT] = {
  [Q_A__EXLM] = COMBO(qa_combo, KC_EXLM),
  [W_R__AT] = COMBO(wr_combo, KC_AT),
  [F_S__HASH] = COMBO(fs_combo, KC_HASH),
  [P_T_DLR] = COMBO(pt_combo, KC_DLR),
  [G_G__PERC] = COMBO(gd_combo, KC_PERC),
  [J_H__CIRC] = COMBO(jh_combo, KC_CIRC),
  [L_N__AMPR] = COMBO(ln_combo, KC_AMPR),
  [U_E__ASTR] = COMBO(ue_combo, KC_ASTR),
  [Y_I__LPRN] = COMBO(yi_combo, KC_LPRN),
  [SCLN_O__RPRN] = COMBO(sclno_combo, KC_RPRN),
  [P_G__DEL] = COMBO(pg_combo, KC_DEL),
  [J_L__DEL] = COMBO(jl_combo, KC_DEL),
  [T_D__BSPC] = COMBO(td_combo, KC_BSPC),
  [H_N__BSPC] = COMBO(hn_combo, KC_BSPC),
  [X_C__S_TAB] = COMBO(xc_combo, S(KC_TAB)),
  [C_V__TAB] = COMBO(cv_combo, KC_TAB),
  [M_COMM__ENT] = COMBO(mcomm_combo, KC_ENT),
  [D_B__SPC] = COMBO(db_combo, KC_SPC),
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
 * Colemak
 * ,-----------------------------------------.                        ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                        |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |-------.        ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |        | Pause |------+------+------+------+------+------|
 * |   \  |   Z  |   X  |   C  |   V  |   B  |-------'        `-------|   K  |   M  |   ,  |   .  | MV / |  =   |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               | LOpt | LCmd | Shft | LCtrl| /  Ent /      \ Bspc \ | SYM  | Spc  |   [  |   ]  |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_COLEMAK] = LAYOUT(
      KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_PLUS,
      KC_TAB,  KC_Q, KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_MINS,
      KC_ESC,  KC_A, KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
      KC_BSLS, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,    KC_MPLY, KC_K,    KC_M,    KC_COMM, KC_DOT, MV_SLSH, KC_EQL,
                     KC_LOPT, KC_LCMD, KC_LSFT, KC_LCTL, KC_ENT,     KC_BSPC, SYM,     KC_SPC,  KC_LBRC, KC_RBRC),

/*
 * QWERTY
 * ,-----------------------------------------.                        ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                        |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.        ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |        | Pause |------+------+------+------+------+------|
 * |   \  |   Z  |   X  |   C  |   V  |   B  |-------'        `-------|   N  |   M  |   ,  |   .  | MV / |  =   |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               | LOpt | LCmd | Shft | LCtrl| /  Ent /      \ Bspc \ | SYM  | Spc  |   [  |   ]  |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_QWERTY] = LAYOUT(
      KC_GRV,  KC_1, KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_PLUS,
      KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_MINS,
      KC_ESC,  KC_A, KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
      KC_BSLS, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,    KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT, MV_SLSH, KC_EQL,
                     KC_LOPT, KC_LCMD, KC_LSFT, KC_LCTL, KC_ENT,     KC_BSPC, SYM,     KC_SPC,  KC_LBRC, KC_RBRC),
/* SYM
 * ,----------------------------------------.                         ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                        |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |  Tab |   0  |   7  |   8  |   9  |   ,  |                        |   {  |   }  |   (  |   )  |   :  |   _  |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |   0  |   4  |   5  |   6  |   .  |-------.        ,-------|   `  |   -  |   [  |   ]  |   ~  |   "  |
 * |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
 * |  Ent |   0  |   1  |   2  |   3  |   :  |-------|        |-------|   \  |   =  |   <  |   >  |   /  |   +  |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               | LOpt | LCmd | Shft | LCtrl| /  Ent /      \ Bspc \ |*TRNS*| Spc  |   [  |   ]  |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_SYM] = LAYOUT(
      KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, KC_0,  KC_7,    KC_8,    KC_9,    KC_COMM,                      KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN, KC_UNDS,
      _______, KC_0,  KC_4,    KC_5,    KC_6,    KC_DOT,                       KC_GRV,  KC_MINS, KC_LBRC, KC_RBRC, KC_TILD, KC_DQUO,
      KC_ENT,  KC_0,  KC_1,    KC_2,    KC_3,    KC_COLN, _______,    _______, KC_BSLS, KC_EQL,  KC_LT,   KC_GT,   _______, KC_PLUS,
                      _______, _______, L_S_SPC, _______, _______,    _______, KC_TRNS, R_S_SPC, _______, _______),
/* MV
 * ,----------------------------------------.                         ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                        | CLMK | QWTY |  NIX | MAC  |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                        |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------|------|
 * |      | Ctrl | LOpt | LCmd | Shft |  Del |-------.        ,-------| Bspc | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |        |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|        |-------|      | Ent  | Home | End  |*TRNS*|      |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               | LOpt | LCmd | Shft | LCtrl| /  Ent /      \ Bspc \ | RCtl | Spc  | PgUp | PgDn |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_MV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CLMK,    QWTY,    NIX,     MAC,      XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_DEL,                       KC_BSPC, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_ENT,  KC_HOME, KC_END,   KC_TRNS, XXXXXXX,
                        _______, _______, L_S_SPC, _______, _______,    _______, KC_RCTL, R_S_SPC, KC_PGUP, KC_PGDN),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case KC_QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  }
  return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Left encoder
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) { // Right encoder
    if (clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  }
  return false;
}

#endif // ENCODER_ENABLE

#ifdef OLED_ENABLE

static void render_logo(void) {
  static const char PROGMEM moosh_image[] = {  // https://imgur.com/27FAEVT
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa0, 0xe0, 0xc0, 0x80, 0x40, 0xc0, 0xc0, 0x40, 0x40, 0xc0,
    0x00, 0x10, 0x18, 0x88, 0x00, 0x10, 0x88, 0x44, 0x20, 0x32, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x30, 0x40, 0x06, 0x83, 0xc8, 0xfe, 0xff, 0xfc, 0xfd, 0xff, 0xcf, 0x9f, 0x3f, 0x7f, 0x7c, 0xfc,
    0xf9, 0xfd, 0xf8, 0x71, 0x80, 0x90, 0x19, 0x16, 0x26, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x10, 0x0f, 0x07, 0x3f, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xc7, 0xd0, 0xf8, 0xf8,
    0xfc, 0x9e, 0x0e, 0x0e, 0x01, 0x31, 0x80, 0x87, 0xc0, 0xf0, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x03, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x05, 0x0d, 0x01, 0x09, 0x09, 0x00, 0x00, 0x00, 0x03, 0x00
  };
  oled_write_raw_P(moosh_image, sizeof(moosh_image));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lalt_lgui) {
        oled_write_ln_P(PSTR("Nix  "), false);
    } else {
        oled_write_ln_P(PSTR("Mac  "), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colmk"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrty"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbl\n"), false);
            break;
        case _MV:
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
