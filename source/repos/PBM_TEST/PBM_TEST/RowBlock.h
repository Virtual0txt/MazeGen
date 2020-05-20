#pragma once
#include "Block.h"
#include <vector>
class RowBlock
{
public:
	std::vector <Block> row;
	void push_back(Block abc);
	std::string GetAllPixels();
	RowBlock();
	~RowBlock();
};

