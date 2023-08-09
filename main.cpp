#include <cstring>
#include <string>
#include "Argumentator.hpp"
#include "SnakeGame.hpp"

int main(int argc, char *argv[])
{
	int sizeX, sizeY;
	float zoom = 2.f;
	sizeX = sizeY = 5;

	Argumentator::getIntValue(argc, argv, "-w", sizeX);
	Argumentator::getIntValue(argc, argv, "-h", sizeY);
	Argumentator::getFloatValue(argc, argv, "-z", zoom);

	SnakeGame game({sizeX, sizeY}, zoom);

	game.Run();

	return 0;

}
