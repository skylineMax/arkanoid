#include "Player.h"


Player::Player(Vec2 & _pos, Vec2& _vel)
	:
	pos(_pos), vel(_vel)
{
}

void Player::Update(const Keyboard& kbd, float dt)
{
	Vec2 dvel(0.0f, 0.0f);
	if (kbd.KeyIsPressed('W'))
		dvel.y -= 1.0f;
	if (kbd.KeyIsPressed('S'))
		dvel.y += 1.0f;
	if (kbd.KeyIsPressed('A'))
		dvel.x -= 1.0f;
	if (kbd.KeyIsPressed('D'))
		dvel.x += 1.0f;
	pos += dvel.GetNormalized() * vel * dt;
}

void Player::Update(const Mouse & mouse, float dt)
{
	if (mouse.LeftIsPressed())
	{
		const Vec2 center = pos + Vec2(width / 2.0f, height / 2.0f);
		const Vec2 toPointer = Vec2((float)mouse.GetPosX(), (float)mouse.GetPosY()) - center;
		if (toPointer.GetLengthSq() > 2.0f)
			pos += toPointer.GetNormalized() * vel * dt;
	}
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
