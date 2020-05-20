#include "pch.h"
#include "Maze.h"
#include <vector>
#include "pch.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <windows.h>
using namespace std;

Maze::Maze(int w, int h) :
	W(w), H(h)
{
	cout << "constructor\n";
	MazeGenerator();
}


Maze::~Maze()
{
}

void Maze::MazeGenerator()
{
	
	GenerateBlankMaze();
	GenerateFirstWalls();
	GenerateFirstExits();
	Field workPlace = GenerateFirstWorkplace();
	RecursiveMaze(workPlace);
}

void Maze::RecursiveMaze(Field workPlace)
{
	if (FieldEnoughBig(workPlace))
	{
		vector <Point> Exits;
		SearchForExitsInMaze(Exits, workPlace);
		GenerateNewWalls(Exits, workPlace);
		ShowMaze();
		
		Field workplaces[4];
		Point crossing = WallsCrossing(workPlace);

		GenerateNewExits(workPlace,crossing);
		GenerateNewWorkplaces(workplaces, workPlace ,crossing);
		for (int i = 0; i < 4; i++)
		{
			RecursiveMaze(workplaces[i]);
		}
	}
}

void Maze::ShowMaze()
{
	system("cls");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cout << maze[j][i];
		cout << endl;
	}
}

void Maze::GenerateBlankMaze()
{
	for (int j = 0; j < H; j++)
	{
		vector <int> arr;
		for (int i = 0; i < W; i++)
			arr.push_back(0);
		maze.push_back(arr);
	}
}

void Maze::GenerateFirstWalls()
{
	for (int i = 0; i < maze.size(); i++) //horizontal walls
	{
		maze[i][0] = 1;
		maze[i][maze.size() - 1] = 1;
	}
	for (int i = 0; i < maze[0].size(); i++) //veritcal walls
	{
		maze[0][i] = 1;
		maze[maze[0].size() - 1][i] = 1;
	}
}

void Maze::GenerateFirstExits()
{
	maze[1][0] = 0;
	maze[maze.size() - 2][maze[0].size() - 1] = 0;
}

Field Maze::GenerateFirstWorkplace()
{
	// LU left upper point, RB right bottom point
	Point LU, RB;
	Field workPlace;
	LU.x = 0;
	LU.y = 0;
	RB.x = W - 1;
	RB.y = H - 1;
	workPlace.LU = LU;
	workPlace.RB = RB;

	return workPlace;
}

bool Maze::FieldEnoughBig(Field &workPlace)
{
	int width = workPlace.RB.x - workPlace.LU.x+1;
	int height = workPlace.RB.y - workPlace.LU.y+1;

	if (width > 5 && height > 5)
		return 1;
	else
		return 0;
}

void Maze::SearchForExitsInMaze(std::vector<Point>& Exits, Field &workPlace)
{
	for (int i = workPlace.LU.x; i < workPlace.RB.x; i++) // search Horizontal walls
	{
		Point E;
		if (maze[i][workPlace.LU.y] == 0)
		{
			E.x = i;
			E.y = workPlace.LU.y;

			Exits.push_back(E);
		}

		if (maze[i][workPlace.RB.y] == 0)
		{
			E.x = i;
			E.y = workPlace.RB.y;

			Exits.push_back(E);
		}
	}

	for (int i = workPlace.LU.y; i < workPlace.RB.y; i++) // search Vertical walls
	{
		Point E;
		if (maze[workPlace.LU.x][i] == 0)
		{
			E.x = workPlace.LU.x;
			E.y = i;

			Exits.push_back(E);
		}

		if (maze[workPlace.RB.x][i] == 0)
		{
			E.x = workPlace.RB.x;
			E.y = i;

			Exits.push_back(E);
		}
	}
}

void Maze::GenerateNewWalls(std::vector <Point> &Exits, Field &workPlace)
{
	int x;
	int y;
	int width = workPlace.RB.x - workPlace.LU.x+1;
	int height = workPlace.RB.y - workPlace.LU.y+1;


	bool test;
	bool specialy = false;
	bool specialx = false;
	do {
		test = false;
		x = randomNumber(workPlace.LU.x + 2, workPlace.RB.x - 2);
			for (int i = 0; i < Exits.size(); i++)
			{
				if (Exits[i].x == x)
				{
					test = true;
					if (Exits[i].x == (workPlace.LU.x + workPlace.RB.x) / 2 && width == 3)
					{
						test = false;
						specialx = true;
					}
				}
			}
	} while (test);

	do {
		test = false;
		y = randomNumber(workPlace.LU.y + 2, workPlace.RB.y - 2);
			for (int i = 0; i < Exits.size(); i++)
			{
				if (Exits[i].y == y)
				{
					test = true;
					if (Exits[i].y == (workPlace.LU.y + workPlace.RB.y) / 2 && height == 3)
					{
						test = false;
						specialy = true;
					}
				}
			}
	} while (test);
	
	for (int i = workPlace.LU.y; i < workPlace.RB.y; i++)
	{
		maze[x][i] = 1;
	}
	for (int i = workPlace.LU.x; i < workPlace.RB.x; i++)
	{
		maze[i][y] = 1;
	}
}

void Maze::GenerateNewExits(Field &workPlace, Point crossing)
{
	int width = workPlace.RB.x - workPlace.LU.x + 1;
	int height = workPlace.RB.y - workPlace.LU.y + 1;
	Point exits[4];
	Point exit;
	int x;
	int y;

	x = randomNumber(workPlace.LU.x + 1, crossing.x - 1);
	exit.y = crossing.y;
	exit.x = x;
	exits[0] = exit;

	x = randomNumber(crossing.x + 1, workPlace.RB.x - 1);
	exit.x = x;
	exits[1] = exit;

	y = randomNumber(workPlace.LU.y + 1, crossing.y - 1);
	exit.x = crossing.x;
	exit.y = y;
	exits[2] = exit;

	y = randomNumber(crossing.y + 1, workPlace.RB.y - 1);
	exit.y = y;
	exits[3] = exit;

	for (int i = 0; i < 4; i++)
	{
		maze[exits[i].x][exits[i].y] = 0;
	}
	int z = randomNumber(0, 3);
	maze[exits[z].x][exits[z].y] = 1;

}

void Maze::GenerateNewWorkplaces(Field workPlaces[4], Field orginal, Point crossing)
{

	for (int i = 0; i < 4; i++)
	{
		Point newLU,newRB;
		switch (i)
		{
		case 0:
			workPlaces[i].LU = orginal.LU;
			workPlaces[i].RB = crossing;

			break;
		case 1:
			
			newLU.y = orginal.LU.y;
			newLU.x = crossing.x;

			newRB.y = crossing.y;
			newRB.x = orginal.RB.x;

			workPlaces[i].LU = newLU;
			workPlaces[i].RB = newRB;

			break;
		case 2:
			newLU.y = crossing.y;
			newLU.x = orginal.LU.x;

			newRB.y = orginal.RB.y;
			newRB.x = crossing.x;

			workPlaces[i].LU = newLU;
			workPlaces[i].RB = newRB;
			break;
		case 3:
			workPlaces[i].LU = crossing;
			workPlaces[i].RB = orginal.RB;
			break;
		}
		
	}
}

Point Maze::WallsCrossing(Field &workPlace)
{
	int wallY;
	int wallX;

	wallY = FindHorizontalWall(workPlace);
	wallX = FindVerticalWall(workPlace);

	Point crossing;
	crossing.x = wallX;
	crossing.y = wallY;

	return crossing;
}

inline int Maze::FindHorizontalWall(Field &workPlace)
{
	for (int i = workPlace.LU.y + 1; i < workPlace.RB.y; i++)
	{
		if (maze[workPlace.LU.x + 1][i] == 1)
		{
			return i;
		}
	}
	return 0;
}

inline int Maze::FindVerticalWall(Field &workPlace)
{
	for (int i = workPlace.LU.x + 1; i < workPlace.RB.x; i++)
	{
		if (maze[i][workPlace.LU.y + 1] == 1)
		{
			return i;
		}
	}
	return 0;
}

int Maze::randomNumber(int from, int to)
{
	srand(time(0));
	int x;
	if (from == to) return from;
	if (to - from + 1 != 0)
		x = rand() % (to - from + 1) + from;
	else
		x = 0;

	return x;
}
