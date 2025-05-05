#include <GL/glut.h>
#include <math.h>
#include <iostream>

#include "scene.h"


void display();
void reshape(int, int);

int sceneNumber = 1;
int totalScene = 11;
int framePerScene = 165; // 30 * 70 / 11 = 245 frames 
int frameDuration = 34;  // 1000 / 30 = frame duration (1 second / 30 frame per second)

void anim(int value) {
	glutPostRedisplay();
	glutTimerFunc(frameDuration, anim, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 800);

	glutCreateWindow("2D Animation");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(frameDuration, anim, 0);

	glutMainLoop();

}

void display()
{
	switch (sceneNumber)
	{
		case 1: sceneNumber += scene1();
				break;
		case 2: sceneNumber += scene2();
				break;
		case 3: sceneNumber += scene3();
				break;
		case 4: sceneNumber += scene4();
				break;
		case 5: sceneNumber += scene5();
				break;
		case 6: sceneNumber += scene6();
				break;
		case 7: sceneNumber += scene7();
				break;
		case 8: sceneNumber += scene8();
				break;
		case 9: sceneNumber += scene9();
				break;
		case 10:sceneNumber += scene10();
				break;
		case 11:sceneNumber += scene11();
				break;
	}
	
}

void reshape(int w, int h) 
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 20, -20, 20);
	glMatrixMode(GL_MODELVIEW);
}



