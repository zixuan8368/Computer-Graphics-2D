#include <GL/glut.h>
#include <math.h>
#include <iostream>

#include "scene.h"


void display();
void reshape(int, int);
void timer(int);

int sceneNumber = 1;
int totalScene = 11;
int frame = 0;
int framePerScene = 165; // 30 * 70 / 11 = 245 frames 
int frameDuration = 34;  // 1000 / 30 = frame duration (1 second / 30 frame per second)


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 800);

	glutCreateWindow("2D Animation");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(frameDuration, timer, 0);

	glutMainLoop();

}

void display()
{
	switch (sceneNumber)
	{
		case 1: scene1(frame);
				break;
		case 2: scene2(frame);
				break;
		case 3: scene3(frame);
				break;
		case 4: scene4(frame);
				break;
		case 5: scene5(frame);
				break;
		case 6: scene6(frame);
				break;
		case 7: scene7(frame);
				break;
		case 8: scene8(frame);
				break;
		case 9: scene9(frame);
				break;
		case 10: scene10(frame);
				break;
		case 11: scene11(frame);
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

void timer(int)
{
	if (sceneNumber <= totalScene)
	{
		frame++;
		if (frame >= framePerScene)
		{
			frame = 0;
			sceneNumber++;
			if (sceneNumber > 11)
			{
				sceneNumber = 1;
			}
		}
		glutPostRedisplay();
		glutTimerFunc(frameDuration, timer, 0);
	}

}

