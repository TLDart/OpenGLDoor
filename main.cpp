#include "main.h"
GLint   luzR = 1;		 	 
GLint   luzG = 1;		
GLint   luzB = 1;
GLfloat localPos[4]    = { 1, 2.0, 2.0, 1.0 };   
GLfloat localCorAmb[4] = { 0, 0, 0, 0.0 };
GLfloat localCorDif[4] = { luzR, luzG, luzB, 1.0 };
GLfloat localCorEsp[4] = { luzR, luzG, luzB, 1.0 };
GLfloat intensidadeDia = 0.8;
GLfloat luzGlobalCorAmb[4] = { intensidadeDia, intensidadeDia,intensidadeDia, 1.0 };   // 

GLfloat  esmeraldAmb []={ 0.0215 ,0.1745 ,0.0215 };
GLfloat  esmeraldDif []={   0.07568 ,0.61424 ,0.07568 };
GLfloat  esmeraldSpec []={ 0.633 ,0.727811 ,0.633 };
GLint    esmeraldCoef = 0.6 *128;

void ilumina() {
	glLightfv(GL_LIGHT0, GL_POSITION, localPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);
	glEnable(GL_LIGHT0);
}
void initLights(void) {
	//����������������������������������������������������� Ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCorAmb);

	//����������������������������������������������������� Teto
	glLightfv(GL_LIGHT0, GL_POSITION, localPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, localCorAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, localCorDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, localCorEsp);

	glMaterialfv(GL_FRONT, GL_AMBIENT, esmeraldAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, esmeraldDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, esmeraldSpec);
	glMaterialf(GL_FRONT, GL_SHININESS, esmeraldCoef);
}
void config(void)
{
	glClearColor(BLACK);		// Clear the current screen
	glEnable(GL_DEPTH_TEST);	//Enable Depth 
	glShadeModel(GL_SMOOTH);	// Color Interpolation	

	loadTextures();
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	initLights();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	
	
	glEnable(GL_TEXTURE_2D);
	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	srand(1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the pipeline
	//Pipeline Stages	
	//Viewport
	glViewport(0, 0, width, height);
	// Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Observer View
	gluPerspective(anguloZ, (float)width / height, 0.1, 9999);	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], obsT[0], obsT[1], obsT[2], 0, 1, 0);

	//Lighting
	ilumina();

	//Draw Objects
	drawEixos();
	DrawDoor();

	glutSwapBuffers(); // Dwap the created buffer with the current one
}


void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(msec, Timer, 1);
}

GLvoid resize(GLsizei w, GLsizei h) {
	width= w;
	height = h;
	glViewport(0, 0, width, height);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // Start GLut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//Inits the display mode, RBG for RBG colors, Double to double the buffer window, depth for a deptth buffer
	glutInitWindowSize(width, height);
	glutInitWindowPosition(width/2, height/2); // Sets the position for the window to be displayed in the user screen
	glutCreateWindow("OpenGL Door");

	config();

	glutSpecialFunc(arrowKeys); // Glut Special Functionality
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard); // Glut Keyboard Functionality
	glutTimerFunc(msec, Timer, 1);

	glutMainLoop();

	return 0;
}



