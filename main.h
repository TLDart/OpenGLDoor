#include "keyboard.h"
#define WIDTH 1280
#define HEIGHT 960


GLint     msec = 10;
GLfloat		yC = 100.0;	//.. Mundo

GLfloat  rVisao = 15, aVisao = PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao * cos(aVisao), 5, rVisao * sin(aVisao) };
GLfloat  obsT[] = { obsP[0] - rVisao * cos(aVisao), obsP[1], obsP[2] - rVisao * sin(aVisao) };


float anguloZ = 95;
int observer = 1;
 GLuint    squareorientation[] = { 0, 1, 2, 3 };
 GLfloat squarevertex[] = {
 0.5,  0.0, -0.5,
-0.5,  0.0, -0.5,
-0.5,  0.0,  0.5, 
 0.5,  0.0,  0.5, 
 };
 GLfloat squarenormal[] = {
0.0, 1.0, 0.0, 
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0 };
 GLfloat color[] = {
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 1.0,
1.0, 1.0, 0.0 };
 GLfloat color2[] = {
1.0, 0.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 0.0,
1.0, 0.0, 0.0 };

GLuint  triangleorientation[] = { 0, 1, 2 };
GLfloat trianglevertex[]{
-0.5,  0.0, -0.5,
-0.5,  0.0,  0.5, 
 0.5,  0.0,  0.5, 
};

GLfloat trianglenormal[]{
    0
};
GLfloat trianglevertex2[]{
 0.5,  0.0, -0.5,
-0.5,  0.0,  0.5, 
 0.5,  0.0,  0.5, 
};

float offset = 0, angle = 90, rotangle = 0; // offset, used to opening motion, angle and rotangle used in the rotation of the knob in the middle of the door
float paddingx = 2; // Initial padding on the left of the door
float doorSizes[][3] ={
    {1,3,1}, // 0
    {2,3,1}, // 1
    {0,0,0}, // 2
    {0,0,0}, // 3
    {5,4,1}, // 4
    {4,1,1}, // 5
    {4,1,1}, // 6
    {4,1,1}, // 7
    {4,1,1}, // 8
    {5,2,1}, // 8
    {1,4,1}, // 10
    {0,0,0}, // 11
    {2,2,0}, // 12
    {0,0,0}, // 13
    {0,0,0}, // 14
    {0,0,0}, // 15
    {0,0,0}, // 16
    {0,0,0}, // 17
    {0,0,0}, // 18
    {0,0,0}, // 19
    {0,0,0}, // 20

};

float doorLocation[][3] = {
    {paddingx + doorSizes[0][0]/2,4 + doorSizes[0][1]/2 ,0}, // 0 
    {doorLocation[0][0] + doorSizes[0][0]/2 + doorSizes[1][0]/2 ,4 + doorSizes[1][1]/2 ,0}, // 1 
    {0,0,0}, // 2
    {0,0,0}, // 3
    {5 + doorSizes[4][0]/2,doorSizes[4][1]/2,0}, // 4
    {5 + doorSizes[5][0]/2,doorSizes[5][1]/2 + doorSizes[4][1],0}, // 5
    {5 + doorSizes[6][0]/2,doorSizes[6][1]/2 + doorSizes[4][1] + doorSizes[5][1],0}, // 6
    {5 + doorSizes[7][0]/2,doorSizes[7][1]/2 + doorSizes[4][1] + doorSizes[5][1]+ doorSizes[6][1],0}, // 7
    {5 + doorSizes[8][0]/2,doorSizes[8][1]/2 + doorSizes[4][1] + doorSizes[5][1]+ doorSizes[6][1]+ doorSizes[7][1],0}, // 8
    {5 + doorSizes[9][0]/2,doorSizes[9][1]/2 + doorSizes[4][1] + doorSizes[5][1]+ doorSizes[6][1]+ doorSizes[7][1]+ doorSizes[8][1],0}, // 8
    {9 + doorSizes[10][0]/2,doorSizes[10][1]/2 + doorSizes[4][1]}, // 10
    {0,0,0}, // 11
    {10+ doorSizes[12][0]/2,doorSizes[12][1]/2 +4,0}, // 12
    {0,0,0}, // 13
    {0,0,0}, // 14
    {0,0,0}, // 15
    {0,0,0}, // 16
    {0,0,0}, // 17
    {0,0,0}, // 18
    {0,0,0}, // 19
    {0,0,0}, // 20
};

void config();