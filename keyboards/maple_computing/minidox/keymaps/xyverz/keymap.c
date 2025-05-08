#include QMK_KEYBOARD_H

// Layer Names Here.
#define DVORAK 0 // Base Layer
#define LOWER 1 // LOWER Layer
#define RAISE 2 // RAISE Layer
#define ADJUST 3 // ADJUST Layer

// Macros Here.
#define CTLSCLN LCTL_T(KC_SCLN)
#define RCTLZED LCTL_T(KC_Z)
#define ALTQ LALT_T(KC_Q)
#define ALTV RALT_T(KC_V)
#define GUIJ LGUI_T(KC_J)
#define GUIW RGUI_T(KC_W)
#define MACLOCK LGUI(LCTL(KC_Q))
#define WINLOCK LGUI(KC_L)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   '  |   ,  |   .  |   P  |   Y  |           |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  |           |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |CTL/ ;|ALT/ Q|GUI/ J|   K  |   X  |           |   B  |   M  |GUI/ W|ALT/ V|CTL/ Z|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | LOWER| BSPC |      |    |      | Spc  |RAISE |
 *                  `-------------| SHFT |    | Ent  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[DVORAK] = LAYOUT_split_3x5_3(
  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
  CTLSCLN, ALTQ,    GUIJ,    KC_K,    KC_X,       KC_B,    KC_M,    GUIW,    ALTV,    RCTLZED,
                    MO(1),   KC_BSPC, KC_LSFT,    KC_ENT,  KC_SPC,  MO(2)
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS |      |  UP  |      | Home |           | PgDn |   +  |   {  |   }  |   _  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   ~  | Left | Down | Right| End  |           | PgUp | Mute | Vol- | Vol+ |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | Del  |      |    |      |   |  |      |
 *                  `-------------| Esc  |    | Tab  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[LOWER] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_CAPS, _______, KC_UP,   _______, KC_HOME,    KC_PGUP, KC_PLUS, KC_LCBR, KC_RCBR, KC_UNDS,
  KC_TILD, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU, KC_SLSH,
                    _______, KC_DEL,  KC_ESC,     KC_TAB,  KC_PIPE, MO(3)
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS |      |  UP  |      | Home |           | PgDn |   =  |   [  |   ]  |   -  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   `  | Left | Down | Right| End  |           | PgUp | Prev | Play | Next |   ?  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | Del  |      |    |      |   \  |      |
 *                  `-------------| Esc  |    | Tab  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[RAISE] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_CAPS, _______, KC_UP,   _______, KC_HOME,    KC_PGUP, KC_EQL,  KC_LBRC, KC_RBRC, KC_MINS,
  KC_GRV,  KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT, KC_QUES,
                    MO(3),   KC_DEL,  KC_ESC,     KC_TAB,  KC_BSLS, _______
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |QKBOOT|      |      |      |           |      | PrSc | ScLk | Paus | F12  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |QKBOOT|      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[ADJUST] =  LAYOUT_split_3x5_3(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_UP,   KC_F9,   KC_F10,
  KC_F11,  QK_BOOT, _______, _______, _______,    _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_F12,
  _______, _______, _______, _______, _______,    QK_BOOT, _______, _______, _______, _______,
                    _______, _______, MACLOCK,    WINLOCK, _______, _______
  )
};
// clang-format on

void matrix_init_user(void) {
#ifdef BOOTLOADER_CATERINA
    // This will disable the red LEDs on the ProMicros
    setPinInput(D5);
    setPinInput(B0);
#endif
};