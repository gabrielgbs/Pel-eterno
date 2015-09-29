#include "Campo.hpp"


Campo::Campo(float posx, float posz, float w, float d){
     posX = posx;
     posZ = posz;
     
     if (w > 90)
          width = 90;
     else if (w < 45)
          width = 45;
     else
          width = w;
     
     if (d > 120)
          depth = 120;
     else if (d < 90)
          depth = 90;
     else
          depth = d;
     
     xCentro = (posX+posX+width)/2;
     zCentro = (posZ+posZ+depth)/2;
     
     manchaVerde = new Arquib(posx, posz, width, depth, 10, 15, TOL*2);
     traves = new Trave(posx, posz, width, depth);
}

Campo::~Campo(){
     delete manchaVerde;
     delete traves;
}

void Campo::circulos(){
//     glLineWidth(LFAIXA);
     int i;//indice do proximo laco (valor do angulo em graus)
     float rad;//valor do angulo em radianos
     glColor3f(COR_FAIXA);
     glBegin(GL_QUAD_STRIP);
          for(i = 0;i<=360;i = i+2){
			rad = PI*i/180;
               glVertex3d(xCentro + RAIO*cos(rad),YFAIXA,zCentro + RAIO*sin(rad));
               glVertex3d(xCentro + (RAIO - LFAIXA)*cos(rad),YFAIXA,zCentro + (RAIO - LFAIXA)*sin(rad));
          }
     glEnd();
     
     glBegin(GL_QUAD_STRIP);
          for(i = 1;i<=180;i = i+2){
			rad = PI*i/180;
			    if(posZ + MPEN + RAIO*sin(rad) >= posZ + CGRA){
					 glVertex3d(xCentro + RAIO*cos(rad),YFAIXA,posZ + MPEN + RAIO*sin(rad));
					 glVertex3d(xCentro + (RAIO - LFAIXA)*cos(rad),YFAIXA,posZ + MPEN + (RAIO - LFAIXA)*sin(rad));
				}
          }
     glEnd();
     
     glBegin(GL_QUAD_STRIP);
          for(i = 1;i<=180;i = i+2){
			rad = PI*i/180;
				if(posZ + depth - MPEN - RAIO*sin(rad) <= posZ + depth - CGRA){
					glVertex3d(xCentro + RAIO*cos(rad),YFAIXA,posZ + depth - MPEN - RAIO*sin(rad));
					glVertex3d(xCentro + (RAIO - LFAIXA)*cos(rad),YFAIXA,posZ + depth - MPEN - (RAIO - LFAIXA)*sin(rad));
				}
          }
     glEnd();

}

void Campo::padraoCircular(int incr, int largFaixa){
     float j;//DISTANCIA DO CENTRO DE CAMPO
     int i;//VALOR DO ANGULO EM GRAUS

     glColor3f(COR_GRAMA2);
     for(j = RAIO; j<= depth/2 + TOL*4; j=j+2*largFaixa){
          glBegin(GL_QUADS);
          for(i = 0;i<=360;i = i+incr){
//			rad = PI*i/180;
			glColor3f(COR_GRAMA2);
               glVertex3d(xCentro + j*cos(PI*i/180),YPADRAO,zCentro + j*sin(PI*i/180));
               glVertex3d(xCentro + (j+largFaixa)*cos(PI*i/180),YPADRAO,zCentro + (j+largFaixa)*sin(PI*i/180));
			glVertex3d(xCentro + (j+largFaixa)*cos(PI*(i + incr)/180),YPADRAO,zCentro + (j+largFaixa)*sin(PI*(i + incr)/180));
			glVertex3d(xCentro + j*cos(PI*(i+ incr)/180),YPADRAO,zCentro + j*sin(PI*(i+incr)/180));
               
               glColor3f(COR_GRAMA1);
               glVertex3d(xCentro + (j+largFaixa)*cos(PI*i/180),YPADRAO,zCentro + (j+largFaixa)*sin(PI*i/180));
               glVertex3d(xCentro + (j+largFaixa*2)*cos(PI*i/180),YPADRAO,zCentro + (j+largFaixa*2)*sin(PI*i/180));
			glVertex3d(xCentro + (j+largFaixa*2)*cos(PI*(i + incr)/180),YPADRAO,zCentro + (j+largFaixa*2)*sin(PI*(i + incr)/180));
			glVertex3d(xCentro + (j+largFaixa)*cos(PI*(i+ incr)/180),YPADRAO,zCentro + (j+largFaixa)*sin(PI*(i+incr)/180));
          }
          glEnd();
     }
     
     //CIRCULO CENTRAL
     glBegin(GL_POLYGON);
     for (i = 0; i<=360; i = i+ incr){
		glVertex3d(xCentro + RAIO*cos(PI*i/180),YPADRAO,zCentro + RAIO*sin(PI*i/180));
	}
	glEnd();
	
}

void Campo::grandeArea(){
		//LINHAS
		//GRANDE AREA
		glColor3f(COR_FAIXA);
		glBegin(GL_QUADS);
		glVertex3d(xCentro - LGRA/2, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro - LGRA/2 + LFAIXA, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro - LGRA/2 + LFAIXA, YFAIXA, posZ + CGRA - LFAIXA/2);
		glVertex3d(xCentro - LGRA/2, YFAIXA, posZ + CGRA - LFAIXA/2);

		glVertex3d(xCentro + LGRA/2 - LFAIXA, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + CGRA - LFAIXA/2);
		glVertex3d(xCentro + LGRA/2 - LFAIXA, YFAIXA, posZ + CGRA - LFAIXA/2);

		glVertex3d(xCentro - LGRA/2 , YFAIXA, posZ + CGRA - LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + CGRA - LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + CGRA + LFAIXA/2);
		glVertex3d(xCentro - LGRA/2, YFAIXA, posZ + CGRA + LFAIXA/2);


		glVertex3d(xCentro - LGRA/2, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro - LGRA/2 + LFAIXA, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro - LGRA/2 + LFAIXA, YFAIXA, posZ + depth - CGRA - LFAIXA/2);
		glVertex3d(xCentro - LGRA/2, YFAIXA, posZ + depth - CGRA - LFAIXA/2);
		
		glVertex3d(xCentro + LGRA/2 - LFAIXA, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + depth - CGRA - LFAIXA/2);
		glVertex3d(xCentro + LGRA/2 - LFAIXA, YFAIXA, posZ + depth - CGRA - LFAIXA/2);

		glVertex3d(xCentro - LGRA/2 , YFAIXA, posZ + depth - CGRA - LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + depth - CGRA - LFAIXA/2);
		glVertex3d(xCentro + LGRA/2, YFAIXA, posZ + depth - CGRA + LFAIXA/2);
		glVertex3d(xCentro - LGRA/2, YFAIXA, posZ + depth - CGRA + LFAIXA/2);
		
		//PEQUENA AREA
		glColor3f(COR_FAIXA);
		glBegin(GL_QUADS);
		glVertex3d(xCentro - LPEQ/2, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2 + LFAIXA, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2 + LFAIXA, YFAIXA, posZ + CPEQ - LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2, YFAIXA, posZ + CPEQ - LFAIXA/2);

		glVertex3d(xCentro + LPEQ/2 - LFAIXA, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + CPEQ - LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2 - LFAIXA, YFAIXA, posZ + CPEQ - LFAIXA/2);

		glVertex3d(xCentro - LPEQ/2 , YFAIXA, posZ + CPEQ - LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + CPEQ - LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + CPEQ + LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2, YFAIXA, posZ + CPEQ + LFAIXA/2);


          glVertex3d(xCentro - LPEQ/2, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2 + LFAIXA, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2 + LFAIXA, YFAIXA, posZ + depth - CPEQ - LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2, YFAIXA, posZ + depth - CPEQ - LFAIXA/2);
		
		glVertex3d(xCentro + LPEQ/2 - LFAIXA, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + depth - CPEQ - LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2 - LFAIXA, YFAIXA, posZ + depth - CPEQ - LFAIXA/2);

		glVertex3d(xCentro - LPEQ/2 , YFAIXA, posZ + depth - CPEQ - LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + depth - CPEQ - LFAIXA/2);
		glVertex3d(xCentro + LPEQ/2, YFAIXA, posZ + depth - CPEQ + LFAIXA/2);
		glVertex3d(xCentro - LPEQ/2, YFAIXA, posZ + depth - CPEQ + LFAIXA/2);

     glEnd();
}

void Campo::desenha(){

	padraoCircular(9,5);
	
	//DESENHAR FAIXAS
     glColor3f(COR_FAIXA);
     glBegin(GL_QUADS);
		glVertex3d(posX, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(posX + LFAIXA, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(posX + LFAIXA, YFAIXA, posZ + depth - LFAIXA/2);
		glVertex3d(posX, YFAIXA, posZ + depth - LFAIXA/2);

		glVertex3d(posX + width - LFAIXA, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, posZ + depth - LFAIXA/2);
		glVertex3d(posX + width - LFAIXA, YFAIXA, posZ + depth - LFAIXA/2);
		
		glVertex3d(posX , YFAIXA, posZ - LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, posZ - LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, posZ + LFAIXA/2);
		glVertex3d(posX, YFAIXA, posZ + LFAIXA/2);
		
		glVertex3d(posX, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, posZ + depth + LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, posZ + depth - LFAIXA/2);
		glVertex3d(posX, YFAIXA, posZ + depth - LFAIXA/2);
		
		glVertex3d(posX, YFAIXA, zCentro + LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, zCentro + LFAIXA/2);
		glVertex3d(posX + width, YFAIXA, zCentro - LFAIXA/2);
		glVertex3d(posX, YFAIXA, zCentro - LFAIXA/2);
     glEnd();
     
     circulos();
     
     //GRANDE AREA
     grandeArea();

	//AQUI DESENHAMOS OS DEMAIS ELEMENTOS
	manchaVerde->desenha();
	traves->desenha();

}
