#include <cstring>
#include <string>
#include "Argumentator.hpp"
#include "SnakeGame.hpp"

int main(int argc, char *argv[])
{
	int sizeX, sizeY;
	float zoom, speed;
	zoom = speed = 2.f;
	sizeX = sizeY = 5;

	Argumentator::getIntValue(argc, argv, "-w", sizeX);
	Argumentator::getIntValue(argc, argv, "-h", sizeY);
	Argumentator::getFloatValue(argc, argv, "-z", zoom);
	Argumentator::getFloatValue(argc, argv, "-s", speed);

	SnakeGame game({sizeX, sizeY}, zoom, speed);

	game.Run();

	return 0;

}
