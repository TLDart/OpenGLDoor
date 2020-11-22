#ifndef LIGHTING
#define LIGHTING
#pragma once
#include <GL/freeglut.h>
extern GLfloat   R, G, B, intensity, lightPos[4], lightAmb[4], lightDif[4], lightSpec[4];
extern GLfloat Spot_Direction[], Spot_Color[], Spot_Att[], Spot_Exp, Spot_opening, Spot_Pos[];
extern GLfloat  chromeAmb[], chromeDif[], chromeSpec[], chromeCoef;


void ilumina();
void initLights(void);
void updateLights();
#endif 