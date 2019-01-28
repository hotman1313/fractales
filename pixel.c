#include "pixel.h"
#include <stdlib.h>



/**
 * \brief       Intialise le pixel avec une couleur
 * \param    	x			Position en x
 * \param    	y			Position en y
 * \param    	r			Intensité de rouge
 * \param    	v			Intensité de vert
 * \param    	b			Intensité de bleu
 * \return    	Une structure Zoom
 */
Pixel *creerPixel(int x, int y, int r, int v, int b){
	//declarations
	Pixel *monPix;
	
	monPix = malloc(sizeof(Pixel));
	
	//initialisation
	monPix->x = x;
	monPix->y = y;
	monPix->rouge = r;
	monPix->vert = v;
	monPix->bleu = b;
	
	return monPix;
}

