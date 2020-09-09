#ifndef ACTIONS_H
#define ACTIONS_H

#include <stdint.h>

typedef enum {
    SET_BRIGHTNESS = 0x01,
    SET_RED = 0x02,
    SET_GREEN = 0x04,
    SET_BLUE = 0x08,
    DECREASE_MODIFIER = 0x10, //if additional button is held, values are decreased, rather than increased (default)
    PRESET_UP = 0x100,
    PRESET_LEFT = 0x200,
    PRESET_RIGHT = 0x400,
    PRESET_DOWN = 0x800,
    SET_PRESET_MODIFIER = 0x1000, //if held, this is also lit up, so we know whether to load a preset, or save one.
    TOGGLE_SETTINGS = 0x4000,
    EXIT = 0x8000
} Action;

//separate getting the actions from pressed buttons which may be platform-dependent, from actually doing stuff.
uint32_t get_actions();
void act(uint32_t actions);

#endif