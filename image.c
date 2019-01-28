#include "image.h"
#include <stdlib.h>
/**
 * \brief       Intialise une image avec une taille donnée
 * \param    	h			Hauteur de l'image
 * \param    	w			Largeur de l'image
 * \return    	Une structure Image
 */
Image *creerImage(int h, int w){
	//declarations
	Image *monImage;
	int i, j;
	
	monImage = malloc(sizeof(Image));
	
	//initialisation
	monImage->hauteur = h;
	monImage->largeur = w;
	
	//Initialise tous les pixels du tableau à null
	for(i = 0; i<monImage->hauteur; i++){
		for(j = 0; j<monImage->largeur; j++){
			monImage->mesPixels[i][j] = NULL;
		}
	}
	
	return monImage;
}

/**
 * \brief       Attribue le pixel P à une image donnée
 * \param    	im			L'image à laquelle le pixel sera attribué
 * \param    	p			Le pixel
 * \param    	lig			La ligne du pixel
 * \param    	col			La colonne du pixel
 * \return    	(void)
 */
void setPixel(Image *im, Pixel *p, int lig, int col){
	im->mesPixels[lig][col] = p;
}
/**
 * \brief 		Supprime un image
 * \param		im			Image à supprimer
 * \return		(void)
 * */
void supprimerImage(Image *im){
	//declarations
	int i, j;
	
	//libère tous les pixels
	for(i = 0; i<im->hauteur; i++){
		for(j = 0; j<im->largeur; j++){
			free(im->mesPixels[i][j]);
		}
	}
	
	//libère l'image
	free(im);
	
}
