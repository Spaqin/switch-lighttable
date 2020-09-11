#include "scr_settings.h"
#include "actions.h"


static bool _brightness_changed = false;

static ScreenSettings _current_settings = {1.0f, 1.0f, 1.0f, 1.0f};

/*
    receives current settings, e.g. for applying to screen, or saving to a preset.
    @setting - pointer to ScreenSettings struct to write current settings to.
    @returns - True if brightness was changed from the last time.
    ^ the logic behind that: don't overload the brightness module if it's not necessary, but OpenGL will need some data to render anyway so we don't care about that.
*/
bool current_settings_get(ScreenSettings* setting)
{
    *setting = _current_settings;
    bool brightness_changed_temp = _brightness_changed;
    _brightness_changed = false;
    return brightness_changed_temp;
}

/*
    overwrites current settings, e.g. at init, or load from preset.
    @setting - pointer to ScreenSetting struct with new data.
*/
void current_settings_set(ScreenSettings* setting)
{
    _current_settings = *setting;
    _brightness_changed = true; //even if it's the same, better safe than sorry...
}

/*
    Applies actions from given vector, if any are applicable, to the current settings.
*/
void apply_action(uint32_t action_vector)
{
    float modifier = 0.03f;
    if(DECREASE_MODIFIER & action_vector)
    {
        modifier = -modifier;
    }
    if(SET_RED & action_vector)
    {
        _current_settings.red += modifier;
        //some clamping
        _current_settings.red = _current_settings.red > 1.0f ? 1.0f : _current_settings.red;
        _current_settings.red = _current_settings.red < 0.0f ? 0.0f : _current_settings.red;
    }
    if(SET_BLUE & action_vector)
    {
        _current_settings.blue += modifier;
        _current_settings.blue = _current_settings.blue > 1.0f ? 1.0f : _current_settings.blue;
        _current_settings.blue = _current_settings.blue < 0.0f ? 0.0f : _current_settings.blue;
    }
    if(SET_GREEN & action_vector)
    {
        _current_settings.green += modifier;
        _current_settings.green = _current_settings.green > 1.0f ? 1.0f : _current_settings.green;
        _current_settings.green = _current_settings.green < 0.0f ? 0.0f : _current_settings.green;
    }
    if(SET_BRIGHTNESS & action_vector)
    {
        _current_settings.brightness += modifier;
        _current_settings.brightness = _current_settings.brightness > 1.0f ? 1.0f : _current_settings.brightness;
        _current_settings.brightness = _current_settings.brightness < 0.0f ? 0.0f : _current_settings.brightness;
        _brightness_changed = true;
    }
}