#include "Line.h"
#include "Game.h"
#include "Screen.h"
#include "Debug.h"

Line::Line(Game* game) :
	GameObject(game)
{
}

Line::~Line(){}

void Line::Create() {
	mData.mStartPosition = { 50,200 };
	mData.mEndPosition = { 1000, 300 };
	mData.mWidth = 5;
}

void Line::Draw() {
	
	Vector2D leftTop = calcVector().Normal().Magnituded(mData.mWidth) + mData.mStartPosition;
	game()->screen()->DrawBox(leftTop, calcVector().Length(), mData.mWidth * 2, calcVector().Angle());
}
