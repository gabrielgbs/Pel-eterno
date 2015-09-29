#include"Trave.hpp"

Trave::Trave(float x, float z, float w, float d){
     posX = (x+x+w)/2;
     posZ1 = z;
     posZ2 = z + d;
     
     t1e = gluNewQuadric();
     t1d = gluNewQuadric();
     t2e = gluNewQuadric();
     t2d = gluNewQuadric();
     t1c = gluNewQuadric();
     t2c = gluNewQuadric();
}

/*
Trave::~Trave(){
	delete t1e;
	delete t1d;
	delete t1c;
	delete t2e;
	delete t2d;
	delete t2c;
}
*/

void Trave::desenha(){

	glColor3f(TRAVE_COR);

	gluQuadricDrawStyle(t1e, GLU_FILL);
	glPushMatrix();
		glTranslatef(posX - TRAVE_LARGURA/2, TRAVE_ALTURA, posZ1);
		glRotated(90,1,0,0);
		gluCylinder(t1e,TRAVE_ESPESS, TRAVE_ESPESS, TRAVE_ALTURA,10,2);
	glPopMatrix();
	

	gluQuadricDrawStyle(t1d, GLU_FILL);
	glPushMatrix();
		glTranslatef(posX + TRAVE_LARGURA/2, TRAVE_ALTURA, posZ1);
		glRotated(90,1,0,0);
		gluCylinder(t1d,TRAVE_ESPESS, TRAVE_ESPESS, TRAVE_ALTURA,10,2);
	glPopMatrix();
	

	gluQuadricDrawStyle(t2e, GLU_FILL);
	glPushMatrix();
		glTranslatef(posX + TRAVE_LARGURA/2, TRAVE_ALTURA, posZ2);
		glRotated(90,1,0,0);
		gluCylinder(t2e,TRAVE_ESPESS, TRAVE_ESPESS, TRAVE_ALTURA,10,2);
	glPopMatrix();
	

	gluQuadricDrawStyle(t2d, GLU_FILL);
	glPushMatrix();
		glTranslatef(posX - TRAVE_LARGURA/2, TRAVE_ALTURA, posZ2);
		glRotated(90,1,0,0);
		gluCylinder(t2d,TRAVE_ESPESS, TRAVE_ESPESS, TRAVE_ALTURA,10,2);
	glPopMatrix();
	
	gluQuadricDrawStyle(t1c, GLU_FILL);
	glPushMatrix();
		glTranslatef(posX - TRAVE_LARGURA/2, TRAVE_ALTURA, posZ1);
		glRotated(90,0,1,0);
		gluCylinder(t1c,TRAVE_ESPESS, TRAVE_ESPESS, TRAVE_LARGURA,10,2);
	glPopMatrix();

	gluQuadricDrawStyle(t2c, GLU_FILL);
	glPushMatrix();
		glTranslatef(posX - TRAVE_LARGURA/2, TRAVE_ALTURA, posZ2);
		glRotated(90,0,1,0);
		gluCylinder(t2c,TRAVE_ESPESS, TRAVE_ESPESS, TRAVE_LARGURA,10,2);
	glPopMatrix();





	//DESENHO DAS REDES
	glLineWidth(0.01);
     glBegin(GL_LINES);
     for(i = 0; i<=GRADE;i++){
      //REDE1
		//LADO1 
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ1);
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ1-TRAVE_ALTURA);

          glVertex3f(posX - TRAVE_LARGURA/2,0,posZ1 - TRAVE_ALTURA*i/GRADE);
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA,posZ1 - TRAVE_ALTURA*i/GRADE);
          //FUNDO DE REDE
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ1-TRAVE_ALTURA);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ1-TRAVE_ALTURA);

          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, 0, posZ1 - TRAVE_ALTURA);
          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ1 - TRAVE_ALTURA);

          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, 0, posZ1 - TRAVE_ALTURA);
          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ1 - TRAVE_ALTURA);
          //LADO2
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ1);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ1-TRAVE_ALTURA);

          glVertex3f(posX + TRAVE_LARGURA/2,0,posZ1 - TRAVE_ALTURA*i/GRADE);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA,posZ1 - TRAVE_ALTURA*i/GRADE);
          //CIMA
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA,posZ1-TRAVE_ALTURA*i/GRADE);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA,posZ1-TRAVE_ALTURA*i/GRADE);

          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ1);
          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ1 - TRAVE_ALTURA);

          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ1);
          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ1 - TRAVE_ALTURA);
     
     
       //REDE2
		 //LADO1 
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ2);
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ2 + TRAVE_ALTURA);

          glVertex3f(posX - TRAVE_LARGURA/2,0,posZ2 + TRAVE_ALTURA*i/GRADE);
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA,posZ2 + TRAVE_ALTURA*i/GRADE);
          //FUNDO DE REDE
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ2 + TRAVE_ALTURA);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ2 + TRAVE_ALTURA);

          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, 0, posZ2 + TRAVE_ALTURA);
          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ2 + TRAVE_ALTURA);

          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, 0, posZ2 + TRAVE_ALTURA);
          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ2 + TRAVE_ALTURA);
          //LADO2
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ2);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA*i/GRADE,posZ2 + TRAVE_ALTURA);

          glVertex3f(posX + TRAVE_LARGURA/2,0,posZ2 + TRAVE_ALTURA*i/GRADE);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA,posZ2 + TRAVE_ALTURA*i/GRADE);
          //CIMA
          glVertex3f(posX - TRAVE_LARGURA/2,TRAVE_ALTURA,posZ2 + TRAVE_ALTURA*i/GRADE);
          glVertex3f(posX + TRAVE_LARGURA/2,TRAVE_ALTURA,posZ2 + TRAVE_ALTURA*i/GRADE);

          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ2);
          glVertex3f(posX - TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ2 + TRAVE_ALTURA);

          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ2);
          glVertex3f(posX + TRAVE_LARGURA/2*i/GRADE, TRAVE_ALTURA, posZ2 + TRAVE_ALTURA);
     }
     
     glEnd();

     
}
