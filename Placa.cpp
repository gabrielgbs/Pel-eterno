#include "Placa.hpp"

Placa::Placa(){
	posX = posY= posZ = 0;
}

Placa::Placa(double x, double y, double z){
	posX = x;
	posY = y;
	posZ = z;
}


void Placa::setPos(double x,double y,double z){
	posX = x;
	posY = y;
	posZ = z;
}

double Placa::getPosX(){
	return posX;
}

double Placa::getPosY(){
	return posY;
}

double Placa::getPosZ(){
	return posZ;
}

void Placa::desenha(){
    //criar placa

    //inicializar o conteudo da lista "placafundo"
    static GLuint placaFundo = glGenLists(1);
    glNewList(placaFundo, GL_COMPILE);
        glScalef(0.0, 1.0, 60.0);
        glColor3f(1.0f,1.0f,1.0f);
        //glutSolidCube(1.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0,1);  glVertex3f(0,0,-0.5);
			glTexCoord2f(0,0);  glVertex3f(0,1,-0.5);
			glTexCoord2f(10,0); glVertex3f(0,1,0.5);
			glTexCoord2f(10,1); glVertex3f(0,0,0.5);
		glEnd();
    glEndList();

    //inicializar o conteudo da lista "placalateral"
    static GLuint placaLateral = glGenLists(1);
    glNewList(placaLateral, GL_COMPILE);
        glScalef(0.0, 1.0, 100.0);
        glColor3f(1.0f,1.0f,1.0f);
        //glutSolidCube(1.0f);
		glBegin(GL_QUADS);
		    glTexCoord2f(0,1);  glVertex3f(0,0,-0.5);
		    glTexCoord2f(0,0);  glVertex3f(0,1,-0.5);
		    glTexCoord2f(18,0); glVertex3f(0,1,0.5);
		    glTexCoord2f(18,1); glVertex3f(0,0,0.5);
		glEnd();
    glEndList();

    //inicializar o conteudo da lista "banderinha"
	static GLuint banderinha = glGenLists(1);
	glNewList(banderinha, GL_COMPILE);
	glScalef(0.0, 5.0, 5.0);
	glColor3f(1.0f,0.0f,0.0f);
	//glutSolidCube(1.0f);
	glBegin(GL_QUAD_STRIP);
	    glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.1,0.0);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0,0.1,0.1);
		glVertex3f(0.1,0.1,0.1);
	glEnd();
	glEndList();

	//inicializar o conteudo da lista "pau_banderinha"
	static GLuint pau_banderinha = glGenLists(1);
	glNewList(pau_banderinha, GL_COMPILE);
	glScalef(0.05, 1.0, 0.05);
	glColor3f(1.0f,1.0f,1.0f);
	glutSolidCube(1.0f);
	glEndList();

	//Desenhar objetos

	static textura texturas[2];
	//CARREGANDO A TEXTURA
	static const int erro = ((!cargarTGA("bozo.tga", &texturas[0]))||(!cargarTGA("2014.tga", &texturas[1])));

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D,texturas[0].ID);
	//SE O ARQUIVO NAO EXISTE
	if(erro) {
		exit(0);
	}

    //desenhar a placaFundo esquerda
    glPushMatrix();
    glTranslatef(30.0, 0, -5.0);
    glRotatef(90,0,1,0);
    glCallList(placaFundo);
    glPopMatrix();

    //desenhar a placaFundo direita
    glPushMatrix();
    glTranslatef(30, 0, 105);
	glRotatef(-90,0,1,0);
    glCallList(placaFundo);
    glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D,texturas[1].ID);
    //desenhar a placaLateral frente
    glPushMatrix();
    glTranslatef(70, 0, 50);
    glCallList(placaLateral);
    glPopMatrix();

    //desenhar a placaLateral tras
    glPushMatrix();
    glTranslatef(-10, 0, 50);
	glRotatef(180,0,1,0);
    glCallList(placaLateral);
    glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	//desenhar o pau_banderinha1
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glCallList(pau_banderinha);
	glPopMatrix();

	//desenhar o banderinha1
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glCallList(banderinha);
	glPopMatrix();

	//desenhar o pau_banderinha2
	glPushMatrix();
	glTranslatef(60, 0.5, 0);
	glCallList(pau_banderinha);
	glPopMatrix();

	//desenhar o banderinha2
	glPushMatrix();
	glTranslatef(60, 0.5, 0);
	glCallList(banderinha);
	glPopMatrix();

	//desenhar o pau_banderinha3
	glPushMatrix();
	glTranslatef(0, 0.5, 100);
	glCallList(pau_banderinha);
	glPopMatrix();

	//desenhar o banderinha3
	glPushMatrix();
	glTranslatef(0, 0.5, 100);
	glCallList(banderinha);
	glPopMatrix();

	//desenhar o pau_banderinha4
	glPushMatrix();
	glTranslatef(60, 0.5, 100);
	glCallList(pau_banderinha);
	glPopMatrix();

	//desenhar o banderinha4
	glPushMatrix();
	glTranslatef(60, 0.5, 100);
	glCallList(banderinha);
	glPopMatrix();
	
    glDeleteLists(placaFundo, 1);
    glDeleteLists(placaLateral, 1);
    glDeleteLists(banderinha, 1);
    glDeleteLists(pau_banderinha, 1);


}
