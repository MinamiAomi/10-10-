#pragma once
class Game
{
// コンテナ
private:
	class Container* mContainer;

public:
	const class Container* container() { return mContainer; }

// シーン
public:
	enum SceneId {
		kNormal,

		kSceneIdNum // シーンの種類
	};

private:
	// 現在のシーン
	SceneId mCurrentSceneId;
	// シーンポインタ
	class Scene* mScene[kSceneIdNum];

public:
	void ChangeScene(SceneId next);

private:
	class Screen* mScreen;

public:
	class Screen* screen() { return mScreen; }

// プレイヤー
private:
	class Player* mPlayer;

public:
	class Player* player() { return mPlayer; }

// 辺
private:
	class Line* mLine;

public:
	class Line* line() { return mLine; }

	// 辺
private:
	class Curve* mCurve;

public:
	class Curve* curve() { return mCurve; }


private:
	class Collision* mCollision;
public:
	class Collision* collision() { return mCollision; }
public:
	Game();
	~Game();

	void Run();

};

