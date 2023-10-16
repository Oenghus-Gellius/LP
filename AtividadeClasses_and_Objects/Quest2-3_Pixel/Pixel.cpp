#include "Pixel.h"

#include <iostream>

Pixel::Pixel(unsigned int coordX, unsigned int coordY)
{
	setCoordX(coordX);
	setCoordY(coordY);
}

unsigned Pixel::getX()
{
	return coordX;
}

unsigned Pixel::getY()
{
	return coordY;
}

void Pixel::setCoordX(unsigned int xCoord)
{
	this->coordX = xCoord;
}

void Pixel::setCoordY(unsigned yCoord)
{
	this->coordY = yCoord;
}

string Pixel::toString()
{
	return "A coordenada do Pixel.: (" + to_string(coordX) + "," + to_string(coordY) + ")";
}

void Pixel::printPixel()
{
	cout << toString() << endl;
}

