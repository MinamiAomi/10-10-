#include "Screen.h"
#include <Novice.h>
#include "Game.h"
#include "Container.h"

Screen::Screen(Game* game):
	GameObject(game)
{}
Screen::~Screen(){}

void Screen::Create(){
	mData = game()->container()->screen();
}

void Screen::Init(){
	mData = game()->container()->screen();
}

void Screen::Update(){}

void Screen::CalcMatrix(){
	mData.mMatrix.setIdentity();
	mData.mMatrix *= Matrix33::CreateTranslation(mData.mScroll);
	mData.mMatrix *= Matrix33::CreateScaling(1.0f, -1.0f);
}

Vector2D Screen::MousePosition() {
	int x, y;
	Novice::GetMousePosition(&x, &y);
	Vector2D temp((float)x, (float)y);
	temp += -mData.mScroll;
	temp.y *= -1;
	return temp;
}

void Screen::DrawBox(const Vector2D& vec, float width, float height, float theta, unsigned int color, ShapeFillMode fillmode) const{
	Vector2D scr = Conversion(vec);
	Novice::DrawBox(scr.x, scr.y, width, height, -theta, color, static_cast<FillMode>(fillmode));
}
void Screen::DrawBox(const Vector2D& vec1, const Vector2D& vec2, const Vector2D& vec3, const Vector2D& vec4, unsigned int color, ShapeFillMode fillmode) const {
	Vector2D scrvec1 = Conversion(vec1);
	Vector2D scrvec2 = Conversion(vec2);
	Vector2D scrvec3 = Conversion(vec3);
	Vector2D scrvec4 = Conversion(vec4);
	Novice::DrawBox(scrvec1.x, scrvec1.y, scrvec2.x, scrvec2.y, scrvec3.x, scrvec3.y, scrvec4.x, scrvec4.y, color, static_cast<FillMode>(fillmode));
}
void Screen::DrawTriangle(const Vector2D& vec1, const Vector2D& vec2, const Vector2D& vec3, unsigned int color, ShapeFillMode fillmode) const{
	Vector2D scr_1 = Conversion(vec1);
	Vector2D scr_2 = Conversion(vec2);
	Vector2D scr_3 = Conversion(vec3);
	Novice::DrawTriangle(scr_1.x, scr_1.y, scr_2.x, scr_2.y, scr_3.x, scr_3.y, color, static_cast<FillMode>(fillmode));
}
void Screen::DrawCircle(const Vector2D& vec, float rad, unsigned int color, ShapeFillMode fillmode) const{
	Vector2D scr = Conversion(vec);
	Novice::DrawEllipse(scr.x, scr.y, rad, rad, 0.0f, color, static_cast<FillMode>(fillmode));
}
void Screen::DrawLine(const Vector2D& vec1, const Vector2D& vec2, unsigned int color) const{
	Vector2D scrvec1 = Conversion(vec1);
	Vector2D scrvec2 = Conversion(vec2);
	Novice::DrawLine(scrvec1.x, scrvec1.y, scrvec2.x, scrvec2.y, color);
}
void Screen::DrawLineWidth(const Vector2D& vec1, const Vector2D& vec2, float width, unsigned int color) const {
	Vector2D normal = (vec1 - vec2).Normal();
	Vector2D upper = normal.Magnituded(width);
	Vector2D lower = -normal.Magnituded(width);

	Vector2D starttop = vec1 + upper;
	Vector2D endtop = vec2 + upper;
	Vector2D startbottom = vec1 + lower;
	Vector2D endbottom = vec2 + lower;

	Vector2D scrvec1 = Conversion(starttop);
	Vector2D scrvec2 = Conversion(endtop);
	Vector2D scrvec3 = Conversion(startbottom);
	Vector2D scrvec4 = Conversion(endbottom);

	Novice::DrawBox(scrvec1.x, scrvec1.y, scrvec2.x, scrvec2.y, scrvec3.x, scrvec3.y, scrvec4.x, scrvec4.y, color, kFillModeSolid);
}

void Screen::DrawSprite() const{}
void Screen::DrawSpriteRect() const{}
void Screen::DrawQuad() const{}