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
	ball(Vec2(790.0f, 375.0f), Vec2(-100.0f, 100.0f), Colors::Red),
	brick(Rect(Vec2(400.0f, 400.0f), Vec2(450.0f, 450.0f)), Colors::Cyan),
	rng(rd()),
	xDist(0.0f, 770.0f),
	yDist(0.0f, 570.0f)
{
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
	ball.Update(dt);
	paddle.Update(wnd.kbd, dt);
	
	brick.DoBallCollision(ball);
	paddle.DoBallCollision(ball);
	if (ball.DoWallCollision(walls))
		paddle.ResetCooldown();

	paddle.DoWallCollision(walls);
}


void Game::ComposeFrame()
{

	paddle.Draw(gfx);
	ball.Draw(gfx);
	if(!brick.isDestroyed())
		brick.Draw(gfx);
}