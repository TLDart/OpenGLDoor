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

	updateLights();

}
void initLights(void) {
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	

	glMaterialfv(GL_FRONT, GL_AMBIENT, chromeAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, chromeDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR,chromeSpec);
	glMaterialf(GL_FRONT, GL_SHININESS,chromeCoef);
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