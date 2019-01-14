#include "Vec2.h"
#include <cmath>

Vec2::Vec2(float _x, float _y)
	:
	x(_x), y(_y)
{
}

bool Vec2::operator==(const Vec2 & rhs) const
{
	return this->x == rhs.x && this->y == rhs.y;
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

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

Vec2 Vec2::operator*(Vec2 & rhs) const
{
	return Vec2(x * rhs.x, y * rhs.y);
}

Vec2 & Vec2::operator*=(float rhs)
{
	return *this = *this * rhs;
}

float Vec2::GetLength() const
{
	return sqrt(GetLengthSq());
}

float Vec2::GetLengthSq() const
{
	return x*x + y*y;
}

Vec2& Vec2::Normalize()
{
	return *this = GetNormalized();
}

Vec2 Vec2::GetNormalized() const
{
	const float len = GetLength();
	if (len != 0) 
		return *this * (1 / len);
	return *this;
}
