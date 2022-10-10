#include "PlayerCollider.h"
#include "Player.h"

std::list<PlayerCollider*> PlayerCollider::sList;

PlayerCollider::PlayerCollider(class Player* player) :
	mPlayer(player)
{
	sList.push_back(this);
}
PlayerCollider::~PlayerCollider() {}

QuadCollider PlayerCollider::getQuad() {	
	Matrix33 mat;
	mat *= Matrix33::CreateTranslation(mPlayer->position());
	mat *= Matrix33::CreateRotation(mPlayer->angle());
	QuadCollider temp;
	temp.Set(mat * LeftTop(),
		mat * RightTop(),
		mat * LeftBottom(),
		mat * RightBottom());
	return temp;
}