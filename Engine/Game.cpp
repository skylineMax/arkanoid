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
#include "Vec2.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	player(Vec2(400,400), Vec2(3,3)),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570)
{
	std::uniform_int_distribution<int> vDist(-1, 1);

	for (int i = 0; i < nMembers; i++)
	{
		members[i].Init( Vec2(xDist(rng), yDist(rng)), Vec2(vDist(rng), vDist(rng)) );
	}
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
	if (!isGameOver)
	{
		player.Update(wnd.kbd);
		player.ClampToScreen();
		for (int i = 0; i < nMembers; i++)
		{
			members[i].Update();
			if(members[i].TestCollision(player))
				isGameOver = true;
		}
	}
}


void Game::ComposeFrame()
{
	for (int i = 0; i < nMembers; i++)
	{
		members[i].Draw(gfx, Colors::Cyan);
	}

	player.Draw(gfx, Colors::Red);
}