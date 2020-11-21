#ifndef KEYBOARD
#define KEYBOARD
#include "elements.h"
extern GLfloat obsT[], obsP[];
extern GLfloat  rProjection, aProjection, incProjection, worldMax;
extern float offset, rotangle;

void keyboard(unsigned char key, int x, int y);
void arrowKeys(int key, int x, int y);

#endif