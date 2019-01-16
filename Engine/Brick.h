#pragma once

#include "Rect.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Rect& _rect, Color _color);
	void Draw(Graphics& gfx);
	bool CheckBallCollision(const Ball& ball) const;
	void DoBallCollision(Ball& ball);

	//Rect GetRect() const;
	bool isDestroyed() const;
private:
	static constexpr float padding = 1;
	Rect brick;
	Vec2 pos;
	Color color;
	bool destroyed = false;
};