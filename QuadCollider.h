#pragma once
#include "MyMath.h"
class QuadCollider
{

private:
	Vector2D mLeftTop;
	Vector2D mRightTop;
	Vector2D mLeftBottom;
	Vector2D mRightBottom;

public:

	virtual ~QuadCollider();

	void Set(const Vector2D& lt, const Vector2D& rt, const Vector2D& lb, const Vector2D& rb);
	void SetLeftTop(const Vector2D& lt, float w, float h, float angle);
	void SetCenter(const Vector2D& cen, float w, float h, float angle);


	const Vector2D& LeftTop() const { return mLeftBottom; }
	const Vector2D& RightTop() const { return mRightTop; }
	const Vector2D& LeftBottom() const { return mLeftBottom; }
	const Vector2D& RightBottom() const { return mRightBottom; }
};

