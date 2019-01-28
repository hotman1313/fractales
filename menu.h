/**
 * \author CHARARA Othmane
 * \date 12/04/2016
 * \version 1.0
 * \brief Déclaration de la structure Menu et en-tête des fonctions
 */
#ifndef __menu__
#define __menu__
#include "bouton.h"
#include "listeChoix.h"
#include "jauge.h"

/**
 * \brief Structure qui permet de créer un menu graphique
 * \details La structure Menu est composée de :
 */
typedef struct Menu Menu;

struct Menu {
	char* titre; /*!< Intitulé de la fenetre */
	int width; /*!< Largeur de la fenetre */	
	int height; /*!< Hauteur de la fenetre */
	Bouton *boutons; /*!< Collection de boutons contenus dans le menu */
	int nbreBoutons; /*!< Nombre de boutonns */
	ListeChoix *listesChoix; /*!< Collection de listes choix */
	int nbreListesChoix; /*!< Nombre de listes Choix */
	Jauge *jauges; /*!< Collection de jauges */
	int nbreJauges; /*!< Nombre de jauges */
	
};

/**
 * \brief       Intialise le menu
 * \param    	nom						Intitulé du
 * \param    	width					Largeur
 * \param    	height					Hauteur		
 * \return    	Une structure menu
 */
Menu *creerMenu(char *nom, int width, int height);

/**
 * \brief       Ajoute un bouton au menu
 * \param    	this					Menu
 * \param    	bouton					Bouton à ajouter
 * \return    	(void)
 */
void ajouterBouton(Menu *this, Bouton bouton);

/**
 * \brief       Ajoute une liste choix au menu
 * \param    	this					Menu
 * \param    	listeChoix				Liste choix à ajouter
 * \return    	(void)
 */
void ajouterListeChoix(Menu *this, ListeChoix listeChoix);

/**
 * \brief       Ajoute une jauge au menu
 * \param    	this					Menu
 * \param    	listeChoix				Jauge à ajouter
 * \return    	(void)
 */
void ajouterJauge(Menu *this, Jauge jauge);

/**
 * \brief       Génère le menu avec Ez_draw ainsi que chaque élément qui le compose
 * \param    	this					Menu 
 * \param    	fenetre					Fenêtre sur laquelle sera affiché le menu
 * \return    	(void)
 */
void dessinerMenu(Menu *this, Ez_window fenetre);

#endif
