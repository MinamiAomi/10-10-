#include "QuadCollider.h"
QuadCollider::~QuadCollider() {

}

void QuadCollider::Set(const Vector2D& lt, const Vector2D& rt, const Vector2D& lb, const Vector2D& rb) {
	mLeftTop = lt;
	mRightTop = rt;
	mLeftBottom = lb;
	mRightBottom = rb;
}

void QuadCollider::SetLeftTop(const Vector2D& lt, float w, float h, float angle) {

	Vector2D LT = { 0,0 };
	Vector2D RT = { w,0 };
	Vector2D LB = { 0,h };
	Vector2D RB = { w,h };

	Matrix33 mat;
	mat	*= Matrix33::CreateRotation(angle);
	mat *= Matrix33::CreateTranslation(lt);

	mLeftTop = mat * LT;
	mRightTop = mat * RT;
	mLeftBottom = mat * LB;
	mRightBottom = mat * RB;
}

void QuadCollider::SetCenter(const Vector2D& cen, float w, float h, float angle) {
	
	float hw = w / 2.0f;
	float hh = h / 2.0f;
	Vector2D LT = { -hw,hh };
	Vector2D RT = { hw,hh };
	Vector2D LB = { -hw,-hh };
	Vector2D RB = { hw,-hh };

	Matrix33 mat;
	mat *= Matrix33::CreateRotation(angle);
	mat *= Matrix33::CreateTranslation(cen);

	mLeftTop = mat * LT;
	mRightTop = mat * RT;
	mLeftBottom = mat * LB;
	mRightBottom = mat * RB;
}
