#include "keyboard.h"
float step = 0.1;
void keyboard(unsigned char key, int x, int y) {
	switch(key){

		case 'd':
		if(ceil(offset *100) /100+ step > 4.02|| ceil(offset *100) /100 +step < 0) {
				std::cout<< "here" << std::endl;
				step = -step;
			}
			offset =offset + step;
			
			std::cout << offset << step << std::endl;
			glutPostRedisplay();
			break;
	case 27:
		exit(0);
		break;
	}

}

void teclasNotAscii(int key, int x, int y) {
	if(observer){
		obsT[0] = 0; obsT[1] = 0; obsT[2] = 0;
		
		if (key == GLUT_KEY_UP)    obsP[1] = obsP[1] + 0.5;
		if (key == GLUT_KEY_DOWN)  obsP[1] = obsP[1] - 0.5;
		if (key == GLUT_KEY_LEFT)  aVisao = aVisao + 0.1;
		if (key == GLUT_KEY_RIGHT) aVisao = aVisao - 0.1;

		if (obsP[1] > yC)   obsP[1] = yC;
		if (obsP[1] < -yC)  obsP[1] = -yC;
		obsP[0] = rVisao * cos(aVisao);
		obsP[2] = rVisao * sin(aVisao);
	}
	else{
		if (key == GLUT_KEY_UP)    obsT[1] = obsT[1] + 0.5;
		if (key == GLUT_KEY_DOWN)  obsT[1] = obsT[1] - 0.5;
		if (key == GLUT_KEY_LEFT)  obsT[0] = obsT[0] + 0.5;
		if (key == GLUT_KEY_RIGHT) obsT[0] = obsT[0] - 0.5;

		if (obsP[1] > yC)   obsP[1] = yC;
		if (obsP[1] < -yC)  obsP[1] = -yC;
		obsP[0] = rVisao * cos(aVisao);
		obsP[2] = rVisao * sin(aVisao);

	}
		   
	    glutPostRedisplay();

}