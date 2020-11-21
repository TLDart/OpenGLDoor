#ifndef ELEMENTS
#define ELEMENTS
#include "textures.h"
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
extern GLuint textures[3];

extern GLfloat squarenormal[], texturas[][16];
extern float offset, angle, rotangle, paddingx;
extern float doorSizes[][4], doorLocation[][3];
extern GLfloat color[], color2[];
void drawEixos();
void DrawDoor();
void DoorLeft();
void DoorRight();
void DrawHandler();
void DrawSolidPrism(float sz, GLuint &tex);
void DrawSolidCube(float sz, GLuint &tex);

#endif