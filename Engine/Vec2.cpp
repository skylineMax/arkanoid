#include "Vec2.h"
#include <cmath>

Vec2::Vec2(int _x, int _y)
	:
	x(_x), y(_y)
{
}

Vec2 Vec2::operator+(const Vec2 & rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y );
}

Vec2 & Vec2::operator+=(const Vec2 & rhs)
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator-(const Vec2 & rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 & Vec2::operator-=(const Vec2 & rhs)
{
	return *this = *this - rhs;
}

Vec2 Vec2::operator*(int rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2 & Vec2::operator*=(int rhs)
{
	return *this = *this * rhs;
}

int Vec2::GetLength() const
{
	return sqrt(GetLengthSq());
}

int Vec2::GetLengthSq() const
{
	return x*x + y*y;
}

Vec2& Vec2::Normalize()
{
	return *this = GetNormalized();
}

Vec2 Vec2::GetNormalized() const
{
	const int len = GetLength();
	if (len != 0.0f) 
		return *this * (1.0f / len);
	return *this;
}
