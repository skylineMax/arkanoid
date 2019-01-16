#pragma once
#include "Graphics.h"
#include "Vec2.h"

class ScoreSprite
{
public:
	ScoreSprite() = default;
	void ShowScore(Graphics& gfx, int score);
	void Draw(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4, Graphics& gfx, int offset);
	void DrawOne(Graphics& gfx, int offset);
	void DrawTwo(Graphics& gfx, int offset);
	void DrawThree(Graphics& gfx, int offset);
	void DrawFour(Graphics& gfx, int offset);
	void DrawFive(Graphics& gfx, int offset);
	void DrawSix(Graphics& gfx, int offset);
	void DrawSeven(Graphics& gfx, int offset);
	void DrawEight(Graphics& gfx, int offset);
	void DrawNine(Graphics& gfx, int offset);
	void DrawZero(Graphics& gfx, int offset);
public:
	int centerX = Graphics::ScreenWidth / 2;
	int centerY = Graphics::ScreenHeight / 2;
};
