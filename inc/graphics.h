#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <switch.h>

#include <EGL/egl.h>    // EGL library
#include <EGL/eglext.h> // EGL extensions
#include <glad/glad.h>  // glad library (OpenGL loader)


bool initEgl(NWindow* win);
void deinitEgl();
void setMesaConfig();

GLuint createAndCompileShader(GLenum type, const char* source);
void sceneInit();
void sceneRender();
void sceneExit();

void swapBuffers();

typedef struct 
{
    float position[3];
    float color[3];
} Vertex;

#endif