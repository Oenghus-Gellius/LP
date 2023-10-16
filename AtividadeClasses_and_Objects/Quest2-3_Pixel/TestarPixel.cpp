#include "TestarPixel.h"

#include <iostream>

int TestarPixel::testarPixel()
{
	Pixel pixelA;

	Pixel pixelB(1300, 400);

	pixelA.printPixel();
	pixelB.printPixel();

	cout << "Coordenada X: " << pixelB.getX() << endl;
	cout << "Coordenada Y: " << pixelB.getY() << endl;

	pixelA.setCoordX(99);
	pixelA.setCoordY(511);
	pixelA.printPixel();


	return EXIT_SUCCESS;
}

int main() {

	return TestarPixel().testarPixel();
}
