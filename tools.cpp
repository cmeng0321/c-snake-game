
#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)
{
	system("title ̰����");//���ڱ���
	char cmd[30];
	//sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ����ռ�����ַ�
	//cmd="mode con cols=82 lines=32    ";
	//printf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ����ռ�����ַ�
	system("mode con cols=82 lines=32");//system(mode con cols=82 lines=32)���ô��ڿ�Ⱥ͸߶�
}

void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetCursorPosition(const int x, const int y)
{
	COORD position;//COORD��ʾһ���ַ��ڿ���̨��Ļ�ϵ�����
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	//���ÿ���̨���λ�ã�����1������̨���������2��COORD�ṹ��ŵ�����
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}