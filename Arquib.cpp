#include "Arquib.hpp"

Arquib::Arquib(float x, float z, float w1, float w2, float h, float d, float t){
     posX = x;
     posZ = z;
     width1 = w1;
     width2 = w2;
     height = h;
     depth = d;
     tol = t;
}

Arquib::~Arquib(){
	delete texturas;
}

void Arquib::desenha(){
	//CARREGANDO A TEXTURA
	static const int erro = (!cargarTGA("multidao.tga", &texturas[0]));
	//SE O ARQUIVO NAO EXISTE
	if(erro) {
		exit(0);
	}

	glEnable(GL_TEXTURE_2D);
       
	glBindTexture(GL_TEXTURE_2D,texturas[0].ID);
	
	glColor3f(.5,.5,.5);
	glBegin(GL_QUADS);
		glTexCoord2f(0,0); glVertex3f(posX - tol, height, posZ - tol - depth);
		glTexCoord2f(14,0);  glVertex3f(posX + width1 + tol, height, posZ - tol - depth);
		glTexCoord2f(14,5);   glVertex3f(posX + width1 + tol, 0, posZ - tol);
		glTexCoord2f(0,5);  glVertex3f(posX - tol, 0, posZ - tol);

		glTexCoord2f(0, 0); glVertex3f(posX - tol - depth, height, posZ + width2 + tol);
		glTexCoord2f(18, 0);  glVertex3f(posX - tol - depth, height, posZ - tol);
		glTexCoord2f(18, 5);   glVertex3f(posX - tol, 0, posZ - tol);
		glTexCoord2f(0, 5);  glVertex3f(posX - tol, 0, posZ + width2 + tol);

		glTexCoord2f(0,5);  glVertex3f(posX - tol, 0, posZ + width2 + tol);
		glTexCoord2f(18,5);   glVertex3f(posX + width1 + tol, 0, posZ + width2 + tol);
		glTexCoord2f(18,0);  glVertex3f(posX + width1 + tol, height, posZ + width2 + depth + tol);
		glTexCoord2f(0,0); glVertex3f(posX - tol, height, posZ + width2 + depth + tol);

		glTexCoord2f(0,5);  glVertex3f(posX + width1 + tol, 0, posZ - tol);
		glTexCoord2f(0,0); glVertex3f(posX + width1 + depth + tol, height, posZ - tol);
		glTexCoord2f(14,0);  glVertex3f(posX + width1 + depth + tol, height, posZ + width2 + tol);
		glTexCoord2f(14,5);   glVertex3f(posX + width1 + tol, 0, posZ + width2 + tol);

	glEnd();
	
	//CANTOS
	glBegin(GL_TRIANGLES);
	     glTexCoord2f(0.5, 5); glVertex3f(posX - tol, 0, posZ - tol);
	     glTexCoord2f(5, 0);   glVertex3f(posX - tol - depth, height, posZ - tol);
	     glTexCoord2f(0, 0);    glVertex3f(posX - tol, height, posZ - tol - depth);

	     glTexCoord2f(0.5, 5); glVertex3f(posX + width1 + tol, 0, posZ - tol);
	     glTexCoord2f(5, 0);   glVertex3f(posX + width1 + tol, height, posZ - tol - depth);
	     glTexCoord2f(0, 0);    glVertex3f(posX + width1 + tol + depth, height, posZ - tol);

	     glTexCoord2f(0.5, 5); glVertex3f(posX + width1 + tol, 0, posZ + width2 + tol);
	     glTexCoord2f(5, 0);   glVertex3f(posX + width1 + tol + depth, height, posZ + width2 + tol);
	     glTexCoord2f(0, 0);    glVertex3f(posX + width1 + tol, height, posZ + width2 + tol + depth);

	     glTexCoord2f(0.5, 5); glVertex3f(posX - tol, 0, posZ + width2 + tol);
	     glTexCoord2f(5, 0);   glVertex3f(posX - tol, height, posZ + width2 + tol + depth);
	     glTexCoord2f(0, 0);    glVertex3f(posX - tol - depth, height, posZ + width2 + tol);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	
}
