#pragma once
#include "GameObject.h"
class Scene :
    public GameObject
{


public:
    Scene(class Game* game);
    virtual ~Scene();

    void Proc();

    virtual void Create() = 0;
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void NextScene() = 0;
};

