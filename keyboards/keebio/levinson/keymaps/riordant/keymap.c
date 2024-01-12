#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _RAISE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  COLEMAK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak-DH
 * ,------------------------------------------             ------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------             -------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |             |   M  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |             |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+             +------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Raise |Space |             |Space |Raise | GUI  | Alt  | Ctrl |      |
 * `------------------------------------------             ------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,   KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,      KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
  _______, KC_LALT, KC_LCTL, KC_LGUI, RAISE,   KC_SPC,      KC_SPC,  RAISE,   KC_LGUI, KC_LCTRL, KC_LALT,   _______
),


/* Raise
 * ,------------------------------------------              ------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+-------              -------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |              |      |   \  |   =  |   [  |   ]  |  '   |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |              |      |      |      |      |      |      |
 * |------+------+------+------+------+------+              +------+------+------+------+------+------|
 * |      |      |      |      |      |      |              |      |      |      |      |      |      |
 * `------------------------------------------              ------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
   KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,      KC_8,    KC_9,    KC_0,      KC_MINS,
  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,            ,  KC_BSLS,   KC_EQL,  KC_LBRC, KC_RBRC,   KC_QUOT,
  _______,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  _______,  _______
),

/* Qwerty
 * ,------------------------------------------       -------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |       |   Y  |   U  |   I  |   O  |   P  | Bksp  |
 * |------+------+------+------+------+-------       -------+------+------+------+------+------ |
 * | Esc  |   A  |   S  |   D  |   F  |   G  |       |   H  |   J  |   K  |   L  |   ;  | Enter |
 * |------+------+------+------+------+------|       |------+------+------+------+------+------ |
 * | Shift|   Z  |   X  |   C  |   V  |   B  |       |   N  |   M  |   ,  |   .  |   /  | Shift |
 * |------+------+------+------+------+------+       +------+------+------+------+------+------ |
 * |      | Ctrl | Alt  | GUI  |Raise |Space |       |Space |Raise | GUI  | Alt  | Ctrl |       |
 * `------------------------------------------       -------------------------------------------'
 */
// testing
//[_QWERTY] = LAYOUT_ortho_4x12(
//KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
//KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
//KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A,
//KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A, KC_A
//),
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
  KC_EXEC, KC_LALT, KC_LCTL, KC_LGUI, RAISE,   KC_SPC,  KC_SPC,  RAISE,   KC_LGUI, KC_LCTRL, KC_LALT, KC_EXEC
),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case KC_H:
        {
        // Initialize a boolean variable that keeps track
        // of the arrow key status: registered or not?
        static bool arrowkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either cmd keys
            if (mod_state & MOD_MASK_GUI) {
                // First temporarily canceling both cmd keys so that
                // cmd isn't applied to the arrow keycode
                del_mods(MOD_MASK_GUI);
                register_code(KC_LEFT);
                // Update the boolean variable to reflect the status of the arrow keycode
                arrowkey_registered = true;
                // Reapplying modifier state so that the held cmd key(s)
                // still work even after having tapped the arrow key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of the arrow key
            // In case the cmd key is still being sent even after the release of the arrow key
            if (arrowkey_registered) {
                unregister_code(KC_LEFT);
                arrowkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case KC_J:
        {
        // Initialize a boolean variable that keeps track
        // of the arrow key status: registered or not?
        static bool arrowkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either cmd keys
            if (mod_state & MOD_MASK_GUI) {
                // First temporarily canceling both cmd keys so that
                // cmd isn't applied to the arrow keycode
                del_mods(MOD_MASK_GUI);
                register_code(KC_DOWN);
                // Update the boolean variable to reflect the status of the arrow keycode
                arrowkey_registered = true;
                // Reapplying modifier state so that the held cmd key(s)
                // still work even after having tapped the arrow key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of the arrow key
            // In case the cmd key is still being sent even after the release of the arrow key
            if (arrowkey_registered) {
                unregister_code(KC_DOWN);
                arrowkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case KC_K:
        {
        // Initialize a boolean variable that keeps track
        // of the arrow key status: registered or not?
        static bool arrowkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either cmd keys
            if (mod_state & MOD_MASK_GUI) {
                // First temporarily canceling both cmd keys so that
                // cmd isn't applied to the arrow keycode
                del_mods(MOD_MASK_GUI);
                register_code(KC_UP);
                // Update the boolean variable to reflect the status of the arrow keycode
                arrowkey_registered = true;
                // Reapplying modifier state so that the held cmd key(s)
                // still work even after having tapped the arrow key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of the arrow key
            // In case the cmd key is still being sent even after the release of the arrow key
            if (arrowkey_registered) {
                unregister_code(KC_UP);
                arrowkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case KC_L:
        {
        // Initialize a boolean variable that keeps track
        // of the arrow key status: registered or not?
        static bool arrowkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either cmd keys
            if (mod_state & MOD_MASK_GUI) {
                // First temporarily canceling both cmd keys so that
                // cmd isn't applied to the arrow keycode
                del_mods(MOD_MASK_GUI);
                register_code(KC_RGHT);
                // Update the boolean variable to reflect the status of the arrow keycode
                arrowkey_registered = true;
                // Reapplying modifier state so that the held cmd key(s)
                // still work even after having tapped the arrow key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of the arrow key
            // In case the cmd key is still being sent even after the release of the arrow key
            if (arrowkey_registered) {
                unregister_code(KC_RGHT);
                arrowkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case KC_C:
        {
        // Initialize a boolean variable that keeps track
        // of the arrow key status: registered or not?
        static bool arrowkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either cmd keys
            if (mod_state & MOD_MASK_GUI) {
                // First temporarily canceling both cmd keys so that
                // cmd isn't applied to the arrow keycode
                del_mods(MOD_MASK_GUI);
                SEND_STRING(SS_LCTRL(SS_LSFT("c")));
                // Update the boolean variable to reflect the status of the arrow keycode
                arrowkey_registered = true;
                // Reapplying modifier state so that the held cmd key(s)
                // still work even after having tapped the arrow key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of the arrow key
            // In case the cmd key is still being sent even after the release of the arrow key
            if (arrowkey_registered) {
                arrowkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case KC_V:
        {
        // Initialize a boolean variable that keeps track
        // of the arrow key status: registered or not?
        static bool arrowkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either cmd keys
            if (mod_state & MOD_MASK_GUI) {
                // First temporarily canceling both cmd keys so that
                // cmd isn't applied to the arrow keycode
                del_mods(MOD_MASK_GUI);
                SEND_STRING(SS_LCTRL(SS_LSFT("v")));
                // Update the boolean variable to reflect the status of the arrow keycode
                arrowkey_registered = true;
                // Reapplying modifier state so that the held cmd key(s)
                // still work even after having tapped the arrow key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of the arrow key
            // In case the cmd key is still being sent even after the release of the arrow key
            if (arrowkey_registered) {
                arrowkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }
    case KC_EXEC:
        {
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a"));
            }
            return false;
            break;
        }
    }
  return true;
}

