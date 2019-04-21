#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
	Controller():speed(200),key(1),score(0){}
	void Start();
	void Select();
	void DrawGame();
	int PlayGame();
	void Game();
	int GameOver();
	void UpdateScore(const int&);
	void RewriteScore();
	int Menu();

private:
	int speed;
	int key;
	int score;
};
#endif
