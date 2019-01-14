#include "Player.h"


Player::Player(Vec2 & _pos, Vec2& _vel)
	:
	pos(_pos), vel(_vel)
{
}

void Player::Update(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed('W'))
		pos.y -= vel.y;
	if (kbd.KeyIsPressed('S'))
		pos.y += vel.y;
	if (kbd.KeyIsPressed('A'))
		pos.x -= vel.x;
	if (kbd.KeyIsPressed('D'))
		pos.x += vel.x;

}

void Player::ClampToScreen()
{
	const int right = pos.x + width;

	if (pos.x < 0)
	{
		pos.x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		pos.x = Graphics::ScreenWidth - width;
	}

	const int bottom = pos.y + height;

	if (pos.y < 0)
	{
		pos.y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		pos.y = Graphics::ScreenHeight - height;
	}
}

void Player::Draw(Graphics & gfx, Color c)
{
	gfx.DrawRect(pos.x, pos.y, width, height, c);
}

Vec2 Player::GetPos() const
{
	return pos;
}

Vec2 Player::GetVel() const
{
	return vel;
}

int Player::GetWidth() const
{
	return width;
}

int Player::GetHeight() const
{
	return height;
}
