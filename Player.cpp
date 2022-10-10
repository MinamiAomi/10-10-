#include "Player.h"
#include "Game.h"
#include "Key.h"
#include "DeltaTime.h"
#include "Screen.h"

Player::Player(Game* game) :
	GameObject(game)
{}

Player::~Player() {

}

void Player::Create() {
	mData.mPosition = { 100, 500 };
	mData.mStemDirection = Vector2D{ -1,1 }.Normalized();
	mData.mVelocity = { 0,0 };
	mData.mGravity = 90.0f;
	mData.mMoveSpeed = 240.0f;
	mData.mRightInput = 0;

	mData.mWidth = 30.0f;
	mData.mHeight = 60.0f;

	float width = 5;

	mData.mOriginalPoint = {
		{ -mData.mWidth / 2.0f,mData.mHeight },
		{ mData.mWidth / 2.0f, mData.mHeight },
		{ -mData.mWidth / 2.0f,0 },
		{ mData.mWidth / 2.0f, 0 },

		{ -mData.mWidth / 2.0f + width,mData.mHeight - width },
		{ mData.mWidth / 2.0f - width, mData.mHeight - width},
		{ -mData.mWidth / 2.0f + width,  width },
		{ mData.mWidth / 2.0f - width,   width },

		{ 0,mData.mHeight - width},
	};
}

void Player::Update() {
	this->Input();

	mData.mStemDirection = (game()->screen()->MousePosition() - mData.mPosition).Normalized();

	mData.mVelocity.SetZero();
	mData.mVelocity += -mData.mStemDirection.Magnituded(mData.mGravity);
	mData.mVelocity += -mData.mStemDirection.Normal().Magnituded(mData.mMoveSpeed * mData.mRightInput);
	mData.mPosition += mData.mVelocity * DeltaTime::get();

}

void Player::Draw() {

	Matrix33 mat = Matrix33::CreateTranslation(mData.mPosition);
	mat *= Matrix33::CreateRotation((-mData.mStemDirection.Normal()).Angle());
	
	std::vector<Vector2D> drawvec;

	for (auto& iter : mData.mOriginalPoint) {
		drawvec.emplace_back(mat * iter);
	}

	game()->screen()->DrawBox(drawvec[DPI_OutSideLeftTop], drawvec[DPI_OutSideRightTop], drawvec[DPI_OutSideLeftBottom], drawvec[DPI_OutSideRightBottom], 0xFFFFFFFF);
	game()->screen()->DrawBox(drawvec[DPI_InSideLeftTop], drawvec[DPI_InSideRightTop], drawvec[DPI_InSideLeftBottom], drawvec[DPI_InSideRightBottom], 0x000000FF);
	game()->screen()->DrawTriangle(drawvec[DPI_InSideMidTop], drawvec[DPI_InSideLeftBottom], drawvec[DPI_InSideRightBottom], 0xFFFFFFFF);
}

void Player::Input() {
	mData.mRightInput = 0;
	if (Key::IsPressed(KC_D)) {
		mData.mRightInput += 1;
	}
	if (Key::IsPressed(KC_A)) {
		mData.mRightInput += -1;
	}
}