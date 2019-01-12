#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& lic, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool isInsideBoard(const Location& loc) const;

private:
	static constexpr int dimension = 20;
	static constexpr int width = 10;
	static constexpr int height = 10;

	Graphics& gfx;

};