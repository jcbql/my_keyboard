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

#include "keymap_danish.h"

enum layers {
    ALPHA,
    NAV,
    SYM,
    NUM,
    GUI,
    SYM_OLD
};

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  TICK,
  CARET,
  TILDE,
};

// Layer tap definitions for complex layer tapping.
#define UNDS_NUM LT(NUM, KC_0) // Underscore when pressed and GUI layer when held
#define SFT_EQ SFT_T(KC_1) // Equalsign when pressed and shift when held
#define QU_Q LT(0, KC_Q) // Send Qu when pressed and Q when held

// Combos
const uint16_t PROGMEM ae_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, CTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM aa_combo[] = {KC_U, SFT_T(KC_A), COMBO_END};
const uint16_t PROGMEM parenth_combo[] = {SFT_T(KC_A), KC_DOT, COMBO_END};
const uint16_t PROGMEM bracket_combo[] = {CTL_T(KC_E), KC_BSPC, COMBO_END};
const uint16_t PROGMEM curly_combo[] = {ALT_T(KC_I), DK_SLSH, COMBO_END};
const uint16_t PROGMEM bracket_num_combo[] = {KC_4, KC_5, COMBO_END};
combo_t key_combos[] = {
  COMBO(ae_combo, DK_AE),
  COMBO(oe_combo, DK_OSTR),
  COMBO(aa_combo, DK_ARNG),
  COMBO(parenth_combo, DK_LPRN),
  COMBO(bracket_combo, DK_LBRC),
  COMBO(curly_combo, DK_LCBR),
  COMBO(bracket_num_combo, DK_LBRC)
};


// Layer definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ALPHA] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_X,    KC_P,    KC_D,    KC_M,    KC_K, KC_MUTE,    KC_VOLU, DK_MINS,    KC_U,    KC_O,    KC_Y,    KC_Z,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
QU_Q,GUI_T(KC_S),ALT_T(KC_N),CTL_T(KC_T),SFT_T(KC_L), KC_F, KC_MPLY, KC_VOLD,DK_COMM,SFT_T(KC_A),CTL_T(KC_E),ALT_T(KC_I),GUI_T(KC_C),KC_W,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_V,    KC_B,    KC_G,    KC_H,    KC_J,                      DK_EQL,  KC_DOT,  KC_BSPC, DK_SLSH, DK_QUOT,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                CW_TOGG, UNDS_NUM, LT(NAV, KC_SPC),    LT(SYM, KC_R), LT(SYM_OLD, KC_ENT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F5,   KC_F6,  KC_F12, KC_MUTE,    KC_VOLU,A(KC_F12), KC_PGUP,  KC_UP, KC_PGDN, C(DK_AE), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, C(KC_A), KC_MPLY,    KC_VOLD,S(KC_F12), KC_LEFT, KC_DOWN, KC_RGHT, C(DK_QUOT), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),                   A(KC_LEFT), KC_HOME, _______,  KC_END,A(KC_RGHT), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,    _______,  LT(NUM, KC_ENT), KC_F11
                                      //`--------------------------'  `--------------------------'
  ),

    [SYM] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, S(KC_4), DK_LABK, DK_RABK, DK_DQUO,    TICK, KC_MUTE,    KC_VOLU, DK_AMPR, DK_RPRN, DK_LCBR, DK_RCBR, DK_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DK_EXLM, DK_MINS, DK_PLUS,  DK_EQL, DK_HASH, KC_MPLY,    KC_VOLD, DK_SCLN, DK_LPRN, DK_LBRC, DK_RBRC, DK_QUES, KC_GRAVE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   CARET, DK_SLSH, DK_ASTR, DK_BSLS,   TILDE,                      DK_PIPE, DK_COLN, _______,  DK_DLR,   DK_AT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, _______,  LT(NUM, KC_SPC),    _______,  LT(NUM, KC_ENT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [GUI] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), XXXXXXX,      BL_UP, G(KC_J), G(KC_L), G(KC_UP), XXXXXXX, C(DK_AE), G(KC_DEL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, G(KC_T), G(KC_S), G(KC_R), G(KC_R), G(KC_D), BL_TOGG,    BL_DOWN, XXXXXXX, G(KC_LEFT), G(KC_DOWN), G(KC_RGHT), XXXXXXX, G(KC_W),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                      G(KC_P), C(KC_1), C(KC_2), C(KC_3), C(DK_OSTR), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, XXXXXXX, _______,    KC_LALT, G(KC_ENT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [NUM] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, DK_LBRC, DK_RBRC, XXXXXXX, XXXXXXX, KC_MUTE,    KC_VOLU, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
XXXXXXX,KC_LGUI,ALT_T(DK_MINS),CTL_T(DK_PLUS),SFT_EQ,XXXXXXX,KC_MPLY,   KC_VOLD, DK_COMM,    KC_4,    KC_5,    KC_6,  KC_DOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, DK_SLSH, DK_ASTR, DK_COLN, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,       KC_0, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [SYM_OLD] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, S(KC_4), DK_LABK, DK_RABK, DK_DQUO,  DK_GRV, KC_MUTE,    KC_VOLU, DK_AMPR, DK_SCLN, DK_LCBR, DK_RCBR, DK_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, DK_EXLM, DK_MINS, DK_PLUS,  DK_EQL, DK_HASH, KC_MPLY,    KC_VOLD, DK_PIPE, DK_COLN, DK_LPRN, DK_RPRN, DK_QUES, KC_GRAVE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DK_CIRC, DK_SLSH, DK_ASTR, DK_BSLS, XXXXXXX,                      DK_TILD,  DK_DLR, DK_LBRC, DK_RBRC,   DK_AT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, _______,  LT(NUM, KC_SPC),    _______,  LT(NUM, KC_ENT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

};


// Adaptive keys
#define ADAPTIVE_TIMEOUT_MS 2000
#define RECENT_SIZE 4 // Number of keys in `recent` buffer.
static uint16_t recent[RECENT_SIZE] = {KC_NO};
static uint16_t deadline = 0;

static void clear_recent_keys(void) {
  memset(recent, 0, sizeof(recent));
}

static bool update_recent_keys(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) { return false; }

  if (((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT) != 0) {
    clear_recent_keys();  // Avoid interfering with hotkeys.
    return false;
  }

  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    // case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0) { return false; }
      keycode &= 0xff;  // Get tapping keycode.
  }

  switch (keycode) {
    case KC_A ... KC_SLASH:  // These keys type letters, digits, symbols.
      break;

    case KC_LSFT:  // These keys don't type anything on their own.
    case KC_RSFT:
    case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
      return false;

    default:  // Avoid acting otherwise, particularly on navigation keys.
      clear_recent_keys();
      return false;
  }

  memmove(recent, recent + 1, (RECENT_SIZE - 1) * sizeof(*recent));

  recent[RECENT_SIZE - 1] = keycode;
  deadline = record->event.time + ADAPTIVE_TIMEOUT_MS;
  return true;
}

void housekeeping_task_user(void) {
  if (recent[RECENT_SIZE - 1] && timer_expired(timer_read(), deadline)) {
    clear_recent_keys();  // Timed out; clear the buffer.
  }
}


// Processing keys
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (update_recent_keys(keycode, record)) {
    if (recent[RECENT_SIZE-3] == KC_B &&
        recent[RECENT_SIZE-2] == KC_E &&
        recent[RECENT_SIZE-1] == DK_QUOT) {
      tap_code(KC_C);
      tap_code(KC_A);
      tap_code(KC_U);
      tap_code(KC_S);
      tap_code(KC_E);
      clear_recent_keys();
      return false;
    }
  }

  switch (keycode) {
    case UNDS_NUM:
      if (record->tap.count > 0) { // Key is being tapped
        if (record->event.pressed) {
            tap_code16(DK_UNDS);
        }
        return false;
      }
      return true;
    case SFT_EQ:
      if (record->tap.count > 0) { // Key is being tapped
        if (record->event.pressed) {
          tap_code16(DK_EQL);
        }
        return false;
      }
      return true;
    case QU_Q:
      if (record->tap.count > 0) { // Key is being tapped
        if (record->event.pressed) {
            tap_code16(KC_Q);
            tap_code16(KC_U);
        }
      } else { // Key is being held
        if (record->event.pressed) {
          tap_code16(KC_Q);
        }
      }
      return false;

    // Macros
    case SELWORD:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_RGHT) SS_LCTL(SS_TAP(X_LEFT) SS_LSFT(SS_TAP(X_RGHT))));
      }
      return false;
    case TICK:
      if (record->event.pressed) {
        tap_code16(DK_GRV);
        tap_code16(KC_SPC);
      }
      return false;
    case CARET:
      if (record->event.pressed) {
        tap_code16(DK_CIRC);
        tap_code16(KC_SPC);
      }
      return false;
    case TILDE:
      if (record->event.pressed) {
        tap_code16(DK_TILD);
        tap_code16(KC_SPC);
      }
      return false;
  }

  return true;
}


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
