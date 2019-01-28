/**
 * \author CHARARA Othmane
 * \date 23/05/2016
 * \version 1.0
 * \brief Déclaration de la structure Mandelbrot et en-tête des fonctions
 */
#ifndef __mandelbrot__
#define __mandelbrot__
#include "cplxio.h"
#include "cplxop.h"
#include "image.h"

/**
 * \brief Structure représentant la fractale Mandelbrot
 * \details Le fractale Mandelbrot est constituée de :
 */
typedef struct Mandelbrot Mandelbrot; 

struct Mandelbrot {
	int mandel; /*!< Si la fractale est une mandelbrot alors vaut 1 sinon vaut 0*/
	Image *image; /*!< Image qui contiendra les pixels */
	COMPLEXE *Zcur; /*!< Complexe qui représente le terme courant de la suite */
	COMPLEXE *C; /*!< Complexe qui représente */
	double xMin; /*!< Borne minimum en abscisse */
	double xMax; /*!< Borne maximale en abscisse */
	double yMin; /*!< Borne minimum en ordonnée */
	double yMax; /*!< Borne maximale en ordonnée */
	int iterationMax; /*!< Nombre d'itérations maximum */
	int zoomX; /*!< Zoom X de la fracale */
	int zoomY; /*!< Zoom y de la fracale */
	
};

/**
 * \brief       Intialise une fractale Mandelbrot
 * \details		À partir d'arguments (premier terme de la suite et limations abscisses/ordonnées), créée un Mandelbrot
 * \param    	xmin				Borne inférieure en x
 * \param    	xmax				Borne supérieure en x
 * \param    	ymin				Borne inférieure en y
 * \param    	ymax				Borne supérieure en y
 * \return    	Une structure de Mandelbrot
 */
Mandelbrot *creerMandelbrot(double xmin, double xmax, double ymin, double ymax);

/**
 * \brief       Intialise une fractale Julia
 * \details		À partir d'arguments (comme pour mandelbrot mais avec la valeur constante de C en plus), créée un Julia
 * \param    	c_re				Partie réelle de la constante C
 * \param    	c_im				Partie imaginaire de la constante C
 * \param    	xmin				Borne inférieure en x
 * \param    	xmax				Borne supérieure en x
 * \param    	ymin				Borne inférieure en y
 * \param    	ymax				Borne supérieure en y
 * \return    	Une structure de Mandelbrot
 */
Mandelbrot *creerJulia(double c_re, double c_im, double xmin, double xmax, double ymin, double ymax);

/**
 * \brief		Chaque pixel de l'image est convertit en complexe pour calculer la suite (cas Mandelbrot) et savoir elle diverge ou pas
 * \param		this		La fractale 
 * \param		x			Position en abscisse du pixel courant
 * \param		y			Position en ordonnée du pixel courant
 */
void convertirComplexeMandelbrot(Mandelbrot *this, double x, double y);

/**
 * \brief		Chaque pixel de l'image est convertit en complexe pour calculer la suite (cas Julia) et savoir elle diverge ou pas
 * \param		this		La fractale 
 * \param		x			Position en abscisse du pixel courant
 * \param		y			Position en ordonnée du pixel courant
 */
void convertirComplexeJulia(Mandelbrot *this, double x, double y);

/**
 * \brief		À partir du pixel qui a été convertit en complexe, calcul la suite jusqu'à l'iteration max et renvoie la valeur à laquelle l'iteration s'est arrêtée
 * \param		this		La fractale 
 */
int convergence(Mandelbrot *this);

/**
 * \brief		En parcourant tous les pixels de l'image et à l'aide des fonctions onvertirComplexe() et convergence(), detecte si le pixel doit être dessiné en noir ou en blanc (pour Mandelbrot)
 * \param		this		La fractale 
 */
void genererMandelBrot(Mandelbrot *this);

/**
 * \brief		En parcourant tous les pixels de l'image et à l'aide des fonctions onvertirComplexe() et convergence(), detecte si le pixel doit être dessiné en noir ou en blanc (pour JULIA)
 * \param		this		La fractale 
 */
void genererJulia(Mandelbrot *this);

#endif
