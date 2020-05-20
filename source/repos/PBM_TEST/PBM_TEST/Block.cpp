#include "pch.h"
#include "Block.h"
#include <iostream>
#include "Pixel.h"

using namespace std;



Block::Block()
{	
}


Block::~Block()
{
}

string Block::GetLine(int no)
{
	string result;
	for (int i = 0; i < 5; i++)
	{
		result += tab[no][i].GetRGB();
		result += " ";
	}
	return result;
}

void Block::SetBlack()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tab[i][j].SetBlack();
}

void Block::SetWhite()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tab[i][j].SetWhite();
}

void Block::SetColor(int R, int G, int B)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			tab[i][j].R = R;
			tab[i][j].G = G;
			tab[i][j].B = B;
		}
}
