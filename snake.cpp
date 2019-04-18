#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>

void Snake::InitSnake()//��ʼ����
{
	for (auto&point : snake) point.PrintCircular();
}

bool Snake::OverEdge()
{
	return snake.back().GetX() < 30 && snake.back().GetY() < 30 && snake.back().GetX()>1 && snake.back().GetY() > 1;
}

bool Snake::HitItself()
{
	std::deque<Point>::size_type cnt = 1;
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//����ߵ�ͷ����
	for(auto& point : snake)
	{
		if (!(point == *head)) ++cnt;
		else break;
	}
	delete head;
	if (cnt == snake.size()) return true;

	else return false;
}

bool Snake::ChangeDirection()
{
	char ch;
	if (_kbhit())//kbhit��������ֵΪ��������conio.h����
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (direction != Direction::DOWN)//�뵱ǰ�˶������෴����Ч
					direction = Direction::UP;
				break;
			case 80:
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
		case 27://ESC
			return false;
		default:
			return true;
		}
	}
	return true;
}

bool Snake::GetFood(const Food& cfood)
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else return false;
}

bool Snake::GetBigFood(Food& cfood)
{
	return false;
}

void Snake::Move()//������
{
	switch (direction)
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX()-1, snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX()+1, snake.back().GetY()));
		break;
	default:
		break;
	}
	SetColor(14);
	snake.back().PrintCircular();
}

void Snake::NormalMove()
{
	Move();
	snake.front().Clear();
	snake.pop_front();
}