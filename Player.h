#pragma once
#include "GameObject.h"
#include "MyMath.h"
#include <vector>
#include "PlayerCollider.h"

class Player : 
	public GameObject {

public:
	struct Data {
		Vector2D mPosition;
		
		Vector2D mStemDirection; // 立っている向き
		Vector2D mVelocity;
		float mGravity;
		float mMoveSpeed;

		int mRightInput; // 右入力

		float mWidth;
		float mHeight;

		std::vector<Vector2D> mOriginalPoint;

		unsigned int color;
	};

private:

	enum DrawPointIndex {
		DPI_OutSideLeftTop,		// 外側左上
		DPI_OutSideRightTop,	// 外側右上
		DPI_OutSideLeftBottom,	// 外側左下
		DPI_OutSideRightBottom,	// 外側右下
		DPI_InSideLeftTop,		// 内側左上
		DPI_InSideRightTop,		// 内側右上
		DPI_InSideLeftBottom,	// 内側左下
		DPI_InSideRightBottom,	// 内側右下
		DPI_InSideMidTop		// 内側真ん中上
	};

private:

	Data mData;
	PlayerCollider mCollider;


public:
	Player(class Game* game);
	~Player();

	void Create();
	void Update();
	void Draw();

	void Collision(bool i);


	const Vector2D& position() { return mData.mPosition; }
	const float angle() { return (-mData.mStemDirection.Normal()).Angle(); }

private:
	void Input();
};