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
	
	DoorLeft();

	//DoorRight();
}
 void DoorLeft(){
//Porta 1
	 for(int i = 0; i < 14; i++){
		 if(doorSizes[i][3] == 1){
		glPushMatrix();
			glColor4f(GREEN);
			glTranslatef(doorLocation[i][0], doorLocation[i][1], doorLocation[i][2]);
			glScalef(doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]);
			glRotatef(90,1,0,0);
			glutSolidCube(1);
		glPopMatrix();
		 }
		else{
			glPushMatrix();
			glTranslatef(doorLocation[i][0], doorLocation[i][1], doorLocation[i][2]);
			if(doorSizes[i][3] == 2)
				glScalef(doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]); 
			else if(doorSizes[i][3] == 3){
				glRotatef(180,0,0,1);
				glScalef(-doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]); 
			}
			else if(doorSizes[i][3] == 4){
				glRotatef(180,0,0,1);
				glScalef(doorSizes[i][0],-doorSizes[i][1],doorSizes[i][2]); 
			}
			else if(doorSizes[i][3] == 5){
				glScalef(-doorSizes[i][0],-doorSizes[i][1],doorSizes[i][2]); 
			}
			glRotatef(90,1,0,0);
			DrawTetraedron();
			glPopMatrix();
		}
	}
	
	/* glPushMatrix();
	glTranslatef(3 + 1, 3 * 1.0 /2 + 7, 0);
	glScalef(2,3,1);
	glRotatef(90,1,0,0);
	DrawTetraedron();
	glPopMatrix();
 */


	glVertexPointer(3, GL_FLOAT, 0, squarevertex); // Sets up the vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
 }

 void DoorRight(){
;
 }

 void DrawTetraedron(){
	glVertexPointer(3, GL_FLOAT, 0, triangle3d); // Sets up the vertex arrays
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,trianglefront);
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,triangleback);
	for(int i = 0; i < 3; i++){
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, t3d[i]);
	}
 }