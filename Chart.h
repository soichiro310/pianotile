#pragma once
#include <GL/glut.h>

class Chart
{
public:
	
	Chart();
	~Chart();

	bool DrawNotes(int chart[], bool record[], int size, double dmove, int miss);

private:
	void DrawMeasureLine(double setY);
	void _SetNote(int keyNumber, double setY);
	void SetNote(int setNumber, double setY);

};

