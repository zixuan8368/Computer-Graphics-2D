#include <GL/glut.h>
#include <math.h>
#include "castle.h"

// Declaring drawLeaf
void drawLeaf(float h, float v)
{
	glPushMatrix();
	glTranslatef(h, v, 0.0);
	glColor3f(0.0, 0.4, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2d(-1.5, -1.0);
	glVertex2d(1.5, -1.0);
	glVertex2f(0.0, 1.0);
	glEnd();

	glPopMatrix();
}

void drawCube()
{
	// Drawing the cube itself
	glColor3f(0.52, 0.48, 0.55);
	glBegin(GL_POLYGON);

	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);

	glEnd();

	// Drawing a dark line around the cube
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);

	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);

	glEnd();
}

void drawWindow(float horizontalP, float verticalP, float radius)
{
	// Drawing window
	glColor3f(0.35, 0.90, 0.96);
	int numSegments = 100;
	glBegin(GL_POLYGON);

	for (int i = 0; i < numSegments; i++)
	{
		float angle = 2 * 3.14159 * i / numSegments;
		float x = horizontalP + radius * cos(angle);
		float y = verticalP + radius * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
}

void drawCastle()
{
	// Draw the triangle of the top of the castle
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 10.0);
	glVertex2f(-1.5, 8.0);
	glVertex2f(1.5, 8.0);

	glVertex2f(-5.0, 10.0);
	glVertex2f(-6.0, 8.0);
	glVertex2f(-4.0, 8.0);

	glVertex2f(5.0, 10.0);
	glVertex2f(4.0, 8.0);
	glVertex2f(6.0, 8.0);
	glEnd();

	// Draw the rectangle under the triangles
	glColor3f(0.7, 0.68, 0.73);
	glBegin(GL_QUADS);
	glVertex2f(-6.0, 8.0);
	glVertex2f(-6.0, 0.0);
	glVertex2f(-4.0, 0.0);
	glVertex2f(-4.0, 8.0);

	glVertex2f(-1.5, 8.0);
	glVertex2f(-1.5, 0.0);
	glVertex2f(1.5, 0.0);
	glVertex2f(1.5, 8.0);

	glVertex2f(4.0, 8.0);
	glVertex2f(4.0, 0.0);
	glVertex2f(6.0, 0.0);
	glVertex2f(6.0, 8.0);
	glEnd();

	// Drawing another two rectangles
	glColor3f(0.51, 0.51, 0.51);
	glBegin(GL_QUADS);

	glVertex2f(-8.0, 6.5);
	glVertex2f(-8.0, 0.0);
	glVertex2f(-5.0, 0.0);
	glVertex2f(-5.0, 6.5);

	glVertex2f(5.0, 6.5);
	glVertex2f(5.0, 0.0);
	glVertex2f(8.0, 0.0);
	glVertex2f(8.0, 6.5);

	glEnd();

	// Draw cube by using translation (via function call drawCube();
	for (float i = -8.0; i <= -5; i += 1.5)
	{
		glPushMatrix();
		glTranslatef(i, 6.5, 0.0);
		drawCube();
		glPopMatrix();
	}

	for (float i = 5.0; i <= 8.0; i += 1.5)
	{
		glPushMatrix();
		glTranslatef(i, 6.5, 0.0);
		drawCube();
		glPopMatrix();
	}

	// Draw the middle of the castle
	glColor3f(0.59, 0.59, 0.59);

	glBegin(GL_QUADS);

	glVertex2f(-6.0, 5.0);
	glVertex2f(-6.0, 0.0);
	glVertex2f(6.0, 0.0);
	glVertex2f(6.0, 5.0);

	glEnd();

	for (float i = -6.0; i <= 6.0; i = i + 1.5)
	{
		glPushMatrix();
		glTranslatef(i, 5.0, 0.0);
		drawCube();
		glPopMatrix();
	}

	// Drawing the door
	glColor3f(0.6, 0.298, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-1.5, 2.0);
	glVertex2f(-1.5, 0.0);
	glVertex2f(1.5, 0.0);
	glVertex2f(1.5, 2.0);
	glEnd();

	
	// Draw curved top (half-circle)
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i += 5) {  // From 0° to 180°
		float angle = i * 3.14159 / 180.0;  // Convert degrees to radians
		float x = 1.5 * cos(angle);   // Adjust width (radius = 0.75)
		float y = 1.0 * sin(angle) + 2.0;  // Adjust height and position (add 2.0 to move up)
		glVertex2f(x, y);
	}
	glEnd();

	drawWindow(-3.5, 3.0, 1.0);
	drawWindow(3.5, 3.0, 1.0);


	// Drawing a frame around the door
	glLineWidth(2.0);
	glColor3f(0.4, 0.2, 0.0);
	glBegin(GL_LINE_LOOP);

	glVertex2f(-1.5, 2.0);
	glVertex2f(-1.5, 0.0);
	glVertex2f(1.5, 0.0);
	glVertex2f(1.5, 2.0);

	glEnd();

	glBegin(GL_LINES);

	glVertex2f(0.0, 2.0);
	glVertex2f(0.0, 0.0);

	glEnd();

	glLineWidth(1.0);

	// Drawing door knobs
	glBegin(GL_QUADS);

	glVertex2f(-0.5, 1.25);
	glVertex2f(-0.5, 0.6);
	glVertex2f(-0.2, 0.6);
	glVertex2f(-0.2, 1.25);

	glVertex2f(0.2, 1.25);
	glVertex2f(0.2, 0.6);
	glVertex2f(0.5, 0.6);
	glVertex2f(0.5, 1.25);
	
	glEnd();

	// Drawing roads in front of the castle gate
	glColor3f(1.0, 0.698, 0.4);
	glBegin(GL_QUADS);
	glVertex2f(-1.5, 0.0);
	glVertex2f(-1.5, -5.0);
	glVertex2f(1.5, -5.0);
	glVertex2f(1.5, 0.0);
	glEnd();

	// Drawing lines beside the road
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(-1.5, 0.0);
	glVertex2f(-1.5, -5.0);
	glVertex2f(1.5, -5.0);
	glVertex2f(1.5, 0.0);
	glEnd();


	// Drawing trees beside the road
	drawTree(-7.0, 2.0, 1.0);
	drawTree(2.5, -1.0, 1.0);
	drawTree(-5.23, -3.0, 1.0);


}

void drawSun(float horizontalP, float verticalP, float radius)
{
	// Drawing window
	glColor3f(1.0, 1.0, 0.0);
	int numSegments = 100;
	glBegin(GL_POLYGON);

	for (int i = 0; i < numSegments; i++)
	{
		float angle = 2 * 3.14159 * i / numSegments;
		float x = horizontalP + radius * cos(angle);
		float y = verticalP + radius * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();


	glColor3f(1.0f, 0.7f, 0.0f);  // Slightly orange color for rays
	for (int i = 0; i < 360; i += 12) {  // Rays every 30 degrees
		float angle = i * 3.14159 / 180.0;
		float xStart = horizontalP + cos(angle) * 3.8;
		float yStart = verticalP + sin(angle) * 3.8;
		float xEnd =  horizontalP + cos(angle) * 7;
		float yEnd = verticalP + sin(angle) * 7;

		glBegin(GL_LINES);
		glVertex2f(xStart, yStart);
		glVertex2f(xEnd, yEnd);
		glEnd();
	}

}

void drawTree(float horizontalP, float verticalP, float scale)
{
	


	glPushMatrix();
		glTranslatef(horizontalP, verticalP, 0.0);
		glScalef(scale, scale, 1.0);

		glColor3f(0.4, 0.2, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(-0.6, -2.0);
		glVertex2f(-0.6, -4.0);
		glVertex2f(0.6, -4.0);
		glVertex2f(0.6, -2.0);

		glEnd();

		drawLeaf(0.0, 0.0);
		drawLeaf(0.0, -1.25);
		drawLeaf(0.0, -2.5);

		glPopMatrix();
}

void drawMoon(float horizontalP, float verticalP, float radius)
{
	glColor3f(0.878, 0.878, 0.878);
	int numSegments = 100;
	glBegin(GL_POLYGON);

	for (int i = 0; i < numSegments; i++)
	{
		float angle = 2 * 3.14159 * i / numSegments;
		float x = horizontalP + radius * cos(angle);
		float y = verticalP + radius * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
}

void drawFireball(float horizontalP, float verticalP, float radius, float rotation) {
	
	glPushMatrix();
	glRotatef(rotation, 0.0, 0.0, 1.0);
	// Draw the main ball (orange circle)
	glColor3f(1.0f, 0.5f, 0.0f);
	int numSegments = 50;
	glBegin(GL_POLYGON);
	for (int i = 0; i < numSegments; i++) {
		float angle = 2 * 3.14159 * i / numSegments;
		float x = horizontalP + radius * cos(angle);
		float y = verticalP + radius * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();

	// Draw some flames (simple triangles)
	glColor3f(0.890, 0.914, 0.153);
	glBegin(GL_TRIANGLES);
	glVertex2f(horizontalP + radius, verticalP);
	glVertex2f(horizontalP + radius + 20, verticalP + 5);
	glVertex2f(horizontalP + radius + 20, verticalP - 5);

	glColor3f(1.0, 0.6, 0.2);
	glVertex2f(horizontalP + radius, verticalP);
	glVertex2f(horizontalP + radius + 19, verticalP + 4);
	glVertex2f(horizontalP + radius + 19, verticalP - 4);

	glColor3f(0.8, 0.4, 0.0);
	glVertex2f(horizontalP + radius, verticalP);
	glVertex2f(horizontalP + radius + 19, verticalP + 3);
	glVertex2f(horizontalP + radius + 19, verticalP - 3);

	glEnd();
	glPopMatrix();
}

void drawFlame(float horizontalP, float verticalP, float scale)
{
	glPushMatrix();
	glTranslatef(horizontalP, verticalP, 0.0);
	glScalef(scale, scale, 1.0);
	
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.0, 0.5);

	glColor3f(1.0f, 0.5f, 0.0f); // Orange
	glVertex2f(-0.4, -0.4);
	glVertex2f(0.4, -0.4);
	glVertex2f(0.0, 0.4);

	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.3, -0.3);
	glVertex2f(0.3, -0.3);
	glVertex2f(0.0, 0.3);

	glEnd();

	glPopMatrix();
}
