
// Vectorized Line Drawing///
///////////////////////////

#include <iostream>
#include <math.h>
#include <vector>
#include "GL\glut.h"
#include "OpenGLPrac.h"

const int HORIZONTAL_SIZE = 400;
const int VERTICAL_SIZE = 250;
const int DATA_DIMENSION = 6;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GLintPoint >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class GLintPoint {
public:
    GLint x;
    GLint y;

    GLintPoint(GLint x, GLint y) {  // Constructor
        this->x = x;
        this->y = y;
    }
};

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GL6DimensionalPoint >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class GL6DimensionalPoint {
public:
    GLfloat d1, d2, d3, d4, d5, d6;

    GL6DimensionalPoint(GLfloat d1, GLfloat d2, GLfloat d3, GLfloat d4, GLfloat d5, GLfloat d6) {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d5 = d5;
        this->d6 = d6;
    }

    std::vector<float> toVector() {
        std::vector<float> vec{ d1, d2, d3, d4, d5, d6 };
        return vec;
    }
};

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GLvec2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class GLvec2    // A 2-D vector
{
public:
    GLfloat x;
    GLfloat y;

    GLvec2(GLfloat x, GLfloat y) { // Constructor
        this->x = x;
        this->y = y;
    }

    GLvec2(const GLvec2& vec) {    // Copy constructor
        this->x = vec.x;
        this->y = vec.y;
    }

    float Length() {               // Return length of vector
        return sqrt(x * x + y * y);
    }

    void Normalize() {             // Transform into normal vector in same direction
        float len = this->Length();
        this->x /= len;
        this->y /= len;
    }

    void Perpendicu() {            // Transform into vector perpendicular to current orientation
        float _x = this->x;
        this->x = -this->y;
        this->y = _x;
    }

    GLvec2 operator+(const GLvec2& b) {     // Overload + Operator
        return GLvec2(this->x + b.x, this->y + b.y);

    }

    GLvec2 operator-(const GLvec2& b) {     // Overload - Operator
        return GLvec2(this->x - b.x, this->y - b.y);

    }

    GLvec2 operator*(const GLint c) {     // Overload * Operator for * by Constants
        float constant = float(c);
        return GLvec2(this->x * c, this->y * c);
    }
};

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawDot >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawDot(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glPointSize(4.0);
    glVertex2i(x, y);
    glEnd();
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawArrow >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawArrow(GLintPoint start, GLintPoint end)
{
    // Draw Line Segment
    glBegin(GL_LINE_STRIP);
        glVertex2i(start.x, start.y);
        glVertex2i(end.x, end.y);
    glEnd();

    // Draw trangle for arrow tip
    glBegin(GL_TRIANGLES);

        GLvec2 p1 = { float(start.x), float(start.y) };
        GLvec2 p2 = { float(end.x), float(end.y) };

        GLvec2 direction = p2 - p1;
        direction.Normalize();

        GLvec2 perpendicular = GLvec2(direction);
        perpendicular.Perpendicu();
    
        GLvec2 pt1 = p2 - direction * (VERTICAL_SIZE / 60) * 3;
        GLvec2 pt2 = pt1 - perpendicular * (VERTICAL_SIZE / 60);
        GLvec2 pt3 = pt1 + perpendicular * (VERTICAL_SIZE/ 60);

        glVertex2i(p2.x, p2.y);
        glVertex2i(pt2.x, pt2.y);
        glVertex2i(pt3.x, pt3.y);

    glEnd();
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawParallelCoords >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawParallelCoords(int dimension)
{
    for (int i = HORIZONTAL_SIZE / 20 ; i < HORIZONTAL_SIZE;
        i += (HORIZONTAL_SIZE - (2 * (HORIZONTAL_SIZE / 20))) / 5)
    {
        drawArrow(GLintPoint(i, 0), GLintPoint(i, VERTICAL_SIZE - 5));
    }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawShiftedParallelCoordinates >>>>>>>>>>>>
void drawShiftedParallelCoords()
{
    GLint yCoords[6] = { 100, 30, 90, 20, 95, 0 };
    for (int cnt = 0, i = HORIZONTAL_SIZE / 20; i < HORIZONTAL_SIZE;
        i += (HORIZONTAL_SIZE - (2 * (HORIZONTAL_SIZE / 20))) / 5)
    {
        drawArrow(GLintPoint(i, yCoords[cnt]), GLintPoint(i, yCoords[cnt] + 200));
        cnt++;
    }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawScaledParallelCoords >>>>>>>>>>>>
void drawScaledParallelCoords()
{
    GLint yCoords[6] = { 150, 90, 130, 110, 230, 100 };
    for (int cnt = 0, i = HORIZONTAL_SIZE / 20; i < HORIZONTAL_SIZE;
        i += (HORIZONTAL_SIZE - (2 * (HORIZONTAL_SIZE / 20))) / 5)
    {
        drawArrow(GLintPoint(i, 0), GLintPoint(i, yCoords[cnt]));
        cnt++;
    }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> drawPCgraph >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void drawPCgraph(GL6DimensionalPoint n)
{
    std::vector<float> data = n.toVector();
    for (int i = HORIZONTAL_SIZE / 20, cnt = 0; i < HORIZONTAL_SIZE - (HORIZONTAL_SIZE / 5); 
        i += (HORIZONTAL_SIZE - (2 * (HORIZONTAL_SIZE / 20))) / 5)
    {
        drawArrow(GLintPoint(i, data.at(cnt)),
            GLintPoint(i + (HORIZONTAL_SIZE - (2 * (HORIZONTAL_SIZE / 20))) / 5, data.at(cnt + 1)));
        cnt++;
    }
};


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> myInit >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, HORIZONTAL_SIZE, 0.0, VERTICAL_SIZE);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //drawShiftedParallelCoords();
    //drawParallelCoords(DATA_DIMENSION);
    drawScaledParallelCoords();
    glLineWidth(2.5);

    glColor3f(1.0, 0.6, 0.0);
    //drawPCgraph(GL6DimensionalPoint(75, 180, 125, 200, 50, 220));     // For Parallel Coords
    //drawPCgraph(GL6DimensionalPoint(130, 130, 130, 130, 130, 130));     // For Shifted PC
    drawPCgraph(GL6DimensionalPoint(50, 50, 50, 50, 50, 50));     // For scaled PC

    glColor3f(0.0, 1.0, 0.0);
    //drawPCgraph(GL6DimensionalPoint(60, 150, 115, 140, 30, 180));     // For Parallel Coords
    //drawPCgraph(GL6DimensionalPoint(140, 150, 145, 140, 160, 150));     // For Shifted PC
    drawPCgraph(GL6DimensionalPoint(60, 70, 65, 60, 80, 70));     // For scaled PC
    //drawNonOrthoPC()

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
    glutCreateWindow("my first attempt");            // Open screen window

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop(); // Go into perpetual loop

    return 0;
}