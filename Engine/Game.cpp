/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#define _USE_MATH_DEFINES

#include "MainWindow.h"
#include "Game.h"
#include <cmath>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

}

void Game::ComposeFrame()
{
	Draw(Graphics::ScreenWidth / 5, Graphics::ScreenHeight / 2, 150, 100, Colors::LightGray);
	Draw(2*Graphics::ScreenWidth / 5, Graphics::ScreenHeight / 2, 150, 100, Colors::LightGray);
	Draw(3*Graphics::ScreenWidth / 5, Graphics::ScreenHeight / 2, 150, 100, Colors::LightGray);
	Draw(4*Graphics::ScreenWidth / 5, Graphics::ScreenHeight / 2, 150, 100, Colors::LightGray);

}

void Game::Draw(int x, int y, int r, Color c)
{
	for (int i = y - r; i < y + r + 1; i++)
	{
		for (int j = x - r; j < x + r + 1; j++)
		{
			int x0 = x - j;
			int y0 = y - i;

			if (x*x + y * y <= r*r)
				gfx.PutPixel(j, i, c);
		}
	}
}