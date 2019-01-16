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

	bool DoBallCollision(Ball& ball);

	Rect GetRect() const;
	bool isDestroyed() const;
private:
	Rect rect;
	Color color;
	bool destroyed = false;
};