/*
      UNIVERSIDADE FEDERAL DO CEARA
        DEPARTAMENTO DE COMPUTACAO

     TRABALHO II - COMPUTACAO GRAFICA I
        "O GOL QUE PELE NAO FEZ"



      Gabriel Brito dos Santos
      Felipe Timbo Brito
      Jose Augusto Baltazar Alves
      Leonardo Silva Lins
      Paulo Eduardo Juvencio Neri

      Projeto desenvolvido em sua maioria
      em C++, openGL e glut
*/

#include <GL/glut.h>
#include <iostream>

#include "Cenario.hpp"

//DIMENSOES DA JANELA PRINCIPAL
#define LJANELAP 640
#define AJANELAP 480

//DIMENSOES DA SUBJANELA
#define LSJANELA 150
#define ASJANELA LSJANELA

//DISTANCIAS PARA NAVEGACAO DA CAMERA
#define RAIO_VISAO 1
#define ALTURA_MAX 10
#define PASSO .5
#define DELTA_CAMERA_MOVE .02

#define GRAVIDADE 9.8

//DIMENSOES DO CAMPO DE FUTEBOL
#define CCAMPO 100
#define LCAMPO 60

//DEFINICOES DE CORES
#define COR_BRANCO 1,1,1
#define COR_CINZAESCURO .25,.25,.25
#define COR_PRETO 0,0,0
#define COR_VERDE 0,1,0
#define COR_CEU 0.0, 0.5, 1, 1.0

#define VELMAXCHUTE 25
#define VELMINCHUTE 1
#define ANGULOMAXCHUTE 60
#define ANGULOMINCHUTE 5

Cenario *meuCenario = new Cenario(0,0,LCAMPO,CCAMPO);

GLfloat aspecto;

GLfloat eyeX, eyeY, eyeZ, alvoX, alvoY, alvoZ, deltaEyeX, deltaEyeY, deltaEyeZ;

GLfloat alturaVisao, deltaAlturaVisao = 0;

GLfloat anguloXZ, deltaAnguloXZ = 0;
//int mouseX, mouseY;

double tempoInicial;

int idJanelaPrincipal, idSubJanela;

bool chutou, foiGol, definindo, praFora;

int velInicialChute, anguloChute;
double velBola;

//FUNCAO NECESSARIA PARA ESCREVER STRINGS NAS JANELAS
char rotulo[50];
char status[50];
void escreveString(char *str){
	unsigned int i = 0;
	do
		glutBitmapCharacter (GLUT_BITMAP_8_BY_13, str[i]);
		//glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, str[i]);
	while(str[++i] != '\0');
}

//INICIA OS VALORES
void inicializa (void)
{
    deltaEyeX = deltaEyeZ = deltaEyeY = 0.0f;

	chutou = praFora = foiGol = false;
	definindo = true;

	//glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);

    glClearColor(COR_CEU);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);

	alvoX = alvoY = alvoZ = 0;
	eyeX = 0 - TOL/2;
	eyeZ = CCAMPO/2;
	eyeY = 2;
	anguloXZ = M_PI_2;
	alturaVisao = 0;

	//INICIALIZAMOS OS VALORES INICIAIS DO CHUTE COMO 10m/s A 45�
	velInicialChute = 10;
	anguloChute = 45;
	//COLOCAMOS A BOLA NO CENTRO DE CAMPO
	meuCenario->setPosBola(LCAMPO/2,0 + RAIOBOLA,CCAMPO/2);
}

//AQUI DEFINIMOS PARAMETROS DE PROJECAO E POSICAO DA CAMERA
void paramProjecao(void)
{
    anguloXZ += deltaAnguloXZ;
    alturaVisao += deltaAlturaVisao;
    eyeZ += deltaEyeZ;
    eyeX += deltaEyeX;
    eyeY += deltaEyeY;

	alvoX = eyeX + RAIO_VISAO*sin(anguloXZ);
	alvoZ = eyeZ + RAIO_VISAO*cos(anguloXZ);
	alvoY = eyeY + alturaVisao;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(45,aspecto,0.1,1000);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(eyeX,eyeY,eyeZ, alvoX,alvoY,alvoZ, 0,1,0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void pressMovementKey(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        deltaEyeZ = PASSO*cos(anguloXZ);
        deltaEyeX = PASSO*sin(anguloXZ);
        break;
    case 'S':
    case 's':
        deltaEyeZ = -PASSO*cos(anguloXZ);
        deltaEyeX = -PASSO*sin(anguloXZ);
        break;
    case 'A':
    case 'a':
        deltaEyeZ = PASSO*cos((anguloXZ+M_PI_2));
        deltaEyeX = PASSO*sin((anguloXZ+M_PI_2));
        break;
    case 'D':
    case 'd':
        deltaEyeZ = -PASSO*cos((anguloXZ+M_PI_2));
        deltaEyeX = -PASSO*sin((anguloXZ+M_PI_2));
        break;
    case 'F':
    case 'f':
        deltaEyeY = -PASSO;
        break;
    case 'R':
    case 'r':
        deltaEyeY = PASSO;
        break;

    }
}

void releaseMovementKey(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        deltaEyeZ = deltaEyeX = 0;
        break;
    case 'S':
    case 's':
        deltaEyeZ = deltaEyeX = 0;
        break;
    case 'A':
    case 'a':
        deltaEyeZ = deltaEyeX = 0;
        break;
    case 'D':
    case 'd':
        deltaEyeZ = deltaEyeX = 0;
        break;
    case 'F':
    case 'f':
    case 'R':
    case 'r':
        deltaEyeY = 0;
        break;
    }
}

void pressKey(unsigned char key, int x, int y)
{
    switch (key)
    {

    case '+':
        glutFullScreen();
        break;

    case '-':
        glutInitWindowSize(LJANELAP,AJANELAP);
        break;

    case 27:
        glutDestroyWindow(idSubJanela);
        glutDestroyWindow(idJanelaPrincipal);
        delete meuCenario;
        exit(0);
        break;

    case 32:
        if(definindo)
        {
            definindo = false;
            velBola = velInicialChute;
            chutou = true;
            tempoInicial = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
            sprintf (status, "Olho no lance...");
        }

        break;
    case 13:
        if(!chutou)
            inicializa();
        break;

    }
    pressMovementKey(key, x, y);
}

void releaseKey(unsigned char key, int x, int y)
{
    releaseMovementKey(key, x, y);
}

void pressDirectionalKey(int key, int x, int y)
{
    switch(key)
    {

		case GLUT_KEY_LEFT:
            deltaAnguloXZ = DELTA_CAMERA_MOVE;
			break;

		case GLUT_KEY_RIGHT:
            deltaAnguloXZ = -DELTA_CAMERA_MOVE;
			break;

		case GLUT_KEY_UP:
			deltaAlturaVisao = DELTA_CAMERA_MOVE;
			break;

		case GLUT_KEY_DOWN:
			deltaAlturaVisao = -DELTA_CAMERA_MOVE;
			break;
    }
}

void releaseDirectionalKey(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT:
			deltaAnguloXZ = 0;
			break;

        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
			deltaAlturaVisao = 0;
			break;

    }
}

void pressSpecialKey(int key, int x, int y)
{
	switch(key){
		case GLUT_KEY_PAGE_UP:
			if(!chutou && anguloChute < ANGULOMAXCHUTE)
			{
				anguloChute++;
			}
            break;
		case GLUT_KEY_PAGE_DOWN:
			if(!chutou && anguloChute > ANGULOMINCHUTE)
			{
				anguloChute--;
			}
            break;
		case GLUT_KEY_HOME:
			if(!chutou && velInicialChute < VELMAXCHUTE)
			{
				velInicialChute++;
			}
            break;
		case GLUT_KEY_END:
			if(!chutou && velInicialChute > VELMINCHUTE)
			{
				velInicialChute--;
			}
			break;
	}
	pressDirectionalKey(key,x,y);
}

void releaseSpecialKey(int key, int x, int y)
{
    releaseDirectionalKey(key, x, y);
}

//DESENHA A JANELA PRINCIPAL, ONDE FICA O CENARIO
void janelaPrincipal(void)
{
    glutSetWindow (idJanelaPrincipal);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	meuCenario->desenha();
	glutSwapBuffers();
}

void subJanela(){
	glutSetWindow (idSubJanela);
	glClearColor (COR_CINZAESCURO, 1);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(definindo){
		//ESCREVER DADOS
		sprintf (rotulo, "Angulo: %d", anguloChute);
		glRasterPos2f (0.05f, 0.90f);
		escreveString(rotulo);

		sprintf (rotulo, "Velocidade: %d", velInicialChute);
		glRasterPos2f (0.05f, 0.80f);
		escreveString(rotulo);

		//DESENHA VETOR
		glColor3f (COR_BRANCO);
		glBegin (GL_LINE_LOOP);
			glVertex2f (0.2, 0.1);
			glVertex2f (.2 + 0.025*VELMAXCHUTE, 0.1);
			glVertex2f (.2 + 0.025*VELMAXCHUTE, .1 + 0.025*VELMAXCHUTE);
			glVertex2f (0.2, .1 + 0.025*VELMAXCHUTE);
		glEnd ();

		glColor3f(COR_VERDE);
		glBegin(GL_LINES);
			glVertex2f(.2,.1);
			glVertex2f(.2 + velInicialChute * 0.025*cos(anguloChute*PI/180),.1 + velInicialChute * 0.025*sin(anguloChute*PI/180));
		glEnd();

		glutSwapBuffers ();
	} else {
		glRasterPos2f (0.1f, 0.60f);
		sprintf (rotulo, "Status:");
		escreveString(rotulo);

		glRasterPos2f (0.1f, 0.40f);
		escreveString(status);

		glutSwapBuffers ();
	}
}

void tamanhoJanelaPrincipal(GLsizei w, GLsizei h)
{
	//PARA EVITAR QUE A JANELA SEJA MUITO PEQUENA
	if (w < LJANELAP)
		w = LJANELAP;
	if (h < AJANELAP)
		h = AJANELAP;

     glutReshapeWindow(w, h);
	glViewport(0, 0, w, h);

	//CALCULAR RAZAO DA TELA
	aspecto = (GLfloat)w/(GLfloat)h;

	paramProjecao();
}

void tamanhoSubJanela(int w, int h){
	glViewport (0, 0, w, h);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0f, 1.0f, 0.0f, 1.0f);
}

void funcaoIdle(){

	static double posXBola = LCAMPO/2;
	static double posInicialZBola;// = CCAMPO/2;
	static double posInicialYBola = 0;

	static double posZBola;
	static double posYBola;
	static double velYBola;
	static double anguloChuteRad;

	if(definindo){
		posInicialZBola = CCAMPO/2;
		posZBola = posInicialZBola;
	}

 	if ((chutou)&&(velBola > 0.1)){
    anguloChuteRad = anguloChute*PI/180;

		if(posYBola < 0){
			posYBola = 0;
			tempoInicial = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
			posInicialZBola = posZBola;
			velBola *= 0.8;
		}
		//MOVIMENTO HORIZONTAL UNIFORME - FORMULA DO SORVETE
		posZBola = posInicialZBola + velBola*cos(anguloChuteRad) * (glutGet(GLUT_ELAPSED_TIME) / 1000.0 - tempoInicial);
		//MOVIMENTO VERTICAL UNIFORMEMENTE VARIADO
		posYBola = posInicialYBola + velBola*sin(anguloChuteRad) * (glutGet(GLUT_ELAPSED_TIME) / 1000.0 - tempoInicial) - GRAVIDADE * (glutGet(GLUT_ELAPSED_TIME) / 1000.0 - tempoInicial) * (glutGet(GLUT_ELAPSED_TIME) / 1000.0 - tempoInicial) * 0.5;
		//EQUACAO DA VELOCIDADE EM MRU
		velYBola = velBola*sin(anguloChuteRad) - GRAVIDADE * (glutGet(GLUT_ELAPSED_TIME) / 1000.0 - tempoInicial);


		if(((CCAMPO - posZBola)<0)){
			if((!foiGol)&&(!praFora)){
				if(TRAVE_ALTURA > posYBola){
					foiGol = true;
					sprintf (status, "TA LA DENTRO!!!");
				} else {
					praFora = true;
					sprintf (status, "PRA FOOORAAA!!!");
				}
			}
			if(foiGol){
				if(posZBola > (CCAMPO + TRAVE_ALTURA)){
					posZBola = (CCAMPO + TRAVE_ALTURA);

				}
				if(posYBola > TRAVE_ALTURA){
					posYBola = TRAVE_ALTURA;
				}
			}
		}


		//AGORA DEFINIMOS A NOVA POSICAO DA BOLA
		meuCenario->setPosBola(posXBola,posYBola,posZBola);
	} else {
		if(chutou){
			chutou = false;
			if(!foiGol)
				sprintf (status, "QUE CHUTE PAIA!");
		}
	}

	//ATUALIZANDO AS DUAS JANELAS
	glutSetWindow (idJanelaPrincipal);
	glutPostRedisplay();
	glutSetWindow (idSubJanela);
	glutPostRedisplay();

}

int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glEnable(GL_MULTISAMPLE);
	glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);

	//JANELA PRINCIPAL
	glutInitWindowSize(LJANELAP,AJANELAP);
	idJanelaPrincipal = glutCreateWindow("O GOL QUE PELE NAO FEZ - v0.25");
	glutDisplayFunc(janelaPrincipal);
	glutReshapeFunc(tamanhoJanelaPrincipal);

	//FUNCOES CALLBACK
	glutKeyboardFunc(pressKey);
	glutKeyboardUpFunc(releaseKey);
	glutSpecialFunc(pressSpecialKey);
	glutSpecialUpFunc(releaseSpecialKey);
	glutIdleFunc(funcaoIdle);
	inicializa();

	//SUBJANELA
	idSubJanela = glutCreateSubWindow(idJanelaPrincipal, 10, 10, LSJANELA, ASJANELA);
	glutDisplayFunc(subJanela);
	glutReshapeFunc(tamanhoSubJanela);

	glutMainLoop();

	//SAINDO DO LOOP PRINCIPAL...
	glutDestroyWindow(idSubJanela);
	glutDestroyWindow(idJanelaPrincipal);
	delete meuCenario;

}


