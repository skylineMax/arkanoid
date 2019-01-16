#include "Paddle.h"

Paddle::Paddle(const Vec2& _pos, float _halfWidth, float _halfHeight, Color _color)
	:pos(_pos), halfWidth(_halfWidth), halfHeight(_halfHeight), color(_color)
{
	
}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed('A'))
		pos.x -= speed * dt;
	if (kbd.KeyIsPressed('D'))
		pos.x += speed * dt;

}

void Paddle::DoWallCollision(const Rect & walls)
{
	Rect paddle = Rect::FromCenter(pos, halfWidth, halfHeight);
	if (paddle.left < walls.left) {
		pos.x += walls.left - paddle.left;
	}
	else if (paddle.right > walls.right)
	{
		pos.x -= (paddle.right - walls.right);
	}
}

bool Paddle::DoBallCollision(Ball & ball)
{
	Rect paddle = Rect::FromCenter(pos, halfWidth, halfHeight);
	
	if (!cooldown)
	{
		if (paddle.isOverLappingWith(ball.GetRect()))
		{
			Vec2 ballPos = ball.GetPos();
			if (std::signbit(ball.GetVel().x) == std::signbit((ballPos - pos).x))
			{
					ball.ReboundY();
			}
			else if (ballPos.x >= paddle.left && ballPos.x <= paddle.right)
			{
				ball.ReboundY();
			}
			else
			{
				ball.ReboundX();
			}
			cooldown = true;
			return true;

		}
		
	}
	return false;
}

void Paddle::Draw(Graphics & gfx)
{
	Rect paddle = Rect::FromCenter(pos, halfWidth, halfHeight);
	gfx.DrawRect(paddle, color);
}

void Paddle::ResetCooldown()
{
	cooldown = false;
}


