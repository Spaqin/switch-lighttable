#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <switch.h>

#include <EGL/egl.h>    // EGL library
#include <EGL/eglext.h> // EGL extensions
#include <glad/glad.h>  // glad library (OpenGL loader)


static bool initEgl(NWindow* win);
static void deinitEgl();
static void setMesaConfig();

static GLuint createAndCompileShader(GLenum type, const char* source);
static void sceneInit();
static void sceneRender();
static void sceneExit();

static void swapBuffers();

typedef struct 
{
    float position[3];
    float color[3];
} Vertex;

#endif