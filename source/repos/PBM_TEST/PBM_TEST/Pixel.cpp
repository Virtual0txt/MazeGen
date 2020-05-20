#include "pch.h"
#include "Pixel.h"
#include <iostream>
#include <string>

using namespace std;

Pixel::Pixel() :
	R(0), G(0), B(0)
{
	
}

Pixel::Pixel(unsigned int Red, unsigned int Green, unsigned int Blue):
	R(Red), G(Green), B(Blue)
{

}

void Pixel::SetWhite()
{
	R = 255;
	G = 255;
	B = 255;
}

void Pixel::SetBlack()
{
	R = 0;
	G = 0;
	B = 0;
}

string Pixel::GetRGB()
{
	string result;
	result += to_string(R);
	result += " ";
	result += to_string(G);
	result += " ";
	result += to_string(B);
	return result;
}


Pixel::~Pixel()
{
}
