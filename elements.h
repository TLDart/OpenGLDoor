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

extern int tipoProjeccao, ssize,steps;
extern GLfloat obsT[], obsP[];

extern GLfloat squarenormal[];
extern float offset, angle, rotangle, paddingx;
extern float doorSizes[][4], doorLocation[][3];
extern GLfloat color[], color2[];
void drawEixos();
void DrawDoor();
void DoorLeft();
void DoorRight();
void DrawHandler();
void DrawTetraedron(float sz);
void DrawSolidCube(float sz);