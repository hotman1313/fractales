/**
 * \author CHARARA Othmane
 * \date 12/04/2016
 * \version 1.0
 */
 
#include "listeChoix.h"


/**
 * \brief       Intialise une ListeChoix
 * \param    	nom						Intitulé de la ListeChoix
 * \param    	width					Largeur
 * \param    	height					Hauteur
 * \param    	x						Position en abscisse
 * \param    	y						Position en ordonnée		
 * \return    	Une structure ListeChoix
 */
ListeChoix creerListeChoix(char *nom, int width, int height, int x, int y){
	//declaration
	ListeChoix maListe;
	
	//initialisation des attributs
	maListe.items = NULL;
	maListe.nbreItems = 0;
	maListe.titre = nom;
	maListe.positionX = x;	
	maListe.positionY = y;	
	maListe.width = width;	
	maListe.height = height;	
	maListe.booleanListeChoix = 0;	
	
	return maListe;
}

/**
 * \brief       Ajoute un item à une liste de choix
 * \param    	this					Liste de choix à laquelle sera ajouté l'item
 * \param    	fenetre					Item à ajouter
 * \return    	(void)
 */
void ajouterItem(ListeChoix *this, ItemOption item){
	this->nbreItems++;
	this->items = realloc(this->items, this->nbreItems*sizeof(ItemOption));
	
	this->items[this->nbreItems-1] = item;	
}

/**
 * \brief       Génère des items de la liste choix avec Ez_Draw
 * \param    	this					Liste choix des items
 * \param    	fenetre					Fenêtre sur laquelle seront affichés les items de la liste
 * \return    	(void)
 */
void dessinerItemListeChoix(ListeChoix *this, Ez_window fenetre){
	int i;
	int yCur = this->positionY+30;
	
	dessinerItem(&this->items[0], fenetre, this->positionX, yCur, this->items[0].color, this->items[0].font);
	
	for(i = 1; i<this->nbreItems; i++){
		yCur += 20;
		dessinerItem(&this->items[i], fenetre, this->positionX, yCur, this->items[i].color, this->items[i].font);
    }
}

/**
 * \brief       Génère la liste de choix avec Ez_draw
 * \param    	this					Liste choix 
 * \param    	fenetre					Fenêtre sur laquelle sera affiché la liste
 * \param    	boolean					Dérouler la liste ou pas (1 => derouler ; 0 => ne pas dérouler)
 * \return    	(void)
 */
void dessinerListeChoix(ListeChoix *this, Ez_window fenetre, int boolean){
	this->booleanListeChoix = boolean;
	if(this->booleanListeChoix == 1){
		ez_draw_rectangle(fenetre, this->positionX, this->positionY, (this->positionX+this->width), (this->positionY+this->height));
		ez_draw_text(fenetre, EZ_MC, (double)this->width/2+this->positionX, (double)this->height/2+this->positionY, this->titre);
		dessinerItemListeChoix(this, fenetre);
	}else{
		ez_draw_rectangle(fenetre, this->positionX, this->positionY, (this->positionX+this->width), (this->positionY+this->height));
		ez_draw_text(fenetre, EZ_MC, (double)this->width/2+this->positionX, (double)this->height/2+this->positionY, this->titre);
	}
}



























