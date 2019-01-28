/**
 * \author CHARARA Othmane
 * \date 7/04/2016
 * \version 1.0
 * \brief Déclaration de la structure Koch et en-tête des fonctions
 */
#ifndef __koch__
#define __koch__
#include "ez-draw.h"
#include "listep.h"


/**
 * \brief Structure représentant le flocon de Koch
 * \details Le flocon de Koch est constitué :
 */
typedef struct Koch Koch; 

struct Koch {
	PLISTE points; /*!< Liste des points */
	int ordreIteration; /*!< Nombre d'iterations souhaitées */
	int ordreIterationCur; /*!< Nombre d'iterations courant (où en le flocon) */
	int animation; /*!< Type d'animation : 1 => aucune ; 2 => finie ; 3 => circulaire */
	Ez_uint32 couleurFond; /*!< Couleur de fond du flocon */
	Ez_uint32 couleurContour; /*!< Couleur contour du flocvon */
	int nombrePoints; /*!< Nombre de points */	
	double longueurSegment; /*!< La longueur du segment initial du flocon */
};


/**
 * \brief       Intialise le Flocon de Koch
 * \details    	A partir de deux points, ajoute un point qui forme le triangle equilateral
 * \param    	x1				Abscisse du premier point
 * \param    	y1				Ordonnée du premier point
 * \param    	x2				Abscisse du second point
 * \param    	y2				Ordonnée du second point
 * \param    	animationType	Type d'animation
 * \return    	Une structure du flocon de Koch
 */
Koch* creerKoch(double x1, double y1, double x2, double y2, int animationType);

/**
 * \brief       Developpe le flocon une seule fois
 * \details    	En partant d'un flocon, developpe pour arriver à l'iteration suivante en parcourant tous les segments
 * \param    	this			Structure d'un flocon de Koch
 * \return    	Une structure du flocon de Koch
 */
Koch* developperKoch(Koch* this);

/**
 * \brief		Calcule le premier ou le second tiers du segment 
 * \param		x1				Point x du premier point du segment
 * \param		y1				Point y du premier point du segment
 * \param		x2				Point x du second point du segment
 * \param		y2				Point y du second point du segment
 * \param		t				Premier ou second tiers à calculer
 */
EPOINT* tiers(double x1, double y1, double x2, double y2, int t);

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
void triangleSegment(Koch* this, EPOINT* pointCourant, EPOINT* pointSuivant, EPOINT* pointTier1, EPOINT* pointTier2, EPOINT* pointEquilateral);

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
EPOINT* equilateral(double x1, double y1, double x2, double y2, double degre);

/**
 * \brief       Mutateur qui modifie la couleur de contour du flocon
 * \param    	this			Strutucture du flocon dont la couleur sera modifiée
 * \param    	couleur			Nouvelle couleur de contour
 */
void setCouleurContour(Koch* this, Ez_uint32 couleur);

/**
 * \brief       Mutateur qui modifie la couleur de fond du flocon
 * \param    	this			Strutucture du flocon dont la couleur sera modifiée
 * \param    	couleur			Nouvelle couleur fond
 */
void setCouleurFond(Koch* this, Ez_uint32 couleur);

/**
 * \brief       Mutateur qui modifie le nombre d'iteration du flocon
 * \param    	this			Strutucture du flocon dont le nombre d'iteration sera modifié
 * \param    	iteration		Nombre d'iteration
 */
void setIteration(Koch* this,int iteration);

/**
 * \brief       Mutateur qui modifie le type d'animation du flocon
 * \param    	this			Strutucture du flocon dont le nombre d'iteration sera modifié
 * \param    	iteration		Type d'animation
 */
void setAnimation(Koch* this,int animation);


#endif

