#include "pch.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include "pch.h"
#include "Block.h"

using namespace std;

Image::Image(string n, int w, int h):
	name(n), W(w), H(h)
{
}

void Image::draw()
{
	srand(time(0));
	for (int i = 0; i < H/5 ; i++)
	{
		RowBlock bb;
		for (int j = 0; j < W/5 ; j++)
		{
			Block abc;

			if (rand()%10==1)
				abc.SetBlack();
			else
				abc.SetWhite();
			
			bb.push_back(abc);
		}
		rows.push_back(bb);
	}
}

void Image::draw(vector <vector <int>> &maze)
{
	for (int j = 0; j < H / 5; j++)
	{
		RowBlock bb;
		for (int i = 0; i < W / 5; i++)
		{
			Block abc;
			switch (maze[i][j])
			{
			case 0:
				abc.SetWhite();
				break;
			case 1:
				abc.SetBlack();
				break;
			case 2:
				abc.SetColor(255, 0, 0);
				break;
			default:
				abc.SetColor(0, 0, 255);
			}

			bb.push_back(abc);
		}
		rows.push_back(bb);
	}
}

void Image::save()
{
	file.open(name.c_str());
	file << "P3 #" << name.c_str() << " "<<endl;
	file << W << " " << H << endl;
	file << "255 ";
	for (int i = 0; i < H/5; i++)
	{
		file << rows[i].GetAllPixels().c_str();
		file << endl;
	}
			
	file.close();
}

Image::~Image()
{

}