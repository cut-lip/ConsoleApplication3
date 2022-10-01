// Basic OpenGL Practice //
///////////////////////////

#include <iostream>
#include "GL\glut.h"
#include <math.h>

const int screenWidth = 640;
const int screenHeight = 480;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GLintPoint >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class GLintPoint {
public:
    GLint x, y;
};


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawDot >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawDot(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> myMouse >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        drawDot((GLint)x, (GLint)(screenHeight - y));
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        exit(-1);
    }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    glPointSize(4.0);
    glFlush();      // Send all output to display
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                           // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB);     // Set display mode
    glutInitWindowSize(screenWidth, screenHeight);                    // Set window size
    glutInitWindowPosition(100, 150);                // Set window position (on screen)
    glutCreateWindow("Mouse Interaction");            // Open screen window

    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);

    glutMainLoop(); // Go into perpetual loop

    return 0;
}