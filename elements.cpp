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
	glPushMatrix();
	glTranslatef(-10, 0,0);	
	DrawHandler();
	DoorLeft();
	DoorRight(); 
	glPopMatrix();
	//DrawWall();
	//glColorPointer(3, GL_FLOAT, 0, color);
	//DrawSolidCube(1);
	//DrawSolidPrism(1, textures[0]);
}
 void DoorLeft(){
	glColorPointer(3, GL_FLOAT, 0, color);

	 for(int i = 0; i < 14; i++){
		 if(doorSizes[i][3] == 1){
			glPushMatrix();
				glTranslatef(doorLocation[i][0] - offset, doorLocation[i][1], doorLocation[i][2]);
				glScalef(doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]);
				glRotatef(90,1,0,0);
				if(i != 6 && i != 8 ) DrawSolidCube(1,textures[0]);
				else{
						;
				}
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
				DrawSolidPrism(1, textures[0]);
			glPopMatrix();
		}
	 }
 }

 void DoorRight(){
	glColorPointer(3, GL_FLOAT, 0, color2);

	for(int i = 14; i < 26; i++){
			if(doorSizes[i][3] == 1){
			glPushMatrix();
				//glColor3ub( rand()%255, rand()%255, rand()%255 );
				glTranslatef(doorLocation[i][0] +offset, doorLocation[i][1], doorLocation[i][2]);
				glScalef(doorSizes[i][0],doorSizes[i][1],doorSizes[i][2]);
				glRotatef(90,1,0,0);
				if(i == 22) DrawSolidCube(1, textures[2]);
				else DrawSolidCube(1, textures[0]);
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
				DrawSolidPrism(1, textures[0]);
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
		DrawSolidCube(1, textures[1]);
	glPopMatrix();

 }

void DrawScene(int dg){
	float w =24, h = 30;
	GLfloat square[][3] ={
		{-0.5,0,-0.5},
		{0.5,0,-0.5},
		{0.5,0,0.5},
		{-0.5,0,0.5},
	};

	//Base	
	glPushMatrix();
		glTranslatef(-0.5,-0.5,0);
		glScaled(w,1,h);
		glutSolidCube(1);
	glPopMatrix();

	//Ceiling
	glPushMatrix();
		glTranslatef(-0.5,10,0);
		glScaled(w,1,h);
		glutSolidCube(1);
	glPopMatrix();

	// Wall Left	
	glPushMatrix();
		glTranslatef(w/2,5,0);
		glScaled(1,10,h);
		glutSolidCube(1);
	glPopMatrix();

	// Wall Left	
	glPushMatrix();
    glTranslatef(-w/2 - 1,5,0); // Door Not symetric
		glScaled(1,10,h);
		glutSolidCube(1);
	glPopMatrix();

	//Behind Door	
	glPushMatrix();
		glTranslatef(-9,5,-1);
		glScaled(7,10,1);
		glutSolidCube(1);
	glPopMatrix();

	//Behind Door
	glPushMatrix();
		glTranslatef(8,5,-1);
		glScaled(7,10,1);
		glutSolidCube(1);
	glPopMatrix();

	//Back Wall
	/* glPushMatrix();
		glTranslatef(0,5,-(h/2));
		glRotatef(90,1,0,0);
		glScaled(w,1,10);
		glutSolidCube(1);
	glPopMatrix(); */

	glPushMatrix();
		glTranslatef(-0.5,0,-(h/2 + 5));
		DrawMalha(w,10, dg);
	glPopMatrix();



}

void DrawLight(){
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(lightPos[0], lightPos[1], lightPos[2]);
	glColor3f(1,1,0);
	glutSolidCube(1);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(Spot_Pos[0], Spot_Pos[1], Spot_Pos[2]);
	glColor3f(1,0,0);
	glutSolidCube(1);
	glPopMatrix();
	glEnable(GL_LIGHTING); 
}

void DrawTransparent(){
	glMaterialfv(GL_FRONT, GL_AMBIENT, chromeAmbTrans);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, chromeDifTrans);
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(-10, 0,0);	
	glPushMatrix();
		glTranslatef(doorLocation[6][0] - offset, doorLocation[6][1], doorLocation[6][2]);
		glScalef(doorSizes[6][0],doorSizes[6][1],doorSizes[6][2]);
		glRotatef(90,1,0,0);
		glutSolidCube(1); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef(doorLocation[8][0] - offset, doorLocation[8][1], doorLocation[8][2]);
		glScalef(doorSizes[8][0],doorSizes[8][1],doorSizes[8][2]);
		glRotatef(90,1,0,0);
		glutSolidCube(1); 
	glPopMatrix();
	glBlendFunc (GL_ONE, GL_ZERO);
	glDisable(GL_BLEND);


}
void DrawMalha(double w,  double h, int degree){
	double wdim = w/degree;
	double hdim = h/degree;


	glPushMatrix();
		glTranslatef(0, 0, 8);  
		glTranslatef((float)-w/2,0, 0);
		glNormal3f(0, 0, 1);       

		glBegin(GL_QUADS);
		for (int i = 0; i < degree; i++)
			for (int j = 0; j < degree; j++) {
				glVertex3d((double) wdim * j , (double)hdim * i, 0);
				glVertex3d((double)wdim* (j + 1),(double)hdim * i, 0);
				glVertex3d((double)wdim * (j + 1) ,(double)hdim * (i + 1), 0);
				glVertex3d((double)wdim * j,(double) hdim * (i + 1), 0);
				/* glVertex3f((float) 0, 0, 0);
				glVertex3f((float)10,(float)0, 0);
				glVertex3f((float)10 ,(float)10, 0);
				glVertex3f((float)0,(float)10, 0); */
			}
		glEnd();
	glPopMatrix();



}

 void DrawSolidPrism(float sz, GLuint &tex){
	GLuint  ttf[][3] = {{ 0, 1, 2 },{ 5 ,4, 3 }};
	GLuint  t3d[][4] ={
		{ 0 ,2, 5, 3 },
		{ 3 ,4, 1, 0 }, 
		{ 2 ,1, 4, 5 },
	};
	GLfloat nttf[][3]={
	{0.0, 1.0, 0.0}, //Top 
	{0.0, -1.0, 0.0} //Bottom
	};
	GLfloat normals[][3] ={
	{1.0, 0.0, 0.0}, //Right
	{0.0, 0.5, 0.5}, //Diag
	{0.0, 0.0, 1.0}, //Front 
	};
	GLuint coords[][2] ={
		{0,0},
		{1,0},
		{1,1},
		{0,1},
	};
	GLfloat body[]{
	 sz/2,  sz/2, -sz/2,
	-sz/2,  sz/2,  sz/2, 
	 sz/2,  sz/2,  sz/2, 
	 sz/2, -sz/2, -sz/2,
	-sz/2, -sz/2,  sz/2, 
	 sz/2, -sz/2,  sz/2,
	};
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	for(int i = 0; i < 3; i++){
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3d(1,1,0);
		for(int j = 0; j < 4; j++){
			glVertex3f(body[t3d[i][j] * 3] , body[t3d[i][j]* 3 + 1] , body[t3d[i][j]* 3 + 2] );
			glNormal3f(normals[i][0],normals[i][2],normals[i][2]);
			glTexCoord2f(coords[j][0], coords[j][1]);
		}
		glEnd();
		glPopMatrix();
	}
	for(int i = 0; i < 2; i++){
		glPushMatrix();
		glBegin(GL_TRIANGLES);
		glColor3d(1,1,0);
		for(int j = 0; j < 3; j++){
			glVertex3f(body[ttf[i][j] * 3] , body[ttf[i][j] * 3 + 1] , body[ttf[i][j] * 3 + 2] );
			glNormal3f(nttf[i][0],nttf[i][2],nttf[i][2]);
			glTexCoord2f(coords[j+ 1][0], coords[j+1][1]);
		}
		glEnd();
		glPopMatrix();
	} 
glDisable(GL_TEXTURE_2D);
	
 }

 void DrawSolidCube(float sz, GLuint &tex){
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
	GLfloat normals[][3] ={
	{0.0, -1.0, 0.0}, //Bottom 
	{1.0, 0.0, 0.0}, //Right
	{0.0, 0.0, -1.0}, //Back
	{-1.0, 0.0, 0.0}, //Left 
	{0.0, 0.0, 1.0}, //Front 
	{0.0, 1.0, 0.0}, //Top
	{0.0, 1.0, 0.0}
	};

	GLuint    c3d[][4] = {
    {0, 3, 2, 1 }, 
    {0, 4, 7, 3 }, 
    {1, 5, 4, 0 }, 
    {2, 6, 5, 1 }, 
    {3, 7, 6, 2 }, 
    {7, 4, 5, 6 }, 
    };

	GLuint coords[][2] ={
		{0,0},
		{1,0},
		{1,1},
		{0,1},
	};

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	for(int i = 0; i < 6; i++){
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3d(1,1,0);
		for(int j = 0; j < 4; j++){
			glVertex3f(cube[c3d[i][j] * 3] , cube[c3d[i][j]* 3 + 1] , cube[c3d[i][j]* 3 + 2] );
			glNormal3f(normals[i][0],normals[i][2],normals[i][2]);
			glTexCoord2f(coords[j][0], coords[j][1]);
		}
		glEnd();
		glPopMatrix();
	}
	glDisable(GL_TEXTURE_2D);

 }