#include "pch.h"
#include "RowBlock.h"
#include <iostream>

using namespace std;

void RowBlock::push_back(Block abc)
{
	row.push_back(abc);
}

string RowBlock::GetAllPixels()
{
	string result;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < row.size(); j++)
		{
			result += row[j].GetLine(i);
			result += " ";
		}
	return result;
}

RowBlock::RowBlock()
{

}


RowBlock::~RowBlock()
{

}
