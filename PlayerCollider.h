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


private:
    static std::list<PlayerCollider*> sList;

public:
    static const std::list<PlayerCollider*>& GroupPtr() { return sList; }

};

