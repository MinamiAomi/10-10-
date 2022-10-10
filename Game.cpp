#include "Game.h"
#include <Novice.h>
#include "Key.h"
#include "Container.h"
#include "DeltaTime.h"
#include "Scene.h"
#include "Normal.h"
#include "Screen.h"
#include "Player.h"
#include "Line.h"
#include "Curve.h"
#include "Collision.h"

Game::Game() {

	mContainer = new Container();

	mScene[kNormal] = new Normal(this);

	mScreen = new Screen(this);

	mPlayer = new Player(this);

	mLine = new Line(this);

	mCurve = new Curve(this);

	mCollision = new Collision(this);
}

Game::~Game() {

	delete mCollision;

	delete mCurve;

	delete mLine;

	delete mPlayer;

	delete mScreen;

	for (int num = 0; num < kSceneIdNum; num++) {
		delete mScene[num];
	}

	delete mContainer;

}


void Game::Run() {

	// ライブラリの初期化
	Novice::Initialize(container()->window().kWindowTitle, container()->window().kWindowWidth, container()->window().kWindowHeight);

	mContainer->Load();

	mScene[kNormal]->Create();

	ChangeScene(kNormal);

	mScreen->Create();

	mPlayer->Create();

	mLine->Create();

	mCurve->Create();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		Key::Input();
		DeltaTime::CalcDeltaTime();

		mScene[mCurrentSceneId]->Proc();
		
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Key::IsTrigger(KC_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();

}


void Game::ChangeScene(SceneId next) {
	mCurrentSceneId = next;
	mScene[mCurrentSceneId]->Init();
}
