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
		
		Vector2D mStemDirection; // �����Ă������
		Vector2D mVelocity;
		float mGravity;
		float mMoveSpeed;

		int mRightInput; // �E����

		float mWidth;
		float mHeight;

		std::vector<Vector2D> mOriginalPoint;

		unsigned int color;
	};

private:

	enum DrawPointIndex {
		DPI_OutSideLeftTop,		// �O������
		DPI_OutSideRightTop,	// �O���E��
		DPI_OutSideLeftBottom,	// �O������
		DPI_OutSideRightBottom,	// �O���E��
		DPI_InSideLeftTop,		// ��������
		DPI_InSideRightTop,		// �����E��
		DPI_InSideLeftBottom,	// ��������
		DPI_InSideRightBottom,	// �����E��
		DPI_InSideMidTop		// �����^�񒆏�
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