#include "main.h"
void config(void)
{
	glClearColor(BLACK);		// Clear the current screen
	glEnable(GL_DEPTH_TEST);	//Enable Depth 
	glShadeModel(GL_SMOOTH);	// Color Interpolation	

	loadTextures();
	/* glEnable(GL_CULL_FACE);		// Enable Cullfacing
	glCullFace(GL_BACK); */		// Select the side of cullfacing
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texturas);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	srand(1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the pipeline
	//Pipeline Stages	
	//Viewport
	glViewport(0, 0, WIDTH, HEIGHT);
	// Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Observer View
	gluPerspective(anguloZ, (float)WIDTH / HEIGHT, 0.1, 9999);	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsP[0], obsP[1], obsP[2], obsT[0], obsT[1], obsT[2], 0, 1, 0);

	//Draw Objects
	drawEixos();
	DrawDoor();

	glutSwapBuffers(); // Dwap the created buffer with the current one
}


void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(msec, Timer, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // Start GLut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//Inits the display mode, RBG for RBG colors, Double to double the buffer window, depth for a deptth buffer
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(WIDTH, HEIGHT); // Sets the position for the window to be displayed in the user screen
	glutCreateWindow("OpenGL Door");

	config();

	glutSpecialFunc(arrowKeys); // Glut Special Functionality
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard); // Glut Keyboard Functionality
	glutTimerFunc(msec, Timer, 1);

	glutMainLoop();

	return 0;
}



