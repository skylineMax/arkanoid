#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"


class Player
{
public:
	Player(Vec2& _pos);
	void Update(const Keyboard& kbd, float dt);
	void Update(const Mouse& mouse, float dt);
	void ClampToScreen();
	void Draw(Graphics& gfx, Color c);

	Vec2 GetPos() const;
	Vec2 GetVel() const;
	float GetWidth() const;
	float GetHeight() const;

private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float speed = 3.0f * 60.0f;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;

};