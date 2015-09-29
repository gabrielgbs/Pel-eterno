#include <GL/glut.h>
#include<math.h>

#define PI 3.1415926535897932384626433832795

#define TRAVE_LARGURA 7.33
#define TRAVE_ALTURA 2.44

//RAIO DOS CILINDROS QUE CONSTRUIRAO AS TRAVES
#define TRAVE_ESPESS .10

#define TRAVE_COR 1,1,1

//QTDE DE LINHAS EM CADA LADO DAS REDES
#define GRADE 10

class Trave{
     private:
          float posX, posZ1, posZ2;
		  int i;
		  float rad;
		  GLUquadricObj *t1e, *t1d, *t1c, *t2e, *t2d, *t2c;
     public:
          Trave(float, float, float, float);
		//~Trave();
          void desenha();
};
