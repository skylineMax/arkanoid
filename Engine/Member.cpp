#include "Member.h"

void Member::Init(Vec2 & _pos, Vec2 & _vel)
{
	pos = _pos;
	vel = _vel;
}

void Member::Update(Player& player, float dt)
{

	pos += vel * dt;

	const float right = pos.x + width;
	
	if (pos.x < 0)
	{
		pos.x = 0;
		vel.x = -vel.x;
	}
	else if (right >= (float)Graphics::ScreenWidth)
	{
		pos.x = (float)Graphics::ScreenWidth - width;
		vel.x = -vel.x;
	}
	

	const float bottom = pos.y + height;

	if (pos.y < 0)
	{
		pos.y = 0;
		vel.y = -vel.y;
	}
	else if (bottom >= (float)Graphics::ScreenHeight)
	{
		pos.y = (float)Graphics::ScreenHeight - height;
		vel.y = -vel.y;
	}

}

void Member::Draw(Graphics& gfx, Color c)
{
	gfx.DrawRect(int(pos.x), int(pos.y), int(width), int(height), c);
}

bool Member::TestCollision(const Player & player)
{
	const float playerRight = player.GetPos().x + player.GetWidth();
	const float playerBottom = player.GetPos().y + player.GetHeight();
	const float memberRight = pos.x + width;
	const float memberBottom = pos.y + height;

	return
		playerRight >= pos.x &&
		memberRight >= player.GetPos().x &&
		playerBottom >= pos.y &&
		memberBottom >= player.GetPos().y;
}

bool Member::GetCollision() const
{
	return isCollided;
}

void Member::SetCollision(bool collision)
{
	isCollided = collision;
}
