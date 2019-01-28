/**
 * \author CHARARA Othmane
 * \date 7/04/2016
 * \version 1.0
 */
 
#include "koch.h"
#include "listep_op.h"
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
/**
 * \brief       Intialise le Flocon de Koch
 * \details    	A partir de deux points, ajoute un point qui forme le triangle equilateral
 * \param    	x1				Abscisse du premier point
 * \param    	y1				Ordonnée du premier poiny
 * \param    	x2				Abscisse du second point
 * \param    	y2				Ordonnée du second point
 * \param    	animationType	Type d'animation
 * \return    	Une structure du flocon de Koch
 */
Koch* creerKoch(double x1, double y1, double x2, double y2, int animationType){
	//declaration
	Koch* monFlocon;
	EPOINT *dernierPT, *equilateralPoint;
	
	monFlocon = malloc(sizeof(Koch));	
	monFlocon->points = init_liste(x1,y1);
	
	dernierPT = monFlocon->points;
	dernierPT = insert_after(dernierPT, x2, y2);
	
	equilateralPoint = equilateral(monFlocon->points->x, monFlocon->points->y, dernierPT->x, dernierPT->y, 60);
	dernierPT = insert_after(dernierPT, equilateralPoint->x, equilateralPoint->y);
	
	//initialisation des attributs de flocon
	monFlocon->ordreIteration = 0;
	monFlocon->ordreIterationCur = 0;
	monFlocon->animation = 1;
	monFlocon->couleurFond = ez_black;
	monFlocon->couleurContour = ez_black;
	monFlocon->nombrePoints = 3;
	monFlocon->longueurSegment = monFlocon->points->next->x - monFlocon->points->x;
	monFlocon->animation = animationType;
	
	return monFlocon;
	
}

/**
 * \brief       Ajoute le point qui forme le triangle equilateral
 * \details    	A partir de deux points, ajoute un point qui forme le triangle equilateral
 * \param    	x1				Abscisse du premier point
 * \param    	y1				Ordonnée du premier poiny
 * \param    	x2				Abscisse du second point
 * \param    	y2				Ordonnée du second point
 * \param    	degre			Degré de rotation du point equilateral
 * \return    	Une structure d'un point
 */
EPOINT* equilateral(double x1, double y1, double x2, double y2, double degre){
	double xtmp, ytmp, c60, s60, dx, dy;
	c60 = cos(degre * (M_PI / 180.0));
	s60 = sin(degre * (M_PI / 180.0));	
	dx = x2-x1;
	dy = y2-y1;
	xtmp = c60 * dx - s60 * dy + x1;
	ytmp = s60 * dx + c60 * dy + y1;	
	
	return create_point(xtmp, ytmp, NULL);
}
/**
 * \brief		Calcule le premier ou le second tiers du segment 
 * \param		x1				Point x du premier point du segment
 * \param		y1				Point y du premier point du segment
 * \param		x2				Point x du second point du segment
 * \param		y2				Point y du second point du segment
 * \param		t				Premier ou second tiers à calculer
 */
EPOINT* tiers(double x1, double y1, double x2, double y2, int t){
	double xtmp=0, ytmp=0;
	
	if(t==1){
		xtmp = x1 + (x2 - x1)/3;
		ytmp = y1 + (y2 - y1)/3;
	}else if(t==2){
		xtmp = x1 + 2*(x2 - x1)/3;			
		ytmp = y1 + 2*(y2 - y1)/3;
	}
	
	return create_point(xtmp, ytmp, NULL);
}
/**
 * \brief       Developpe le triangle equilateral d'un segment
 * \details    	Ajoute les points tiers du segement et le point pour former le triangle à partir des deux points
 * \param    	this			Structure d'un flocon de Koch
 * \param    	pointCourant	Premier point du segment
 * \param    	pointSuivant	Second point du segment
 * \param    	pointTier1		Point du premier tier du segment
 * \param    	pointTier2		Point du second tier du segment
 * \param    	pointEquilateral Pointr formant le triangle equilateral
 */
void triangleSegment(Koch* this, EPOINT* pointCourant, EPOINT* pointSuivant, EPOINT* pointTier1, EPOINT* pointTier2, EPOINT* pointEquilateral){
	//mise en place point premier tier
	//pointMilieu = milieu(pointCourant->x, pointCourant->y, pointSuivant->x, pointSuivant->y);
	pointTier1 = tiers(pointCourant->x, pointCourant->y, pointSuivant->x, pointSuivant->y, 1);
	pointTier1 = insert_after(pointCourant, pointTier1->x, pointTier1->y);
	this->nombrePoints++;

	//mise en place point second tier
	pointTier2 = tiers(pointCourant->x, pointCourant->y, pointSuivant->x, pointSuivant->y, 2);
	pointTier2 = insert_after(pointTier1, pointTier2->x, pointTier2->y);
	this->nombrePoints++;

	//mise en place point formation equilateral
	pointEquilateral = equilateral(pointTier1->x, pointTier1->y, pointTier2->x, pointTier2->y, -60);
	pointEquilateral = insert_after(pointTier1, pointEquilateral->x, pointEquilateral->y);
	this->nombrePoints++;
}

/**
 * \brief       Developpe le flocon une seule fois
 * \details    	En partant d'un flocon, developpe pour arriver à l'iteration suivante en parcourant tous les segments
 * \param    	this			Structure d'un flocon de Koch
 * \return    	Une structure du flocon de Koch
 */
Koch* developperKoch(Koch* this){
	//Declarations
	EPOINT *pointCourant, *pointSuivant, *pointTier1, *pointTier2, *pointEquilateral;
	int continuer;
	
	//initialisations
	pointCourant = pointSuivant = pointTier1 = pointTier2 = pointEquilateral = NULL;
	pointCourant = this->points;
	pointSuivant = pointCourant->next;
	continuer = 1;
	
	//parcourt des points du flocon
	while(continuer == 1){
		triangleSegment(this, pointCourant, pointSuivant, pointTier1, pointTier2, pointEquilateral);

		//repositionnement sur le segment suivant
		if(pointSuivant->next == NULL){
			pointCourant = pointSuivant;
			pointSuivant = this->points;
			triangleSegment(this, pointCourant, pointSuivant, pointTier1, pointTier2, pointEquilateral);
			continuer=0;
		}else{
			pointCourant = pointSuivant;
			pointSuivant = pointSuivant->next;
		}	
		
	}
	
	this->ordreIterationCur++;
	return this;
}

/**
 * \brief       Mutateur qui modifie la couleur de contour du flocon
 * \param    	this			Strutucture du flocon dont la couleur sera modifiée
 * \param    	couleur			Nouvelle couleur de contour
 */
void setCouleurContour(Koch* this, Ez_uint32 couleur){
	//test sur les couleurs
	this->couleurContour = couleur;
}

/**
 * \brief       Mutateur qui modifie la couleur de fond du flocon
 * \param    	this			Strutucture du flocon dont la couleur sera modifiée
 * \param    	couleur			Nouvelle couleur fond
 */
void setCouleurFond(Koch* this, Ez_uint32 couleur){
	//test sur les couleurs
	this->couleurFond = couleur;
}

/**
 * \brief       Mutateur qui modifie le nombre d'iteration du flocon
 * \param    	this			Strutucture du flocon dont le nombre d'iteration sera modifié
 * \param    	iteration		Nombre d'iteration
 */
void setIteration(Koch* this,int iteration){
	this->ordreIteration = iteration;
}

/**
 * \brief       Mutateur qui modifie le type d'animation du flocon
 * \param    	this			Strutucture du flocon dont le nombre d'iteration sera modifié
 * \param    	iteration		Type d'animation
 */
void setAnimation(Koch* this,int animation){
	this->animation = animation;
}
