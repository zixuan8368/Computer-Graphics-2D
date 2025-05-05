#include <GL/glut.h>
#include <time.h>
#include <cstdlib>
#include "scene.h"
#include "castle.h"
#include "character.h"

float char1_x = 0;
float char2_x = 0;
float dragon_x = 0;

int scene1()
{
	glClearColor(0.2, 0.6, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Drawing grass
	glColor3f(0.678, 1.0, 0.184);
	glBegin(GL_QUADS);
	glVertex2f(-20.0, 0.0);
	glVertex2f(-20.0, -20.0);
	glVertex2f(20.0, -20.0);
	glVertex2f(20.0, 0.0);
	glEnd();

	//Drawing castle
	glLoadIdentity();
	glPushMatrix();
		glScalef(2.0, 2.0, 2.0);
		glTranslatef(-1.0, -2.0, 0.0);
		drawCastle();
	glPopMatrix();

	drawSun(18.0, 18.0, 3.5);

	//Drawing character1
	glPushMatrix();
	glTranslatef(-15.0 + char1_x * 0.1, -6.0, 0.0);
	glScalef(1.25, 1.25, 1.25);
	drawCharacter1();
	glPopMatrix();

	//Drawing character2
	glPushMatrix();
	glTranslatef(-10.0 + char2_x * 0.1, -6.0, 0.0);
	glScalef(1.25, 1.25, 1.25);
	drawCharacter2();
	glPopMatrix();


	glutSwapBuffers();

	if (char1_x == 100) {
		return 1;
	}
	
	char1_x += 1;
	char2_x += 1;

	return 0;
}

int scene2()
{
	glClearColor(0.0, 0.0, 0.6, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Drawing grass
	glColor3f(0.678, 1.0, 0.184);
	glBegin(GL_POLYGON);
	glVertex2f(-20.0, 6.0);
	glVertex2f(-20.0, -20.0);
	glVertex2f(20.0, -20.0);
	glVertex2f(20.0, 6.0);

	glEnd();

	// Drawing a very big moon
	drawMoon(0.0, 28.0, 20.0);

	// Drawing the castle
	glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glTranslatef(-17.0, 4.0, 0.0);
		drawCastle();
	glPopMatrix();
	

	// Drawing the dragon
	int verticalP = 7.0 - dragon_x * 0.075;
	if(verticalP < -5.0)
		verticalP = -5.0;
	glPushMatrix();
		glScalef(-1.0, 1.0, 1.0);
		drawDragon(-13.0 + dragon_x * 0.05, verticalP, 2.5);
	glPopMatrix();

	dragon_x += 1.0f;
	glutSwapBuffers();
	if (dragon_x >= 100) {
		return 1;
	}

	return 0;
	
}

int scene3()
{
	srand(240);
	glClearColor(0.678, 1.0, 0.184, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	
	glPushMatrix();
	glTranslatef(10.0, 9.0, 0.0);
	drawDragonMouth(0.0, 0.0, 1.0, 40.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11.8, 9.0, 0.0);
	drawFireball(0.0, 0.0, 1.0, 230.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-15.0, 15.0, 0.0);
	glScalef(0.8, 0.8, 0.8);
	drawCastle();
	glPopMatrix();


	drawTree(-4.0, -3.0, 1.0);
	drawTree(16.0, 5.0, 1.0);
	drawTree(4.0, 17.0, 1.0);
	drawTree(-8.0, -7.0, 1.0);
	drawTree(-14.0, 6.0, 1.0);

	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);
	drawFlame(rand() % 41 - 20, rand() % 41 - 20, (rand() % 10) + 1.0);

	glPushMatrix();
	glTranslatef(-5.0 + char1_x * 0.02, -8.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	drawCharacter1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.0 + char2_x * 0.01, -4.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	drawCharacter2();
	glPopMatrix();


	glutSwapBuffers();

	if (char2_x >= 600) {
		return 1;
	}
	
	char2_x += 10.0f;
	char1_x -= 10.0f;

	return 0;

}

int scene4()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	int count = 0;
	while (count < 10000) {
		count++;
	}
	


	glutSwapBuffers();
	return 1;
}

int scene5()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene6()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene7()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene8()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene9()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene10()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
	return 1;
}

int scene11()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	return 1;
}

