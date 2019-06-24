#include "fractaleManager.h"
#include "zoom.h"
/**
 * 
 */

/**
 * \brief fonction qui initalise toutes les stuctures
 * \param manager		Structure qui représente le contôleur de l'application
 * \return (void)
 */
FractaleManager *init(){
	//Declaration controleur
	FractaleManager *manager;
	
	//declarations des structures metier;
	Sauvegarde *sauvegarde;
	
	// -------------- Declaration des elements de la vue -------------------------------
	
	//Les listes déroulantes
	ListeChoix listeFractales, listeNbreIterations, listeCouleurs, listeAnimation, listeTailles; 
	
	//Les items de chaque liste déroulante
	ItemOption itemKoch, itemMandelbrot, itemJulia, itemSanMarco, itemLapinDouady, //fractales
				itemIter1, itemIter2, itemIter3, itemIter4, itemIter5, itemIter6, //iterations
				itemCouleurNoir, itemCouleurBleu, itemCouleurRouge, itemCouleurVert, //couleurs
				itemAnimFinie, itemAnimCirc, itemAnimNone, //type animation
				itemTaille150, itemTaille350, itemTaille550; //taille segment koch
	
	//Les boutons
	Bouton btnValider, btnEffacer, btnStopAnimation, btnSauvegardePPM, btnSauvegardePoints, btnRestaurerdePoints;
	
	
	//Le menu qui contiendra tous les éléments graphiques du menu 
	Menu *menu;
	
		
	//initialistion des modèles
	sauvegarde = NULL;

	// ---------------------- Initialisation éléments menu et mise en place ------------------------------------------------
	
	listeFractales = creerListeChoix("Koch", 120, 15, 110, 60);
	itemKoch = creerItemOptionTexte("Koch", listeFractales.width, 10, "Koch");
	itemKoch.color = ez_blue;
	itemMandelbrot = creerItemOptionTexte("MandelBrot", listeFractales.width, 10, "Mandelbrot");
	itemJulia = creerItemOptionTexte("Julia", listeFractales.width, 10, "Mandelbrot");
	itemSanMarco = creerItemOptionTexte("Dragon San Marco", listeFractales.width, 10, "Mandelbrot");
	itemLapinDouady = creerItemOptionTexte("Lapin de Douady", listeFractales.width, 10, "Mandelbrot");
	ajouterItem(&listeFractales, itemKoch);
	ajouterItem(&listeFractales, itemMandelbrot);
	ajouterItem(&listeFractales, itemJulia);
	ajouterItem(&listeFractales, itemSanMarco);
	ajouterItem(&listeFractales, itemLapinDouady);
	
	listeNbreIterations = creerListeChoix("1", 120, 15, 450, 60);
	itemIter1 = creerItemOptionNumerique("1", listeNbreIterations.width, 10, 1);
	itemIter1.color = ez_blue;
	itemIter2 = creerItemOptionNumerique("2", listeNbreIterations.width, 10, 2);
	itemIter3 = creerItemOptionNumerique("3", listeNbreIterations.width, 10, 3);
	itemIter4 = creerItemOptionNumerique("4", listeNbreIterations.width, 10, 4);
	itemIter5 = creerItemOptionNumerique("5", listeNbreIterations.width, 10, 5);
	itemIter6 = creerItemOptionNumerique("6", listeNbreIterations.width, 10, 6);
	ajouterItem(&listeNbreIterations, itemIter1);
	ajouterItem(&listeNbreIterations, itemIter2);
	ajouterItem(&listeNbreIterations, itemIter3);
	ajouterItem(&listeNbreIterations, itemIter4);
	ajouterItem(&listeNbreIterations, itemIter5);
	ajouterItem(&listeNbreIterations, itemIter6);
	
	
	listeCouleurs = creerListeChoix("Noir", 120, 15, 110, 130);
	itemCouleurNoir = creerItemOptionCouleur("Noir", listeCouleurs.width, 10, ez_black);
	itemCouleurNoir.color = ez_blue;
	itemCouleurBleu = creerItemOptionCouleur("Bleu", listeCouleurs.width, 10, ez_blue);
	itemCouleurRouge = creerItemOptionCouleur("Rouge", listeCouleurs.width, 10, ez_red);
	itemCouleurVert = creerItemOptionCouleur("Vert", listeCouleurs.width, 10, ez_green);
	ajouterItem(&listeCouleurs, itemCouleurNoir);
	ajouterItem(&listeCouleurs, itemCouleurBleu);
	ajouterItem(&listeCouleurs, itemCouleurRouge);
	ajouterItem(&listeCouleurs, itemCouleurVert);
	
	listeAnimation = creerListeChoix("Aucune", 120, 15, 450, 130);
	itemAnimNone = creerItemOptionNumerique("Aucune", listeAnimation.width, 10, 1);
	itemAnimNone.color = ez_blue;
	itemAnimFinie = creerItemOptionNumerique("Finie", listeAnimation.width, 10, 2);
	itemAnimCirc = creerItemOptionNumerique("Circulaire", listeAnimation.width, 10, 3);
	ajouterItem(&listeAnimation, itemAnimNone);
	ajouterItem(&listeAnimation, itemAnimFinie);
	ajouterItem(&listeAnimation, itemAnimCirc);
	
	
	listeTailles = creerListeChoix("150", 120, 15, 135, 175);
	itemTaille150 = creerItemOptionNumerique("150", listeTailles.width, 10, 150);
	itemTaille150.color = ez_blue;
	itemTaille350 = creerItemOptionNumerique("350", listeTailles.width, 10, 350);
	itemTaille550 = creerItemOptionNumerique("500", listeTailles.width, 10, 550);
	ajouterItem(&listeTailles, itemTaille150);
	ajouterItem(&listeTailles, itemTaille350);
	ajouterItem(&listeTailles, itemTaille550);
	
	btnValider = creerBouton("Valider", 100, 20, 400, 220);
	btnEffacer = creerBouton("Effacer Fractale", 100, 20, 530, 220);
	btnStopAnimation = creerBouton("Stopper Animation", 110, 20, 10, 300);
	btnSauvegardePPM = creerBouton("Sauvegarder PPM", 110, 20, 140, 335);
	btnSauvegardePoints = creerBouton("Sauvegarder Points", 110, 20, 270, 335);
	btnRestaurerdePoints = creerBouton("Restaurer Points", 110, 20, 400, 335);
	
	menu = creerMenu("Menu Fractale", 800, 600);
	
	ajouterListeChoix(menu, listeFractales);
	ajouterListeChoix(menu, listeNbreIterations);
	ajouterListeChoix(menu, listeCouleurs);
	ajouterListeChoix(menu, listeAnimation);
	ajouterListeChoix(menu, listeTailles);
	ajouterBouton(menu, btnValider);
	ajouterBouton(menu, btnEffacer);
	ajouterBouton(menu, btnStopAnimation);
	ajouterBouton(menu, btnSauvegardePPM);
	ajouterBouton(menu, btnSauvegardePoints);
	ajouterBouton(menu, btnRestaurerdePoints);
	
	//initialisation du manager
	manager = creerManager(menu, sauvegarde);	
	
	return manager;
}

int main() {
	//CVontyrôleur principal
	//on place tout dedans (menu, sauvegarde, et fractale) afin de tout gérer avec une structure
	FractaleManager *manager;
	
	if(ez_init() < 0) exit(1);
	
	//Initialise tous les attributs
	manager = init();
	
	//initialisation fenetres
	manager->fenetreMenu = ez_window_create(manager->menuGraphique->width, manager->menuGraphique->height, manager->menuGraphique->titre, winMenu_event);
	manager->fenetreFractale = ez_window_create(600, 600, "Fenetre Fractale", winFractale_event);

	//Chaque fenetre créée contient un manager pour pouvoir gérer ce que l'on
	//souhaite (fractales, menu, sauvegarde)
	ez_set_data(manager->fenetreMenu, manager);
	ez_set_data(manager->fenetreFractale, manager);
	ez_main_loop();
	exit(0);	
}
