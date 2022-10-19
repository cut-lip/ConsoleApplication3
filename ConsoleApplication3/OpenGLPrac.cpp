
// Vectorized Line Drawing///
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
    glLoadIdentity();
    gluOrtho2D(-HORIZONTAL_SIZE, HORIZONTAL_SIZE, -VERTICAL_SIZE, VERTICAL_SIZE);
    //glEnable(GL_DEPTH_TEST);
    //gluPerspective(45, (float)HORIZONTAL_SIZE / VERTICAL_SIZE, .1, 100);
    //glMatrixMode(GL_MODELVIEW);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    //int anchor = 4;
    glColor3f(1.0, 0.6, 0.0);
    drawCircle(0, 0, 50.0, 100);

    //drawShiftedParallelCoords(anchor);
    //drawParallelCoords(DATA_DIMENSION);
    //drawScaledParallelCoords();

    //GL6DimensionalPoint pointy = GL6DimensionalPoint(75, 180, 125, 200, 50, 220);
    //GL6DimensionalPoint pointy2 = GL6DimensionalPoint(59, 140, 100, 150, 25, 180);

    //drawNonOrthoPC();

    //drawRadialCoords();
    //glLineWidth(2.5);

    //glColor3f(1.0, 0.6, 0.0);
    //drawPCgraph(GL6DimensionalPoint(pointy));     // For Parallel Coords
    //drawPCgraph(GL6DimensionalPoint(shiftPoint(pointy, anchor)));     // For Shifted PC (choose anchor dimension for shiftPoint()
    //drawPCgraph(GL6DimensionalPoint(50, 50, 50, 50, 50, 50));     // For scaled PC

    //glColor3f(0.0, 1.0, 0.0);
    //drawPCgraph(GL6DimensionalPoint(60, 150, 115, 140, 30, 180));     // For Parallel Coords
    //drawPCgraph(GL6DimensionalPoint(shiftPoint(pointy2, 4)));     // For Shifted PC
    //drawPCgraph(GL6DimensionalPoint(60, 70, 65, 60, 80, 70));     // For scaled PC

    //drawNonOrthoPC();

    glFlush();      // Send all output to display
    //drawArrow(GLintPoint(100, 100), GLintPoint(200, 200));
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