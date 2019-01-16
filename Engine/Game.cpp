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
	paddle(Vec2(750.0f,500.0f), 50.0f, 20.0f, Colors::White),
	walls(0.0f, 0.0f, (float)gfx.ScreenWidth, (float)gfx.ScreenHeight),
	ball(Vec2(790.0f, 375.0f), Vec2(-400.0f, 400.0f), Colors::Red),
	rng(rd()),
	xDist(0.0f, 770.0f),
	yDist(0.0f, 570.0f)
{
	int i = 0;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < columns; x++)
		{
			bricks[i] = Brick(Rect(x * 20.0f, y * 10.0f, x * 40.0f + 20.0f, y * 20.0f + 10.0f), Colors::Cyan);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	/* Updating */
	ball.Update(dt);
	paddle.Update(wnd.kbd, dt);

	/* Collisions*/

	for (int i = 0; i < n; i++)
	{
		if (bricks[i].CheckBallCollision(ball))
			bricks[i].DoBallCollision(ball);
	}
	
	paddle.DoBallCollision(ball);

	if (ball.DoWallCollision(walls))
		paddle.ResetCooldown();

	paddle.DoWallCollision(walls);
}


void Game::ComposeFrame()
{

	paddle.Draw(gfx);
	ball.Draw(gfx);

	for (int i = 0; i < n; i++)
	{
		bricks[i].Draw(gfx);
	}
}