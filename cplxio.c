#include "cplxio.h"

#include <stdio.h>
#include <stdlib.h>


/*
 * Cree un complexe a partir de deux reels.
 * 
 * INPUT: reel partie reelle, reel partie imaginaire
 * OUTPUT: pointeur sur struct Complexe, allocation memoire dans la 
 * fonction
 */ 
COMPLEXE * create_complexe(double r, double i){
	//inits
	COMPLEXE *unComplexe;
	
	//alloc. mém pour le pointeur en sortie
	unComplexe = malloc(sizeof(COMPLEXE));
		
	//init de chaque attr. de l'objet (structure)
	unComplexe->im = i;
	unComplexe->re = r;

	return unComplexe;	
}

/* Le format est la lecture de deux reels de type long, separes
 * par un espace (partie reelle suivie de partie imaginaire).
 * La fonction renvoit un pointeur vers le complexe nouvellement lu.
 * L'affectation memoire se fait dans la fonction.
 * Lecture sur entrée standard (clavier).
 *
 * INPUT: --
 * OUTPUT: pointeur sur nouvelle structure de complexe
 * 
 */

COMPLEXE * lire_complexe(void){
	//inits
	double partReelle, partImaginaire;
	COMPLEXE *unComplexe;
	
	//alloc. mém pour le pointeur en sortie
	unComplexe = create_complexe(0, 0);
	
	//lecture de l'entrée au clavier
	printf("entrez 2 nombres séparés d'un espace : ");
	scanf("%lf %lf", &partReelle, &partImaginaire);
		
	//init de chaque attr. de l'objet (structure)
	unComplexe->im = partImaginaire;
	unComplexe->re = partReelle;
	
	return unComplexe;	
			
}


/* Ecrit le complexe sans le i, comme deux coordonnees separees par un
 * espace, sur la sortie standard (terminal). 
 * Le format est le meme que pour la lecture (partie reelle puis 
 * imaginaire). 
 * 
 * INPUT: pointeur sur un element de structure de complexe.
 * OUTPUT: --
 * 
 */

void ecrire_complexe (COMPLEXE *c){
	printf(" %lf + %lf.i", c->re, c->im);
}




