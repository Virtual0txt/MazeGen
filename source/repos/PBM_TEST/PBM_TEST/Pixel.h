#pragma once
#include <fstream>

class Pixel
{
public:
	unsigned int R;
	unsigned int G;
	unsigned int B;

	Pixel();
	Pixel(unsigned int Red, unsigned int Green, unsigned int Blue);
	void SetWhite();
	void SetBlack();
	std::string GetRGB();
	~Pixel();
};

