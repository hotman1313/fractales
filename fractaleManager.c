/**
 * \author CHARARA Othmane
 * \date 16/04/2016
 * \version 1.0
 */

#include "fractaleManager.h"

#include "zoom.h"

/**
 * \brief       Intialise le manager
 * \param    	menu					Le menu graphiqueIntitulé du bouton
 * \param    	sauvegarde				La structure qui permet de sauvegarder
 * \return    	Une structure FractaleManager
 */
FractaleManager *creerManager(Menu *menu, Sauvegarde *sauvegarde){
	//Declaration
	FractaleManager *monManager;
	
	//Allocation mémoire
	monManager = malloc(sizeof(FractaleManager));
	
	//Initialisation des attributs
	monManager->menuGraphique = menu;
	monManager->sauvegarde = sauvegarde;
	monManager->koch = NULL;
	monManager->mandelbrot = NULL;
	
	return monManager;
}

/**
 * \brief       Remplit la matrice de points de l'image
 * \param 		this					Manager
 * \return    	(void)
 */
void remplirMapPixels(FractaleManager *this){
	//declaration
	int i,j;
	
	//vidage du tableau dans un premier temps
	for(i=0; i<600; i++){
		for(j=0;j<600;j++){
			this->tabPixRGBFenFractale[i][j] = ez_white;	
		}
	}
	
	//----------------------- Cas N°1 : Fractale de Mandelbrot ---------------------------------------
	if(this->mandelbrot != NULL){
		//remplissage du tableau pixels representant la fenetre fractale (uniquement partie fractale)
		for(i=0; i<600; i++){
			for(j=0;j<600;j++){
				if(this->mandelbrot->image->mesPixels[i][j]->rouge == 255){ 
					this->tabPixRGBFenFractale[i][j] = ez_black;	
				}
			}
		}
		
		//remplissage du tableau pixels representant la fenetre fractale (le reste, en blanc)
		for(i=0; i<600; i++){
			for(j=0;j<600;j++){
			if(this->tabPixRGBFenFractale[i][j] != ez_black)
				this->tabPixRGBFenFractale[i][j] = ez_white;
			}
		}
	}
}

/**
 * \brief		Affichage de la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_on_expose(Ez_event *ev){
	
	//Partie generation de la fractale
	ez_set_color(ez_red);
	ez_set_nfont(3);
	ez_draw_text(ev->win, EZ_ML, 5, 10, "Configuration de base : ");
	ez_set_color(ez_black);
	ez_set_nfont(0);

	//Placement libellés
	ez_draw_text(ev->win, EZ_ML, 5, 65, "Type fractales : ");
	ez_draw_text(ev->win, EZ_ML, 320, 65, "Nombre d'iterations : ");
	ez_draw_text(ev->win, EZ_ML, 5, 135, "Couleur : ");
	ez_draw_text(ev->win, EZ_ML, 320, 135, "Animation : ");
	ez_draw_text(ev->win, EZ_ML, 5, 180, "Taille segment Koch : ");
	
	//Partie action sur la fractale
	ez_set_color(ez_red);
	ez_set_nfont(3);
	ez_draw_text(ev->win, EZ_ML, 5, 270, "Actions sur la fractale : ");
	ez_set_color(ez_black);
	ez_set_nfont(0);
	
	//Mise en place du menu
	FractaleManager *manager = ez_get_data(ev->win);
	Menu *menu = manager->menuGraphique;
	
	dessinerMenu(menu, ev->win);
	
}

/**
 * \brief		Action suite au clique souris sur la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_on_buttonPress(Ez_event *ev){
	//declarations
	FractaleManager *manager = ez_get_data(ev->win);
	Menu *m = manager->menuGraphique;
	int i, j, k;
	
	//parcourt des listes de menu
	//on s'arrete lorsque la position de la souris se trouve 
	//dans la surface cliquable de la liste. 
	//NB : Aucune action n'est faite, il s'agit juste de récupérer les valeurs
	for(i = 0; i<m->nbreListesChoix; i++){
		if(ev->mx >= m->listesChoix[i].positionX && ev->mx <= (m->listesChoix[i].width+m->listesChoix[i].positionX)&&
			ev->my >= m->listesChoix[i].positionY && ev->my <= (m->listesChoix[i].height+m->listesChoix[i].positionY)){
			if(m->listesChoix[i].booleanListeChoix == 1) m->listesChoix[i].booleanListeChoix =0; else m->listesChoix[i].booleanListeChoix = 1;
		}
		
		//une liste est cliquée, parcours des items de la liste
		//pour savoir quel item sera cliqué.
		//Quand un item est choisi, on l'affiche
		for(j = 0; j<m->listesChoix[i].nbreItems; j++){
			if(m->listesChoix[i].booleanListeChoix == 1 && ev->mx >= m->listesChoix[i].items[j].positionX && ev->mx <= (m->listesChoix[i].items[j].width+m->listesChoix[i].items[j].positionX)&&
				ev->my >= m->listesChoix[i].items[j].positionY && ev->my <= (m->listesChoix[i].items[j].height+m->listesChoix[i].items[j].positionY)){
					m->listesChoix[i].items[j].font = 1;
					m->listesChoix[i].items[j].color = ez_blue;
					m->listesChoix[i].booleanListeChoix =0; 
					m->listesChoix[i].titre = m->listesChoix[i].items[j].titre;
					
				//Remise en place des couleurs et fonts des autres items 
				//afin que l'item choisi soit unique (et oui poulet ;) )
				for(k = 0; k<m->listesChoix[i].nbreItems; k++){
					if(m->listesChoix[i].items[k].positionY != m->listesChoix[i].items[j].positionY && m->listesChoix[i].items[k].color == m->listesChoix[i].items[j].color){
						m->listesChoix[i].items[k].font = 0;
						m->listesChoix[i].items[k].color = ez_black;
					}
				}
			}
		}
	}
	
	//parcourt des boutons du menu
	//on s'arrete lorsque la position de la souris se trouve 
	//dans la surface cliquable du bouton. 
	//NB : Aucune action n'est faite, il s'agit juste de récupérer les valeurs
	for(i = 0; i<m->nbreBoutons; i++){
		if(ev->mx >= m->boutons[i].positionX && ev->mx <= (m->boutons[i].width+m->boutons[i].positionX)&&
			ev->my >= m->boutons[i].positionY && ev->my <= (m->boutons[i].height+m->boutons[i].positionY)){
			m->boutons[i].font = 1;
			m->boutons[i].color = ez_red;
			m->boutons[i].clique = 1;
		}
	}
	
	//on remet à jours la vue
	ez_send_expose(manager->fenetreMenu);
}

/**
 * \brief		Action suite au relâchement souris sur la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_on_buttonRelease(Ez_event *ev){
	//declarations
	FractaleManager *manager = ez_get_data(ev->win);
	Menu *m = manager->menuGraphique;
	int i, j, k, l, ordreIter, tailleSegmentInitKoch, typeAnim;
	ItemOption argsFractale[4];
		
	//Recherche le bouton cliqué et le remet normal
	//pour faire un effet de cliques.
	//Afin de ne pas avoir plusieurs boutons cliqués et pour reconnaitre le bon bouton,
	//seul un bouton peut avoir l'atribut "clique" à 1
	for(i = 0; i<m->nbreBoutons; i++){
		if(m->boutons[i].font == 1 && m->boutons[i].color == ez_red){
			m->boutons[i].font = 0;
			m->boutons[i].color = ez_black;
		}
	}
		
	//recherche du bouton cliqué et emission d'un action 
	for(i = 0; i<m->nbreBoutons; i++){
		if(m->boutons[i].clique == 1){
		
			//-----------Cas du bouton "Valider"
			if(strcmp(m->boutons[i].intitule, "Valider") == 0){
				//-----------CHOIX KOCH----------------------
				if(m->listesChoix[0].items[0].color == ez_blue){
				
					//Une boucle pour chaque liste déroulante
					//afin de récuperer les valeurs
					for(j = 0; j<m->nbreListesChoix; j++){
				
						//récupère la valeur de chaque liste déroulante
						//dont l'item est sélectionné 
						for(k = 0; k<m->listesChoix[j].nbreItems; k++){
							if(m->listesChoix[j].items[k].color == ez_blue) //donc l'item sélectionné hein
								argsFractale[j] = m->listesChoix[j].items[k]; //là, on ajoute l'item à la liste d'arguments de la fractale
						}
					}	
									
					//création du flocon avec les paramètres choisies dans le menu
					Koch *koch = creerKoch(100, 150, argsFractale[4].valeur.numerique, 150, argsFractale[3].valeur.numerique);
					
					setIteration(koch, argsFractale[1].valeur.numerique); //nombre d'iter	
					setCouleurContour(koch, argsFractale[2].valeur.col); //couleur
					
					//Cas ou on souhaite générer le flocon avec une animation
					if(koch->animation == 1){ //aucune animation, donc génère le koch avec l'ordre d'iter donnée d'un seul coup
				
						//Développe le flocon (nombre choisi au menu) fois
						for(l = 0; l<koch->ordreIteration; l++){
							koch = developperKoch(koch);
						}
						//on envoie le flocon au manager						
						manager->koch = koch;
						
						//on envoie le manager à la fenetre fractale, elle s'occupe du reste ;)
						ez_set_data(manager->fenetreFractale, manager);
									
						//et on lui demande de dessiner ;)
						ez_send_expose(manager->fenetreFractale);
					}else if(koch->animation == 2 || koch->animation == 3){ //animation finie ou circulaire
				
						//on envoie le flocon au manager						
						manager->koch = koch;
						
						//on envoie le manager à la fenetre fractale, elle s'occupe du reste ;)
						ez_set_data(manager->fenetreFractale, manager);
									
						//et on lui demande de dessiner ;)
						ez_send_expose(manager->fenetreFractale);
						//arme le timer
						ez_start_timer(manager->fenetreFractale, 1000);
					}
				//-----------------CHOIX MANDELBROT-----------------
				}else if(m->listesChoix[0].items[1].color == ez_blue){
					//creation fractale mandelbrot
					Mandelbrot *mandel = creerMandelbrot(-2.1, 0.6, -1.2, 1.2);
					
					//Mandelbrot *mandel = creerJulia(0.285, 0.01, -1, 1, -1.2, 1.2);
					
					//genere mandelbrot
					genererMandelBrot(mandel);

					//on envoie le mandelbrot au manager						
					manager->mandelbrot = mandel;
					remplirMapPixels(manager);
					//on envoie le manager à la fenetre fractale, elle s'occupe du reste ;)
					ez_set_data(manager->fenetreFractale, manager);
									
					//et on lui demande de dessiner ;)
					ez_send_expose(manager->fenetreFractale);
				//-----------------CHOIX JULIA-----------------
				}else if(m->listesChoix[0].items[2].color == ez_blue){
					//creation fractale julia
					Mandelbrot *mandel = creerJulia(0.285, 0.01, -1, 1, -1.2, 1.2);
					
					//genere mandelbrot
					genererJulia(mandel);

					//on envoie le mandelbrot au manager						
					manager->mandelbrot = mandel;
					remplirMapPixels(manager);
					//on envoie le manager à la fenetre fractale, elle s'occupe du reste ;)
					ez_set_data(manager->fenetreFractale, manager);
									
					//et on lui demande de dessiner ;)
					ez_send_expose(manager->fenetreFractale);
				
				//-----------------CHOIX San marco-----------------
				}else if(m->listesChoix[0].items[3].color == ez_blue){
					//creation fractale julia
					Mandelbrot *mandel = creerJulia(-1, 0, -1, 1, -1.2, 1.2);
					
					//genere mandelbrot
					genererJulia(mandel);

					//on envoie le mandelbrot au manager						
					manager->mandelbrot = mandel;
					remplirMapPixels(manager);
					//on envoie le manager à la fenetre fractale, elle s'occupe du reste ;)
					ez_set_data(manager->fenetreFractale, manager);
									
					//et on lui demande de dessiner ;)
					ez_send_expose(manager->fenetreFractale);
				//-----------------CHOIX Duady-----------------
				}else if(m->listesChoix[0].items[4].color == ez_blue){
					//creation fractale julia
					Mandelbrot *mandel = creerJulia(-0.123, -0.745, -1, 1, -1.2, 1.2);
					
					//genere mandelbrot
					genererJulia(mandel);

					//on envoie le mandelbrot au manager						
					manager->mandelbrot = mandel;
					remplirMapPixels(manager);
					//on envoie le manager à la fenetre fractale, elle s'occupe du reste ;)
					ez_set_data(manager->fenetreFractale, manager);
									
					//et on lui demande de dessiner ;)
					ez_send_expose(manager->fenetreFractale);
				}
			}//----------Cas du bouton "Effacer Fractale" -------------
			else if(strcmp(m->boutons[i].intitule, "Effacer Fractale") == 0){
				manager->koch = NULL;
				manager->mandelbrot = NULL;
				ez_window_clear(manager->fenetreFractale);
			}//-----------Cas du bouton "Sauvegarder PPM" ---------------
			else if(strcmp(m->boutons[i].intitule, "Sauvegarder PPM") == 0){
				//Vérifie si la fenêtre de fractale contient une donnée
				if(ez_get_data(manager->fenetreFractale) != NULL && manager->mandelbrot != NULL){
					manager->sauvegarde = creerSauvegardeMandelBrot(manager->mandelbrot, "test.ppm");
					genererFichierPPMMandelbrot(manager->sauvegarde);
				}else if(ez_get_data(manager->fenetreFractale) != NULL && manager->koch != NULL){
					manager->sauvegarde = creerSauvegardeKoch(manager->koch, "test.ppm");
					genererFichierPPMKoch(manager->sauvegarde);
				}
			}//-----------Cas du bouton "Sauvegarder points" ---------------
			else if(strcmp(m->boutons[i].intitule, "Sauvegarder Points") == 0){

				//Vérifie si la fenêtre de fractale contient une donnée
				if(ez_get_data(manager->fenetreFractale) != NULL && manager->koch != NULL){
					manager->sauvegarde = creerSauvegardeKoch(manager->koch, "test.in");
					genererFichierPoints(manager->sauvegarde);
				}
			}
		}
	}
	
	//remise à zéro de tous les boutons
	//pour qu'aucun ne soit cliqué
	for(i = 0; i<m->nbreBoutons; i++){
		m->boutons[i].clique = 0;
	}
	//on remet à jours la vue
	ez_send_expose(manager->fenetreMenu);
}

/**
 * \brief		Association evenement -> foncion sur la fenêtre du menu
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winMenu_event(Ez_event *ev){
    switch (ev->type) {
        case Expose   : winMenu_on_expose    (ev); break;
		case ButtonPress: winMenu_on_buttonPress(ev); break;
		case ButtonRelease: winMenu_on_buttonRelease(ev); break;
    }
}

/**
 * \brief		Affichage de la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_on_expose(Ez_event *ev){
	//declaration
	FractaleManager *manager = ez_get_data(ev->win);
	EPOINT *cur;
	int i, j;
	
	if(manager->koch != NULL){
		//initialisations
		cur = manager->koch->points;
		
		//couleur du Flocon
		ez_set_color(manager->koch->couleurContour);
		//génération du flocon de Koch
		while(cur->next != NULL){	
			ez_draw_line(manager->fenetreFractale, cur->x, cur->y, cur->next->x, cur->next->y);
			cur = cur->next;
		}
		ez_draw_line(manager->fenetreFractale, cur->x, cur->y, manager->koch->points->x, manager->koch->points->y);
	}else if(manager->mandelbrot != NULL){
		for(i=0; i<600; i++){
			for(j=0;j<600;j++){
				ez_set_color(manager->tabPixRGBFenFractale[i][j]);
				ez_draw_point(manager->fenetreFractale, i, j);	
			}
		}
	}
}

/**
 * \brief		Action suite au clique souris sur la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_on_button_press(Ez_event *ev){
	FractaleManager *manager = ez_get_data(ev->win);
	Zoom *zoom = creerZoom(manager);
	
	if(manager->koch != NULL){
		zoomerKoch(zoom, ev->mx, ev->my , 1.2);
		ez_set_data(manager->fenetreFractale, manager);
		ez_send_expose(manager->fenetreFractale);
	}else if(manager->mandelbrot != NULL){
		zoomerMandelbrotTest(zoom, ev->mx, ev->my, 1.2);
		remplirMapPixels(manager);
		ez_set_data(manager->fenetreFractale, manager);
		ez_send_expose(manager->fenetreFractale);
	}
}

/**
 * \brief		Action suite à l'arrivée du terme du timer sur la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_on_timerNotify(Ez_event *ev){
	//declaration
	FractaleManager *manager = ez_get_data(ev->win);
	
	//s il y a une fractale de Koch
	if(manager->koch != NULL){
		if(manager->koch->ordreIteration == manager->koch->ordreIterationCur){
			ez_start_timer(manager->fenetreFractale, -1);
		}else{	
			//developpement du flocon
			manager->koch = developperKoch(manager->koch);
	
			ez_set_data(manager->fenetreFractale, manager);
			ez_send_expose(manager->fenetreFractale);
		
			ez_start_timer(manager->fenetreFractale, 1000);
		}
	}
}

/**
 * \brief		Association evenement -> foncion sur la fenêtre de la fractale
 * \param		ev					Evenements relatives
 * \return		(void)
 * */
void winFractale_event(Ez_event *ev){
    switch (ev->type) {
		case Expose   : winFractale_on_expose    (ev); break;
		case ButtonPress: winFractale_on_button_press(ev); break;
		case TimerNotify: winFractale_on_timerNotify(ev); break;
	}
}
