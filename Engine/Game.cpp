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
	rng(rd()),
	xDist(0.0f, 770.0f),
	yDist(0.0f, 570.0f),
	paddle(Vec2(400.0f, 550.0f), 30.0f, 5.0f, Colors::White),
	walls(100.0f, 20.0f, 700, (float)gfx.ScreenHeight),
	ball(Vec2(400.0f , 300.0f), Vec2(-300.0f, 300.0f), Colors::Red)
{
	int i = 0;
	float width = 40.0f;
	float height = 20.0f;
	Vec2 topLeft(100.0f, 100.0f);
	Color colors[rows] = {Colors::Cyan, Colors::Green, Colors::Magenta, Colors::Blue, Colors::Yellow};
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < columns; x++)
		{
			bricks[i] = Brick(
				Rect(topLeft + Vec2(x * width , y * height), width, height), 
				colors[y]);
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
	if (isStarted && !isGameOver)
	{
	/* Updating */
	ball.Update(dt);
	paddle.Update(wnd.kbd, dt);

	/* Collisions*/
	bool collisionHappend = false;
	float oldSq;
	int oldIdx;
	for (int i = 0; i < n; i++)
	{
		if (bricks[i].CheckBallCollision(ball))
		{
			const float currentSq = (ball.GetPos() - bricks[i].GetPos()).GetLengthSq();

			if (collisionHappend)
			{
				if (currentSq < oldSq)
				{
					oldSq = currentSq;
					oldIdx = i;
				}
			}
			else 
			{
				oldSq = currentSq;
				oldIdx = i;
				collisionHappend = true;
			}
		}
	}
	if (collisionHappend)
	{
		paddle.ResetCooldown();
		bricks[oldIdx].DoBallCollision(ball);
		Score++;
	}
	
	paddle.DoBallCollision(ball);

	if (ball.DoWallCollision(walls))
		paddle.ResetCooldown();

	paddle.DoWallCollision(walls);
	}
	else {
		if(wnd.kbd.KeyIsPressed(VK_RETURN))
			isStarted = true;
	}
}


void Game::ComposeFrame()
{


	paddle.Draw(gfx);
	if (!ball.isDead())
	{
		ball.Draw(gfx);
	}
	else
	{
		score.ShowScore(gfx, Score);
		isGameOver = true;
	}

	for (int i = 0; i < n; i++)
	{
		if(!bricks[i].isDestroyed())
			bricks[i].Draw(gfx);
	}
	gfx.DrawRectWithPoints(80,0,720,20,Colors::Blue);
	gfx.DrawRectWithPoints(80,20,100,gfx.ScreenHeight,Colors::Blue);
	gfx.DrawRectWithPoints(700,20,720, gfx.ScreenHeight,Colors::Blue);
}