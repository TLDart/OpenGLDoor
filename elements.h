#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#define BLUE     0.0, 0.0, 1.0, 1.0
#define RED		 1.0, 0.0, 0.0, 1.0
#define YELLOW	 1.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0
#define ORANGE   1.0, 0.5, 0.1, 1.0
#define CYAN     0.0, 1.0, 1.0, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.3, 0.3, 0.3, 1.0
#define PI		 3.14159

extern int doorSizex, doorSizey;
extern float offset;
extern GLfloat obsT[], obsP[];
extern int tipoProjeccao, ssize,steps;
extern char texto[30];
extern GLfloat cores[], cores2[];
extern GLuint poligono[];
void drawEixos();
void DrawDoor();