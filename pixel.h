/**
 * \author CHARARA Othmane
 * \date 23/05/2016
 * \version 1.0
 * \brief Déclaration de la structure Pixel et en-tête des fonctions
 */
#ifndef __pixel__
#define __pixel__

/**
 * \brief Structure représentant le pixel d'une image
 * \details Un Pixel est constitué de :
 */
typedef struct Pixel Pixel; 

struct Pixel {
	int x; /*!< Position en abscisse (x) */
	int y; /*!< Position en ordonnée (y) */
	int rouge; /*!< Intensité Rouge du Pixel*/
	int vert; /*!< Intensité Vert du Pixel*/
	int bleu; /*!< Intensité Bleu du Pixel*/
};

/**
 * \brief       Intialise le pixel avec une couleur
 * \param    	x			Position en x
 * \param    	y			Position en y
 * \param    	r			Intensité de rouge
 * \param    	v			Intensité de vert
 * \param    	b			Intensité de bleu
 * \return    	Une structure Zoom
 */
Pixel *creerPixel(int x, int y, int r, int v, int b);

#endif
