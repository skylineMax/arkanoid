#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& center, const Vec2& _vel, Color _color);
	void Update(float dt);
	void Draw(Graphics& gfx);
	bool DoWallCollision(const Rect& walls);
	void ResetBall();

	void ReboundX();
	void ReboundY();
	Rect GetRect() const;
	Vec2 GetPos() const;
	Vec2 GetVel() const;
	void SetDir(const Vec2& _vel);
	bool isDead() const;
private:
	static constexpr float radius = 5.0f;
	static constexpr float speed = 400.0f;
	Vec2 pos;
	Vec2 vel;
	Color color;
	bool dead = false;
	
};