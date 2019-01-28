/**
 * \author CHARARA Othmane
 * \date 15/04/2016
 * \version 1.0
 * \brief Déclaration de la structure Jauge et en-tête des fonctions
 */
#ifndef __jauge__
#define __jauge__
#include "ez-draw.h"
/**
 * \brief Structure qui permet dre créer une jauge graphique
 * \details La structure Jauge est composée de :
 */
typedef struct Jauge Jauge; 

struct Jauge {
	char* titre; /*!< Intitulé visible sur la jauge */
	int width; /*!< Largeur de la jauge */	
	int height; /*!< Hauteur de la jauge */	
	int positionX; /*!< Position en X abscisse */	
	int positionY; /*!< Position en Y ordonnée */
	char* min; /*!< Valeur minimale de la jauge */
	char* max; /*!< Valeur maximale de la jauge */
	char* positionJauge; /*!< Position du curseur */
	Ez_uint32 color; /*!< Couleur texte curseur */
	int font; /*!< Taille texte curseur */
};

/**
 * \brief       Intialise une jauge
 * \param    	nom						Intitulé de la jauge
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	x						Position en abscisse
 * \param    	y						Position en ordonnée			
 * \param    	min						Valeur minimale			
 * \param    	max						Valeur maximale			
 * \return    	Une structure Jauge
 */
Jauge creerJauge(char *nom,  int width, int height, int x, int y, char* min, char* max);

/**
 * \brief       Génère le Jauge avec Ez_Draw
 * \param    	this					Jauge à dessiner
 * \param    	fenetre					Fenêtre sur laquelle sera affiché le Jauge
 * \param    	color					Couleur du texte du Jauge
 * \param    	font					Taille du texte du Jauge
 * \return    	(void)
 */
void dessinerJauge(Jauge this, Ez_window fenetre, Ez_uint32 color, int font);

#endif
