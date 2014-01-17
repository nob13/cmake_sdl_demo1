#include <SDL.h>

#include "Scene.h"
#include "Timer.h"

int main(int argc, char * argv[])
{
    Scene scene(800, 600);
    Timer timer(30.0);
    while(scene.handleEvents())
    {
        scene.render();
        timer.waitTick();
    }

    return 0;
}
