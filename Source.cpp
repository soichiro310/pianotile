#include "GLPianoTile.h"
using namespace std;

#define SIZE 1000

GLPianoTile game;
int chart[SIZE];
bool isCorrectKeyDown[SIZE];
int drawCount = 0, score = 0, combo = 0, miss = 0;
double hispeed = 1.0, dmove = 0.0;
bool isGameStart = false;

void CorrectKeyDownJudge(int keyNumber) {	
	if (combo > 0) {
		if (chart[combo] == keyNumber && isGameStart == true) {
			isCorrectKeyDown[combo] = true;
			score += (int)(hispeed * 10.0);
			combo++;
		} else {
			miss = keyNumber;
			isGameStart = false;
		}
	}
	else {
		if (chart[combo] == keyNumber && isGameStart == false) {
			isCorrectKeyDown[combo] = true;
			score += (int)(hispeed * 10.0);
			combo++;
			isGameStart = true;
		}
	}
}

void display(void)
{
	bool isFailed = false;

	glClear(GL_COLOR_BUFFER_BIT);
	isFailed = game.DrawNotes(chart, isCorrectKeyDown, SIZE, dmove, miss);
	game.DrawInfo(hispeed, score, combo);
	game.DrawScreen();
	glutSwapBuffers();

	if (isFailed)
		isGameStart = false;
}

void init(void)
{
	isGameStart = false;
	dmove = 0.0;
	drawCount = score = combo = miss = 0;
	hispeed = 1.0;
	
	glClearColor(0.9, 0.9, 0.9, 0.7);

	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> rand(1, 4);	
	
	for (int i = 0; i < SIZE; i++) {
		chart[i] = rand(mt);
		isCorrectKeyDown[i] = false;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '\033': /* '\033' は ESC の ASCII コード */
		exit(0);
		break;
	case 'q':
		init();
		display();
		break;
	case 'z':
		CorrectKeyDownJudge(1);
		break;
	case 'x':
		CorrectKeyDownJudge(2);
		break;
	case 'c':
		CorrectKeyDownJudge(3);
		break;
	case 'v':
		CorrectKeyDownJudge(4);
		break;
	default:
		break;
	}
}

void timer(int t)
{
	if (isGameStart) {
		if (drawCount % 100 == 0)
			hispeed += 0.1;

		dmove += 0.01 * hispeed;
		drawCount++;
	}
	else {
		drawCount = 0;
	}

	display();
	glutTimerFunc(t, timer, 20); //タイマー関数(50fps)
}

int main(int argc, char *argv[])
{
	//config
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 960);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 20);

	//drawing?
	init();
	glutMainLoop();
	return 0;
}