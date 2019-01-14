#pragma once

class Vec2
{
public:
	Vec2() = default;
	Vec2(int _x, int _y);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs) const;
	Vec2& operator-=(const Vec2& rhs);
	Vec2 operator*(int rhs) const;
	Vec2& operator*=(int rhs);
	int GetLength() const;
	int GetLengthSq() const;
	Vec2& Normalize();
	Vec2 GetNormalized() const;

public:
	int x;
	int y;
};