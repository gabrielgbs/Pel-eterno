#include <GL/glut.h>

class Jogador{
	private:
		double posX, posY, posZ;
		GLuint braco, busto, cabeca, perna, mao, articulacao, ombro, pe, calcao, canela, antebraco;
		
	public:
		Jogador();
		Jogador(double, double, double);
		void setPos(double, double, double);
		double getPosX();
		double getPosY();
		double getPosZ();
		void  desenhaPele();
		void  desenhaGoleiro();
		void  desenhaJuiz();
};
