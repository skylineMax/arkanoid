#include "Member.h"

void Member::Init(Vec2 & _pos, Vec2 & _vel)
{
	pos = _pos;
	vel = _vel;
}

void Member::Update()
{
	pos += vel;

	const int right = pos.x + width;

	if (pos.x < 0)
	{
		pos.x = 0;
		vel.x = -vel.x;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		pos.x = Graphics::ScreenWidth - width;
		vel.x = -vel.x;
	}

	const int bottom = pos.y + height;

	if (pos.y < 0)
	{
		pos.y = 0;
		vel.y = -vel.y;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		pos.y = Graphics::ScreenHeight - height;
		vel.y = -vel.y;
	}

}

void Member::Draw(Graphics& gfx, Color c)
{
	gfx.DrawRect(pos.x, pos.y, width, height, c);
}

bool Member::TestCollision(const Player & player)
{
	const int playerRight = player.GetPos().x + player.GetWidth();
	const int playerBottom = player.GetPos().y + player.GetHeight();
	const int memberRight = pos.x + width;
	const int memberBottom = pos.y + height;

	return
		playerRight >= pos.x &&
		memberRight >= player.GetPos().x &&
		playerBottom >= pos.y &&
		memberBottom >= player.GetPos().y;
}
