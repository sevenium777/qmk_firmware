#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen
#define KC_ESCC MT(MOD_LCTL, KC_ESC)    // Control (hold), Escape (tap)
#define KC_BACK LGUI(KC_LEFT)           // Browser Back
#define KC_FORW LGUI(KC_RIGHT)          // Browser Forward
#define KC_RST RESET
#define KC_BL_S BL_STEP

#define KC_LOWR LT(_LOWER, KC_SPC)
#define KC_RASE LT(_RAISE, KC_ENT)
#define KC_LALT MT(KC_LALT, KC_LANG2)

//Tap Dance Declarations

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
   * | ESC| 1  | 2  | 3  | 4  | 5  |              | 6  | 7  | 8  | 9  | 0  | -  |
   * |----+----+----+----+----+----|              |----+----+----+----+----+----|
   * | TAB| Q  | W  | E  | R  | T  |              | Y  | U  | I  | O  | P  | BSP|
   * |----+----+----+----+----+----|              |----+----+----+----+----+----|
   * | CTL| A  | S  | D  | F  | G  |              | H  | J  | K  | L  | ;  | :  |
   * |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
   * | CMD| Z  | X  | C  | V  | B  | (  |    | )  | N  | M  | ,  | .  | /  | '  |
   * `----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
   *                  \LANG2| SFT | SPC /    \ ENT \SFT |LANG1\ 
   *                  \ ALT |     |LOWR/      \RASE\    |    \ 
   *                   `----+----+----'        `----+----+----'
   */
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESCC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,COLN,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LGUI, Z  , X  , C  , V  , B  ,LPRN,     RPRN, N  , M  ,COMM, DOT,SLSH,QUOT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LALT,LSFT,LOWR,       RASE,LSFT,LANG1
  //                  `----+----+----'        `----+----+----'
),


/* LOWER
 * ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
 * |    | !  | @  | #  | $  | %  |              | ^  | &  | *  | (  | )  | del|
 * |----+----+----+----+----+----|              |----+----+----+----+----+----|
 * |    |  & |  | |  ' |  " |  ` |              | (  | )  |    |    |    |BSPC|
 * |----+----+----+----+----+----|              |----+----+----+----+----+----|
 * |    |    |  - |  _ |  + |  = |              | [  | ]  |    |    |    |    |
 * |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
 * |    |    |  ~ |    |    |  ¥ |    |    |    | {  | }  |    |    |    |    |
 * `----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
 *                  \      |    |SPC /    \ ENT \    |     \ 
 *                   `----+----+----'        `----+----+----'
 */
  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,AMPR,PIPE,QUOT,DQUO,GRV ,               LPRN,RPRN,    ,    ,    ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,MINS,UNDS,PLUS,EQL ,               LBRC,RBRC,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,TILD,    ,    ,BSLS,    ,         ,LCBR,RCBR,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,SPC ,       ENT,    ,
  //                  `----+----+----'        `----+----+----'
),


/* RAISE
 * ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
 * |F12 | F1 | F2 | F3 | F4 | F5 |              | F6 | F7 | F8 | F9 | F10| F11|
 * |----+----+----+----+----+----|              |----+----+----+----+----+----|
 * |    |    |    |    |    |    |              |    |    |  ↑ |    |    |BSPC|
 * |----+----+----+----+----+----|              |----+----+----+----+----+----|
 * |    |    |    |    |    |    |              |    |  ⇦ |  ↓ | →  |    |    |
 * |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
 * |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
 * `----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
 *                  \      |    |SPC /    \ ENT \    |     \ 
 *                   `----+----+----'        `----+----+----'
 */
  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,UP  ,    ,    ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,LEFT,DOWN,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,SPC ,       ENT,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RESET  , DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
