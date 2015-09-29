#include "Jogador.hpp"

Jogador::Jogador(){
	posX = posZ = posY = 0;
}

Jogador::Jogador(double x, double y, double z){
	posX = x;
	posY = y;
	posZ = z;
	//criaListas();
}

void Jogador::setPos(double x,double y,double z){
	posX = x;
	posY = y;
	posZ = z;
}

double Jogador::getPosX(){
	return posX;
}

double Jogador::getPosY(){
	return posY;
}

double Jogador::getPosZ(){
	return posZ;
}

void Jogador::desenhaPele(){
	//criar braco
    static GLuint braco = glGenLists(1);//gerar um indice de uma lista
    glNewList(braco, GL_COMPILE);
        glScalef(0.05, 0.18, 0.05);
        glColor3f(0.478f,0.2862f,0.2745f);
        glutSolidCube(2.0f);
    glEndList();//Finaliza a lista iniciada
    
    //criar ante-braco
    static GLuint antebraco = glGenLists(1);
    glNewList(antebraco, GL_COMPILE);
        glScalef(0.06, 0.18, 0.07);
        glColor3f(1.0f,1.0f,0.0f);
        glutSolidCube(2.0f);
    glEndList();
    
    //criar mao
    static GLuint mao = glGenLists(1);
    glNewList(mao, GL_COMPILE);
        glScalef(0.2,0.25,0.2);
        glColor3f(0.478f,0.2862f,0.2745f);
        glutSolidSphere(0.35, 10, 10);
    glEndList();
    
    //criar articulacao
    static GLuint articulacao = glGenLists(1);
    glNewList(articulacao, GL_COMPILE);
        glScalef(0.2,0.2,0.2);
        glColor3f(0.478f,0.2862f,0.2745f);
        glutSolidSphere(0.25, 10, 10);
    glEndList();
    
    //criar ombro
    static GLuint ombro = glGenLists(1);
    glNewList(ombro, GL_COMPILE);
        glScalef(0.3,0.2,0.2);
        glColor3f(1.0f,1.0f,0.0f);
        glutSolidSphere(0.4, 10, 10);
    glEndList();
    
    //criar busto
    static GLuint busto = glGenLists(1);
    glNewList(busto, GL_COMPILE);
        glScalef(0.21, 0.45, 0.14);
        glColor3f(1.0f,1.f,0.0f);
        glutSolidTorus(1, 0, 8, 8);//Definindo um solido para ser o corpo
    glEndList();

    //criar cabeca
    static GLuint cabeca = glGenLists(1);
    glNewList(cabeca, GL_COMPILE);
        glScalef(0.2, 0.27, 0.2);
        glColor3f(0.478f,0.2862f,0.2745f);
        glutSolidSphere(0.6, 10, 10);
    glEndList();

    //criar perna
    static GLuint perna = glGenLists(1);
    glNewList(perna, GL_COMPILE);
        glScalef(0.06, 0.22, 0.06);
        glColor3f(0.0f,0.0f,1.0f);
        glutSolidCube(2.0f);
    glEndList();
    
    //criar canela
    static GLuint canela = glGenLists(1);
    glNewList(canela, GL_COMPILE);
        glScalef(0.05, 0.16, 0.05);
		//glColor3f(0.478f,0.2862f,0.2745f);
        glColor3f(0.9f,0.9f,0.9f);
        glutSolidCube(2.0f);
    glEndList();
    
    //criar calcao
    static GLuint calcao = glGenLists(1);
    glNewList(calcao, GL_COMPILE);
        glScalef(0.15, 0.18, 0.07);
        glColor3f(0.0f,0.0f,1.0f);
        glutSolidCube(2.0f);
    glEndList();
    
    //criar pe
    static GLuint pe = glGenLists(1);
    glNewList(pe, GL_COMPILE);
        glScalef(0.05, 0.02, 0.1);
        glColor3f(0.0f,0.0f,0.0f);
        glutSolidCube(2.0f);
    glEndList();
    
    //desenhar a figura
    
    //desenhar o busto
    glPushMatrix();
    glTranslatef(posX+30, posY+1.2, posZ+47);
    glCallList(busto);
    glPopMatrix();

    //desenhar as pernas
    
    glPushMatrix();//desenha calcao
    glTranslatef(posX+30, posY+0.7, posZ+47);
    glCallList(calcao);
    glPopMatrix();
    
    glPushMatrix();//perna direita
    glTranslatef(posX+30.1, posY+0.65, posZ+47);
    glPushMatrix();
    glCallList(perna);
    glPopMatrix();
    
    glPushMatrix();//canela direita
    glTranslatef(0.0, -0.424, 0.0);
    glCallList(canela);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();//joelho direito
    glTranslatef(posX+30.1, 0.4, posZ+47);
    glCallList(articulacao);
    glPopMatrix();

    glPushMatrix();//perna esquerda
    glTranslatef(posX+29.9, posY+0.65, posZ+47);
    glPushMatrix();
    glCallList(perna);
    glPopMatrix();
    
    glPushMatrix();//canela esquerda
    glTranslatef(0.0, -0.424, 0.0);
    glCallList(canela);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();//joelho esquerdo
    glTranslatef(posX+29.9, 0.4, posZ+47);
    glCallList(articulacao);
    glPopMatrix();
    
    //desenhar pes
    
    glPushMatrix();//pe direito
    glTranslatef(posX+30.1, posY+0.05, posZ+47.05);
    glCallList(pe);
    glPopMatrix();
    
    glPushMatrix();//pe esquerdo
    glTranslatef(posX+29.9, posY+0.05, posZ+47.05);
    glCallList(pe);
    glPopMatrix();

    //desenhar a cabeca
    glPushMatrix();
    glTranslatef(posX+30, posY+1.75, posZ+47);
    glCallList(cabeca);
    glPopMatrix();
    
    //desenhar ombros
    
    glPushMatrix();//ombro direito
    glTranslatef(posX+30.17, posY+1.47, posZ+47);
    glCallList(ombro);
    glPopMatrix();
    
    glPushMatrix();//ombro esquerdo
    glTranslatef(posX+29.83, posY+1.47, posZ+47);
    glCallList(ombro);
    glPopMatrix();

    //desenhar os bracos
    glPushMatrix();//Ante-braco direito
    glTranslatef(posX+30.23, posY+1.3, posZ+47);
    glPushMatrix();
    glCallList(antebraco);
    glPopMatrix();

    glPushMatrix();//braco direito
    glTranslatef(0.02, -0.4, 0.0);
    glCallList(braco);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();//cotovelo direito
    glTranslatef(posX+30.25, posY+1.12, posZ+47);
    glCallList(articulacao);
    glPopMatrix();
   
    glPushMatrix();//Ante-braco esquerdo
    glTranslatef(posX+29.77, posY+1.3, posZ+47);
    glPushMatrix();
    glCallList(antebraco);
    glPopMatrix();

    glPushMatrix();//braco esquerdo
    glTranslatef(-0.02, -0.4, 0.0);
    glCallList(braco);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();//cotovelo esquerdo
    glTranslatef(posX+29.75, posY+1.12, posZ+47);
    glCallList(articulacao);
    glPopMatrix();
    
    //desenhar as maos
    glPushMatrix();//mao direita
    glTranslatef(posX+30.25, posY+0.65, posZ+47);
    glCallList(mao);
    glPopMatrix();
    
    glPushMatrix();//mao esquerda
    glTranslatef(posX+29.75, posY+0.65, posZ+47);
    glCallList(mao);
    glPopMatrix();

    
    glDeleteLists(braco, 1);
    glDeleteLists(antebraco, 1);
    glDeleteLists(mao, 1);
    glDeleteLists(articulacao, 1);
    glDeleteLists(ombro, 1);
    glDeleteLists(busto, 1);
    glDeleteLists(cabeca, 1);
    glDeleteLists(perna, 1);
    glDeleteLists(canela, 1);
    glDeleteLists(calcao, 1);
    glDeleteLists(pe, 1);
}

void Jogador::desenhaGoleiro(){

    //criar braco
	static GLuint braco = glGenLists(1);//gerar um indice de uma lista
	glNewList(braco, GL_COMPILE);
	glScalef(0.05, 0.18, 0.05);
	glColor3f(0.3098f,0.6431f,0.8352f);
	glutSolidCube(2.0f);
	glEndList();//Finaliza a lista iniciada
    
    //criar ante-braco
	static GLuint antebraco = glGenLists(1);
	glNewList(antebraco, GL_COMPILE);
	glScalef(0.06, 0.18, 0.07);
	glColor3f(0.9098f,0.8588f,0.8078f);
	glutSolidCube(2.0f);
	glEndList();
    
    //criar mao
	static GLuint mao = glGenLists(1);
	glNewList(mao, GL_COMPILE);
	glScalef(0.2,0.25,0.2);
	glColor3f(0.9803f,0.8588f,0.7725f);
	glutSolidSphere(0.35, 10, 10);
	glEndList();
    
    //criar articulacao
	static GLuint articulacao = glGenLists(1);
	glNewList(articulacao, GL_COMPILE);
	glScalef(0.2,0.2,0.2);
	glColor3f(0.9098f,0.8745f,0.8078f);
	glutSolidSphere(0.25, 10, 10);
	glEndList();
    
    //criar ombro
	static GLuint ombro = glGenLists(1);
	glNewList(ombro, GL_COMPILE);
	glScalef(0.3,0.2,0.2);
	glColor3f(0.3098f,0.6431f,0.8352f);
	glutSolidSphere(0.4, 10, 10);
	glEndList();
    
    //criar busto
	static GLuint busto = glGenLists(1);
	glNewList(busto, GL_COMPILE);
	glScalef(0.21, 0.45, 0.14);
	glColor3f(0.3098f,0.6431f,0.8352f);
	glutSolidTorus(1, 0, 8, 8);//Definindo um solido para ser o corpo
	glEndList();

    //criar cabeca
	static GLuint cabeca = glGenLists(1);
	glNewList(cabeca, GL_COMPILE);
	glScalef(0.2, 0.27, 0.2);
	glColor3f(1.0f,0.2862f,0.2745f);
	glutSolidSphere(0.6, 10, 10);
	glEndList();

    //criar perna
	static GLuint perna = glGenLists(1);
	glNewList(perna, GL_COMPILE);
	glScalef(0.06, 0.22, 0.06);
	glColor3f(0.0f,0.0f,0.0f);
	glutSolidCube(2.0f);
	glEndList();
    
    //criar canela
	static GLuint canela = glGenLists(1);
	glNewList(canela, GL_COMPILE);
	glScalef(0.05, 0.16, 0.05);
		//glColor3f(0.478f,0.2862f,0.2745f);
	glColor3f(0.9f,0.9f,0.9f);
	glutSolidCube(2.0f);
	glEndList();
    
    //criar calcao
	static GLuint calcao = glGenLists(1);
	glNewList(calcao, GL_COMPILE);
	glScalef(0.15, 0.18, 0.07);
	glColor3f(0.0f,0.0f,0.0f);
	glutSolidCube(2.0f);
	glEndList();
    
    //criar pe
	static GLuint pe = glGenLists(1);
	glNewList(pe, GL_COMPILE);
	glScalef(0.05, 0.02, 0.1);
	glColor3f(0.0f,0.0f,0.0f);
	glutSolidCube(2.0f);
	glEndList();

    //desenhar a figura
    
    //desenhar o busto
	glPushMatrix();
	glTranslatef(posX+30, posY+1.2, posZ+47);
	glCallList(busto);
	glPopMatrix();

    //desenhar as pernas
    
	glPushMatrix();//desenha calcao
	glTranslatef(posX+30, posY+0.7, posZ+47);
	glCallList(calcao);
	glPopMatrix();
    
	glPushMatrix();//perna direita
	glTranslatef(posX+30.1, posY+0.65, posZ+47);
	glPushMatrix();
	glCallList(perna);
	glPopMatrix();
    
	glPushMatrix();//canela direita
	glTranslatef(0.0, -0.424, 0.0);
	glCallList(canela);
	glPopMatrix();
	glPopMatrix();
    
	glPushMatrix();//joelho direito
	glTranslatef(posX+30.1, 0.4, posZ+47);
	glCallList(articulacao);
	glPopMatrix();

	glPushMatrix();//perna esquerda
	glTranslatef(posX+29.9, posY+0.65, posZ+47);
	glPushMatrix();
	glCallList(perna);
	glPopMatrix();
    
	glPushMatrix();//canela esquerda
	glTranslatef(0.0, -0.424, 0.0);
	glCallList(canela);
	glPopMatrix();
	glPopMatrix();
    
	glPushMatrix();//joelho esquerdo
	glTranslatef(posX+29.9, 0.4, posZ+47);
	glCallList(articulacao);
	glPopMatrix();
    
    //desenhar pes
    
	glPushMatrix();//pe direito
	glTranslatef(posX+30.1, posY+0.05, posZ+46.95);
	glCallList(pe);
	glPopMatrix();
    
	glPushMatrix();//pe esquerdo
	glTranslatef(posX+29.9, posY+0.05, posZ+46.95);
	glCallList(pe);
	glPopMatrix();

    //desenhar a cabeca
	glPushMatrix();
	glTranslatef(posX+30, posY+1.75, posZ+47);
	glCallList(cabeca);
	glPopMatrix();
    
    //desenhar ombros
    
	glPushMatrix();//ombro direito
	glTranslatef(posX+30.17, posY+1.47, posZ+47);
	glCallList(ombro);
	glPopMatrix();
    
	glPushMatrix();//ombro esquerdo
	glTranslatef(posX+29.83, posY+1.47, posZ+47);
	glCallList(ombro);
	glPopMatrix();

    //desenhar os bracos
	glPushMatrix();//Ante-braco direito
	glTranslatef(posX+30.3, posY+1.4, posZ+47);
	glPushMatrix();
	glRotatef(65, 0, 0, 1);
	glCallList(antebraco);
	glPopMatrix();

	glPushMatrix();//braco direito
	glTranslatef(0.27, 0.1, 0.0);
	glRotatef(-20, 0, 0, 1);
	glCallList(braco);
	glPopMatrix();
	glPopMatrix();
    
	glPushMatrix();//cotovelo direito
	glTranslatef(posX+30.5, posY+1.3, posZ+47);
	glCallList(articulacao);
	glPopMatrix();
   
	glPushMatrix();//Ante-braco esquerdo
	glTranslatef(posX+29.7, posY+1.4, posZ+47);
	glPushMatrix();
	glRotatef(-65, 0, 0, 1);
	glCallList(antebraco);
	glPopMatrix();

	glPushMatrix();//braco esquerdo
	glTranslatef(-0.27, 0.1, 0.0);
	glRotatef(20, 0, 0, 1);
	glCallList(braco);
	glPopMatrix();
	glPopMatrix();
    
	glPushMatrix();//cotovelo esquerdo
	glTranslatef(posX+29.5, posY+1.3, posZ+47);
	glCallList(articulacao);
	glPopMatrix();
    
    //desenhar as maos
	glPushMatrix();//mao direita
	glTranslatef(posX+30.66, posY+1.75, posZ+47);
	glCallList(mao);
	glPopMatrix();
    
	glPushMatrix();//mao esquerda
	glTranslatef(posX+29.34, posY+1.75, posZ+47);
	glCallList(mao);
	glPopMatrix();


    glDeleteLists(braco, 1);
    glDeleteLists(antebraco, 1);
    glDeleteLists(mao, 1);
    glDeleteLists(articulacao, 1);
    glDeleteLists(ombro, 1);
    glDeleteLists(busto, 1);
    glDeleteLists(cabeca, 1);
    glDeleteLists(perna, 1);
    glDeleteLists(canela, 1);
    glDeleteLists(calcao, 1);
    glDeleteLists(pe, 1);


}
