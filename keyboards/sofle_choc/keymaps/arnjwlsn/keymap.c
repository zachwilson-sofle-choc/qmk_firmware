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
#define NIX AG_SWAP   // Swap Alt/Opt and Gui/Cmd to work for Linux
#define MAC AG_NORM   // Unswap Alt/Opt and Gui/Cmd to work for Mac (default)


#define PRV_WS LCTL(LWIN(KC_LEFT))   // Previous workspace (formerly M2)
#define NXT_WS LCTL(LWIN(KC_RIGHT))  // Next workspace (formerly M3)
#define C_SLSH LCTL(KC_SLSH)         // Ctrl+Slash (formerly M6)

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

const uint16_t PROGMEM qa_combo[]    = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM wr_combo[]    = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM fs_combo[]    = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM pt_combo[]    = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM gd_combo[]    = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM jh_combo[]    = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM ln_combo[]    = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM ue_combo[]    = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM yi_combo[]    = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM sclno_combo[] = {KC_SCLN, KC_O, COMBO_END};
const uint16_t PROGMEM pg_combo[]    = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM jl_combo[]    = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM td_combo[]    = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM hn_combo[]    = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM xc_combo[]    = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM db_combo[]    = {KC_D, KC_B, COMBO_END};

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
  [Q_A__EXLM]    = COMBO(qa_combo, KC_EXLM),
  [W_R__AT]      = COMBO(wr_combo, KC_AT),
  [F_S__HASH]    = COMBO(fs_combo, KC_HASH),
  [P_T_DLR]      = COMBO(pt_combo, KC_DLR),
  [G_G__PERC]    = COMBO(gd_combo, KC_PERC),
  [J_H__CIRC]    = COMBO(jh_combo, KC_CIRC),
  [L_N__AMPR]    = COMBO(ln_combo, KC_AMPR),
  [U_E__ASTR]    = COMBO(ue_combo, KC_ASTR),
  [Y_I__LPRN]    = COMBO(yi_combo, KC_LPRN),
  [SCLN_O__RPRN] = COMBO(sclno_combo, KC_RPRN),
  [P_G__DEL]     = COMBO(pg_combo, KC_DEL),
  [J_L__DEL]     = COMBO(jl_combo, KC_DEL),
  [T_D__BSPC]    = COMBO(td_combo, KC_BSPC),
  [H_N__BSPC]    = COMBO(hn_combo, KC_BSPC),
  [X_C__S_TAB]   = COMBO(xc_combo, S(KC_TAB)),
  [C_V__TAB]     = COMBO(cv_combo, KC_TAB),
  [M_COMM__ENT]  = COMBO(mcomm_combo, KC_ENT),
  [D_B__SPC]     = COMBO(db_combo, KC_SPC),
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
 * |------+------+------+------+------+------|  Mute |        |       |------+------+------+------+------+------|
 * | LCtrl|   Z  |   X  |   C  |   V  |   B  |-------'        `-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------'  /------/    \------\  '-----------------------------------------'
 *               | LAlt | Shft | SYM  | Spc  | / Bspc /      \ Ent  \ | Shft | SYM  | NAV  | LWin |
 *               `----------------------------/------/        \------\----------------------------'
 */
  [_BASE] = LAYOUT(
      KC_GRV,  KC_1, KC_2,    KC_3,    KC_4, KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
      KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R, KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_MINS,
      KC_ESC,  KC_A, KC_S,    KC_D,    KC_F, KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
      KC_LCTL, KC_Z, KC_X,    KC_C,    KC_V, KC_B,   KC_MUTE,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
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
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, XXXXXXX,
      _______,    KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_PSCR, XXXXXXX,
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
      tap_code(KC_RIGHT);
    } else {
      tap_code(KC_LEFT);
    }
  }
  return false;
}

#endif // ENCODER_ENABLE

#ifdef OLED_ENABLE

static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
  };

  oled_write_P(qmk_logo, false);
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
    case _BASE:
      oled_write_ln_P(PSTR("Base"), false);
      break;
    default:
      oled_write_P(PSTR("Undef"), false);
  }
  oled_write_P(PSTR("\n\n"), false);
  // Print current layer
  oled_write_ln_P(PSTR("LAYER"), false);
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("Symbl\n"), false);
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
