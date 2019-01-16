#include "Ball.h"

Ball::Ball(const Vec2 & center, const Vec2& _vel, Color _color) :
	pos(center), vel(_vel), color(_color)
{

}

void Ball::Update(float dt)
{
	pos += vel * dt;

}

void Ball::Draw(Graphics & gfx)
{
	gfx.DrawCircle(pos, radius, color);

}

bool Ball::DoWallCollision(const Rect & walls)
{
	bool collided = false;
	const Rect rect = GetRect();

	if (rect.left < walls.left) {
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= (rect.right - walls.right + 1);
		ReboundX();
		collided = true;
	}
	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= (rect.bottom - walls.bottom + 1);
		ReboundY();
		collided = true;
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

Rect Ball::GetRect() const
{
	return Rect::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetPos() const
{
	return pos;
}

Vec2 Ball::GetDir() const
{
	return vel;
}

void Ball::SetDir(Vec2 _vel)
{
	vel = _vel;
}
