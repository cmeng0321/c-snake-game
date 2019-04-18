#include "map.h"
#include <Windows.h>

void Map::PrintInitmap()
{
	system("cls");
	for (auto& point : initmap)
	{
		point.Print();
		Sleep(10);
	}
}