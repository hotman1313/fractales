/**
 * \author CHARARA Othmane
 * \date 11/04/2016
 * \version 1.0
 * \brief Déclaration de la structure Sauvegarde et en-tête des fonctions
 */
#ifndef __sauvegarde__
#define __sauvegarde__
#include "koch.h"
#include "mandelbrot.h"
#include "listep_op.h"
/**
 * \brief Structure qui gère la Sauvegarde de fractale
 * \details La structure sauvegarde est composée de :
 */
typedef struct Sauvegarde Sauvegarde; 

struct Sauvegarde {
	Koch *fractale; /*!< Une fractale à enregistrer */
	Mandelbrot *fractaleM; /*!< Une fractale à enregistrer */
	char* nomFichier; /*!< Nom de fichier de sortie */	
	int tableauPixelsPPM[600][600]; /*!< Tableau des pixels PPM */
};

/**
 * \brief       Intialise la sauvegarde pour le flocon de Koch
 * \details    	Sauve la fractale renseignée sous un nom donné
 * \param    	fractale				La fractale à sauvegarde
 * \param    	nomFichier				Nom de fichier de sauvegarde
 * \return    	Une structure Sauvegarde
 */
Sauvegarde *creerSauvegardeKoch(void *fractale, char* nomFichier);

/**
 * \brief       Intialise la sauvegarde pour la fractale Mandelbrot
 * \details    	Sauve la fractale renseignée sous un nom donné
 * \param    	fractale				La fractale à sauvegarde
 * \param    	nomFichier				Nom de fichier de sauvegarde
 * \return    	Une structure Sauvegarde
 */
Sauvegarde *creerSauvegardeMandelBrot(void *fractale, char* nomFichier);

/**
 * \brief       Algorithme de Bresenham sur les huits octants
 * \details    	L’algorithme détermine quels sont les points d’un plan discret qui 
 * 				doivent être tracés afin de former une approximation de segment de droite entre deux points donnés.
 * 				N.B : Cette algorithme a été trouvé sur le site http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/
 * \param    	this					La sauvegarde
 * \param    	x1						Abscisse de premier point du segment
 * \param    	y1						Ordonné de premier point du segment
 * \param    	x2						Abscisse de second point du segment
 * \param    	y2						Ordonné de second point du segment
 * \return    	(void)
 */

void TracerSegmentBresenham(Sauvegarde *this, int x1, int y1, int x2, int y2);

/**
 * \brief       Génère un fichier de points
 * \details    	Produits un fichier qui contient tous les points (x y) de la fractale
 * \param    	this					La sauvegarde
 * \return    	(void)
 */ 
void genererFichierPoints(Sauvegarde *this);
/**
 * \brief       Lit un fichier de points pour restaurer une image
 * \details    	À partir d'une liste de points, crée l'image
 * \param    	this					La sauvegarde
 * \return    	Liste de points
 */ 
void restaurerFichierPoints(Sauvegarde *this);

/**
 * \brief       Génère une image PPM pour le flocon de koch
 * \details    	Produits un fichier PPM qui contient tous les points (x y) de la fractale
 * \param    	this					La sauvegarde
 * \return    	(void)
 */ 
void genererFichierPPMKoch(Sauvegarde *this);

/**
 * \brief       Génère une image PPM pour la fractale Mandelbrot et ses ensemble Julia
 * \details    	Produits un fichier PPM qui contient tous les points (x y) de la fractale
 * \param    	this					La sauvegarde
 * \return    	(void)
 */ 
void genererFichierPPMMandelbrot(Sauvegarde *this);

#endif
