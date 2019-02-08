#include "GameInfo.h"

GameInfo::GameInfo()
{
}


GameInfo::~GameInfo()
{
}

void GameInfo::_DrawInfo(double x, double y, std::string str) {
	glRasterPos2f(x, y);

	for (int i = 0; i < str.size(); ++i) {
		char ic = str[i];
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ic);
	}
}

void GameInfo::DrawInfo(double hispeed, int score, int combo) {
	_DrawInfo(-0.950, -0.85, "HISPEED: " + std::to_string(hispeed));
	_DrawInfo(-0.875, -0.90, "SCORE: "   + std::to_string(score));
	_DrawInfo(-0.875, -0.95, "COMBO: "   + std::to_string(combo) + " / 1000");
}

