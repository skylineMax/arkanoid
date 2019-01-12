#pragma once
#include "Board.h"


class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
		void MoveBy(const Location& dloc);
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& dloc);
	Location GetNextHeadLocation(const Location& dloc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool isInTile(const Location& target) const;
private:

	static constexpr Color headColor = Colors::Red;
	static constexpr Color bodyColor = Colors::Gray;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};