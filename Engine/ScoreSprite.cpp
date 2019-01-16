#include "ScoreSprite.h"
#include <vector>
void ScoreSprite::ShowScore(Graphics& gfx, int score)
{
	int temp = score;
	std::vector<int> digits;
	while (temp != 0)
	{
		int mod = temp % 10;
		temp /= 10;
		digits.push_back(mod);
	}

	int size = (int)digits.size();

	if (size > 1)
	{
		int n = size;
		while (size != 0)
		{
			int offset = -25*(n - 1);
			switch (*(digits.end() - 1))
			{
			case 1:
				DrawOne(gfx, offset);
				break;
			case 2:
				DrawTwo(gfx, offset);
				break;
			case 3:
				DrawThree(gfx, offset);
				break;
			case 4:
				DrawFour(gfx, offset);
				break;
			case 5:
				DrawFive(gfx, offset);
				break;
			case 6:
				DrawSix(gfx, offset);
				break;
			case 7:
				DrawSeven(gfx, offset);
				break;
			case 8:
				DrawEight(gfx, offset);
				break;
			case 9:
				DrawNine(gfx, offset);
				break;
			case 0:
				DrawZero(gfx, offset);
				break;
			}
			digits.pop_back();
			--size;
			n = n - 2;
		}
	}
	else
	{
		switch (score) 
		{
			case 1:
				DrawOne(gfx, 0);
				break;
			case 2:
				DrawTwo(gfx, 0);
				break;
			case 3:
				DrawThree(gfx, 0);
				break;
			case 4:
				DrawFour(gfx, 0);
				break;
			case 5:
				DrawFive(gfx, 0);
				break;
			case 6:
				DrawSix(gfx, 0);
				break;
			case 7:
				DrawSeven(gfx, 0);
				break;
			case 8:
				DrawEight(gfx, 0);
				break;
			case 9:
				DrawNine(gfx, 0);
				break;
			case 0:
				DrawZero(gfx, 0);
				break;
		}
	}
}
void ScoreSprite::Draw(int _x1, int _y1,int _x2, int _y2,int _x3, int _y3,int _x4, int _y4,Graphics & gfx, int offset)
{
	int x0 = centerX - 20 + offset;
	int x1 = centerX + _x1 + offset;
	int x2 = centerX + _x2 + offset;
	int x3 = centerX + _x3 + offset;
	int x4 = centerX + _x4 + offset;

	int y0 = centerY - 35;
	int y1 = centerY + _y1;
	int y2 = centerY + _y2;
	int y3 = centerY + _y3;
	int y4 = centerY + _y4;

	for (int i = 0; i < 70; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			gfx.PutPixel(x0 + j, y0 + i, Colors::Gray);
		}
	}
	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			gfx.PutPixel(j, i, Colors::Black);
		}
	}
	for (int i = y3; i < y4; i++)
	{
		for (int j = x3; j < x4; j++)
		{
			gfx.PutPixel(j, i, Colors::Black);
		}
	}
}

void ScoreSprite::DrawOne(Graphics & gfx, int offset)
{
	gfx.DrawRectWithPoints(centerX + 10 + offset, centerY - 35, centerX + 20 + offset, centerY + 35, Colors::Gray);
	int x0 = centerX + 10 + offset;
	int y0 = centerY - 35;
	for (int k = 0; k < 10; k++)
	{
		for (int i = 0; i < 35; i++)
		{
			for (int j = 0; j < 35; j++)
			{
				if (i == j)
					gfx.PutPixel(x0 - j + k, y0 + i, Colors::Gray);
			}
		}
	}
	
}


void ScoreSprite::DrawTwo(Graphics & gfx, int offset)
{
	Draw(-20, -25, 10, -5, -10, 5, 20, 25, gfx, offset);
}

void ScoreSprite::DrawThree(Graphics & gfx, int offset)
{
	Draw(-20, -25, 10, -5, -20, 5, 10, 25, gfx, offset);
}

void ScoreSprite::DrawFour(Graphics & gfx, int offset)
{
	Draw(-10, -35, 10, -5, -20, 5, 10, 35, gfx, offset);
}

void ScoreSprite::DrawFive(Graphics & gfx, int offset)
{
	Draw(-10, -25, 20, -5, -20, 5, 10, 25, gfx, offset);
}

void ScoreSprite::DrawSix(Graphics & gfx, int offset)
{
	Draw(-10, -25, 20, -5, -10, 5, 10, 25, gfx, offset);
}

void ScoreSprite::DrawSeven(Graphics & gfx, int offset)
{
	Draw(-20, -25, 10, 5, -20, 5, 10, 35, gfx, offset);
}

void ScoreSprite::DrawEight(Graphics & gfx, int offset)
{
	Draw(-10, -25, 10, -5, -10, 5, 10, 25, gfx, offset);
}

void ScoreSprite::DrawNine(Graphics & gfx, int offset)
{
	Draw(-10, -25, 10, -5, -20, 5, 10, 25, gfx, offset);
}

void ScoreSprite::DrawZero(Graphics & gfx, int offset)
{
	Draw(-10, -25, 10, 0, -10, 0, 10, 25, gfx, offset);
}

