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
	
	//Porta 1
	glPushMatrix();
		glColorPointer(3,GL_FLOAT,0,cores);
		glTranslatef(doorSizex/2 - offset,doorSizey/2 + 0.5, 0);
		glScalef(doorSizex,doorSizey,1);
		glRotatef(90,1,0,0);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, poligono);
	glPopMatrix();
	//Door Lever
	glPushMatrix();
		glColorPointer(3,GL_FLOAT,0,cores);
		glTranslatef(doorSizex/2 + doorSizex + offset,doorSizey/2 + 0.5, 0.1);
		//glScalef(doorSizex,doorSizey,1);
		glTranslatef(0,0.5,0);
		glRotatef(angle - rotangle,1,0,0);
		glTranslatef(0,0,0.5);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, poligono);
	glPopMatrix();
	// Door back level
	glPushMatrix();
		glColorPointer(3,GL_FLOAT,0,cores);
		glTranslatef(doorSizex/2 + doorSizex + offset,doorSizey/2 + 0.5, 0.1);
		glRotatef(90,1,0,0);
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, poligono);
	glPopMatrix();
	//Porta 2
	glPushMatrix();
	glColorPointer(3,GL_FLOAT,0,cores2);
	glTranslatef(doorSizex/2 + doorSizex + offset,doorSizey/2 + 0.5, 0);
	glScalef(doorSizex,doorSizey,1);
	glRotatef(90,1,0,0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, poligono);
	glPopMatrix();


}