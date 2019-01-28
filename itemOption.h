/**
 * \author CHARARA Othmane
 * \date 13/04/2016
 * \version 1.0
 * \brief Déclaration de la structure ItemOption et en-tête des fonctions
 */
#ifndef __itemoption__
#define __itemoption__
#include "ez-draw.h"
/**
 * \brief Structure qui permet dre créer un item pour une liste graphique
 * \details La structure ItemOption est composée de :
 */
typedef struct ItemOption ItemOption; 

struct ItemOption {
	char* titre; /*!< Intitulé de l'item */
	union{
		int numerique; /*!< Valeur numérique (nombre) */
		char* str; /*!< Valeur texte */
		Ez_uint32 col; /*!< Valeur coloaration */
	}valeur; /*!< Valeur de l'item */
	int idItem; /*!< Identifiant de l'item */	
	int positionX; /*!< Position en X abscisse */	
	int positionY; /*!< Position en Y ordonnée */
	int width; /*!< Largeur de l'item */
	int height; /*!< Longueur de l'item */
	Ez_uint32 color; /*!< Couleur de l'item */
	int font; /*!< Taille de l'item */
};


/**
 * \brief       Intialise un item pour être ajouté dans une liste de choix
 * \param    	nom						Intitulé de l'item
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	valeur					Valeur de l'item (numérique)
 * \return    	Une structure ItemOption
 */
ItemOption creerItemOptionNumerique(char *nom, int width, int height, int valeur);

/**
 * \brief       Intialise un item pour être ajouté dans une liste de choix
 * \param    	nom						Intitulé de l'item
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	valeur					Valeur de l'item (texte)
 * \return    	Une structure ItemOption
 */
ItemOption creerItemOptionTexte(char *nom, int width, int height, char* valeur);

/**
 * \brief       Intialise un item pour être ajouté dans une liste de choix
 * \param    	nom						Intitulé de l'item
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	valeur					Valeur de l'item (coloration)
 * \return    	Une structure ItemOption
 */
ItemOption creerItemOptionCouleur(char *nom, int width, int height, Ez_uint32 valeur);

/**
 * \brief       Génère le item avec Ez_Draw
 * \param    	this					item à dessiner
 * \param    	fenetre					Fenêtre sur laquelle sera affiché l'item
 * \param    	color					Couleur du texte de l'item
 * \param    	font					Taille du texte de l'item
 * \return    	(void)
 */
void dessinerItem(ItemOption *this, Ez_window fenetre, int x, int y, Ez_uint32 color, int font);

#endif
