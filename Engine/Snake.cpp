#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & dloc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(dloc);
}

Location Snake::GetNextHeadLocation(const Location & dloc) const
{
	Location l(segments[0].GetLocation());
	l.Add(dloc);
	return l;
}

void Snake::Grow()
{

	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody();
		++nSegments;
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::isInTile(const Location & target) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLocation() == target)
			return true;
	}
	return false;
}


void Snake::Segment::InitHead(const Location & sloc)
{
	loc = sloc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

void Snake::Segment::MoveBy(const Location & dloc)
{
	assert(abs(dloc.x) + abs(dloc.y) == 1);
	loc.Add(dloc);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
