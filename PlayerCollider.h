#pragma once
#include "QuadCollider.h"
#include <list>
class PlayerCollider :
    public QuadCollider
{

private:
    class Player* mPlayer;

public:
    PlayerCollider(class Player* player);
    ~PlayerCollider();

    class Player* player() { return mPlayer; }

    QuadCollider getQuad();

private:
    static std::list<PlayerCollider*> sList;

public:
    static std::list<PlayerCollider*>& GroupPtr() { return sList; }

};

