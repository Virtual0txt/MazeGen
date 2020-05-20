#pragma once
#include "Pixel.h"

class Block
{
public:
	Pixel tab[5][5];
	std::string GetLine(int no);
	Block();
	~Block();
	void SetBlack();
	void SetWhite();
	void SetColor(int R, int G, int B);
};

