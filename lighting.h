#ifndef LIGHTING
#define LIGHTING
#pragma once
#include <GL/freeglut.h>
extern GLfloat   R, G, B;
extern GLfloat intensity;
extern GLfloat lightPos[4];
extern GLfloat lightAmb[4];
extern GLfloat lightDif[4];
extern GLfloat lightSpec[4];

extern GLfloat  chromeAmb [];
extern GLfloat  chromeDif [];
extern GLfloat  chromeSpec [];
extern GLint  chromeCoef;


void ilumina();
void initLights(void);
void updateLights();
#endif 