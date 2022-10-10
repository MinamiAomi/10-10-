#include "Line.h"
#include "Game.h"
#include "Screen.h"
#include "Debug.h"

Line::Line(Game* game) :
	GameObject(game),
	mCollider(this)
{
}

Line::~Line(){}

void Line::Create() {
	mData.mStartPosition = { 50,200 };
	mData.mEndPosition = { 1000, 300 };
	mData.mWidth = 5;

	Vector2D leftTop = calcVector().Normal().Magnituded(mData.mWidth) + mData.mStartPosition;
	
	mCollider.SetLeftTop(leftTop, calcVector().Length(), mData.mWidth * 2, calcVector().Angle());
}

void Line::Draw() {
	
	Vector2D leftTop = calcVector().Normal().Magnituded(mData.mWidth) + mData.mStartPosition;
	game()->screen()->DrawBox(leftTop, calcVector().Length(), mData.mWidth * 2, calcVector().Angle());
}
