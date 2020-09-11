#ifndef SCR_SETTINGS_H
#define SCR_SETTINGS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    float red; //all variables here are between 0.0f and 1.0f
    float green;
    float blue;
    float brightness;
} ScreenSettings;

/*
    receives current settings, e.g. for applying to screen, or saving to a preset.
    @setting - pointer to ScreenSettings struct to write current settings to.
    @returns - True if brightness was changed from the last time.
    ^ the logic behind that: don't overload the brightness module if it's not necessary, but OpenGL will need some data to render anyway so we don't care about that.
*/
bool current_settings_get(ScreenSettings* setting);

/*
    overwrites current settings, e.g. at init, or load from preset.
    @setting - pointer to ScreenSetting struct with new data.
*/
void current_settings_set(ScreenSettings* setting);

/*
    Applies actions from given vector, if any are applicable, to the current settings.
*/
void apply_action(uint32_t action_vector);

#endif