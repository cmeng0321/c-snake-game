#include "food.h"
#include "tools.h"
#include <cstdlib>//实现stdlib.h中的所有功能
#include <iostream>

void Food::DrawFood(Snake& csnake)
{
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snake)
		{
			if ((point.GetX() == tmp_x && point.GetY()
 == tmp_y) || (tmp_x == big_x && tmp_y == big_y))
			{
				flag = true;
				break;
			}
		}
		if (flag) continue;
		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x, y);
		SetColor(13);
		std::cout << "★";
		++cnt;
		cnt %= 5 ;
		if (cnt == 0)
		{
			DrawBigFood(csnake);
		}
		break;
	}
}

void Food::DrawBigFood(Snake& csnake)
{
	return;
}
 
int Food::GetCnt()
{
	return cnt;

}

void Food::FlashBigFood()
{

}

bool Food::GetBigFlag()
{
	return big_flag;
}

int Food::GetProgressBar()
{
	return progress_bar;
}
