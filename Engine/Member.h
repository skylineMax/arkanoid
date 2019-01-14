#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Player.h"

class Member
{
public:
	void Init(Vec2& _pos, Vec2& _vel);
	void Update(Player& player, float dt);
	void Draw(Graphics& gfx, Color c);
	bool TestCollision(const Player& player);

	bool GetCollision() const;
	void SetCollision(bool collision);
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
	bool isCollided = false;
};
