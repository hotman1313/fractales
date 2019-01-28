/**
 * \author CHARARA Othmane
 * \date 16/04/2016
 * \version 1.0
 */
 
#include "jauge.h"
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
Jauge creerJauge(char *nom,  int width, int height, int x, int y, char* min, char* max){
	//Declaration
	Jauge maJauge;
	
	//Initialisation des attributs
	maJauge.titre = nom;
	maJauge.width = width;
	maJauge.height = height;
	maJauge.positionX = x;
	maJauge.positionY = y;
	maJauge.min = min;
	maJauge.max = max;
	maJauge.positionJauge = maJauge.min;
	maJauge.color = ez_black;
	maJauge.font = 0;
	
	return maJauge;
}

/**
 * \brief       Génère le Jauge avec Ez_Draw
 * \param    	this					Jauge à dessiner
 * \param    	fenetre					Fenêtre sur laquelle sera affiché le Jauge
 * \param    	color					Couleur du texte du Jauge
 * \param    	font					Taille du texte du Jauge
 * \return    	(void)
 */
void dessinerJauge(Jauge this, Ez_window fenetre, Ez_uint32 color, int font){
	//Génération de la jeuge avec ez-draw
	ez_draw_rectangle(fenetre, this.positionX, this.positionY, (this.positionX+this.width), (this.positionY+this.height));
	
	//màj attributs jauge
	this.color = color;
	this.font = font;
		
	//Génération du curseur de la jeuge avec ez-draw
	ez_draw_rectangle(fenetre, this.positionX, this.positionY-6, (this.positionX+8), (this.positionY+26));
	
	//placement du nom du bouton
	ez_draw_text(fenetre, EZ_MC, this.positionX+4, this.positionY+35, this.positionJauge);
}











