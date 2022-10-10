#include "Container.h"
#include "Game.h"
#include <Novice.h>
#include "Rect.h"

Container::Container() :
	mWindowData({ "ƒ^ƒCƒgƒ‹", 1280, 720 })
{}

Container::~Container(){}

void Container::Load() {
	setData();
	setImages();
}

void Container::setData() {
	mGameData.screen.mScroll = { 0,720 };
	mGameData.screen.isCameraShake = false;
	mGameData.screen.mMatrix.setIdentity();
	mGameData.screen.mColor = 0xFFFFFFFF;
	
}

void Container::setImages() {
	

}