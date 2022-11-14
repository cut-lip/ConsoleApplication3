// Classes Adapted from 

#pragma once

#include "GL\glut.h"

// Defines a 2-D point consisting of two floating point values
class Point2 {
public:
	Point2() { x = y = 0.0; }
	Point2(float xx, float yy) { x = xx; y = yy; }
	
	void set(float xx, float yy) { x = xx; y = yy; }
	float getX() { return x;  }
	float getY() { return y;  }
	void draw(void)
	{
		glBegin(GL_POINTS);
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();
	}
private:
	float x, y;
};

// Defines an aligned rectangle with integer coordinates to describe the viewport
class IntRect
{
public:
	IntRect() {
		l = 0;
		r = 100;
		b = 0;
		t = 100;
	}

	IntRect(int left, int right, int bottom, int top)
	{
		l = left;
		r = right;
		b = bottom;
		t = top;
	}

	void set(int left, int right, int bottom, int top)
	{
		l = left; r = right; b = bottom; t = top;
	}

	void draw(void)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(l, b);
		glVertex2i(l, t);
		glVertex2i(r, t);
		glVertex2i(r, b);
		glEnd();
	}

private:
	int l, r, b, t;
};

// Defines an aligned rectangle with integer coordinates to describe the viewport
class RealRect
{
public:
	RealRect() {
		l = 0.0;
		r = 100.0;
		b = 0.0;
		t = 100.0;
	}

	RealRect(int left, int right, int bottom, int top)
	{
		l = left;
		r = right;
		b = bottom;
		t = top;
	}

	void set(int left, int right, int bottom, int top)
	{
		l = left; r = right; b = bottom; t = top;
	}

	void draw(void)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(l, b);
		glVertex2i(l, t);
		glVertex2i(r, t);
		glVertex2i(r, b);
		glEnd();
	}

private:
	float l, r, b, t;
};

class Canvas
{
public:
	// Constructor
	Canvas(int width, int height, char* windowTitle);

private:


};