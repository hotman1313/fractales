/**
 * \author CHARARA Othmane
 * \date 12/04/2016
 * \version 1.0
 */
 
#include "bouton.h"

/**
 * \brief       Intialise un bouton
 * \param    	nom						Intitulé du bouton
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	x						Position en abscisse
 * \param    	y						Position en ordonnée			
 * \return    	Une structure Bouton
 */
Bouton creerBouton(char *nom, int width, int height, int x, int y){
	//Declaration
	Bouton monBouton;
		
	//initialisation des attributs
	monBouton.intitule = nom;
	monBouton.width = width;
	monBouton.height = height;
	monBouton.positionX = x;
	monBouton.positionY = y;
	monBouton.color = ez_black;
	monBouton.font = 0;
	monBouton.clique = 0;
	
	return monBouton;
}

/**
 * \brief       Génère le bouton avec Ez_Draw
 * \param    	this					Bouton à dessiner
 * \param    	fenetre					Fenêtre sur laquelle sera affiché le bouton
 * \param    	color					Couleur du texte du bouton
 * \param    	font					Taille du texte du bouton
 * \return    	(void)
 */
void dessinerBouton(Bouton this, Ez_window fenetre, Ez_uint32 color, int font){
	
	//Génération du bouton avec ez-draw
	ez_draw_rectangle(fenetre, this.positionX, this.positionY, (this.positionX+this.width), (this.positionY+this.height));
	
	//màj attributs bouton
	this.color = color;
	this.font = font;
	
	ez_set_color(this.color);
	ez_set_nfont(this.font);
	
	//placement du nom du bouton
	ez_draw_text(fenetre, EZ_MC, (double)this.width/2+this.positionX, (double)this.height/2+this.positionY, this.intitule);
	ez_set_color(ez_black);
	ez_set_nfont(0);
}
