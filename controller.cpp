
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"

void Controller::Start()//��ʼ����
{
	
	SetWindowSize(41, 32);
	SetColor(2);
	StartInterface *start = new StartInterface();//��̬����һ��StartInterface��start
	start->Action();//����ʼ������
	delete start;//�ͷ��ڴ�ռ�

	SetCursorPosition(13, 26);
	std::cout << "Press any key to start";
	SetCursorPosition(13, 27);
	system("pause");
}

void Controller::Select()//ѡ�����
{
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          " << std::endl;
	SetCursorPosition(13, 27);
	std::cout << "                          " << std::endl;
	SetCursorPosition(6, 21);
	std::cout << "��ѡ����Ϸ�Ѷȣ�" << std::endl;
	SetCursorPosition(6, 22);
	std::cout << "�����¼�ѡ�񣬻س�ȷ�ϣ�" << std::endl;
	SetCursorPosition(27, 22);
	SetBackColor();//��ʾѡ��
	std::cout << "��ģʽ" << std::endl;
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "��ͨģʽ" << std::endl;
	SetCursorPosition(27, 26);
	std::cout << "����ģʽ" << std::endl;
	SetCursorPosition(27, 28);
	std::cout << "����ģʽ" << std::endl;
	SetCursorPosition(0, 31);
	score = 0;//��ʼ������ѡ��

	int ch;//����ֵ
	key = 1;//ѡ�����ʼʱΪ��һ��
	bool flag = false;//�Ƿ����Enter����ǣ���ʼʱΪ��
	while (ch = _getch())//conio.hͷ�ļ�������̨���������������ͨ������̨���������������������ĺ���
	{
		switch (ch)
		{
		case 72://UP �Ϸ����
			if (key > 1)
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "��ģʽ";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "����ģʽ";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN �·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨģʽ";

					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "��ģʽ";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����ģʽ";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "��ͨģʽ";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "����ģʽ";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "����ģʽ";

					++key;
					break;
				}
			}
			break;

		case 13://Enter��
			flag = true;

			break;
		default://��Ч��
			break;
		}
		if (flag) break;//����Enter��������ѭ��
		SetCursorPosition(0, 31);//����������½ǣ���������˸Ӱ��
	}
	switch (key)//����ѡ�������ߵ��ƶ��ٶȣ�speedԽС��SleepԽС�����ƶ�Խ��
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

void Controller::DrawGame()//��Ϸ����
{
	system("cls");
	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "̰����";
	SetCursorPosition(31, 4);
	std::cout << "�Ѷȣ�";
	SetCursorPosition(34, 5);
	switch (key)
	{
	case 1:
		std::cout << "��ģʽ";
		break;
	case 2:
		std::cout << "��ͨģʽ";
		break;
	case 3:
		std::cout << "����ģʽ";
		break;
	case 4:
		std::cout << "����ģʽ";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "�÷֣�";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "������ƶ�";
	SetCursorPosition(33, 15);
	std::cout << "ESC����ͣ";
}

void Controller::UpdateScore(const int& tmp)
{
	score += key * 10 * tmp;//��Ϸ�Ѷȣ��������tmp
}

void Controller::RewriteScore()//�ػ����
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

int Controller::Menu()//ѡ��˵�
{
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "���¿�ʼ";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "�˳���Ϸ";
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
					std::cout << "������Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "�˳���Ϸ";
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
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "������Ϸ";
					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";
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
	srand((unsigned)time(NULL));//������������ӣ�ʳ����ֵ�λ�ý����
	cfood->DrawFood(*csnake);

	while (csnake->OverEdge()&&csnake->HitItself())//����δײ����ѭ��
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
		if (csnake->GetFood(*cfood))//�Ե�ʳ��
		{
			csnake->Move();
			UpdateScore(1);//1ΪȨ��
			RewriteScore();
			cfood->DrawFood(*csnake);
		}
		else csnake->NormalMove();//�������ƶ�

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

void Controller::Game()//��Ϸһ��ѭ��
{
	Start();//��ʼ����
	while (true)//break������Ϸѭ��
	{
		Select();
		system("cls");
		DrawGame();//��Ϸ����
		int tmp = PlayGame();//��ʼ��Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
		if (tmp == 1) //���¿�ʼ��Ϸ
		{
			system("cls");
			continue;
		}
		else if (tmp == 2)//�˳���Ϸ
		{
			break;
		}
		else { break; }
	}
}