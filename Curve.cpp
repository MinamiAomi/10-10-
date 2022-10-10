#include "Curve.h"
#include "Game.h"
#include "Screen.h"


Curve::Curve(Game* game) :
	GameObject(game)
{

}
Curve::~Curve() {}

void Curve::Create() {
	mData.mStartPosition = { 100,100 };
	mData.mControlPosition1 = {400, 600};
	mData.mControlPosition2 = {1100,600};
	mData.mEndPosition = { 800, 100 };
	mData.mNumDivision = 40;
	mData.mWidth = 5;

	for (int index = 0; index < mData.mNumDivision; index++) {
		float t = static_cast<float>(index) / static_cast<float>(mData.mNumDivision - 1);
		Vector2D bzierPoint = CalcCubicBezierCurve(t, mData.mStartPosition, mData.mControlPosition1, mData.mControlPosition2, mData.mEndPosition);
		Vector2D diffBzier = DiffCubicBezierCurve(t, mData.mStartPosition, mData.mControlPosition1, mData.mControlPosition2, mData.mEndPosition);
		Vector2D normal = diffBzier.Normal().Magnituded(mData.mWidth);
		mData.mBezierPoints.emplace_back(bzierPoint);
		mData.mUpperBezierPoints.emplace_back(normal + bzierPoint);
		mData.mLowerBezierPoints.emplace_back(-normal + bzierPoint);
		mData.mBezierNormalVector.emplace_back(normal.Magnituded(50));
	}
}

void Curve::Draw() {
	game()->screen()->DrawCircle(mData.mStartPosition, 10, 0xFFFFFF66);
	game()->screen()->DrawCircle(mData.mControlPosition1, 10, 0xFFFFFF66);
	game()->screen()->DrawCircle(mData.mControlPosition2, 10, 0xFFFFFF66);
	game()->screen()->DrawCircle(mData.mEndPosition, 10, 0xFFFFFF66);

	for (int index = 0; index < mData.mNumDivision; index++) {

		game()->screen()->DrawLine(mData.mBezierPoints[index], mData.mBezierPoints[index] + mData.mBezierNormalVector[index]);
	}

	for (int index = 0; index < mData.mNumDivision - 1; index++) {
		int next = index + 1;
		game()->screen()->DrawTriangle(mData.mUpperBezierPoints[index], mData.mUpperBezierPoints[next], mData.mLowerBezierPoints[index]);
		game()->screen()->DrawTriangle(mData.mUpperBezierPoints[next], mData.mLowerBezierPoints[index], mData.mLowerBezierPoints[next]);
	}
}
