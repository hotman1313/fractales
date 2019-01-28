/**
 * \author CHARARA Othmane
 * \date 23/05/2016
 * \version 1.0
 * \brief Déclaration de la structure Mandelbrot et en-tête des fonctions
 */
#include "mandelbrot.h"

/**
 * \brief       Intialise une fractale Mandelbrot
 * \details		À partir d'arguments (premier terme de la suite et limations abscisses/ordonnées), créée un Mandelbrot
 * \param    	xmin				Borne inférieure en x
 * \param    	xmax				Borne supérieure en x
 * \param    	ymin				Borne inférieure en y
 * \param    	ymax				Borne supérieure en y
 * \return    	Une structure de Mandelbrot
 */
Mandelbrot *creerMandelbrot(double xmin, double xmax, double ymin, double ymax){
	Mandelbrot *monMandelbrot;
	
	monMandelbrot = malloc(sizeof(Mandelbrot));
	
	monMandelbrot->mandel = 1;
	monMandelbrot->image = creerImage(600, 600);
	monMandelbrot->Zcur = create_complexe(0, 0);
	monMandelbrot->xMin = xmin;
	monMandelbrot->xMax = xmax;
	monMandelbrot->yMin = ymin;
	monMandelbrot->yMax = ymax;
	monMandelbrot->iterationMax = 50;	
	monMandelbrot->zoomX = 600/(monMandelbrot->xMax - monMandelbrot->xMin);	
	monMandelbrot->zoomY = 600/(monMandelbrot->yMax - monMandelbrot->yMin);	
	
	return monMandelbrot;
}
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
Mandelbrot *creerJulia(double c_re, double c_im, double xmin, double xmax, double ymin, double ymax){
	Mandelbrot *monMandelbrot;
	
	monMandelbrot = malloc(sizeof(Mandelbrot));
	monMandelbrot->mandel = 0;
	monMandelbrot->image = creerImage(600, 600);
	monMandelbrot->Zcur = create_complexe(0, 0);
	monMandelbrot->C = create_complexe(c_re, c_im);
	monMandelbrot->xMin = xmin;
	monMandelbrot->xMax = xmax;
	monMandelbrot->yMin = ymin;
	monMandelbrot->yMax = ymax;
	monMandelbrot->iterationMax = 50;	
	monMandelbrot->zoomX = 600/(monMandelbrot->xMax - monMandelbrot->xMin);	
	monMandelbrot->zoomY = 600/(monMandelbrot->yMax - monMandelbrot->yMin);	
	
	return monMandelbrot;
}
/**
 * \brief		Chaque pixel de l'image est convertit en complexe pour calculer la suite (cas Mandelbrot) et savoir elle diverge ou pas
 * \param		this		La fractale 
 * \param		x			Position en abscisse du pixel courant
 * \param		y			Position en ordonnée du pixel courant
 */
void convertirComplexeMandelbrot(Mandelbrot *this, double x, double y){
	this->C = create_complexe(x/(this->zoomX)+this->xMin, y/(this->zoomY)+this->yMin);
	this->Zcur = create_complexe(0, 0);
}

/**
 * \brief		Chaque pixel de l'image est convertit en complexe pour calculer la suite (cas Julia) et savoir elle diverge ou pas
 * \param		this		La fractale 
 * \param		x			Position en abscisse du pixel courant
 * \param		y			Position en ordonnée du pixel courant
 */
void convertirComplexeJulia(Mandelbrot *this, double x, double y){
	//this->C = create_complexe(0.285, 0.01);//(x/(this->zoomX)+this->xMin, y/(this->zoomY)+this->yMin);
	this->Zcur = create_complexe(x/this->zoomX+this->xMin, y/this->zoomY+this->yMin);
}
/**
 * \brief		À partir du pixel qui a été convertit en complexe, calcul la suite jusqu'à l'iteration max et renvoie la valeur à laquelle l'iteration s'est arrêtée
 * \param		this		La fractale 
 */
int convergence(Mandelbrot *this){
	int i = 0;
	do{
		this->Zcur = add_cplx(mul_cplx(this->Zcur, this->Zcur), this->C);
		i+=1;
	}while(moduleCplx(this->Zcur) < 2 && i < this->iterationMax);
	
	return i;
}
/**
 * \brief		En parcourant tous les pixels de l'image et à l'aide des fonctions onvertirComplexe() et convergence(), detecte si le pixel doit être dessiné en noir ou en blanc (pour Mandelbrot)
 * \param		this		La fractale 
 */
void genererMandelBrot(Mandelbrot *this){
	int i, j, c;
	Pixel *p;
	
	for(i = 0; i<600; i++){
		for(j = 0; j<600; j++){
			convertirComplexeMandelbrot(this, i, j);
			c = convergence(this);
			if(c == this->iterationMax){
				p = creerPixel(i, j, 0, 0, 0);
				setPixel(this->image, p, i, j);
			}else{
				p = creerPixel(i, j, 255, 255, 255);
				setPixel(this->image, p, i, j);
			}
		}
	}
}
/**
 * \brief		En parcourant tous les pixels de l'image et à l'aide des fonctions onvertirComplexe() et convergence(), detecte si le pixel doit être dessiné en noir ou en blanc (pour JULIA)
 * \param		this		La fractale 
 */
void genererJulia(Mandelbrot *this){
	int i, j, c;
	Pixel *p;
	
	for(i = 0; i<600; i++){
		for(j = 0; j<600; j++){
			convertirComplexeJulia(this, i, j);
			c = convergence(this);
			if(c == this->iterationMax){
				p = creerPixel(i, j, 0, 0, 0);
				setPixel(this->image, p, i, j);
			}else{
				p = creerPixel(i, j, 255, 255, 255);
				setPixel(this->image, p, i, j);
			}
		}
	}
}
