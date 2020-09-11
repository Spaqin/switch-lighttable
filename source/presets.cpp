#include "presets.h"


const int ScreenSettingsCount = 4;
static ScreenSettings _presets[ScreenSettingsCount];

void presets_load()
{
    //for now, only load defaults -- will load from file later
    ScreenSettings bright_preset = {1.0f, 1.0f, 1.0f, 1.0f};
    ScreenSettings dark_preset = {0.0f, 0.0f, 0.0f, 0.0f};
    _presets[PRESET_POS_UP] = bright_preset;
    _presets[PRESET_POS_LEFT] = bright_preset;
    _presets[PRESET_POS_RIGHT] = bright_preset;
    _presets[PRESET_POS_DOWN] = dark_preset;
}
void preset_save(ScreenSettings* new_setting, PresetPostition pos)
{
    if(new_setting == nullptr || pos < PRESET_POS_UP || pos > PRESET_POS_RIGHT)
    {
        return;
    }
    _presets[pos] = *new_setting;
}

void preset_get(PresetPostition pos, ScreenSettings* out_setting)
{
    if(out_setting == nullptr || pos < PRESET_POS_UP || pos > PRESET_POS_RIGHT)
    {
        return;
    }
    *out_setting = _presets[pos];
}

void preset_act(uint32_t actions)
{
    PresetPostition pos = PRESET_POS_NONE;
	ScreenSettings settings;
    switch(actions & (PRESET_UP | PRESET_DOWN | PRESET_LEFT | PRESET_RIGHT))
    {
    case PRESET_UP:
        pos = PRESET_POS_UP;
        break;
    case PRESET_DOWN:
        pos = PRESET_POS_DOWN;
        break;
    case PRESET_LEFT:
        pos = PRESET_POS_LEFT;
        break;
    case PRESET_RIGHT:
        pos = PRESET_POS_RIGHT;
        break;
    }
    if(pos == PRESET_POS_NONE)
    {
        return;
    }
    if(actions & SET_PRESET_MODIFIER)
    {
		current_settings_get(&settings);
        preset_save(&settings, pos);
    }
    else
    {
        preset_get(pos, &settings);
		current_settings_set(&settings);
    }
    
}