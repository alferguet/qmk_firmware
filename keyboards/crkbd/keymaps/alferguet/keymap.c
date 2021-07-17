#include QMK_KEYBOARD_H

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _GAMING 4

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	LOWER,
	RAISE,
	ADJUST,
	BACKLIT,
	RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x6_3( \
	KC_LBRC,    		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  RALT_T(KC_RBRC),\
  LCTL_T(KC_GRV), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, RCTL_T(KC_QUOT),\
  KC_LSPO, 			  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,\
													GUI_T(KC_TAB), LT(1, KC_ESC), KC_SPC ,    KC_BSPC, LT(2, KC_ENT),  LALT_T(KC_MINS) \
),

	[_LOWER] = LAYOUT_split_3x6_3( \
	LGUI(KC_6), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),     KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, TO(4),\
  LGUI(KC_ENT), LGUI(KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,\
	KC_CAPS, LCTL(KC_Z), LCTL(KC_Y), LCTL(KC_C), LCTL(KC_V), XXXXXXX,     KC_END, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
																					XXXXXXX,   XXXXXXX,  XXXXXXX,     KC_DEL, KC_LSFT  , MO(3) \
	),

	[_RAISE] = LAYOUT_split_3x6_3( \
		KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
		KC_PLUS,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
		KC_F12,  KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
																					MO(3), XXXXXXX, KC_COLON, _______, _______, _______ \
		),

	[_ADJUST] = LAYOUT_split_3x6_3( \
	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
		RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
																			XXXXXXX,   XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX \
																			//`--------------------------'  `--------------------------'
	),
[_GAMING] = LAYOUT_split_3x6_3( \
	KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  TO(0),\
KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,\
													KC_TAB, LT(1, KC_ESC), KC_SPC ,    KC_BSPC, LT(2,KC_ENT),  GUI_T(KC_MINS) \

)
};
