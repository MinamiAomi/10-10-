#pragma once
#include "Screen.h"
class Container
{

private:
	// ウィンドウデータ
	struct WindowData {
		const char* kWindowTitle;	// タイトル
		const int kWindowWidth;		// 幅
		const int kWindowHeight;	// 高さ
	};

	// ゲームデータ
	struct GameData	{
		Screen::Data screen;
	};

private:
	WindowData mWindowData;
	GameData mGameData;

// ゲッター
public:
	const WindowData& window() const { return mWindowData; }

	const Screen::Data& screen() const { return mGameData.screen; }

public:
	Container();
	~Container();

	void Load();

private:
	void setData();
	void setImages();
};

