#include "PlayScreenBase.h"

PlayScreenBase::PlayScreenBase()
{
}

PlayScreenBase::~PlayScreenBase()
{
}

void PlayScreenBase::DrawScreen() {	
	DrawInfoArea();
	DrawLane();
}

//ƒŒ[ƒ“•`‰æ
void PlayScreenBase::DrawLane() {
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_LINES);

	for (int i = 0; i < 4; i++) {
		glVertex2d(-1.0 + (double)i * 0.5, 1.0);
		glVertex2d(-1.0 + (double)i * 0.5, -0.7);
	}
	
	glVertex2d(-1.0, -0.7);
	glVertex2d(1.0, -0.7);
	glEnd();
}

void PlayScreenBase::DrawInfoArea() {
	glColor3d(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	glVertex2d(-1.0, -0.7);
	glVertex2d(1.0, -0.7);
	glVertex2d(1.0, -0.75);
	glVertex2d(-1.0, -0.75);
	glEnd();
}
