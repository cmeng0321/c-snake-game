
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"

void Controller::Start()//开始界面
{
	
	SetWindowSize(41, 32);
	SetColor(2);
	StartInterface *start = new StartInterface();//动态分配一个StartInterface类start
	start->Action();//【开始动画】
	delete start;//释放内存空间

	SetCursorPosition(13, 26);
	std::cout << "Press any key to start";
	SetCursorPosition(13, 27);
	system("pause");
}

void Controller::Select()//选择界面
{
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          " << std::endl;
	SetCursorPosition(13, 27);
	std::cout << "                          " << std::endl;
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度：" << std::endl;
	SetCursorPosition(6, 22);
	std::cout << "（上下键选择，回车确认）" << std::endl;
	SetCursorPosition(27, 22);
	SetBackColor();//表示选中
	std::cout << "简单模式" << std::endl;
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "普通模式" << std::endl;
	SetCursorPosition(27, 26);
	std::cout << "困难模式" << std::endl;
	SetCursorPosition(27, 28);
	std::cout << "炼狱模式" << std::endl;
	SetCursorPosition(0, 31);
	score = 0;//初始化界面选项

	int ch;//键入值
	key = 1;//选中项，初始时为第一个
	bool flag = false;//是否键入Enter键标记，初始时为否
	while (ch = _getch())//conio.h头文件，控制台输入输出，定义了通过控制台进行数据输入和数据输出的函数
	{
		switch (ch)
		{
		case 72://UP 上方向键
			if (key > 1)
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "简单模式";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "炼狱模式";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN 下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";

					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "简单模式";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "炼狱模式";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";

					++key;
					break;
				}
			}
			break;

		case 13://Enter键
			flag = true;

			break;
		default://无效键
			break;
		}
		if (flag) break;//输入Enter键，跳出循环
		SetCursorPosition(0, 31);//光标置于左下角，避免光标闪烁影响
	}
	switch (key)//根据选项设置蛇的移动速度，speed越小，Sleep越小，蛇移动越快
	{
	case 1:
		speed = 135;
		break;
	case 2:
		speed = 100;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
}

void Controller::DrawGame()//游戏界面
{
	system("cls");
	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度：";
	SetCursorPosition(34, 5);
	switch (key)
	{
	case 1:
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "得分：";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "方向键移动";
	SetCursorPosition(33, 15);
	std::cout << "ESC键暂停";
}

void Controller::UpdateScore(const int& tmp)
{
	score += key * 10 * tmp;//游戏难度，传入参数tmp
}

void Controller::RewriteScore()//重绘分数
{
	SetCursorPosition(37, 8);
	SetColor(11);
	int bit = 0;
	int tmp = score;
	while(tmp != 0)
	{
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i != (bit-1); ++i)
	{
		std::cout << " ";
	}
	std::cout << score;
}

int Controller::Menu()//选择菜单
{
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "退出游戏";
	SetCursorPosition(0, 31);

	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72:
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "继续游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "退出游戏";
					--tmp_key;
					break;
				}

			}
			break;
		case 80:
			if (tmp_key < 3)

			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "继续游戏";
					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";
					++tmp_key;
					break;
				}

			}
			break;
		case 13:
			flag = true;
			break;
		default:
			break;
		}
		if (flag) break;
		SetCursorPosition(0, 31);
	}
	if (tmp_key == 1)
	{
		SetCursorPosition(32, 19);
		std::cout << "      ";
		SetCursorPosition(34, 21);
		std::cout << "        ";
		SetCursorPosition(34, 23);
		std::cout << "        ";
		SetCursorPosition(34, 25);
		std::cout << "        ";
	}
	return tmp_key;
}



int Controller::PlayGame()
{
	Snake *csnake = new Snake();
	Food *cfood = new Food();
	SetColor(6);
	csnake->InitSnake();
	srand((unsigned)time(NULL));//设置随机数种子，食物出现的位置将随机
	cfood->DrawFood(*csnake);

	while (csnake->OverEdge()&&csnake->HitItself())//若蛇未撞到，循环
	{
		if (!csnake->ChangeDirection())
		{
			int tmp = Menu();
			switch (tmp)
			{
			case 1:
				break;
			case 2:
				delete csnake;
				delete cfood;
				return 1;
				break;
			case 3:
				delete csnake;
				delete cfood;
				return 2;
				break;
			default:
				break;
			}
		}
		if (csnake->GetFood(*cfood))//吃到食物
		{
			csnake->Move();
			UpdateScore(1);//1为权重
			RewriteScore();
			cfood->DrawFood(*csnake);
		}
		else csnake->NormalMove();//蛇正常移动

		if (csnake->GetBigFood(*cfood))
		{
			csnake->Move();
			UpdateScore(cfood->GetProgressBar() / 5);
			RewriteScore();
		}
		if (cfood->GetBigFlag())
		{
			cfood->FlashBigFood();
		}
		Sleep(speed);
	}

	
}

void Controller::Game()//游戏一级循环
{
	Start();//开始界面
	while (true)//break跳出游戏循环
	{
		Select();
		system("cls");
		DrawGame();//游戏界面
		int tmp = PlayGame();//开始游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp
		if (tmp == 1) //重新开始游戏
		{
			system("cls");
			continue;
		}
		else if (tmp == 2)//退出游戏
		{
			break;
		}
		else { break; }
	}
}