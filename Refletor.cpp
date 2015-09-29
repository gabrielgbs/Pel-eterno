#include "Refletor.hpp"

Refletor::Refletor(){
	posX = posY= posZ = 0;
}

Refletor::Refletor(double x, double y, double z){
	posX = x;
	posY = y;
	posZ = z;
}


void Refletor::setPos(double x,double y,double z){
	posX = x;
	posY = y;
	posZ = z;
}

double Refletor::getPosX(){
	return posX;
}

double Refletor::getPosY(){
	return posY;
}

double Refletor::getPosZ(){
	return posZ;
}

void Refletor::desenha(){
     
     //Declarando variaveis para objetos luminosos
     
     static GLfloat cor_luz0[] = { 0.15, 0.15, 0.15, 1.0};
    //criar torre_sust
    
    //inicializar o conteudo da lista "torre_sust"
    static GLuint torre_sust = glGenLists(1);
    glNewList(torre_sust, GL_COMPILE);
        glScalef(0.5, 6.0, 0.5);
        glColor3f(0.0f,0.0f,0.0f);
        glutSolidCube(2.0f);
    glEndList();
    
    //criar holofote
    static GLuint holofote = glGenLists(1);
    glNewList(holofote, GL_COMPILE);
        glScalef(1.5,5.0,10.0);
        glColor3f(1.0f,1.0f,1.0f);
        glMaterialfv(GL_FRONT, GL_EMISSION, cor_luz0);
        glutSolidCube(1.0f);
    glEndList();
    
    //desenhar a refletor
    
    //desenhar o torre1
    glPushMatrix();
    glTranslatef(posX-28, posY+8.5, posZ-28);
    glCallList(torre_sust);
    glPopMatrix();
    
    //desenhar o holofote1
    glPushMatrix();
    glTranslatef(posX-28, posY+17, posZ-28);
    glRotatef(-45,0,1,0);
    glCallList(holofote);
    glPopMatrix();
    
    //desenhar o torre2
    glPushMatrix();
    glTranslatef(posX+88, posY+8.5, posZ-28);
    glCallList(torre_sust);
    glPopMatrix();
    
    //desenhar o holofote2
    glPushMatrix();
    glTranslatef(posX+88, posY+17, posZ-28);
    glRotatef(45,0,1,0);
    glCallList(holofote);
    glPopMatrix();
    
    //desenhar o torre3
    glPushMatrix();
    glTranslatef(posX-28, posY+8.5, posZ+128);
    glCallList(torre_sust);
    glPopMatrix();
    
    //desenhar o holofote3
    glPushMatrix();	
    glTranslatef(posX-28, posY+17, posZ+128);
    glRotatef(45,0,1,0); 
    glCallList(holofote);
    glPopMatrix();
    
    //desenhar o torre4
    glPushMatrix();
    glTranslatef(posX+88, posY+8.5, posZ+128);
    glCallList(torre_sust);
    glPopMatrix();
    
    //desenhar o holofote4
    glPushMatrix();	
    glTranslatef(posX+88, posY+17, posZ+128);
    glRotatef(-45,0,1,0);
    glCallList(holofote);
    glPopMatrix();
    
    glDeleteLists(torre_sust, 1);
    glDeleteLists(holofote, 1);


}
