#include "Scene.h"
#include "Game.h"
#include "Screen.h"

Scene::Scene(class Game* game) : 
	GameObject(game)
{

}
Scene::~Scene(){}

void Scene::Proc() {
	this->Update();
	game()->screen()->CalcMatrix();
	this->Draw();
	this->NextScene();
}