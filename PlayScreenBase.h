#pragma once
#include <GL/glut.h>

class PlayScreenBase
{
public:
	PlayScreenBase();
	~PlayScreenBase();
	void DrawScreen();

private:
	void DrawLane();
	void DrawInfoArea();
};

