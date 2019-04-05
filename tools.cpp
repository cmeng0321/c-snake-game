
#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)
{
	system("title 贪吃蛇");//窗口标题
	char cmd[30];
	//sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个■占两个字符
	//cmd="mode con cols=82 lines=32    ";
	//printf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个■占两个字符
	system("mode con cols=82 lines=32");//system(mode con cols=82 lines=32)设置窗口宽度和高度
}

void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetCursorPosition(const int x, const int y)
{
	COORD position;//COORD表示一个字符在控制台屏幕上的坐标
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	//设置控制台光标位置：参数1：控制台句柄；参数2：COORD结构存放的坐标
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}