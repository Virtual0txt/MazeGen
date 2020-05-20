#pragma once
#include <vector>
#include "pch.h"

class Maze
{
public:
	std::vector<std::vector<int>> maze;

	Maze(int w, int h);
	~Maze();

private:
	const int W;
	const int H;
	void MazeGenerator();
		void GenerateBlankMaze();
		void GenerateFirstWalls();
		void GenerateFirstExits();
		Field GenerateFirstWorkplace();
			

		void RecursiveMaze(Field workPlace);
			bool FieldEnoughBig(Field &workPlace);
				void ShowMaze();
				void SearchForExitsInMaze( std::vector <Point> &Exits, Field &workPlace);
				void GenerateNewWalls(std::vector <Point> &Exits, Field &workPlace);
				void GenerateNewExits(Field &workPlace,Point crossing);
				void GenerateNewWorkplaces(Field workPlaces[4], Field orginal, Point crossing);
					Point WallsCrossing(Field &workPlace);
					inline int FindHorizontalWall(Field &workPlace);
					inline int FindVerticalWall(Field &workPlace);
					int randomNumber(int from, int to);
};

