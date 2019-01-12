#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{

}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x <= Graphics::ScreenWidth);
	assert(loc.y >= 0);
	assert(loc.y <= Graphics::ScreenHeight);

	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::isInsideBoard(const Location & loc) const
{
	return loc.x >= 0 && loc.x <= width && loc.y >= 0 && loc.y <= height;
}
