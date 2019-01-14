#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"


class Player
{
public:
	Player(Vec2& _pos, Vec2& _vel);
	void Update(const Keyboard& kbd);
	void ClampToScreen();
	void Draw(Graphics& gfx, Color c);

	Vec2 GetPos() const;
	Vec2 GetVel() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	Vec2 pos;
	Vec2 vel;
	static constexpr int width = 20;
	static constexpr int height = 20;

};