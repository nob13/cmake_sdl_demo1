#ifndef SCENE_H
#define SCENE_H


class Scene {
public:
    Scene(int width, int height);
    ~Scene();
    void render();
    bool handleEvents();
private:
    int width, height;
};


#endif // SCENE_H

