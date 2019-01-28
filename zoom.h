/**
 * \author CHARARA Othmane
 * \date 20/04/2016
 * \version 1.0
 * \brief Déclaration de la structure Zoom et en-tête des fonctions
 */
#ifndef __zoom__
#define __zoom__
#include "ez-draw.h"
#include "fractaleManager.h"


/**
 * \brief Structure représentant le Zoom
 * \details La structure Zoom est constituée :
 */
typedef struct Zoom Zoom; 

struct Zoom {
	FractaleManager *manager; /*!< Fractale à zoomer */	
};

/**
 * \brief       Intialise le zoom
 * \details    	Zoom la fenetre renseignée à un certain % en x y
 * \param    	fractale		La fenetre à zoomer
 * \return    	Une structure Zoom
 */
Zoom *creerZoom(FractaleManager *manager);

/**
 * \brief		Zoom du flocon de Koch
 * \param		this		Structure Zoom qui contient un flocon de Koch à zoomer
 * \param		x			Point en abscisse du zoom
 * \param		y			Point en ordonnée du zoom
 * \param		pct			Pourcentage du zoom
 * \return		(void)
 */
void zoomerKoch(Zoom *this, int x, int y, double pct);


/**
 * \brief		Zoom de Mandelbrot
 * \param		this		Structure Zoom qui contient une fractale à zoomer
 * \param		x			Point en abscisse du zoom
 * \param		y			Point en ordonnée du zoom
 * \param		pct			Pourcentage du zoom
 * \return		(void)
 */
void zoomerMandelbrot(Zoom *this, int x, int y, double pct);

void zoomerMandelbrotTest(Zoom *this, int x, int y, double pct);
#endif
