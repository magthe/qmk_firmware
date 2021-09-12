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
     * |      |      |      |      |  ESC |    Space    |      |      |      |      | Menu |
     * | CapsL| Ctrl | GUI  | Alt  |(_NAV)|    (_SYM)   |  ENT | Alt  | GUI  | Ctrl |(_FUN)|
     * `-----------------------------------------------------------------------------------'
     */
	[QWE] = LAYOUT_planck_1x2uC(
      KC_DEL,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
      KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      LT(NUM,KC_CAPS), KC_LCTL, KC_LGUI, KC_LALT, LT(NAV,KC_ESC),
      LT(SYM,KC_SPC),
      LT(NUM,KC_ENT), KC_RALT, KC_RGUI, KC_RCTL, LT(FUN,KC_APP)),

    /* Navigation
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      | PgUp | Home |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      | Left | Down | Up   |Right | PgDn | End  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|      |      |      |      |      |      |  å   |  ä   |  ö   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Ctrl | GUI  | Alt  |  ▽  |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
	[NAV] = LAYOUT_planck_1x2uC(
      KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_PGUP, KC_HOME,
      KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT,  KC_PGDN, KC_END,
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   UC_ARING, UC_ADIAE, UC_ODIAE, KC_NO,   KC_NO,
      KC_NO, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,
      KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_APP),

    /* Function keys
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  | F4   |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Alt  | GUI  | Ctrl |  ▽  |
     * `-----------------------------------------------------------------------------------'
     */
	[FUN] = LAYOUT_planck_1x2uC(
      KC_NO, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO,
      KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_TRNS),

    /* Symbols
     * ,-----------------------------------------------------------------------------------.
     * |  ~   |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |      |      |  _   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  `   |  (   |  {   |  [   |      |      |      |      |      |  =   |  \   |  -   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  )   |  }   |  ]   |      |      |      |      |      |  +   |  |   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Ctrl |  GUI | Alt  |      |     ▽      |      | Alt  | GUI  | Ctrl |      |
     * `-----------------------------------------------------------------------------------'
     */
	[SYM] = LAYOUT_planck_1x2uC(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_NO,   KC_NO,   KC_UNDS,
      KC_GRV,  KC_LPRN, KC_LCBR, KC_LBRC, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQL,  KC_BSLS, KC_MINS,
      KC_NO,   KC_RPRN, KC_RCBR, KC_RBRC, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PLUS, KC_PIPE, KC_NO,
      KC_NO, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,
      KC_TRNS,
      KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_NO),

    /* Numbers
     * ,-----------------------------------------------------------------------------------.
     * |      |  1   |  2   |  3   |  4   |  5   |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  6   |  7   |  8   |  9   |  0   |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ▽  | Ctrl |  Gui | Alt  |      |             |  ▽  | Alt  | Gui  | Ctrl |      |
     * `-----------------------------------------------------------------------------------'
     */
	[NUM] = LAYOUT_planck_1x2uC(
      KC_NO, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_9,  KC_0,  KC_NO, KC_NO, KC_NO,
      KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,
      KC_NO,
      KC_TRNS, KC_RALT, KC_RGUI, KC_RCTL, KC_NO),
};
