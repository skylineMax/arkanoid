#include "Brick.h"

Brick::Brick(const Rect& _rect,Color _color) :
	rect(_rect), color(_color)
{
}

void Brick::Draw(Graphics & gfx)
{
	gfx.DrawRect(rect, color);
}

bool Brick::DoBallCollision(Ball& ball)
{
	Rect ballRect = ball.GetRect();
	if (!destroyed && rect.isOverLappingWith(ballRect))
	{
		ball.ReboundY();
		destroyed = true;

	}
		
	return destroyed;
}

bool Brick::isDestroyed() const
{
	return destroyed;
}
