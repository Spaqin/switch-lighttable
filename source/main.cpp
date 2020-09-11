#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>

#include "graphics.h"
#include "actions.h"
#include "scr_settings.h"


int main(int argc, char* argv[])
{
    float pre_app_brightness;
    lblGetCurrentBrightnessSetting(&pre_app_brightness);
    // Set mesa configuration (useful for debugging)
    setMesaConfig();

    // Initialize EGL on the default window
    if (!initEgl(nwindowGetDefault()))
        return EXIT_FAILURE;

    // Load OpenGL routines using glad
    gladLoadGL();

    // Initialize our scene
    sceneInit();

    // Main graphics loop
    while (appletMainLoop())
    {
        ScreenSettings current_settings;
        bool brightness_changed;
        // Get and process input
        uint32_t actions = get_actions();
        act(actions);
        brightness_changed = current_settings_get(&current_settings);
        if(brightness_changed)
        {
            lblSetCurrentBrightnessSetting(current_settings.brightness);
        }
        // Render stuff!
        sceneRender(&current_settings);
        swapBuffers();
        if(EXIT & actions)
        {
            break;
        }
    }

    // Deinitialize our scene
    sceneExit();

    // Deinitialize EGL
    deinitEgl();
    
    // Restore brightness
    lblSetCurrentBrightnessSetting(pre_app_brightness);
    return EXIT_SUCCESS;
}
