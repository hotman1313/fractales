/**
 * \author CHARARA Othmane
 * \date 12/04/2016
 * \version 1.0
 */
 
#include "menu.h"


/**
 * \brief       Intialise le menu
 * \param    	nom						Intitulé du
 * \param    	width					Largeur
 * \param    	height					Hauteur		
 * \return    	Une structure menu
 */
Menu *creerMenu(char *nom, int width, int height){
	//Declaration
	Menu *monMenu;
	
	//allocation mémoire
	monMenu = malloc(sizeof(Menu));
	
	//initialisation des attributs
	monMenu->titre = nom;
	monMenu->width = width;
	monMenu->height = height;
	monMenu->boutons = NULL;
	monMenu->listesChoix = NULL;
	monMenu->jauges = NULL;
	monMenu->nbreBoutons = 0;
	monMenu->nbreListesChoix = 0;
	monMenu->nbreJauges = 0;
		
	return monMenu;
}


/**
 * \brief       Ajoute un bouton au menu
 * \param    	this					Menu
 * \param    	bouton					Bouton à ajouter
 * \return    	(void)
 */
void ajouterBouton(Menu *this, Bouton bouton){
	this->nbreBoutons++;
	this->boutons = realloc(this->boutons, this->nbreBoutons*sizeof(Bouton));
	
	this->boutons[this->nbreBoutons-1] = bouton;
}

/**
 * \brief       Ajoute une liste choix au menu
 * \param    	this					Menu
 * \param    	listeChoix				Liste choix à ajouter
 * \return    	(void)
 */
void ajouterListeChoix(Menu *this, ListeChoix listeChoix){
	this->nbreListesChoix++;
	this->listesChoix = realloc(this->listesChoix, this->nbreListesChoix*sizeof(ListeChoix));
	
	this->listesChoix[this->nbreListesChoix-1] = listeChoix;
}

/**
 * \brief       Ajoute une jauge au menu
 * \param    	this					Menu
 * \param    	listeChoix				Jauge à ajouter
 * \return    	(void)
 */
void ajouterJauge(Menu *this, Jauge jauge){
	this->nbreJauges++;
	this->jauges = realloc(this->jauges, this->nbreJauges*sizeof(Jauge));
	
	this->jauges[this->nbreJauges-1] = jauge;
}

/**
 * \brief       Génère le menu avec Ez_draw ainsi que chaque élément qui le compose
 * \param    	this					Menu 
 * \param    	fenetre					Fenêtre sur laquelle sera affiché le menu
 * \return    	(void)
 */
void dessinerMenu(Menu *this, Ez_window fenetre){
	int i;
	
	//dessine tous les boutons
	for(i = 0; i<this->nbreBoutons; i++)
		dessinerBouton(this->boutons[i], fenetre, this->boutons[i].color, this->boutons[i].font);
	
	//dessine toutes les listes
	for(i = 0; i<this->nbreListesChoix; i++)
		dessinerListeChoix(&this->listesChoix[i], fenetre, this->listesChoix[i].booleanListeChoix);
	
	//dessine toutes les jauges
	for(i = 0; i<this->nbreJauges; i++)
		dessinerJauge(this->jauges[i], fenetre, this->jauges[i].color, this->jauges[i].font);
    
}
