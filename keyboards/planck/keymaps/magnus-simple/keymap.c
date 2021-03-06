/* Build: qmk flash -kb planck/rev6 -km magnus-simple */
#include QMK_KEYBOARD_H

enum unicode_name {
    LARING = 0,
    UARING,
    LADIAE,
    UADIAE,
    LODIAE,
    UODIAE,
};

const uint32_t PROGMEM unicode_map[] = {
    [LARING] = 0xe5,  // å
    [UARING] = 0xc5,  // Å
    [LADIAE] = 0xe4,  // ä
    [UADIAE] = 0xc4,  // Ä
    [LODIAE] = 0xf6,  // ö
    [UODIAE] = 0xd6,  // Ö
};
#define UC_ARING XP(LARING,UARING)
#define UC_ADIAE XP(LADIAE,UADIAE)
#define UC_ODIAE XP(LODIAE,UODIAE)

enum {
    QWE = 0,
    NAV,
    FUN,
    SYM,
    NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Del  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      | RAlt |  ESC |    Space    |  ENT | RAlt |      |      | Menu |
     * | CapsL| GUI  | Ctrl |(Alt) |(_NAV)|    (_SYM)   | _NUM |(Alt) | Ctrl | GUI  |(_FUN)|
     * `-----------------------------------------------------------------------------------'
     */
	[QWE] = LAYOUT_planck_1x2uC(
      KC_DEL,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
      KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
      LSFT_T(KC_RALT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_RALT),
      KC_CAPS, KC_LGUI, KC_LCTL, LALT_T(KC_RALT), LT(NAV,KC_ESC),
      LT(SYM,KC_SPC),
      LT(NUM,KC_ENT), LALT_T(KC_RALT), KC_RCTL, KC_LGUI, LT(FUN,KC_APP)),

    /* Navigation
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      | PgUp | Home |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      | Left | Down | Up   |Right | PgDn | End  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | GUI  | Ctrl | Alt  |  ▽  |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
	[NAV] = LAYOUT_planck_1x2uC(
      KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_PGUP, KC_HOME,
      KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGDN, KC_END,
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,
      KC_NO, KC_LGUI, KC_LCTL, KC_LALT, KC_TRNS,
      KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_APP),

    /* Function keys
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Alt  | Ctrl | GUI  |  ▽  |
     * `-----------------------------------------------------------------------------------'
     */
	[FUN] = LAYOUT_planck_1x2uC(
      KC_NO, KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_LALT, KC_RCTL, KC_LGUI, KC_TRNS),

    /* Symbols
     * ,-----------------------------------------------------------------------------------.
     * |  ~   |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |      |      |  _   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  `   |  (   |  {   |  [   |  (   |      |      |      |      |  =   |  \   |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  )   |  }   |  ]   |  )   |      |      |      |      |  +   |  |   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | GUI  | Ctrl | Alt  |      |     ▽      |      | Alt  | Ctrl | GUI  |      |
     * `-----------------------------------------------------------------------------------'
     */
	[SYM] = LAYOUT_planck_1x2uC(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_NO,   KC_NO,   KC_UNDS,
      KC_GRV,  KC_LPRN, KC_LCBR, KC_LBRC, KC_LPRN, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQL,  KC_BSLS, KC_MINS,
      KC_NO,   KC_RPRN, KC_RCBR, KC_RBRC, KC_RPRN, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PLUS, KC_PIPE, KC_NO,
      KC_NO, KC_LGUI, KC_LCTL, KC_LALT, KC_NO,
      KC_TRNS,
      KC_NO, KC_LALT, KC_RCTL, KC_LGUI, KC_NO),

    /* Numbers
     * ,-----------------------------------------------------------------------------------.
     * |      |  1   |  2   |  3   |  4   |  5   |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  6   |  7   |  8   |  9   |  0   |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | GUI  | Ctrl | Alt  |      |             |  ▽  | Alt  | Ctrl | GUI  |      |
     * `-----------------------------------------------------------------------------------'
     */
	[NUM] = LAYOUT_planck_1x2uC(
      KC_NO, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_9,  KC_0,  KC_NO, KC_NO, KC_NO,
      KC_NO, KC_LGUI, KC_LCTL, KC_LALT, KC_NO,
      KC_NO,
      KC_TRNS, KC_LALT, KC_RCTL, KC_LGUI, KC_NO),
};
