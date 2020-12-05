#include "lighting.h"

void ilumina() {
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glEnable(GL_LIGHT0);

	// Focus
	glLightfv(GL_LIGHT1, GL_POSITION, Spot_Pos);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Spot_Color);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, Spot_Att[0]);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, Spot_Att[1]);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, Spot_Att[2]);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, Spot_opening);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Spot_Direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, Spot_Exp);

	drawLaserRoom();

	updateLights();

}

void drawLaserRoom(){

	GLfloat p0[] = {10.0f, 9.0f, 1.0f, 1.0f };   
	GLfloat p1[] = {10.0f, 5.0f, 1.0f, 1.0f };   
	GLfloat p2[] = {10.0f, 1.0f, 1.0f, 1.0f };   
	GLfloat p3[] = {-10.0f, 9.0f, 1.0f, 1.0f };   
	GLfloat p4[] = {-10.0f, 5.0f, 1.0f, 1.0f };   
	GLfloat p5[] = {-10.0f, 1.0f, 1.0f, 1.0f };   
	GLfloat dira[] = {-1, 0, 0, 0 };   
	GLfloat dirb[] = {1, 0, 0, 0 };   
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glLightfv(GL_LIGHT1, GL_POSITION, p0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Spot_Color);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, Spot_Att[0]);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, Spot_Att[1]);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, Spot_Att[2]);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, Spot_opening);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dira);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, Spot_Exp);
	glLightfv(GL_LIGHT2, GL_POSITION, p1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Spot_Color);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, Spot_Att[0]);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, Spot_Att[1]);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, Spot_Att[2]);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, Spot_opening);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dira);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, Spot_Exp);
	glLightfv(GL_LIGHT3, GL_POSITION, p2);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, Spot_Color);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, Spot_Att[0]);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, Spot_Att[1]);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, Spot_Att[2]);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, Spot_opening);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, dira);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, Spot_Exp);

	glEnable(GL_LIGHT4);
	glLightfv(GL_LIGHT4, GL_POSITION, p3);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, Spot_Color);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, Spot_Att[0]);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, Spot_Att[1]);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, Spot_Att[2]);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, Spot_opening);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, dirb);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, Spot_Exp);
	glLightfv(GL_LIGHT5, GL_POSITION, p4);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, Spot_Color);
	glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, Spot_Att[0]);
	glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, Spot_Att[1]);
	glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, Spot_Att[2]);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, Spot_opening);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, dirb);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, Spot_Exp);
	glLightfv(GL_LIGHT6, GL_POSITION, p5);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, Spot_Color);
	glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, Spot_Att[0]);
	glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, Spot_Att[1]);
	glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, Spot_Att[2]);
	glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, Spot_opening);
	glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, dirb);
	glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, Spot_Exp);

}

void initLights(void) {
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	

 	/* glMaterialfv(GL_FRONT, GL_AMBIENT, chromeAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, chromeDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR,chromeSpec);
	glMaterialf(GL_FRONT, GL_SHININESS,chromeCoef);  */
	glMaterialfv(GL_FRONT, GL_AMBIENT, emeraldAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, emeraldDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR,emeraldSpec);
	glMaterialf(GL_FRONT, GL_SHININESS,emeraldCoef);
} 

void updateLights(){
	lightAmb[0] = R * intensity;
	lightAmb[1] = G * intensity;
	lightAmb[2] = B * intensity;
	lightDif[0] = R * intensity;
	lightDif[1] = G * intensity;
	lightDif[2] = B * intensity;
	lightSpec[0] = R * intensity;
	lightSpec[1] = G * intensity;
	lightSpec[2] = B * intensity;;
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glutPostRedisplay();
	} 