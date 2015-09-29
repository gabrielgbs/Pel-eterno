#include"Cenario.hpp"

Cenario::Cenario(float posx, float posz, float w, float d){
	castelao = new Campo(posx, posz, w, d);
	canarinha = new Bola(posx + w/2, 0, posz + d/2);
	pele = new Jogador(0,0,2);
	goleiro = new Jogador(-20,0,0);
	holof = new Refletor();
	propaganda = new Placa();

};

Cenario::~Cenario(){
	delete castelao;
	delete canarinha;
	delete pele;
	delete goleiro;
	delete holof;
	delete propaganda;
};

void Cenario::setPosBola(float x, float y, float z){
	canarinha->setPos(x,y,z);
};

void Cenario::desenha(){
	//============================================================
	//DEFINICOES DAS LUZES
	static const GLfloat luzAmbiente[4]={0.35,0.35,0.35,1};
	static const GLfloat luzDifusa[4]={0.3,0.3,0.3,1.0};
	static const GLfloat luzEspecular[4]={0.5, 0.5, 0.5, 1.0};
	//POSICAO DA FONTE DE LUZ
	static const GLfloat posLuz[4]={0.0, 10, 0, 0};
/*
	//REFLEXOES DAS LUZES
	GLfloat refAmbiente[4]={0,0,0,0};
	GLfloat refDifusa[4]={0,0,0,0};
	GLfloat refEspecular[4]={.5, .5, .5, 1.0};
*/
	

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente );
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posLuz );

/*
	glMaterialfv(GL_FRONT,GL_SPECULAR, refEspecular);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, refDifusa);
	glMaterialfv(GL_FRONT,GL_AMBIENT, refAmbiente);

	glEnable(GL_LIGHT0);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);


/*
	luzAmbiente = LUZAMBIENTE;
	luzDifusa = LUZDIFUSA;
	luzEspecular= LUZESPECULAR;
	GLfloat posLuz = POSLUZ;
	
	glLightfv(GL_LIGHT0, GL_POSITION, POSLUZ );
	glLightfv(GL_LIGHT0, GL_AMBIENT, LUZAMBIENTE );
	glLightfv(GL_LIGHT0, GL_SPECULAR, LUZESPECULAR );
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LUZDIFUSA );
*/

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);

	holof->desenha();
	propaganda->desenha();
	castelao->desenha();
	pele->desenhaPele();
	goleiro->desenhaGoleiro();
	canarinha->desenha();
     
     
}
