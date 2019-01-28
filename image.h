/**
 * \author CHARARA Othmane
 * \date 23/05/2016
 * \version 1.0
 * \brief Déclaration de la structure Image et en-tête des fonctions
 */
#ifndef __image__
#define __image__
#include "pixel.h"

/**
 * \brief Structure représentant une image
 * \details Une image est constituée de :
 */
typedef struct Image Image; 

struct Image {
	int hauteur; /*!< Hauteur de l'image */
	int largeur; /*!< Largeur de l'image */
	Pixel *mesPixels[600][600]; /*!< Matrice de pixels qui forment l'image (600*600) */
};

/**
 * \brief       Intialise une image avec une taille donnée
 * \param    	h			Hauteur de l'image
 * \param    	w			Largeur de l'image
 * \return    	Une structure Image
 */
Image *creerImage(int h, int w);

/**
 * \brief       Attribue le pixel P à une image donnée
 * \param    	im			L'image à laquelle le pixel sera attribué
 * \param    	p			Le pixel
 * \param    	lig			La ligne du pixel
 * \param    	col			La colonne du pixel
 * \return    	(void)
 */
void setPixel(Image *im, Pixel *p, int lig, int col);

/**
 * \brief 		Supprime un image
 * \param		im			Image à supprimer
 * \return		(void)
 * */
void supprimerImage(Image *im);

#endif
