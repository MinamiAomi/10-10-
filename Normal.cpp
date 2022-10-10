#include "Normal.h"
#include "Game.h"
#include "Player.h"
#include <Novice.h>
#include "Line.h"
#include "Curve.h"
#include "Collision.h"

Normal::Normal(Game* game) :
	Scene(game)
{

}
Normal::~Normal(){}

void Normal::Create(){
}

void Normal::Init() {
	
}

void Normal::Update(){
	game()->player()->Update();
	game()->collision()->Proc();
}

void Normal::Draw(){
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000FF, kFillModeSolid);
	game()->line()->Draw();
	//game()->curve()->Draw();
	game()->player()->Draw();
	game()->collision()->Debug();
}

void Normal::NextScene(){}