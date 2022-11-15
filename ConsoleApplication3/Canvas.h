// Class Adapted from "Computer Graphics Using Open GL" Chapter 3

#pragma once

#include "GL\glut.h"
#include "OpenGLPrac.h"
#include "Canvas.cpp"

class Canvas
{
public:
	// Constructor
	Canvas(int width, int height, char* windowTitle);

	void setWindow(float l, float r, float b, float t);

	void setViewport(int l, int r, int b, int t);

	IntRect getViewport(void);	// Divulge the viewport data

	RealRect getWindow(void);	// Divulge the window data

	float getWindowAspectRatio(void);

	void clearScreen();

	void setBackgroundColor(float r, float g, float b);

	void lineTo(float x, float y);

	void lineTo(Point2 p);

	void moveTo(float x, float y);

	void moveTo(Point2 p);

	// More functions to be added

private:
	Point2 CP;	// Current position

	IntRect viewport;

	RealRect window;

	// More members to be added
};