#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Rect.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle(const Vec2& _pos, float _halfWidth, float _halfHeight, Color _color);

	void Update(const Keyboard& kbd, float dt);
	void DoWallCollision(const Rect& walls);
	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx);
	void ResetCooldown();
private:
	Vec2 pos;
	float halfWidth;
	float halfHeight;
	Color color;
	float speed = 500.0f;
	bool cooldown = false;
};