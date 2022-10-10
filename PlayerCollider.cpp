#include "PlayerCollider.h"
#include "Player.h"

PlayerCollider::PlayerCollider(class Player* player) :
	mPlayer(player)
{
	sList.push_back(this);
}
PlayerCollider::~PlayerCollider() {}