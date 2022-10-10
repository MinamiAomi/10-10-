#include "Collision.h"
#include "Game.h"
#include "LineCollider.h"
#include "PlayerCollider.h"
#include "Player.h"
#include "Line.h"
#include "Screen.h"

Collision::Collision(Game* game) :
	GameObject(game)
{}

Collision::~Collision(){}

void Collision::Create() {

}
void Collision::Init() {

}
void Collision::Proc() {

	for (auto& piter : PlayerCollider::GroupPtr()) {
		for (auto& liter : LineCollider::GroupPtr()) {
			bool flag = QuadCollider::QuadToQuad(liter->getQuad(), piter->getQuad());
			piter->player()->Collision(flag);
			if (flag) {
				break;
			}
		}
	}
}

void Collision::Debug() {
	for (auto& piter : PlayerCollider::GroupPtr()) {
		QuadCollider a = piter->getQuad();
		game()->screen()->DrawBox(a.LeftTop(), a.RightTop(), a.RightBottom(), a.LeftBottom(),  0x0000FFFF, kFrame);
	}
	for (auto& liter : LineCollider::GroupPtr()) {
		QuadCollider a = liter->getQuad();
		game()->screen()->DrawBox(a.LeftTop(), a.RightTop(),  a.RightBottom(), a.LeftBottom(), 0x0000FFFF, kFrame);
	}
}