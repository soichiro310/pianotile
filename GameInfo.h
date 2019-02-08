#pragma once
#include <GL/glut.h>
#include <string>

class GameInfo
{
public:
	GameInfo();
	~GameInfo();

	void DrawInfo(double hispeed, int score, int combo);

private:
	void _DrawInfo(double x, double y, std::string str);
};

