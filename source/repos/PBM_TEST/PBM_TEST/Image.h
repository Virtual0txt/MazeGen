#pragma once
#include <iostream>
#include <fstream>
#include "Pixel.h"
#include "RowBlock.h"


class Image
{
	const int W;
	const int H;
	std::ofstream file;
	std::string name;

	vector <RowBlock> rows;

public:
	Image(std::string,int,int);
	void draw();
	void draw(std::vector <std::vector <int>> &maze);
	void save();
	~Image();
};

