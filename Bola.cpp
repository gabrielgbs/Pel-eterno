#include "Bola.hpp"

Bola::Bola(){
	posX = posZ = 0;
	posY = RAIOBOLA;
	bol = gluNewQuadric();
}

Bola::Bola(double x, double y, double z){
	posX = x;
	posY = y;
	posZ = z;
	if (posY < RAIOBOLA) posY = RAIOBOLA;
	bol = gluNewQuadric();
}

Bola::~Bola(){
	delete texturas;
}

void Bola::setPos(double x,double y,double z){
	posX = x;
	posY = y;
	posZ = z;
	if (posY < RAIOBOLA) posY = RAIOBOLA;
}

double Bola::getPosX(){
	return posX;
}

double Bola::getPosY(){
	return posY;
}

double Bola::getPosZ(){
	return posZ;
}

void Bola::desenha(){
	//CARREGANDO A TEXTURA
	static const int erro = (!cargarTGA("penalty.tga", &texturas[0]));
	//SE O ARQUIVO NAO EXISTE
	if(erro) {
		exit(0);
	}

	glEnable(GL_TEXTURE_2D);
       
	glBindTexture(GL_TEXTURE_2D,texturas[0].ID);
	
	//gluQuadricDrawStyle(bol, GLU_FILL);
	gluQuadricTexture (bol, GL_TRUE );
	glPushMatrix();
		glTranslatef(posX, posY, posZ);
		glRotatef(-90,2,.5,1);
		gluSphere (bol, RAIOBOLA, 10, 10);
	glPopMatrix();
	
	glDisable(GL_TEXTURE_2D);
/*
	glColor3f(CORBOLA);
	glPushMatrix();
		glTranslated(posX,posY,posZ);
		glutSolidSphere(RAIOBOLA,15,15);
	glPopMatrix();
	*/
}
