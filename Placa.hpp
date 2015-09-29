//As placas de propaganda e outros acessorios
#include "texturaTGA.h"
#include <GL/glut.h>

class Placa{
	private:
		double posX, posY, posZ;
	public:
		Placa();
		Placa(double, double, double);
		void setPos(double, double, double);
		double getPosX();
		double getPosY();
		double getPosZ();
		void  desenha();
};
