#include "scr_settings.h"
#include "actions.h"
#include <stdint.h>


typedef enum {
    PRESET_POS_UP = 0,
    PRESET_POS_DOWN = 1,
    PRESET_POS_LEFT = 2,
    PRESET_POS_RIGHT = 3,
    PRESET_POS_NONE = 0xFF
} PresetPostition;

void presets_load();
void preset_save(ScreenSettings*, PresetPostition);
void preset_get(PresetPostition, ScreenSettings*);
void preset_act(uint32_t);