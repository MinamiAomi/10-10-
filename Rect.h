#pragma once
#include "Vector2.h"

template<typename TYPE> 
class Rect
{

public:
	TYPE left;
	TYPE top;
	TYPE width;
	TYPE height;

public:
	Rect();
	Rect(TYPE left, TYPE top, TYPE width, TYPE height);
	~Rect();

	inline void set(TYPE left, TYPE top, TYPE width, TYPE height);
	inline void setLeftTop(TYPE left, TYPE top);
	inline void setLeftTop(const Vector2& pos);
	inline void setSize(TYPE width, TYPE height);
	inline void setCenter(TYPE x, TYPE y);
	inline void setCenter(const Vector2& pos);

	inline TYPE getLeft() const;
	inline TYPE getRight() const;
	inline TYPE getTop() const;
	inline TYPE getBottom() const;

};

typedef Rect<int> ImageRect;

#pragma region ’è‹`
template<typename TYPE> 
Rect<TYPE>::Rect() :
	left(0), top(0), width(0), height(0)
{	
}

template<typename TYPE>
Rect<TYPE>::Rect(TYPE left, TYPE top, TYPE width, TYPE height) :
	left(left), top(top), width(width), height(height)
{
}

template<typename TYPE>
Rect<TYPE>::~Rect(){}

template<typename TYPE>
void Rect<TYPE>::set(TYPE left, TYPE top, TYPE width, TYPE height) {
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
}

template<typename TYPE>
void Rect<TYPE>::setLeftTop(TYPE left, TYPE top) {
	this->left = left;
	this->top = top;
}

template<typename TYPE>
void Rect<TYPE>::setLeftTop(const Vector2& pos) {
	setLeftTop(static_cast<TYPE>(pos.x), static_cast<TYPE>(pos.y));
}

template<typename TYPE>
void Rect<TYPE>::setSize(TYPE width, TYPE height) {
	this->width = width;
	this->height = height;
}

template<typename TYPE>
void Rect<TYPE>::setCenter(TYPE x, TYPE y) {
	this->left = x - width / static_cast<TYPE>(2);
	this->top = y - height / static_cast<TYPE>(2);
}

template<typename TYPE>
void Rect<TYPE>::setCenter(const Vector2& pos) {
	setCenter(static_cast<TYPE>(pos.x), static_cast<TYPE>(pos.y));
}

template<typename TYPE>
TYPE Rect<TYPE>::getLeft() const {
	return left;
}

template<typename TYPE>
TYPE Rect<TYPE>::getRight() const {
	return left + width;
}

template<typename TYPE>
TYPE Rect<TYPE>::getTop() const {
	return top;
}

template<typename TYPE>
TYPE Rect<TYPE>::getBottom() const {
	return top - height;
}

#pragma endregion


