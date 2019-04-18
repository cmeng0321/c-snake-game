#include "startinterface.h"
#include <windows.h>

void StartInterface::PrintFirst()//蛇从左边出现到完全出现
{
	for (auto& point : startsnake)
	{
		point.Print();
		Sleep(speed);
	}
}

void StartInterface::PrintSecond()//蛇从左向右移动
{
	for (int i=10;i!=40;++i)//蛇头从10移到40
	{
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startsnake.emplace_back(Point(i, j));
		startsnake.back().Print();
		startsnake.front().Clear();
		startsnake.pop_front();
		Sleep(speed);
	}
}

void StartInterface::PrintThird()//蛇从右边消失
{
	while (!startsnake.empty() || textsnake.back().GetX() < 33)//当蛇还没有消失或文字没有移动到指定位置
	{
		if (!startsnake.empty())
		{
			startsnake.front().Clear();
			startsnake.pop_front();
		}
		ClearText();//清除已有的文字
		PrintText();//绘制更新位置后的文字
		Sleep(speed);
	}
}

void StartInterface::PrintText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Print();
	}
}

void StartInterface::ClearText()
{
	for (auto& point : textsnake)//清除的同时将文字整体向右移动一格
	{
		if (point.GetX() >= 0)
			point.Clear();
		point.ChangePosition(point.GetX() + 1, point.GetY());
	}
}

void StartInterface::Action()//开始游戏
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}