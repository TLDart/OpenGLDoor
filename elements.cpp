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
	//DrawSolidCube(2);
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
				if(i != 6 && i != 8 ) DrawSolidCube(1);
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
				DrawTetraedron(1);
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
				DrawSolidCube(1);
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
				DrawTetraedron(1);
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

 void DrawTetraedron(float sz){
	GLuint  trianglefront[] = { 0, 1, 2 };
	GLuint  triangleback[] = { 5 ,4, 3 };
	GLuint  t3d[][4] ={
		{ 0 ,2, 5, 3 },
		{ 3 ,4, 1, 0 }, 
		{ 2 ,1, 4, 5 },
	};

	GLfloat triangle3d[]{
	 sz/2,  sz/2, -sz/2,
	-sz/2,  sz/2,  sz/2, 
	 sz/2,  sz/2,  sz/2, 
	 sz/2, -sz/2, -sz/2,
	-sz/2, -sz/2,  sz/2, 
	 sz/2, -sz/2,  sz/2,
	};
	glVertexPointer(3, GL_FLOAT, 0, triangle3d); // Sets up the vertex arrays
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,trianglefront);
	glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT,triangleback);
	for(int i = 0; i < 3; i++){
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, t3d[i]);
	}
 }

 void DrawSolidCube(float sz){
	GLfloat cube[] = {
	 sz/2, -sz/2, -sz/2,
	-sz/2, -sz/2, -sz/2,
	-sz/2, -sz/2,  sz/2, 
	 sz/2, -sz/2,  sz/2,
	 sz/2,  sz/2, -sz/2,
	-sz/2,  sz/2, -sz/2,
	-sz/2,  sz/2,  sz/2, 
	 sz/2,  sz/2,  sz/2,  
	};
	GLuint    c3d[][4] = {
    {0, 3, 2, 1 }, 
    {0, 4, 7, 3 }, 
    {1, 5, 4, 0 }, 
    {2, 6, 5, 1 }, 
    {3, 7, 6, 2 }, 
    {7, 4, 5, 6 }, 
    };
	glVertexPointer(3, GL_FLOAT, 0, cube); // Sets up the vertex arrays
	for(int i = 0; i < 6; i++){
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, c3d[i]);
	}
 }