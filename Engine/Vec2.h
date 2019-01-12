#pragma once

class Vec2
{
public:
	Vec2() = default;
	Vec2(float _x, float _y);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator*(float rhs) const;
	Vec2& operator*=(float rhs);
public:
	float x;
	float y;
};