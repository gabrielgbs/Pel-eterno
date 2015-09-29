#include "texturaTGA.h"

int cargarTGA( char *nombre, textura *imagen) {
	GLubyte		cabezeraTGA[12]={0,0,2,0,0,0,0,0,0,0,0,0};		// Cabezera de un tga sin compresion
	GLubyte         compararTGA[12];                                        // Aca vamos a comprar la cabezera
	GLubyte		cabezera[6];						// Los 6 bytes importantes
	GLuint		bytesporpunto;						// Cuantos bytes hay por punto
	GLuint		tamanoimagen;						// Aca guardaremos el tamaño de la imagen
	GLuint		temp,i;							// Variable temporal, y una para usar con el for
	GLuint		tipo=GL_RGBA;						// Nuestro typo por defecto, lo veremos mas abajo

	FILE *archivo=fopen(nombre, "rb");	// Cargamos nuestro archivo en memoria
	if( archivo == NULL ||			// Existe nuestro archivo??
            fread(compararTGA,1,sizeof(compararTGA),archivo)!=sizeof(compararTGA)  ||      // Hay 12 bytes para leer??
	    memcmp(cabezeraTGA,compararTGA,sizeof(compararTGA))!=0		||	// Son iguales??
	    fread(cabezera,1,sizeof(cabezera),archivo)!=sizeof(cabezera)) {
		if(archivo==NULL) {
			printf("No se encontro el archivo %s\n",nombre);
			return 0;		// No se abrio el archivo
		}
		else {
			fclose(archivo);
			return 0;
		}
	}
	/* Ahora hay que leer la cabezera del archivo, para saber cuanto es el largo, ancho, y los bytes por puntos,
	para eso aca hay una ilustracion de la cabezera :
	6 bytes -> xxxxxxx xxxxxxx xxxxxxx xxxxxxx xxxxxxx xxxxxxx	
		   |--- Largo ---| |---Ancho-----| |-bpp-|
	El dato del largo se guarda en el cabezera[0] y cabezera[1], para leerlo hay que multiplicar cabezera[0] por 256 y 	sumarselo a cabezera[1], para leer ancho y bpp es el mismo procedimiento */
	imagen->largo=256*cabezera[1]+ cabezera[0];
	imagen->ancho=256*cabezera[3]+ cabezera[2];

	/* Ahora vemos si hay datos no validos, como largo o ancho iguales menores a 0 o iguales a 0 */
	if( imagen->largo <= 0 ||	// Largo mayor que 0?? 
	    imagen->ancho <= 0 ||	// Ancho mayor que 0??
	    (cabezera[4]!=24 && cabezera[4]!=32)) {	// bpp es 24 o 32?? (solo se cargan 24 y 32 bpp)
                printf("Daton invalidos\n");
		fclose(archivo);
		return 0;
	}
	imagen->bpp=cabezera[4];	// Aca se guardan los bits por punto
	bytesporpunto=cabezera[4]/8;	// Aca los bytes por punto (1 byte = 8 bits)
        tamanoimagen=imagen->largo * imagen->ancho * bytesporpunto;      // Esta es la memoria que nesecitaremos para guardar los datos de la textura
	/*Ahora reservamos espacio en memoria para nuestra textura, luego leemos la textura del archivo */
	imagen->dibujo = (GLubyte *)malloc(tamanoimagen);	// Reservamos la memoria necesaria para nuestra textura
	if(imagen->dibujo== NULL ||		// Se logro reservar la memoria???
	   fread(imagen->dibujo, 1, tamanoimagen, archivo) != tamanoimagen ) {	// Se lee, y se comprueba que lo leido es de la misma longitud que la asignada a a dibujo.
		if(imagen->dibujo != NULL) {
			printf("Error leyendo imagen\n");
			free(imagen->dibujo);
		} else printf("Error asignando memoria\n");
		fclose(archivo);
		return 0;
	}
	/* El formato tga guarda las imagenes en BGR, y opengl usa RGB,por lo cambiamos de lugares */
        for(i=0; i< (int)tamanoimagen; i+=bytesporpunto)
	{
		temp=imagen->dibujo[i];				// Guardamos el primer valor
		imagen->dibujo[i] = imagen->dibujo[i + 2];	// Asignamos el nuevo primer valor
		imagen->dibujo[i + 2] = temp;			// Asignamos el ultimo valor
	}
	
	fclose (archivo);	// Cerramos el archivo
	
	/* Listo, terminamos con el codigo de carga, volvemos a opengl, ahora hay que asignarle a la textura un ID, luego 	decirle a opengl cuales son el largo, el ancho y los bpp */

        glGenTextures( 1 , &imagen[0].ID);    // Crea un ID para la textura, buscando un id que este vacio
        glBindTexture(GL_TEXTURE_2D, imagen[0].ID);       // Seleccionamos nuestra textura
	if(imagen->bpp ==24) tipo= GL_RGB;	// Si nuestra textura es de 24 bits, entonces se crea una textura rgb, sino una rgba
	/* Ahora creamos nuestra textura, entrando el largo, ancho y tipo */
        glTexImage2D(GL_TEXTURE_2D, 0, tipo, imagen[0].ancho, imagen[0].largo, 0, tipo, GL_UNSIGNED_BYTE, imagen[0].dibujo);
	/* Ahora le decimos a opengl como queremos que se vea nuestra textura, MAG_FILTER es cuando la textura es mas grande que el lugar donde la asignamos, y MIG_FILTER, es cuando la textura es mas pequeña que el lugar donde la asignamos, GL_LINEAR es para que se vea bien tanto cerca como lejos, pero ocupa bastante procesador. Otra opcion el GL_NEARES, que ocupa menos prosesador */
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return 1;	// Todo salio bien
}
