#include <cmath>

#include <SDL_opengl.h>
#include <SDL.h>

#include "Scene.h"

Scene::Scene(int width, int height)
:
    width(width),
    height(height)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetVideoMode(width, height, 32, /*SDL_HWSURFACE |*/ SDL_OPENGL);

    float ratio = (float)width / height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ratio, ratio, -1.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

Scene::~Scene()
{
    SDL_Quit();
}

bool Scene::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                return 0;
            }
        }
    }
    return 1;
}

void Scene::render()
{
    static float delta = 0.0f;
    delta += 0.025f;
    if (delta > 2.f * 3.14f)
        delta -= 2.f * 3.14f;

    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex3f(sin(delta), cos(delta), -1.0f);
        glVertex3f(sin(delta + 2.f * 3.14f / 3.f), cos(delta + 2.f * 3.14f / 3.f), -1.0f);
        glVertex3f(sin(delta + 2.f * 3.14f / 3.f * 2.f), cos(delta + 2.f * 3.14f / 3.f * 2.f), -1.0f);
    glEnd();

    SDL_GL_SwapBuffers();
}
