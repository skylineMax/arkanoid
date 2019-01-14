#include "Player.h"


Player::Player(Vec2 & _pos, Vec2& _vel)
	:
	pos(_pos), vel(_vel)
{
}

void Player::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed('W'))
		pos.y -= vel.y * dt;
	if (kbd.KeyIsPressed('S'))
		pos.y += vel.y * dt;
	if (kbd.KeyIsPressed('A'))
		pos.x -= vel.x * dt;
	if (kbd.KeyIsPressed('D'))
		pos.x += vel.x * dt;

}

void Player::ClampToScreen()
{
	const float right = pos.x + width;

	if (pos.x < 0)
	{
		pos.x = 0;
	}
	else if (right >= (float)Graphics::ScreenWidth)
	{
		pos.x = (float)Graphics::ScreenWidth - width;
	}

	const float bottom = pos.y + height;

	if (pos.y < 0)
	{
		pos.y = 0;
	}
	else if (bottom >= (float)Graphics::ScreenHeight)
	{
		pos.y = (float)Graphics::ScreenHeight - height;
	}
}

void Player::Draw(Graphics & gfx, Color c)
{
	gfx.DrawRect(int(pos.x), int(pos.y), (int)width, (int)height, c);
}

Vec2 Player::GetPos() const
{
	return pos;
}

Vec2 Player::GetVel() const
{
	return vel;
}

float Player::GetWidth() const
{
	return width;
}

float Player::GetHeight() const
{
	return height;
}
