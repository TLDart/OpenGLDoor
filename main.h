#include "keyboard.h"
#define WIDTH 1280
#define HEIGHT 960

GLint     msec = 10;
GLfloat		yC = 100.0;	//.. Mundo

//------------------------------------------------------------ Observador 
GLfloat  rVisao = 8, aVisao = PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), 0.0, rVisao * sin(aVisao) };
GLfloat  obsT[] = { obsP[0] - rVisao * cos(aVisao), obsP[1], obsP[2] - rVisao * sin(aVisao) };


float anguloZ = 95;
int observer = 1;
 GLuint    poligono[] = { 0, 1, 2, 3 };
 GLfloat vertices[] = {
 0.5,  0.0, -0.5,
-0.5,  0.0, -0.5,
-0.5,  0.0,  0.5, 
 0.5,  0.0,  0.5, 
 };
 GLfloat normais[] = {
0.0, 1.0, 0.0, 
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0 };
 GLfloat cores[] = {
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 1.0,
1.0, 1.0, 0.0 };
 GLfloat cores2[] = {
1.0, 0.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 0.0 };

int doorSizex = 2, doorSizey =5;
float offset = 0;