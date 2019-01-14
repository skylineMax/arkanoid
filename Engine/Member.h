#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Player.h"

class Member
{
public:
	void Init(Vec2& _pos, Vec2& _vel);
	void Update();
	void Draw(Graphics& gfx, Color c);
	bool TestCollision(const Player& player);
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr int width = 20;
	static constexpr int height = 20;
};
