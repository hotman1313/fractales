#ifndef __CPLXOP__
#define __CPLXOP__

#include "cplx.h"
#include <stdlib.h>

/* Calcule la somme de deux complexes 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * add_cplx (COMPLEXE *c1, COMPLEXE *c2);

/* Calcule la soustraction entre deux complexes z1-z2 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 *        entier, si 1 = moins unaire (oppose), si 2 = moins binaire 

 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * moins_cplx (COMPLEXE *c1, COMPLEXE *c2, int i);

/* Calcule la multiplication entre deux complexes 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */

COMPLEXE * mul_cplx (COMPLEXE *c1, COMPLEXE *c2);

/* Calcule le produit d'un complexe et d'un reel
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeur sur un complexe et un reel (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * mul_cplx_reel (COMPLEXE *c1, double r);

/**
 * \brief	Calcule le module d'un nombre complexe
 * */
double moduleCplx(COMPLEXE *c);
#endif
