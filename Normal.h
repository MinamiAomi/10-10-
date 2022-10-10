#pragma once
#include "Scene.h"
class Normal :
    public Scene
{


public:
    Normal(class Game* game);
    ~Normal();

    void Create();
    void Init();
    void Update();
    void Draw();
    void NextScene();

};

