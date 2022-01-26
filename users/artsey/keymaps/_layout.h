// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once
#include "layers.h"

// //////////
// ARTSEY layer ids (needed everywhere)
#define LAYER_ID_GLOBAL -1
#define BASE 0
#define NUM 1
#define SYM 2
#define PAR 3
#define NAV 4
#define CUS 5
#define BIG_SYM 6
#define BIG_FUN 7

// //////////
// Board tuning so standard layout/map can be built programatically
#ifdef KEYBOARD_crkbd_rev1
#include "boards/crkbd_rev1.h"
#endif

// //////////
// Keymap generation stuff to use left/right handedness based on qmk compile env selection
// Standard ARTSEY layer definitions

// Artsey layout wrapper
#ifdef KEYBOARD_crkbd_rev1
#define ARTSEY_LAYOUT_WRAPPER(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#else
#define ARTSEY_LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)
#endif

// Allow proper auto selection of std size via keymaps
#ifdef ARTSEY_SIZE_STD
// Allow proper auto selection of left / right via keymaps
#ifdef ARTSEY_HAND_LEFT
#define ARTSEY_STD_LAYER_BASE ARTSEY_STD_LAYER_BASE_LEFT
#define ARTSEY_STD_LAYER_NUM ARTSEY_STD_LAYER_NUM_LEFT
#endif
#ifdef ARTSEY_HAND_RIGHT
#define ARTSEY_STD_LAYER_BASE ARTSEY_STD_LAYER_BASE_RIGHT
#endif
#endif

// Allow proper auto selection of big size via keymaps
#ifdef ARTSEY_SIZE_BIG
// Allow proper auto selection of left / right via keymaps
#ifdef ARTSEY_HAND_LEFT
#define ARTSEY_BIG_LAYER_BASE ARTSEY_BIG_LAYER_BASE_LEFT
#endif
#ifdef ARTSEY_HAND_RIGHT
#define ARTSEY_BIG_LAYER_BASE ARTSEY_BIG_LAYER_BASE_RIGHT
#endif
#endif
