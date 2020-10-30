#include "elements.h"
void drawEixos(){
	glColor4f(ORANGE);
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(10, 0, 0);
	glEnd();
	glColor4f(GREEN);
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 10, 0);
	glEnd();
	glColor4f(CYAN);
	glBegin(GL_LINES);
		glVertex3i(0, 0, 0);
		glVertex3i(0, 0, 10);
	glEnd();

}

void DrawDoor(){
	
	//DoorLeft();
	//DoorRight();
	
	


}
 void DoorLeft(){
//Porta 1
	 for(int i = 0; i < 14; i++){
		glPushMatrix();
			float randomR = (double)rand() / (RAND_MAX);
			float randomG = (double)rand() / (RAND_MAX);
			float randomB = (double)rand() / (RAND_MAX);
			glColor3f(randomR,randomG,randomB);
			glTranslatef(doorLocation[i][0], doorLocation[i][1], doorLocation[i][2]);
			glScalef(doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]);
			glRotatef(90,1,0,0);
			//glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT,squareorientation );
			glutSolidCube(1);
		glPopMatrix();
	}
	glVertexPointer(3, GL_FLOAT, 0, trianglevertex); // Sets up the vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);

	glPushMatrix();
	glTranslatef(3+1, 4/2, 0);
	glRotatef(180,0,0,1);
	glScalef(2,4,1);
	glRotatef(90,1,0,0);
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,squareorientation);
	glPopMatrix();
	
	glVertexPointer(3, GL_FLOAT, 0, trianglevertex2); // Sets up the vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glPushMatrix();
	glTranslatef(3 + 1, 3 * 1.0 /2 + 7, 0);
	glScalef(2,3,1);
	glRotatef(90,1,0,0);
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,triangleorientation);
	glPopMatrix();



	glVertexPointer(3, GL_FLOAT, 0, squarevertex); // Sets up the vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
 }

 void DoorRight(){
;
 }