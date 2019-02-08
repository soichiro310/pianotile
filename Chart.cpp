#include "Chart.h"

Chart::Chart()
{
}

Chart::~Chart()
{
}

void Chart::DrawMeasureLine(double setY) {
	if (setY > -0.7 && setY <= 1.0) {
		glColor3d(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2d(-1.0, setY);
		glVertex2d(1.0, setY);
		glEnd();
	}
}

void Chart::_SetNote(int keyNumber, double setY) {
	if (setY > -0.75 && setY <= 1.0) {
		glBegin(GL_QUADS);
		glVertex2d(-1.0 + (double)keyNumber * 0.5, setY);
		glVertex2d(-1.0 + (double)keyNumber * 0.5, setY + 0.4);
		glVertex2d(-0.5 + (double)keyNumber * 0.5, setY + 0.4);
		glVertex2d(-0.5 + (double)keyNumber * 0.5, setY);
		glEnd();
	}
}

void Chart::SetNote(int setNumber, double setY) {
	switch (setNumber) {
	case 1:
		_SetNote(0, setY);
		break;
	case 2:
		_SetNote(1, setY);
		break;
	case 3:
		_SetNote(2, setY);
		break;
	case 4:
		_SetNote(3, setY);
		break;
	default:
		break;
	}
}

bool Chart::DrawNotes(int chart[], bool record[], int size, double dmove, int miss) {

	bool isFailed = false;

	for (int i = 0; i < size; i++) {
		double setY = i * 0.4 - dmove - 0.7;
		DrawMeasureLine(setY);

		if(record[i] == true)
			glColor3d(0.0, 0.8, 0.0);
		else {
			if (miss >= 1 && miss <= 4) {
				isFailed = true;
				glColor3d(0.8, 0.0, 0.0);
				SetNote(miss, setY);
				miss = 0;
			}

			glColor3d(0.0, 0.0, 0.0);

			if (setY < -0.70) {
				isFailed = true;
				glColor3d(0.8, 0.0, 0.0);
			}
		}

		SetNote(chart[i], setY);
	}

	return isFailed;
}


