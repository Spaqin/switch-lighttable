#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>

#include "graphics.h"
#include "actions.h"


int main(int argc, char* argv[])
{
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
        // Get and process input
        uint32_t actions = get_actions();
        act(actions);

        // Render stuff!
        sceneRender();
        swapBuffers();
    }

    // Deinitialize our scene
    sceneExit();

    // Deinitialize EGL
    deinitEgl();
    return EXIT_SUCCESS;
}
