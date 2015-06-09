// Omnibook X3
static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(\
                                                     APP, PSCR,NLCK, BRK,       INS, HOME,PGUP, \
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,  F12,       DEL, END, PGDN, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL, BSPC,                 \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, RBRC,ENT,                  \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, BSLS,                      \
        LSFT,FN1, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, RSFT,                      \
        LCTL,FN0, LGUI,LALT,               SPC,      RALT,RCTL,                      UP,        \
                                                                                LEFT,DOWN,RGHT  ),
    /* 1: Numpad and media keys */
    KEYMAP(\
                                                     TRNS,TRNS,TRNS,TRNS,       TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MUTE,CALC,TRNS,TRNS,TRNS,TRNS,       TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,P7,  P8,  P9,  PAST,TRNS,TRNS,TRNS,                  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,P4,  P5,  P6,  PMNS,TRNS,TRNS,TRNS,                  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,P1,  P2,  P3,  PPLS,TRNS,TRNS,                       \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,P0,  TRNS,PDOT,PSLS,TRNS,                       \
        TRNS,TRNS,RGUI,RALT,               TRNS,     TRNS,TRNS,                      VOLU,      \
                                                                                TRNS,VOLD,TRNS  ),
    /* 2: Mouse keys
       Arrows - mouse movement, 
       Z - left button, 
       X - right button,
       Page Up - scroll up,
       Page Down - scroll down.
    */
    KEYMAP(\
                                                     TRNS,TRNS,TRNS,TRNS,       TRNS,TRNS,WH_U, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       TRNS,TRNS,WH_D, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                       \
        TRNS,TRNS,BTN1,BTN2,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                       \
        TRNS,TRNS,TRNS,TRNS,               TRNS,     TRNS,TRNS,                      MS_U,      \
                                                                                MS_L,MS_D,MS_R  )
};

/* X: Empty layer */
/*   KEYMAP(\
                                                     TRNS,TRNS,TRNS,TRNS,       TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                       \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                       \
        TRNS,TRNS,TRNS,TRNS,               TRNS,     TRNS,TRNS,                      TRNS,      \
	                                                                        TRNS,TRNS,TRNS  )
*/

static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(2)
};
