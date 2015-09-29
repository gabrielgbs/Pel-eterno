#include<GL/glut.h>
#include "texturaTGA.h"

class Arquib{
	 
	private:
		float posX, posZ, width1, width2, height, depth, tol;
		textura texturas[1];
		
	public:
		Arquib(float, float, float, float, float, float, float);//Posição inicial do campo
		~Arquib();
		void desenha();
          
};
