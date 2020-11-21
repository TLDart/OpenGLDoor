#include "lighting.h"

void ilumina() {
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glEnable(GL_LIGHT0);
}
void initLights(void) {
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	GLfloat Foco_direccao[] = { 0, 0, -1, 0 };	//��� -Z
	GLfloat Foco1_cor[]     = { 0, 1,  0, 1 };	//��� Cor da luz 1
	GLfloat Foco2_cor[]     = { 1, 0,  0, 1 };	//��� Cor da luz 2
	GLfloat Foco_ak         = 1.0;
	GLfloat Foco_al         = 0.05f;
	GLfloat Foco_aq         = 0.0f;
	GLfloat Foco_Expon      = 2.0;	
	GLfloat		aberturaFoco = 25.0;		//.. angulo inicial do foco
	GLfloat Pos2[] = {  0.0f, 5.0f, 10.0f, 1.0f };   // Foco 2 


	//�����������������������������������������������Foco Direita
	glLightfv(GL_LIGHT1, GL_POSITION, Pos2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Foco2_cor);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, Foco_ak);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, Foco_al);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, Foco_aq);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, aberturaFoco);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Foco_direccao);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, Foco_Expon);

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