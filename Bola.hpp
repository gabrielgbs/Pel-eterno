#include <GL/glut.h>
#include "texturaTGA.h"
#define RAIOBOLA 0.125
#define CORBOLA 1,0.75,0.25

class Bola{
	private:
		double posX, posY, posZ;
		textura texturas[1];
		GLUquadricObj *bol;
	public:
		Bola();
		~Bola();
		Bola(double, double, double);
		void setPos(double, double, double);
		double getPosX();
		double getPosY();
		double getPosZ();
		void  desenha();
};
