/**
 * \author CHARARA Othmane
 * \date 14/04/2016
 * \version 1.0
 * \brief Déclaration de la structure ListeChoix et en-tête des fonctions
 */
#ifndef __listechoix__
#define __listechoix__
#include "itemOption.h"
/**
 * \brief Structure qui permet de  une ListeChoix graphique
 * \details La structure ListeChoix est composée de :
 */
typedef struct ListeChoix ListeChoix; 

struct ListeChoix {
	ItemOption *items; /*!< Collection d'items de la ListeChoix */
	int nbreItems; /*!< Nombre d'items de la ListeChoix */
	char* titre; /*!< Intitulé de la ListeChoix */
	int positionX; /*!< Position en X abscisse */	
	int positionY; /*!< Position en Y ordonnée */
	int width; /*!< largeur */
	int height; /*!< longueur */
	int booleanListeChoix; /*!< Derouler liste choix */
};


/**
 * \brief       Intialise une ListeChoix
 * \param    	nom						Intitulé de la ListeChoix
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	x						Position en abscisse
 * \param    	y						Position en ordonnée		
 * \return    	Une structure ListeChoix
 */
ListeChoix creerListeChoix(char *nom, int width, int height, int x, int y);

/**
 * \brief       Ajoute un item à une liste de choix
 * \param    	this					Liste de choix à laquelle sera ajouté l'item
 * \param    	fenetre					Item à ajouter
 * \return    	(void)
 */
void ajouterItem(ListeChoix *this, ItemOption item);

/**
 * \brief       Génère des items de la liste choix avec Ez_Draw
 * \param    	this					Liste choix des items
 * \param    	fenetre					Fenêtre sur laquelle seront affichés les items de la liste
 * \return    	(void)
 */
void dessinerItemsListeChoix(ListeChoix *this, Ez_window fenetre);

/**
 * \brief       Génère la liste de choix avec Ez_draw
 * \param    	this					Liste choix 
 * \param    	fenetre					Fenêtre sur laquelle sera affiché la liste
 * \param    	boolean					Dérouler la liste ou pas (1 => derouler ; 0 => ne pas dérouler)
 * \return    	(void)
 */
void dessinerListeChoix(ListeChoix *this, Ez_window fenetre, int boolean);


#endif
