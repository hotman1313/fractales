/**
 * \author CHARARA Othmane
 * \date 12/04/2016
 * \version 1.0
 * \brief Déclaration de la structure Bouton et en-tête des fonctions
 */
#ifndef __bouton__
#define __bouton__
#include "ez-draw.h"
/**
 * \brief Structure qui permet dre créer un bouton graphique
 * \details La structure Bouton est composée de :
 */
typedef struct Bouton Bouton; 

struct Bouton {
	char* intitule; /*!< Intitulé visible sur le bouton */
	int width; /*!< Largeur du bouton */	
	int height; /*!< Hauteur du bouton */	
	int positionX; /*!< Position en X abscisse */	
	int positionY; /*!< Position en Y ordonnée */
	Ez_uint32 color; /*!< Couleur du nom du bouton */
	int clique; /*!< Bouton cliqué ou pas : 0 pour non, 1 pour oui*/
	int font; /*!< Taille du nom du bouton */
};


/**
 * \brief       Intialise un bouton
 * \param    	nom						Intitulé du bouton
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	x						Position en abscisse
 * \param    	y						Position en ordonnée			
 * \return    	Une structure Bouton
 */
Bouton creerBouton(char *nom, int width, int height, int x, int y);

/**
 * \brief       Génère le bouton avec Ez_Draw
 * \param    	this					Bouton à dessiner
 * \param    	fenetre					Fenêtre sur laquelle sera affiché le bouton
 * \param    	color					Couleur du texte du bouton
 * \param    	font					Taille du texte du bouton
 * \return    	(void)
 */
void dessinerBouton(Bouton this, Ez_window fenetre, Ez_uint32 color, int font);

#endif
