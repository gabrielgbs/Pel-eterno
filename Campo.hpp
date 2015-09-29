#include<GL/glut.h>
#include<math.h>

#include"Arquib.hpp"
#include"Trave.hpp"

#define PI 3.1415926535897932384626433832795



#define LFAIXA  0.2

//DIMENSOES OFICIAIS DE GRANDE E PEQUENA AREA
#define LPEQ 18.3
#define CPEQ 5.5
#define LGRA 40.3
#define CGRA 16.5

//RAIO DO CIRCULO CENTRAL E MEIA-LUA
#define RAIO 9.15

//DISTANCIA DA MARCA DO PENALTI
#define MPEN 11

//MARGEM ENTRE O CAMPO E A ARQUIBANCADA
#define TOL 10

#define COR_GRAMA1 0,0.7,0
#define COR_GRAMA2 0,0.5,0
#define COR_FAIXA 1,1,1

//ALTURA DAS FAIXAS NO CAMPO PARA ENGANAR O Z-BUFFER (GAMBIARRA)
#define YFAIXA 0.02f
#define YPADRAO 0.0f


class Campo{
	 
	private:
          float posX, posZ, width, depth, xCentro, zCentro;
          
          Arquib *manchaVerde;
          Trave *traves;

          void circulos();
          void padraoCircular(int, int);
          void grandeArea();
          
	public:
          Campo(float, float, float, float);//Posi��o inicial do campo
          ~Campo();
          void desenha();
          
};
