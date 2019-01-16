#include "Brick.h"
#include <assert.h>

Brick::Brick(const Rect& _brick,Color _color) :
	brick(_brick), 
	pos(brick.left + (brick.right - brick.left)/2, brick.top + (brick.bottom - brick.top) / 2),
	color(_color)
{
}

void Brick::Draw(Graphics & gfx)
{
	gfx.DrawRect(brick, color);
}

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !destroyed && brick.isOverLappingWith(ball.GetRect());
}

void Brick::DoBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));

	Vec2 ballPos = ball.GetPos();

	if (std::signbit(ball.GetVel().x) == std::signbit((ballPos - pos).x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= brick.left && ballPos.x <= brick.right)
	{
		ball.ReboundY();
	}
	else {
		ball.ReboundX();
	}

	destroyed = true;
}


bool Brick::isDestroyed() const
{
	return destroyed;
}
