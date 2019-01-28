#include "cplxop.h"
#include "cplxio.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Calcule la somme de deux complexes 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * add_cplx (COMPLEXE *c1, COMPLEXE *c2){		
	return create_complexe((c1->re + c2->re), (c1->im + c2->im));
}

/* Calcule la soustraction entre deux complexes z1-z2 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 *        entier, si 1 = moins unaire (oppose), si 2 = moins binaire 

 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * moins_cplx (COMPLEXE *c1, COMPLEXE *c2, int i){
	//renvoie
	if(i==1){
		return create_complexe(-(c1->re), -(c1->im));
	}else{
		return create_complexe((c1->re - c2->re), (c1->im - c2->im));
	}	
}

/* Calcule la multiplication entre deux complexes 
 * Allocation memoire d'un nouveau pointeur.
 *
 * formule générale pour la multiplication
 * (a + i.b) x (a' + i.b') = (aa' – bb') + i (ab' + ba')
 *
 * INPUT: pointeurs vers des complexes (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */

COMPLEXE * mul_cplx (COMPLEXE *c1, COMPLEXE *c2){
	//inits
	double reelle, imaginaire;
	
	//Calcul partie reelle
	reelle = (c1->re * c2->re) - (c1->im * c2->im);
	
	//Calcul partie imaginaire
	imaginaire = (c1->re * c2->im) + (c1->im * c2->re);
	
	return create_complexe(reelle, imaginaire);
	
}


/* Calcule le produit d'un complexe et d'un reel
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeur sur un complexe et un reel (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * mul_cplx_reel (COMPLEXE *c1, double r){
	//inits
	double reelle, imaginaire;
	
	//Calcul partie reelle
	reelle = (c1->re * r);
	
	//Calcul partie imaginaire
	imaginaire = (c1->im * r);
	
	return create_complexe(reelle, imaginaire);
}


/**
 * \brief	Calcule le module d'un nombre complexe
 * */
double moduleCplx(COMPLEXE *c){
	return sqrt((c->re*c->re)+(c->im*c->im));
}




