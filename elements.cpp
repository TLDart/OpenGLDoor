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
	glTranslatef(-8.5, 0,0);	
	DrawHandler();
	DoorLeft();
	DoorRight();
}
 void DoorLeft(){
	glColorPointer(3, GL_FLOAT, 0, color);
	glEnableClientState(GL_COLOR_ARRAY);

	 for(int i = 0; i < 14; i++){
		 if(doorSizes[i][3] == 1){
			glPushMatrix();
				if(i == 6 || i == 8) glColor4f(GRAY);
				else glColor4f(GREEN);
				glTranslatef(doorLocation[i][0] - offset, doorLocation[i][1], doorLocation[i][2]);
				glScalef(doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]);
				glRotatef(90,1,0,0);
				if(i != 6 && i != 8 ) glutSolidCube(1);
			glPopMatrix();
		 }
		else{
			glPushMatrix();
				glTranslatef(doorLocation[i][0] -offset, doorLocation[i][1], doorLocation[i][2]);
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
 }

 void DoorRight(){
	glColorPointer(3, GL_FLOAT, 0, color2);
	glEnableClientState(GL_COLOR_ARRAY);

	for(int i = 14; i < 26; i++){
			if(doorSizes[i][3] == 1){
			glPushMatrix();
				if(i == 22) glColor4f(YELLOW);
				else glColor4f(BLUE); 
				//glColor3ub( rand()%255, rand()%255, rand()%255 );
				glTranslatef(doorLocation[i][0] +offset, doorLocation[i][1], doorLocation[i][2]);
				glScalef(doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]);
				glRotatef(90,1,0,0);
				glutSolidCube(1);
			glPopMatrix();
			}
		else{
			glPushMatrix();
				glTranslatef(doorLocation[i][0] + offset, doorLocation[i][1], doorLocation[i][2]);
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
 }
 
 void DrawHandler(){
			glPushMatrix();
				glColor4f(RED);
				glTranslatef(doorLocation[26][0] +offset, doorLocation[26][1], doorLocation[26][2]);
				glTranslatef(0,doorSizes[26][1]/2,0);
				glRotatef(-rotangle, 1,0,0);
				glTranslatef(0,-doorSizes[26][1]/2,0);
				glScalef(doorSizes[26][0],doorSizes[26][1],doorSizes[26][2]);
				glRotatef(90,1,0,0);
				glutSolidCube(1);
			glPopMatrix();

 }

 void DrawTetraedron(){
	glVertexPointer(3, GL_FLOAT, 0, triangle3d); // Sets up the vertex arrays
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,trianglefront);
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,triangleback);
	for(int i = 0; i < 3; i++){
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, t3d[i]);
	}
 }