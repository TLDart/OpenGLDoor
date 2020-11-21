#include "keyboard.h"
float step = 0.1, anglestep = 1;
void keyboard(unsigned char key, int x, int y) {
	switch(key){

		case 'd':
		if(ceil(offset *100) /100+ step > 4.02|| ceil(offset *100) /100 +step < 0) {
				step = -step;
			}
			offset =offset + step;
			
			//std::cout << offset << step << std::endl;
			break;
		case 'w':
		if(rotangle == 70 || rotangle == -1) anglestep = -anglestep;
			rotangle = rotangle + anglestep;
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