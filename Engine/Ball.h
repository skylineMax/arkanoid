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

	void ReboundX();
	void ReboundY();
	Rect GetRect() const;
	Vec2 GetPos() const;
	Vec2 GetVel() const;
	void SetDir(Vec2 _vel);
private:
	static constexpr float radius = 10.0f;
	Vec2 pos;
	Vec2 vel;
	Color color;
	
};