#include "Rect.h"

Rect::Rect(float _left, float _top, float _right, float _bottom)
	: left(_left), top(_top), right(_right), bottom(_bottom)
{
}

Rect::Rect(const Vec2 & topLeft, const Vec2 & bottomRight)
	: Rect(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{
}

Rect::Rect(const Vec2 & topLeft, float width, float height)
	: Rect(topLeft, topLeft + Vec2(width, height))
{
}

bool Rect::isOverLappingWith(const Rect & other) const
{
	return 
		left < other.right && right > other.left && 
		top < other.bottom && bottom > other.top;
}

Rect Rect::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return Rect(center - half, center + half);
}

//Rect Rect::GetRect() const
//{
//	return *this;
//}
