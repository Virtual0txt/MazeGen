#include "pch.h"
#include <iostream>
#include <fstream>
#include "Pixel.h"
#include <cstdlib>
#include <time.h>

using namespace std;
/*/
ostream & operator<<(ofstream & plik, Pixel &abc)
{
	plik << abc.R << " " << abc.G << " " << abc.B;
	return plik;
}
/*/


void MazeGenerator(vector <vector <int>> &maze, int H, int W)
{
	GenerateBlankMaze(maze, H, W);
	GenerateFirstWalls(maze);
	GenerateFirstExits(maze);
	Field workPlace = GenerateFirstWorkplace(H, W);

	//RecursiveMaze(maze, workPlace); 
}

void RecursiveMaze(vector <vector <int>> &maze, Field workPlace)
{
	if (FieldEnoughBig(workPlace))
	{
		vector <Point> Exits;
		SearchForExitsInMaze(maze, Exits, workPlace);
		GenerateNewWalls(maze, Exits, workPlace);

		Field workplaces[4];
		Point crossing = WallsCrossing(maze, workPlace);
		GenerateNewExits(maze, workPlace);
		GenerateNewWorkplaces(maze, workplaces, workPlace);
		for (int i = 0; i < 4; i++)
		{
			RecursiveMaze(maze, workplaces[i]);
		}
	}
}

void GenerateBlankMaze(std::vector <std::vector <int>> &maze, int H, int W)
{
	for (int j = 0; j < H; j++)
	{
		vector <int> arr;
		for (int i = 0; i < W; i++)
			arr.push_back(0);
		maze.push_back(arr);
	}
}

void GenerateFirstWalls(vector <vector <int>> &maze)
{
	for (int i = 0; i < maze.size(); i++) //horizontal walls
	{
		maze[i][0] = 1;
		maze[i][maze.size()-1] = 1;
	}
	for (int i = 0; i < maze[0].size(); i++) //veritcal walls
	{
		maze[0][i] = 1;
		maze[maze[0].size()-1][i] = 1;
	}
}

void GenerateFirstExits(std::vector <std::vector <int>> &maze)
{
	maze[1][0] = 0;
	maze[maze.size() - 2][maze[0].size() - 1] = 0;
}

Field GenerateFirstWorkplace(int H, int W)
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

bool FieldEnoughBig(Field &workPlace)
{
	int width = workPlace.RB.x - workPlace.LU.x;
	int height = workPlace.RB.y - workPlace.LU.y;

	if (width >= 3 && height >= 3)
		return 1;
	else
		return 0;
}

void SearchForExitsInMaze(std::vector<std::vector<int>>& maze, std::vector<Point>& Exits, Field &workPlace)
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

void GenerateNewWalls(std::vector <std::vector <int>> &maze, std::vector <Point> &Exits, Field &workPlace)
{
	srand(time(0));

}



void GenerateNewExits(std::vector <std::vector <int>> &maze, Field &workPlace)
{


	srand(time(0));

}

void GenerateNewWorkplaces(std::vector<std::vector<int>>& maze, Field workPlaces[4], Field orginal)
{


}

Point WallsCrossing(std::vector <std::vector <int>> &maze, Field &workPlace)
{
	int wallY;
	int wallX;

	wallY = FindHorizontalWall(maze, workPlace);
	wallX = FindVerticalWall(maze, workPlace);

	Point crossing;
	crossing.x = wallX;
	crossing.y = wallY;

	return crossing;
}

inline int FindHorizontalWall(std::vector <std::vector <int>> &maze, Field &workPlace)
{
	for (int i = workPlace.LU.y + 1 ; i < workPlace.RB.y ; i++)
	{
		if (maze[workPlace.LU.x + 1][i] == 1)
		{
			return i;
		}
	}
}

inline int FindVerticalWall(std::vector <std::vector <int>> &maze, Field &workPlace)
{
	for (int i = workPlace.LU.x+1 ; i < workPlace.RB.x ; i++)
	{
		if (maze[i][workPlace.LU.y + 1] == 1)
		{
			return i;
		}
	}
}