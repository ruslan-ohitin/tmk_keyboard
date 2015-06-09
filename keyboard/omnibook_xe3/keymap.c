/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

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

/* 
 * Keymap for Phantom controller
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "debug.h"
#include "keymap.h"

// Convert physical keyboard layout to matrix array.
// This is a macro to define keymap easily in keyboard layout form.
// Skip letter O for it looks like 0, so columns is ABCDEFGHIJKLMPQ. And I foregt about N.
// Omnibook X3 keyboard matrix is very different from real keys layout
#define KEYMAP( \
                                             K7Q, K6M, K5J, K4M,         K5P, K6P, K7P, \
K5E, K4G, K7G, K6G, K5G, K7F, K6F, K5F, K4F, K7K, K6K, K5K, K4K,         K4P, K3P, K2P, \
K7E, K0E, K0F, K0G, K0H, K7H, K7I, K0I, K0J, K0K, K0L, K7L, K4L, K5M, \
K6E, K1E, K1F, K1G, K1H, K6H, K6I, K1I, K1J, K1K, K1L, K6L, K6J, K2M, \
K4E, K2E, K2F, K2G, K2H, K5H, K5I, K2I, K2J, K2K, K2L, K5L, K7M, \
K3B, K7J, K3E, K3F, K3G, K3H, K4H, K4I, K3I, K3J, K3K, K3L, K1B, \
K6C, K7A, K5R, K0D,           K3M,           K4D, K2C,                        K1M, \
                                                                         K1P, K0M, K0P \
) { \
/*             0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15   */  \
/* 0 */	  { KC_NO   , KC_NO   , KC_NO   , KC_##K0D, KC_##K0E, KC_##K0F, KC_##K0G, KC_##K0H, KC_##K0I, KC_##K0J, KC_##K0K, KC_##K0L, KC_##K0M, KC_##K0P, KC_NO   , KC_NO    }, \
/* 1 */	  { KC_NO   , KC_##K1B, KC_NO   , KC_NO   , KC_##K1E, KC_##K1F, KC_##K1G, KC_##K1H, KC_##K1I, KC_##K1J, KC_##K1K, KC_##K1L, KC_##K1M, KC_##K1P, KC_NO   , KC_NO    }, \
/* 2 */	  { KC_NO   , KC_NO   , KC_##K2C, KC_NO   , KC_##K2E, KC_##K2F, KC_##K2G, KC_##K2H, KC_##K2I, KC_##K2J, KC_##K2K, KC_##K2L, KC_##K2M, KC_##K2P, KC_NO   , KC_NO    }, \
/* 3 */	  { KC_NO   , KC_##K3B, KC_NO   , KC_NO   , KC_##K3E, KC_##K3F, KC_##K3G, KC_##K3H, KC_##K3I, KC_##K3J, KC_##K3K, KC_##K3L, KC_##K3M, KC_##K3P, KC_NO   , KC_NO    }, \
/* 4 */	  { KC_NO   , KC_NO   , KC_NO   , KC_##K4D, KC_##K4E, KC_##K4F, KC_##K4G, KC_##K4H, KC_##K4I, KC_NO   , KC_##K4K, KC_##K4L, KC_##K4M, KC_##K4P, KC_NO   , KC_NO    }, \
/* 5 */	  { KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_##K5E, KC_##K5F, KC_##K5G, KC_##K5H, KC_##K5I, KC_##K5J, KC_##K5K, KC_##K5L, KC_##K5M, KC_##K5P, KC_NO   , KC_##K5R }, \
/* 6 */	  { KC_NO   , KC_NO   , KC_##K6C, KC_NO   , KC_##K6E, KC_##K6F, KC_##K6G, KC_##K6H, KC_##K6I, KC_##K6J, KC_##K6K, KC_##K6L, KC_##K6M, KC_##K6P, KC_NO   , KC_NO    }, \
/* 7 */	  { KC_##K7A, KC_NO   , KC_NO   , KC_NO   , KC_##K7E, KC_##K7F, KC_##K7G, KC_##K7H, KC_##K7I, KC_##K7J, KC_##K7K, KC_##K7L, KC_##K7M, KC_##K7P, KC_##K7Q, KC_NO    }  \
/*             0         1         2         3         4         5         6         7         8         9         10        11        12        13        14        15   */  \
}

#include "keymap_omni.h"

#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    if (layer < KEYMAPS_SIZE) {
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    action_t action;
    if (FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    } else {
        action.code = ACTION_NO;
    }
    return action;
}
