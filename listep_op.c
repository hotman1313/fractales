#include "listep_op.h"
#include "listep.h"
#define BUFFER 1000
/*
 * Crée un point
 * INPUT: coordonnees du point
 * OUTPUT: pointeur sur le point cree 
 * */
EPOINT *create_point(double xx, double yy, EPOINT *next){
		//Déclarations
		EPOINT *point;
		
		//Allocation
		point = malloc(sizeof(EPOINT));
		
		//Affectations
		point->x = xx;
		point->y = yy;
		point->next = next;
		
		return point;
}
  
/*
 * Initialisation avec un point
 * INPUT: coordonnees du point
 * OUTPUT: pointeur sur liste creee
 */
PLISTE init_liste(double xx, double yy){
	//Déclarations
	PLISTE uneListeP;
		
	//allocation
	uneListeP = malloc(sizeof(EPOINT));
	uneListeP = create_point(xx, yy, NULL);
		
	return uneListeP;
}


/*
 * Insere un point apres element elt 
 * INPUT: ptr sur element avant insertion, coordonnees du nouveau point
 * OUTPUT: ptr sur element ajoute
 */
EPOINT *insert_after(EPOINT * elt, double xx, double yy){
	//Déclarations
	EPOINT *point;
	
	//ajout
	point = create_point(xx, yy, elt->next);
	elt->next = point;
	
	
	return point;
}

/*
 * Supprime un point de la liste apres element elt 
 * INPUT: ptr sur element avant suppression
 * OUTPUT: ptr sur element courant avant suppression
 */
EPOINT * remove_after(EPOINT * elt){
	//Déclarations
	EPOINT *ptrEltCourant = NULL, *pTmp = NULL;
	
	//Affectations
	ptrEltCourant = create_point(elt->x, elt->y, elt->next);
	
	//MàJ de la liste
	if(elt->next == NULL){
	}else if(elt->next->next != NULL){
		pTmp = create_point(elt->next->next->x, elt->next->next->y, elt->next->next->next);
		free(elt->next);
		elt->next = pTmp;
	}else
		free(elt->next);
	
	return ptrEltCourant;
}


/*
 * Lecture d'une liste de points depuis fichier de nom nf
 * On suppose un point par ligne, avec coordonnees separees par un
 * espace. 
 * INPUT: nom fichier
 * OUTPUT: liste de points lus sur le fichier en entree.
 */  
PLISTE lire_liste(char *nf){
	//Déclarations
	FILE *fichier = NULL;
	PLISTE liste = NULL;
	EPOINT *ptrNextPoint = NULL, *ptrCurrentPoint = NULL;
	double x, y;
	char chaine[BUFFER] = "";
	
	//Ouverture fichier
	fichier = fopen(nf, "r");
	
	//Generation de la liste
	if(fichier != NULL){
		while(fgets(chaine, BUFFER, fichier)){
			if(sscanf(chaine, "%lf %lf", &x, &y) == 2 && liste == NULL){
				liste = init_liste(x, y);
				ptrCurrentPoint = liste;
			}else if(sscanf(chaine, "%lf %lf", &x, &y) == 2){
				ptrNextPoint = insert_after(ptrCurrentPoint, x, y);
				ptrCurrentPoint = ptrNextPoint;
			}
		}		
	}
	
	//fermeture fichier
	fclose(fichier);
	
	return liste;
}


/*
 * Ecriture fichier des points de la liste.
 * Un point par ligne, coordonnees separees par un espace, 
 * RC a la fin d'un point.
 * INPUT: nom fichier d'ecriture, liste a ecrire
 * OUTPUT: --
 */ 
void ecrire_liste(char *nf, PLISTE pl){
	//Déclarations
	FILE *fichier = NULL;
	EPOINT *cur=pl;
	
	//Ouverture fichier
	fichier = fopen(nf, "w");
	
	//parcourt de la liste de points	
	while(cur != NULL){
		fprintf(fichier, "%lf %lf\n", cur->x, cur->y);
		cur=cur->next;
	}
	
	//fermeture fichier
	fclose(fichier);
}






