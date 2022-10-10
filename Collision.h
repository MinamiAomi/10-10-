#pragma once
#include "GameObject.h"
#include "MyMath.h"
class Collision :
    public GameObject
{
private:


public:
    Collision(class Game* game);
    ~Collision();

    void Create();
    void Init();
    void Proc();
    void Debug();
};

