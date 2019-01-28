/**
 * \author CHARARA Othmane
 * \date 13/04/2016
 * \version 1.0
 */
 
#include "itemOption.h"


/**
 * \brief       Intialise un item pour être ajouté dans une liste de choix
 * \param    	nom						Intitulé de l'item
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	valeur					Valeur de l'item (numérique)
 * \return    	Une structure ItemOption
 */
ItemOption creerItemOptionNumerique(char *nom, int width, int height, int valeur){
	//Declaration
	ItemOption monItem;
	
	
	//initialisations des attributs
	monItem.titre = nom;
	monItem.idItem = 0;
	monItem.positionX = 0;
	monItem.positionY = 0;
	monItem.width = width;
	monItem.height = height;
	monItem.color = ez_black;
	monItem.font = 0;
	monItem.valeur.numerique = valeur;
	
	return monItem;
	
}

/**
 * \brief       Intialise un item pour être ajouté dans une liste de choix
 * \param    	nom						Intitulé de l'item
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	valeur					Valeur de l'item (texte)
 * \return    	Une structure ItemOption
 */
ItemOption creerItemOptionTexte(char *nom, int width, int height, char* valeur){
	//Declaration
	ItemOption monItem;
	
	
	//initialisations des attributs
	monItem.titre = nom;
	monItem.idItem = 0;
	monItem.positionX = 0;
	monItem.positionY = 0;
	monItem.width = width;
	monItem.height = height;
	monItem.color = ez_black;
	monItem.font = 0;
	monItem.valeur.str = valeur;
	
	return monItem;
	
}

/**
 * \brief       Intialise un item pour être ajouté dans une liste de choix
 * \param    	nom						Intitulé de l'item
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	valeur					Valeur de l'item (coloration)
 * \return    	Une structure ItemOption
 */
ItemOption creerItemOptionCouleur(char *nom, int width, int height, Ez_uint32 valeur){
	//Declaration
	ItemOption monItem;
	
	
	//initialisations des attributs
	monItem.titre = nom;
	monItem.idItem = 0;
	monItem.positionX = 0;
	monItem.positionY = 0;
	monItem.width = width;
	monItem.height = height;
	monItem.color = ez_black;
	monItem.font = 0;
	monItem.valeur.col = valeur;
	
	return monItem;
	
}

/**
 * \brief       Génère le item avec Ez_Draw
 * \param    	this					item à dessiner
 * \param    	fenetre					Fenêtre sur laquelle sera affiché l'item
 * \param    	color					Couleur du texte de l'item
 * \param    	font					Taille du texte de l'item
 * \return    	(void)
 */
void dessinerItem(ItemOption *this, Ez_window fenetre, int x, int y, Ez_uint32 color, int font){
	//màaj attributs
	this->positionX = x;
	this->positionY = y;
	this->color = color;
	this->font = font;
	
	ez_set_color(this->color);
	ez_set_nfont(this->font);
	
	//Placement de l'item
	ez_draw_text(fenetre, EZ_ML, this->positionX, this->positionY, this->titre);
	ez_set_color(ez_black);
	ez_set_nfont(0);
}
