#include "QuadCollider.h"

struct Segment {
	Vector2D start;
	Vector2D end;
};

bool SegmentCollision(const Segment& s1, const Segment& s2) {
	Vector2D AB = s1.end - s1.start;
	Vector2D CD = s2.end - s2.start;

	float crossAC = AB.Cross(s2.start - s1.start) > 0 ? 1 : -1;
	float crossAD = AB.Cross(s2.end - s1.start) > 0 ? 1 : -1;
	float crossCA = CD.Cross(s1.start - s2.start) > 0 ? 1 : -1;
	float crossCB = CD.Cross(s1.end - s2.start) > 0 ? 1 : -1;

	if (crossAC != crossAD && crossCA != crossCB) {
		return true;
	}
	return false;
}

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
	Vector2D LB = { 0,-h };
	Vector2D RB = { w,-h };

	Matrix33 mat;
	mat *= Matrix33::CreateTranslation(lt);
	mat	*= Matrix33::CreateRotation(angle);

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

bool QuadCollider::QuadToQuad(const QuadCollider& q1, const QuadCollider& q2) {
	
	constexpr int segnum = 4;

	Segment q1seg[segnum] = {
		{q1.LeftTop(), q1.RightTop()},
		{q1.RightTop(), q1.RightBottom()},
		{q1.RightBottom(), q1.LeftBottom()},
		{q1.LeftBottom(), q1.LeftTop()}
	};
	Segment q2seg[segnum] = {
		{q2.LeftTop(), q2.RightTop()},
		{q2.RightTop(), q2.RightBottom()},
		{q2.RightBottom(), q2.LeftBottom()},
		{q2.LeftBottom(), q2.LeftTop()}
	};

	for (int i = 0; i < segnum; i++) {
		for (int j = 0; j < segnum; j++) {
			if (SegmentCollision(q1seg[i], q2seg[j])) {
				return true;
			}
		}
	}

	return false;

}