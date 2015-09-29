#include<GL/glut.h>
#include"Campo.hpp"
#include"Bola.hpp"
#include"Jogador.hpp"
#include"Refletor.hpp"
#include"Placa.hpp"
/*
#define LUZAMBIENTE {0.2,0.2,0,2}
#define LUZDIFUSA {0.5,0.5,0.5,1.0}
#define LUZESPECULAR {0.5,0.5,0.5,1.0}
#define POSLUZ {0.0, 2, 0, 1}
*/
class Cenario{
     private:
		Campo *castelao;
		Bola *canarinha;
		Jogador *pele;
		Jogador *goleiro;
		Refletor *holof;
		Placa *propaganda;
/*
		GLfloat *luzAmbiente;
		GLfloat *luzDifusa;
		GLfloat *luzEspecular;
		GLfloat *posLuz;
*/
     public:
		Cenario(float, float, float, float);
		~Cenario();
		void setPosBola(float, float, float);
		void desenha();

};
