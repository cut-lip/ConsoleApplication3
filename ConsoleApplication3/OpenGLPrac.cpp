
//////// GLC Drawing/////////
/////////////////////////////

#include <iostream>
#include <vector>
#include <math.h>
#include <vector>
#include "GL\glut.h"
#include "OpenGLPrac.h"

using namespace GLprac;

const int DATA_DIMENSION = 6;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit()
{
    //glViewport(-HORIZONTAL_SIZE, -VERTICAL_SIZE, HORIZONTAL_SIZE, VERTICAL_SIZE);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    // glLoadIdentity(); // Why would this by necessary?
    // 
    // gluOrtho2D is used for the case of projecting a 2D image onto a 2D screen
    gluOrtho2D(-HORIZONTAL_SIZE, HORIZONTAL_SIZE, -VERTICAL_SIZE, VERTICAL_SIZE);
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawPCVisualization >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawPCVisualization()
{
    drawParallelCoords(DATA_DIMENSION);

    // Data Class 1
    GL6DimensionalPoint pointy1 = GL6DimensionalPoint(75, 230, 125, 200, 50, 220);
    GL6DimensionalPoint pointy2 = GL6DimensionalPoint(59, 100, 100, 150, 25, 180);

    // Data class 2
    GL6DimensionalPoint pointy3 = GL6DimensionalPoint(380, 490, 420, 500, 480, 530);
    GL6DimensionalPoint pointy4 = GL6DimensionalPoint(350, 430, 400, 450, 380, 500);

    glColor3f(1.0, 0.6, 0.0);
    drawPCgraph(pointy1);     // For Parallel Coords
    glColor3f(1.0, 0.0, 0.0);
    drawPCgraph(pointy2);     // For Parallel Coords

    glColor3f(0.0, 1.0, 0.0);
    drawPCgraph(pointy3);     // For Parallel Coords
    glColor3f(0.3, 1.0, 0.0);
    drawPCgraph(pointy4);     // For Parallel Coords
}

void drawPairedShiftedVisualization()
{
    // Draw (X_1, X_2) paired coordinates
    drawArrow(GLintPoint(25, 50), GLintPoint(25, 650));
    drawArrow(GLintPoint(25, 50), GLintPoint(900, 50));

    // Draw (X_3, X_4) paired coordinates
    drawArrow(GLintPoint(75, 100), GLintPoint(75, 600));
    drawArrow(GLintPoint(75, 100), GLintPoint(850, 100));

    // Draw (X_5, X_6) paired coordinates
    drawArrow(GLintPoint(100, 150), GLintPoint(100, 525));
    drawArrow(GLintPoint(100, 150), GLintPoint(775, 150));

    // Draw preattentive point for goal
    glPointSize(15.0);
    glColor3f(0.0, 1.0, 0.0);
    drawDot(350, 300);

    // Draw other member of goal's class
    glColor3f(0.7, 1.0, 0.0);
    drawArrow(GLintPoint(390, 420), GLintPoint(325, 350));
    drawArrow(GLintPoint(325, 350), GLintPoint(310, 450));
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> myDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(0, 0, 500.0, 100);
    //drawPCVisualization();
    //drawPairedShiftedVisualization();
    glFlush();      // Send all output to display
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                           // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     // Set display mode
    glutInitWindowSize(HORIZONTAL_SIZE, VERTICAL_SIZE);                    // Set window size
    glutInitWindowPosition(100, 150);                // Set window position (on screen)
    glutCreateWindow("GLC Visualization");            // Open screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop(); // Go into perpetual loop

    return 0;
}