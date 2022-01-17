#include QMK_KEYBOARD_H 

#define RECT1ST LCA(KC_1)
#define RECT2ND LCA(KC_2)
#define RECT3RD LCA(KC_3)
#define RECT4TH LCA(KC_4)
#define RECTCNT LCA(KC_SPC)
#define RECTFLL LCA(KC_ENT)
#define RECTLFT LCA(KC_LEFT)
#define RECTRGT LCA(KC_RGHT)
#define KC_SFEQ RSFT_T(KC_EQL)
#define TMX_LFT LSFT(KC_LEFT)
#define TMX_RGT LSFT(KC_RGHT)

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Enter  /       \Space \  |RAISE | LEAD |  \   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_SFEQ,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_ENT, KC_SPC, MO(_RAISE), KC_LEAD, KC_BSLS
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |RECT1 |RECT2 |RECT3 |RECT4 |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|RECTCNT|    |RECTFLL|------+------+------+------+------+------|
 * |BackSP|      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / PGDW  /       \ PGUP \  |RAISE |      |  \   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV, RECT1ST, RECT2ND, RECT3RD, RECT4TH, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  KC_BSPC, _______, _______, _______, _______, _______, RECTCNT, RECTFLL, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, KC_PGDN, KC_PGUP,  _______, _______, _______
),
/* RAISE
 * ,--------------------------------------------.                    ,-----------------------------------------.
 * |   ~  |       |       |       |      |      |                    |      |      |      |      |      |  DEL |
 * |------+-------+-------+-------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |       |       |       |      |      |                    |      |      |      |  Up  |      | VOLUP|
 * |------+-------+-------+-------+------+------|                    |------+------+------+------+------+------|
 * |      |TMX_LFT|       |TMX_RGT|      |      |-------.    ,-------|      |      | Left | Down |Right | VOLD |
 * |------+-------+-------+-------+------+------|RECTLFT|    |RECTRGT|------+------+------+------+------+------|
 * |      |       |       |       |      |      |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / HOME  /       \  END \  |RAISE |      |  \   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_TILD, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_DEL,
  KC_CAPS, _______, _______, _______, _______, _______,                     _______, _______, _______,   KC_UP, _______,  KC_KB_VOLUME_UP,
  XXXXXXX, TMX_LFT, XXXXXXX, TMX_RGT, XXXXXXX, XXXXXXX,                     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_KB_VOLUME_DOWN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RECTLFT, RECTRGT,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  KC_HOME, KC_END,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | / Enter /       \Space \  |RAISE |      |  \   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_caps(void);
const char *read_keylog(void);
const char *read_keylogs(void);
//const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_caps(), false);
        // oled_write_ln(read_keylogs(), false);
        //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif  // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Open and close parenthesis
    SEQ_ONE_KEY(KC_COMM) {
      SEND_STRING("()" SS_TAP(X_LEFT));
    }

    // Wrap a word within parenthesis (macOS version)
    SEQ_TWO_KEYS(KC_COMM, KC_COMM) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) "(" SS_LALT(SS_TAP(X_RIGHT)) ")");
    }

    // Wrap selection within parenthesis (macOS version)
    SEQ_THREE_KEYS(KC_COMM, KC_COMM, KC_COMM) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)) "()" SS_TAP(X_LEFT) SS_LGUI(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }

    // Open and close brackets
    SEQ_ONE_KEY(KC_DOT) {
      SEND_STRING("[]" SS_TAP(X_LEFT));
    }

    // Wrap a word within brackets (macOS version)
    SEQ_TWO_KEYS(KC_DOT, KC_DOT) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) "[" SS_LALT(SS_TAP(X_RIGHT)) "]");
    }

    // Wrap selection within brackets (macOS version)
    SEQ_THREE_KEYS(KC_DOT, KC_DOT, KC_DOT) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)) "[]" SS_TAP(X_LEFT) SS_LGUI(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }

    // Open and close curly brackets
    SEQ_ONE_KEY(KC_SLSH) {
      SEND_STRING("{}" SS_TAP(X_LEFT));
    }

    // Wrap a word within curly brackets (macOS version)
    SEQ_TWO_KEYS(KC_SLSH, KC_SLSH) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) "{" SS_LALT(SS_TAP(X_RIGHT)) "}");
    }

    // Wrap selection within curly brackets (macOS version)
    SEQ_THREE_KEYS(KC_SLSH, KC_SLSH, KC_SLSH) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)) "{}" SS_TAP(X_LEFT) SS_LGUI(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }

    // Open and close quotes
    SEQ_ONE_KEY(KC_SCLN) {
      SEND_STRING("\"\"" SS_TAP(X_LEFT));
    }

    // Wrap a word within quotes (macOS version)
    SEQ_TWO_KEYS(KC_SCLN, KC_SCLN) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) "\"" SS_LALT(SS_TAP(X_RIGHT)) "\"");
    }

    // Wrap selection within quotes (macOS version)
    SEQ_THREE_KEYS(KC_SCLN, KC_SCLN, KC_SCLN) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)) "\"\"" SS_TAP(X_LEFT) SS_LGUI(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }

    // Open and close tilde
    SEQ_ONE_KEY(KC_TILD) {
      SEND_STRING("''" SS_TAP(X_LEFT));
    }

    // Wrap a word within tilde (macOS version)
    SEQ_TWO_KEYS(KC_TILD, KC_TILD) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) "'" SS_LALT(SS_TAP(X_RIGHT)) "'");
    }

    // Wrap selection within tilde (macOS version)
    SEQ_THREE_KEYS(KC_TILD, KC_TILD, KC_TILD) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)) "''" SS_TAP(X_LEFT) SS_LGUI(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }

    // Start comment C style
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("/**/" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }

    // Wrap a word within comment C style (macOS version)
    SEQ_TWO_KEYS(KC_C, KC_C) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)) "/*" SS_LALT(SS_TAP(X_RIGHT)) "*/");
    }

    // Wrap selection within comment C style (macOS version)
    SEQ_THREE_KEYS(KC_C, KC_C, KC_C) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)) "/**/" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_LGUI(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }

    // Delete word on cursor
    SEQ_ONE_KEY(KC_BSPC) {
      SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)) SS_LALT(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
    }

    // Backward delete word
    SEQ_TWO_KEYS(KC_BSPC, KC_BSPC) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
    }

    // Forward delete word
    SEQ_THREE_KEYS(KC_BSPC, KC_BSPC, KC_BSPC) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_RIGHT)))  SS_TAP(X_BSPC));
    }

    // Delete to the end of the line
    SEQ_TWO_KEYS(KC_BSPC, KC_SCLN) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_END)))  SS_TAP(X_BSPC));
    }

    // Delete to the begining of the line
    SEQ_TWO_KEYS(KC_BSPC, KC_K) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_HOME)))  SS_TAP(X_BSPC));
    }

    // VIM quit without saving
    SEQ_ONE_KEY(KC_Q) {
      SEND_STRING(SS_TAP(X_ESC) ":q!" SS_TAP(X_ENTER));
    }

    // VIM quit saving
    SEQ_ONE_KEY(KC_W) {
      SEND_STRING(SS_TAP(X_ESC) ":wq!" SS_TAP(X_ENTER));
    }

    // VIM set paste mode
    SEQ_ONE_KEY(KC_P) {
      SEND_STRING(SS_TAP(X_ESC) ":set paste" SS_TAP(X_ENTER));
    }

    // VIM set no paste mode
    SEQ_TWO_KEYS(KC_N, KC_P) {
      SEND_STRING(SS_TAP(X_ESC) ":set nopaste" SS_TAP(X_ENTER));
    }

  }
}