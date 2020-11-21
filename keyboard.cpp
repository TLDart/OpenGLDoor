#include "keyboard.h"
float step = 0.1, anglestep = 1;
void keyboard(unsigned char key, int x, int y) {
	switch(key){

		case 'd':
		if(ceil(offset *100) /100+ step > 4.52|| ceil(offset *100) /100 +step < 0) {
				step = -step;
			}
			offset =offset + step;
			
			//std::cout << offset << step << std::endl;
			break;
		case 'w':
		if(rotangle == 70 || rotangle == -1) anglestep = -anglestep;
			rotangle = rotangle + anglestep;
			break;
		case 'l':
			intensity = std::min((intensity + 0.1), 1.0);
			updateLights();
			break;
		case 'k':
			intensity = std::max((intensity - 0.1), 0.0);
			updateLights();
			break;
		case 't':
			R = std::min((R + 0.1), 1.0);
			updateLights();
			break;
		case 'g':
			R = std::max((R - 0.1), 0.0);
			updateLights();
			break;
		case 'y':
			G = std::min((G + 0.1), 1.0);
			updateLights();
			break;
		case 'h':
			G = std::max((G - 0.1), 0.0);
			updateLights();
			break;
		case 'u':
			B = std::min((B + 0.1), 1.0);
			updateLights();
			break;
		case 'j':
			B = std::max((B - 0.1), 0.0);
			updateLights();
			break;
		case 'm':
			lightPos[0]++;
			updateLights();
			break;
		case 'n':
			lightPos[0]--;
			updateLights();
			break;
		case 'b':
			chromeSpec[0] += 0.1;
			chromeSpec[1] += 0.1;
			chromeSpec[2] += 0.1;
			glMaterialfv(GL_FRONT, GL_SPECULAR,chromeSpec);
			glutPostRedisplay();
			break;
		case 'v':
			chromeSpec[0] -= 0.1;
			chromeSpec[1] -= 0.1;
			chromeSpec[2] -= 0.1;
			glMaterialfv(GL_FRONT, GL_SPECULAR,chromeSpec);
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
	}

}

void arrowKeys(int key, int x, int y) {
		
		if (key == GLUT_KEY_UP)    {obsP[0] = obsP[0] + incProjection * cos(aProjection); obsP[2] = obsP[2] - incProjection * sin(aProjection); }
		if (key == GLUT_KEY_DOWN)  {obsP[0] = obsP[0] - incProjection * cos(aProjection); obsP[2] = obsP[2] + incProjection * sin(aProjection); }
		if (key == GLUT_KEY_LEFT)  aProjection += 0.1;
		if (key == GLUT_KEY_RIGHT) aProjection -= 0.1;

		if (obsP[1] > worldMax)   obsP[1] = worldMax;
		if (obsP[1] < -worldMax)  obsP[1] = -worldMax;

		obsT[0] = obsP[0] + rProjection * cos(aProjection);
		obsT[2] = obsP[2] - rProjection* sin(aProjection);
		   
	    glutPostRedisplay();

}