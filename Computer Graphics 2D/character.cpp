#include <GL/glut.h>
#include <math.h>
#include "character.h"

void drawCharacter1() {
    // Head
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, 3.0f);
    glVertex2f(1.0f, 3.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Hair
    glColor3f(1.0f, 0.9f, 0.2f); // Blonde hair
    glBegin(GL_POLYGON);
    glVertex2f(-1.2f, 3.5f);
    glVertex2f(1.2f, 3.5f);
    glVertex2f(1.0f, 3.0f);
    glVertex2f(-1.0f, 3.0f);
    glEnd();

    // Eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, 2.0f);
    glVertex2f(-0.2f, 2.0f);
    glVertex2f(-0.2f, 2.5f);
    glVertex2f(-0.6f, 2.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.2f, 2.0f);
    glVertex2f(0.6f, 2.0f);
    glVertex2f(0.6f, 2.5f);
    glVertex2f(0.2f, 2.5f);
    glEnd();

    // Body
    glColor3f(0.4f, 0.7f, 1.0f); // Light blue armor
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -2.0f);
    glVertex2f(-1.0f, -2.0f);
    glEnd();

    // Arms
    glBegin(GL_POLYGON); // Left arm
    glVertex2f(-1.5f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, -1.5f);
    glVertex2f(-1.5f, -1.5f);
    glEnd();

    glBegin(GL_POLYGON); // Right arm
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.5f, 0.5f);
    glVertex2f(1.5f, -1.5f);
    glVertex2f(1.0f, -1.5f);
    glEnd();

    // Sword
    glColor3f(0.6f, 1.0f, 1.0f); // Cyan sword
    glBegin(GL_POLYGON);
    glVertex2f(1.5f, -1.5f);
    glVertex2f(2.0f, -1.5f);
    glVertex2f(2.0f, 2.0f);
    glVertex2f(1.5f, 2.0f);
    glEnd();
}



void drawCharacter2() {
    // Head
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, 3.0f);
    glVertex2f(1.0f, 3.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Hair
    glColor3f(0.8f, 0.2f, 0.2f); // Red hair
    glBegin(GL_POLYGON);
    glVertex2f(-1.2f, 3.5f);
    glVertex2f(1.2f, 3.5f);
    glVertex2f(1.0f, 3.0f);
    glVertex2f(-1.0f, 3.0f);
    glEnd();

    // Eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, 2.0f);
    glVertex2f(-0.2f, 2.0f);
    glVertex2f(-0.2f, 2.5f);
    glVertex2f(-0.6f, 2.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.2f, 2.0f);
    glVertex2f(0.6f, 2.0f);
    glVertex2f(0.6f, 2.5f);
    glVertex2f(0.2f, 2.5f);
    glEnd();

    // Body
    glColor3f(0.2f, 0.8f, 0.4f); // Green armor
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -2.0f);
    glVertex2f(-1.0f, -2.0f);
    glEnd();

    // Arms
    glBegin(GL_POLYGON); // Left arm
    glVertex2f(-1.5f, 0.5f);
    glVertex2f(-1.0f, 0.5f);
    glVertex2f(-1.0f, -1.5f);
    glVertex2f(-1.5f, -1.5f);
    glEnd();

    glBegin(GL_POLYGON); // Right arm
    glVertex2f(1.0f, 0.5f);
    glVertex2f(1.5f, 0.5f);
    glVertex2f(1.5f, -1.5f);
    glVertex2f(1.0f, -1.5f);
    glEnd();

    // Sword
    glColor3f(0.6f, 1.0f, 0.6f); // Light green sword
    glBegin(GL_POLYGON);
    glVertex2f(1.5f, -1.5f);
    glVertex2f(2.0f, -1.5f);
    glVertex2f(2.0f, 2.0f);
    glVertex2f(1.5f, 2.0f);
    glEnd();
}

void drawDragon(float x, float y, float scale) {

    glPushMatrix();
    // Apply transformations
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    // Body (main oval shape)
    glColor3f(0.8f, 0.2f, 0.2f); // Red
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float degInRad = i * 3.14159f / 180;
        glVertex2f(cos(degInRad) * 2.0f * 1.5f, sin(degInRad) * 2.0f);
    }
    glEnd();

    // Head
    glColor3f(0.7f, 0.1f, 0.1f); // Darker red
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float degInRad = i * 3.14159f / 180;
        glVertex2f(3.0f + cos(degInRad) * 1.0f, 0.5f + sin(degInRad) * 0.8f);
    }
    glEnd();

    // Eyes
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float degInRad = i * 3.14159f / 180;
        glVertex2f(3.5f + cos(degInRad) * 0.2f, 0.7f + sin(degInRad) * 0.2f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float degInRad = i * 3.14159f / 180;
        glVertex2f(3.5f + cos(degInRad) * 0.2f, 0.3f + sin(degInRad) * 0.2f);
    }
    glEnd();

    // Pupils
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float degInRad = i * 3.14159f / 180;
        glVertex2f(3.6f + cos(degInRad) * 0.1f, 0.7f + sin(degInRad) * 0.1f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float degInRad = i * 3.14159f / 180;
        glVertex2f(3.6f + cos(degInRad) * 0.1f, 0.3f + sin(degInRad) * 0.1f);
    }
    glEnd();

    // Horns
    glColor3f(0.5f, 0.5f, 0.5f); // Gray
    glBegin(GL_TRIANGLES);
    // Left horn
    glVertex2f(3.8f, 1.2f);
    glVertex2f(3.5f, 0.8f);
    glVertex2f(4.0f, 0.8f);

    // Right horn
    glVertex2f(3.8f, -0.2f);
    glVertex2f(3.5f, 0.2f);
    glVertex2f(4.0f, 0.2f);
    glEnd();

    // Wings
    glColor3f(0.6f, 0.1f, 0.1f); // Dark red
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Wing base
    for (int i = 0; i <= 180; i += 20) {
        float degInRad = (i - 90) * 3.14159f / 180;
        glVertex2f(-3.0f + cos(degInRad) * 3.0f,
            2.0f + sin(degInRad) * 1.5f);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Wing base
    for (int i = 180; i <= 360; i += 20) {
        float degInRad = (i - 90) * 3.14159f / 180;
        glVertex2f(-3.0f + cos(degInRad) * 3.0f,
            -2.0f + sin(degInRad) * 1.5f);
    }
    glEnd();

    // Tail
    glColor3f(0.8f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-3.0f, 0.3f);
    glVertex2f(-4.0f, 0.0f);
    glVertex2f(-5.0f, 0.5f);
    glVertex2f(-6.0f, 0.0f);
    glVertex2f(-7.0f, 0.0f);
    glEnd();

    // Restore matrix
    glPopMatrix();
}

void drawDragonMouth(float horizontalP, float verticalP, float scale, float rotate)
{
    glPushMatrix();
    glRotatef(rotate, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    // Draw upper mouth
    glBegin(GL_QUADS);
    glVertex2f(horizontalP - 5.0, verticalP + 1.0);
    glVertex2f(horizontalP - 5.0, verticalP + 0.0);
    glVertex2f(horizontalP + 5.0, verticalP + 0.0);
    glVertex2f(horizontalP + 5.0, verticalP + 1.0);

    // Draw lower mouth
    glVertex2f(horizontalP - 4.5, verticalP - 6.0);
    glVertex2f(horizontalP - 4.25, verticalP - 7.0);
    glVertex2f(horizontalP + 5.25, verticalP + -1.0);
    glVertex2f(horizontalP + 5.0, verticalP + 0.0);

    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);

    // Drawing teeth for upper mouth
    for (float i = horizontalP - 5.0; i <= horizontalP + 4.5; i += 0.5)
    {
        glVertex2f(i, verticalP);
        glVertex2f(i + 0.25, verticalP - 0.5);
        glVertex2f(i + 0.5, verticalP);
    }

    // Drawing teeth for lower mouth

    glEnd();

    // Drawing the head of the dragon
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);

    glVertex2f(horizontalP + 5.0, verticalP + 3.5);
    glVertex2f(horizontalP + 5.0, verticalP + -2.5);
    glVertex2f(horizontalP + 15.0, verticalP + -2.5);
    glVertex2f(horizontalP + 15.0, verticalP + 3.5);

    glEnd();


    // Drawing the eye of the dragon
    glColor3f(1.0, 1.0, 0.8);
    glBegin(GL_POLYGON);

    glVertex2f(horizontalP + 7.0, verticalP + 2.0);
    glVertex2f(horizontalP + 9.0, verticalP + 3.0);
    glVertex2f(horizontalP + 10.0, verticalP + 2.5);
    glVertex2f(horizontalP + 9.5, verticalP + 1.0);
    glVertex2f(horizontalP + 8.5, verticalP + 0.5);
    glVertex2f(horizontalP + 7.6, verticalP + 1.2);
    glVertex2f(horizontalP + 7.0, verticalP + 2.0);

    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);

    glVertex2f(horizontalP + 8.0, verticalP + 2.5);
    glVertex2f(horizontalP + 8.5, verticalP + 0.3);
    glVertex2f(horizontalP + 9.0, verticalP + 3.0);
    glVertex2f(horizontalP + 9.5, verticalP + 0.7);

    glEnd();

    glPopMatrix();
}
