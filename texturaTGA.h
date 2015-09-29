#ifndef TEXTURATGA_H
#define TEXTURATGA_H

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	GLubyte  *dibujo;        // Un puntero a los datos de la imagen
	GLuint	bpp;		// bpp significa bits per pixel (bits por punto) es la calidad en palabras sensillas
	GLuint largo;		// Largo de la textura
	GLuint ancho;		// Ancho de la textura
	GLuint ID;		// ID de la textura, es como su nombre para opengl
}textura;

int cargarTGA( char *nombre, textura *imagen);
#endif

