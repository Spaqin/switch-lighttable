#include "actions.h"

#include <switch.h>

uint32_t get_actions()
{
    //for holding presets
    static uint32_t held_counter = 0;
    const uint32_t held_threshold = 60; //idk, 60 frames, will be probably adjusted later.

    uint32_t action_vector = 0;

    hidScanInput();

    uint64_t kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
    //hmm... there will be a 1 frame lag if I use only keysHeld... but it will simplify the code, and that's a sacrifice I'm willing to make.
    uint64_t kDown = hidKeysDown(CONTROLLER_P1_AUTO);
    uint64_t kUp = hidKeysUp(CONTROLLER_P1_AUTO);

    if(KEY_A & kHeld)
    {
        action_vector |= SET_BLUE;
    }
    if(KEY_B & kHeld)
    {
        action_vector |= SET_GREEN;
    }
    if(KEY_Y & kHeld)
    {
        action_vector |= SET_RED;
    }
    if(KEY_X & kHeld)
    {
        action_vector |= SET_BRIGHTNESS;
    }
    if(KEY_R & kHeld)
    {
        action_vector |= DECREASE_MODIFIER;
    }

    if((KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT) & kHeld) //if ANY key is held, count the timer.
    {
        held_counter += 1; //yes, it can be overfilled. that's holding it for a long time...
    }

    //toggling doesn't work with holding a key down really, so it's just on down
    if(KEY_PLUS & kDown)
    {
        action_vector |= TOGGLE_SETTINGS;
    }

    if((KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT) & kUp) //any key released...
    {
        switch(kUp) //switch/case - for >equality<. only one button can be released at a time, so you can change your mind on the preset.
        {
            case KEY_UP:
                action_vector |= PRESET_UP;
                break;
            case KEY_DOWN:
                action_vector |= PRESET_DOWN;
                break;
            case KEY_LEFT:
                action_vector |= PRESET_LEFT;
                break;
            case KEY_RIGHT:
                action_vector |= PRESET_RIGHT;
                break;
        }
        if(held_counter >= held_threshold)
        {
            action_vector |= SET_PRESET_MODIFIER;
        }
        //and reset the counter!
        held_counter = 0;
    }
    return action_vector;
}


void act(uint32_t actions)
{

}