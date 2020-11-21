#ifndef MAIN
#define MAIN
#include "keyboard.h"
#include "lighting.h"
GLint width = 1280, height = 960;


GLint     msec =     10;
GLfloat		worldMax = 30.0;	

// Observer Options
GLfloat  rProjection = 15, aProjection = 0.5* PI, incProjection = 0.25;
GLfloat  obsP[] = {0 , 5, 15 };
GLfloat  obsT[] = { obsP[0] - rProjection * cos(aProjection), obsP[1], obsP[2] - rProjection * sin(aProjection) };

//Textures
GLuint textures[3];
//Colors
float anguloZ = 95;
 
 GLfloat color[] = {
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0,
0.0, 1.0, 0.0 };
 GLfloat color2[] = {
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0,
0.0, 0.0, 1.0 };

GLfloat texturas[][16] = {
{1,1,
0,1,
0,0,
1,0,
0,1,
1,1,
0,0,
0,0},
{0,0,
1,0,
1,0,
0,0,
0,1,
1,1,
0,0,
0,0},
{0,0,
1,0,
1,0,
0,0,
0,1,
1,1,
0,0,
0,0},
 };



float offset = 0, angle = 90, rotangle = 0; // offset, used to opening motion, angle and rotangle used in the rotation of the knob in the middle of the door
float paddingx = 2; // Initial padding on the left of the door
float doorSizes[][4] ={
    {1,3,1,1}, // 0
    {2,4,1,3}, // 1
    {2,3,1,1}, // 2
    {2,3,1,2}, // 3
    {5,4,1,1}, // 4
    {4,1,1,1}, // 5
    {4,1,1,1}, // 6
    {4,1,1,1}, // 7
    {4,1,1,1}, // 8
    {5,2,1,1}, // 8
    {1,4,1,1}, // 10
    {2,2,1,5}, // 11
    {2,2,1,1}, // 12
    {2,2,1,4}, // 13
    {4,2,1,1}, // 14
    {2,2,1,2}, // 15
    {2,2,1,3}, // 16
    {4,2,1,1}, // 17
    {2,2,1,1}, // 18
    {1,3,1,1}, // 19
    {2,1,1,1}, // 20
    {2,3,0.5,1}, // 21
    {2,2.99,0.5,1}, // 22
    {2,4,1,5}, // 23
    {2,3,1,1}, // 24
    {2,3,1,4}, // 25
    {2,3,0.4,1}, // 26
};

float leftside = paddingx + doorSizes[4][0] + doorSizes[1][0] + doorSizes[0][0];

float doorLocation[][3] = {
    {paddingx + doorSizes[0][0]/2 ,4 + doorSizes[0][1]/2 ,0}, // 0 
    {paddingx + doorSizes[1][0]/2 + doorSizes[0][0],doorSizes[1][1]/2,0}, // 1 
    {paddingx + doorSizes[2][0]/2 + doorSizes[0][0],doorSizes[2][1]/2 + doorSizes[1][1],0}, // 2
    {paddingx + doorSizes[3][0]/2 + doorSizes[0][0],doorSizes[3][1]/2 + doorSizes[2][1] + doorSizes[1][1],0}, // 3
    {paddingx + doorSizes[4][0]/2 + doorSizes[0][0] + doorSizes[1][0],doorSizes[4][1]/2,0}, // 4
    {paddingx + doorSizes[5][0]/2 + doorSizes[0][0] + doorSizes[1][0],doorSizes[5][1]/2 + doorSizes[4][1],0}, // 5
    {paddingx + doorSizes[6][0]/2 + doorSizes[0][0] + doorSizes[1][0],doorSizes[6][1]/2 + doorSizes[4][1] + doorSizes[5][1],0}, // 6
    {paddingx + doorSizes[7][0]/2 + doorSizes[0][0] + doorSizes[1][0],doorSizes[7][1]/2 + doorSizes[4][1] + doorSizes[5][1]+ doorSizes[6][1],0}, // 7
    {paddingx + doorSizes[8][0]/2 + doorSizes[0][0] + doorSizes[1][0],doorSizes[8][1]/2 + doorSizes[4][1] + doorSizes[5][1]+ doorSizes[6][1]+ doorSizes[7][1],0}, // 8
    {paddingx + doorSizes[9][0]/2 + doorSizes[0][0] + doorSizes[1][0],doorSizes[9][1]/2 + doorSizes[4][1] + doorSizes[5][1]+ doorSizes[6][1]+ doorSizes[7][1]+ doorSizes[8][1],0}, // 8
    {paddingx + doorSizes[10][0]/2 + doorSizes[5][0] + doorSizes[1][0] + doorSizes[0][0],doorSizes[10][1]/2 + doorSizes[4][1]}, // 10
    {paddingx + doorSizes[11][0]/2 + doorSizes[4][0] + doorSizes[1][0] + doorSizes[0][0],2 + doorSizes[11][1]/2,0}, // 11
    {paddingx + doorSizes[12][0]/2 + doorSizes[4][0] + doorSizes[1][0] + doorSizes[0][0],doorSizes[12][1]/2 +doorSizes[4][1],0}, // 12
    {paddingx + doorSizes[13][0]/2 + doorSizes[4][0] + doorSizes[1][0] + doorSizes[0][0],doorSizes[13][1]/2 +doorSizes[12][1] +doorSizes[4][1],0}, // 13
    {leftside + doorSizes[14][0]/2,doorSizes[14][1]/2,0}, // 14
    {leftside + doorSizes[15][0]/2 ,doorSizes[15][1]/2 + doorSizes[14][1],0}, // 15
    {leftside + doorSizes[16][0]/2 ,doorSizes[16][1]/2 + doorSizes[15][1]+ doorSizes[14][1]+ doorSizes[12][1],0}, // 16
    {leftside + doorSizes[17][0]/2 ,doorSizes[17][1]/2 + doorSizes[16][1] + doorSizes[15][1]+ doorSizes[14][1]+ doorSizes[12][1],0}, // 17
    {leftside + doorSizes[18][0]/2 + doorSizes[14][0]/2 ,doorSizes[18][1]/2 + doorSizes[14][1],0}, // 18
    {leftside + doorSizes[19][0]/2 + doorSizes[14][0]/2 ,doorSizes[19][1]/2  + doorSizes[18][1] + doorSizes[14][1],0}, // 19
    {leftside + doorSizes[20][0]/2 + doorSizes[14][0]/2 ,doorSizes[20][1]/2  + doorSizes[19][1] + doorSizes[18][1] + doorSizes[14][1],0}, // 19
    {leftside + doorSizes[21][0]/2 + doorSizes[15][0] + doorSizes[19][0] ,doorSizes[21][1]/2 + doorSizes[18][1] + doorSizes[14][1],-doorSizes[21][2]/2}, // 21
    {leftside + doorSizes[22][0]/2 + doorSizes[15][0] + doorSizes[19][0] ,doorSizes[21][1]/2 + doorSizes[18][1] + doorSizes[14][1],doorSizes[21][2]/2}, // 22
    {leftside + doorSizes[23][0]/2 + doorSizes[14][0],doorSizes[23][1]/2,0}, // 23
    {leftside + doorSizes[24][0]/2 + doorSizes[14][0] + doorSizes[23][0]/2,doorSizes[24][1]/2 + doorSizes[23][1],0}, // 24
    {leftside + doorSizes[25][0]/2 + doorSizes[14][0],doorSizes[25][1]/2+ doorSizes[23][1]+ doorSizes[24][1],0}, // 25
    {leftside + doorSizes[26][0]/2 + doorSizes[15][0] + doorSizes[19][0] ,doorSizes[26][1]/2 + doorSizes[18][1] + doorSizes[14][1], (float)(0.5) + doorSizes[26][2]/2}, // 26
};
//ILunimation
GLfloat   R = 1;		 	 
GLfloat  G = 1;		
GLfloat   B = 1;
GLfloat intensity = 0.5;
GLfloat lightPos[4]    = {-12.5, 5.0, 12.5, 1.0 };   
GLfloat lightAmb[4] = { 0, 0, 0, 0.0 };
GLfloat lightDif[4] = { (float)R,(float) G,(float) B, 1.0 };
GLfloat lightSpec[4] = {(float) R,(float) G,(float) B, 1.0 };

GLfloat  chromeAmb []={ 0.25 ,0.25 ,0.25 };
GLfloat  chromeDif []={   0.4 ,0.4 ,0.4 };
GLfloat  chromeSpec []={ 0.774597 ,0.774597 ,0.774597 };
GLint  chromeCoef = 0.6 *128;
//Screen padding
void config();

#endif