#pragma once

#include "Vec2.h"

class Rect
{
public:
	Rect() = default;
	Rect(float _left, float _top, float _right, float _bottom);
	Rect(const Vec2& topLeft, const Vec2& bottomRight);
	Rect(const Vec2& topLeft, float width, float height);
	bool isOverLappingWith(const Rect& other) const;
	static Rect FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	//Rect GetRect() const;
public:
	float left;
	float top;
	float right;
	float bottom;
};