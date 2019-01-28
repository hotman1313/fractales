/**
 * \author CHARARA Othmane
 * \date 16/04/2016
 * \version 1.0
 * \brief Déclaration de la structure FractaleManager et en-tête des fonctions
 */
#ifndef __fractalemanager__
#define __fractalemanager__
#include "ez-draw.h"
#include "koch.h"
#include "mandelbrot.h"
#include "sauvegarde.h"
#include "menu.h"


/**
 * \brief Structure qui permet dre créer un contrôlleur FractaleManager
 * \details La structure FractaleManager est composée de :
 */
typedef struct FractaleManager FractaleManager; 

struct FractaleManager {
	Ez_window fenetreMenu; /*!< Fenêtre du menu */
	Ez_window fenetreFractale; /*!< Fenêtre qui affiche la fractale */
	Koch *koch; /*!< Fractale de Koch (optionnelle) */
	Mandelbrot *mandelbrot; /*!< Fractale de Mandelbrot (optionnelle) */
	Sauvegarde *sauvegarde; /*!< Structure gérant la sauvegarde */
	Menu *menuGraphique; /*!< Menu de l'application */
	Ez_uint32 tabPixRGBFenFractale[600][600]; /*!< Matrice de points (largeur * hauteur) */
};

/**
 * \brief       Intialise le manager
 * \param    	menu					Le menu graphiqueIntitulé du bouton
 * \param    	sauvegarde				La structure qui permet de sauvegarder
 * \return    	Une structure FractaleManager
 */
FractaleManager *creerManager(Menu *menu, Sauvegarde *sauvegarde);

/**
 * \brief       Remplit la matrice de points de l'image
 * \param 		this					Manager
 * \return    	(void)
 */
void remplirMapPixels(FractaleManager *this);

/**
 * \brief		Affichage de la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_on_expose(Ez_event *ev);

/**
 * \brief		Action suite au clique souris sur la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_on_buttonPress(Ez_event *ev);

/**
 * \brief		Action suite au relâchement souris sur la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_on_buttonRelease(Ez_event *ev);


/**
 * \brief		Association evenement -> foncion sur la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_event(Ez_event *ev);

/**
 * \brief		Affichage de la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_on_expose(Ez_event *ev);

//void win1_on_configure_notify (Ez_event *ev);

/**
 * \brief		Action suite au clique souris sur la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_on_buttonPress(Ez_event *ev);

/**
 * \brief		Action suite à l'arrivée du terme du timer sur la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_on_timerNotify(Ez_event *ev);

/**
 * \brief		Association evenement -> foncion sur la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_event(Ez_event *ev);
#endif
