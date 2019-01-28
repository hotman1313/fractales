/**
 * \author CHARARA Othmane
 * \date 20/04/2016
 * \version 1.0
 */
 
#include "zoom.h"


/**
 * \brief       Intialise le zoom
 * \details    	Zoom la fractale renseignée à un certain %
 * \param    	fractale				La fractale à zoomer
 * \return    	Une structure Zoom
 */
Zoom *creerZoom(FractaleManager *manager){
	//declaration
	Zoom *monZoom;
	
	//alloc.
	monZoom = malloc(sizeof(Zoom));
	
	//init des attributs
	monZoom->manager = manager;
	
	return monZoom;
}

/**
 * \brief		Zoom du flocon de Koch
 * \param		this		Structure Zoom qui contient un flocon de Koch à zoomer
 * \param		x			Point en abscisse du zoom
 * \param		y			Point en ordonnée du zoom
 * \param		pct			Pourcentage du zoom
 * \return		(void)
 */
void zoomerKoch(Zoom *this, int x, int y, double pct){
	Koch *koch;
	
	//printf("x ---> %lf\n", this->manager->koch->points);
	koch = creerKoch(100, 150, this->manager->koch->longueurSegment*pct+this->manager->koch->points->x, 150, 1);
	
	setIteration(koch, this->manager->koch->ordreIteration); //nombre d'iter	
	setCouleurContour(koch, this->manager->koch->couleurContour); //couleur
	
	int l;
	
	for(l = 0; l<koch->ordreIteration; l++){
		koch = developperKoch(koch);
	}
		this->manager->koch = koch;
}

/**
 * \brief		Zoom de Mandelbrot
 * \param		this		Structure Zoom qui contient une fractale à zoomer
 * \param		x			Point en abscisse du zoom
 * \param		y			Point en ordonnée du zoom
 * \param		pct			Pourcentage du zoom
 * \return		(void)
 */
 
void zoomerMandelbrot(Zoom *this, int x, int y, double pct){
	//declarations
	int width =600, height=600, xFen, yFen, xZoom, yZoom,i,j;
	
	Ez_uint32 tabPixRGBZoom[600][600];
	
	
	//on parcourt les pixels un à un pour zoomer
	for(xFen = 0; xFen < width; xFen++){
		for(yFen = 0; yFen < height; yFen++){
			xZoom = xFen + pct*(x - xFen);
			yZoom = yFen + pct*(y - yFen);
			if(xZoom >= 0 && xZoom < width && yZoom >= 0 && yZoom < height){
				tabPixRGBZoom[xFen][yFen] = this->manager->tabPixRGBFenFractale[xZoom][yZoom];
			}
		}	
	}
	//copie du nouveau tableau de pixels Zoomé !!!
	for(i=0; i<width; i++){
		for(j=0; j<height; j++){
			this->manager->tabPixRGBFenFractale[i][j] = tabPixRGBZoom[i][j];
		}
	}
}


void zoomerMandelbrotTest(Zoom *this, int x, int y, double pct){
	//declarations
	
	this->manager->mandelbrot->zoomX *= pct;
	this->manager->mandelbrot->zoomY *= pct;
	this->manager->mandelbrot->iterationMax *= pct;
	this->manager->mandelbrot->xMin -= pct-1;
	this->manager->mandelbrot->xMax += pct-1;
	this->manager->mandelbrot->yMin -= pct-1;
	this->manager->mandelbrot->yMax += pct-1;
	
	if(this->manager->mandelbrot->mandel == 1)
		genererMandelBrot(this->manager->mandelbrot);
	else
		genererJulia(this->manager->mandelbrot);
}
