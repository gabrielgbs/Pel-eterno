#include <GL/glut.h>

class Refletor{
	private:
		double posX, posY, posZ;
	public:
		Refletor();
		Refletor(double, double, double);
		void setPos(double, double, double);
		double getPosX();
		double getPosY();
		double getPosZ();
		void  desenha();
};
