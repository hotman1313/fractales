/**
 * \author CHARARA Othmane
 * \date 11/04/2016
 * \version 1.0
 */
 
#include "sauvegarde.h"
#include <stdio.h>
#include <math.h>

/**
 * \brief       Intialise la sauvegarde pour le flocon de Koch
 * \details    	Sauve la fractale renseignée sous un nom donné
 * \param    	fractale				La fractale à sauvegarde
 * \param    	nomFichier				Nom de fichier de sauvegarde
 * \return    	Une structure Sauvegarde
 */
Sauvegarde *creerSauvegardeKoch(void *fractale, char* nomFichier){
	//declarations
	Sauvegarde *maSauvegarde;
	int i, j;
	
	//initialisation
	maSauvegarde = malloc(sizeof(Sauvegarde));
	
	//initialisation des attributs
	maSauvegarde->fractale = fractale;
	maSauvegarde->fractaleM = NULL;
	maSauvegarde->nomFichier = nomFichier;
	
	for(i=0 ; i<600; i++){
		for(j=0; j<600; j++)
			maSauvegarde->tableauPixelsPPM[i][j] = 0;
	}
	
	return maSauvegarde;
}
/**
 * \brief       Intialise la sauvegarde pour la fractale Mandelbrot
 * \details    	Sauve la fractale renseignée sous un nom donné
 * \param    	fractale				La fractale à sauvegarde
 * \param    	nomFichier				Nom de fichier de sauvegarde
 * \return    	Une structure Sauvegarde
 */
Sauvegarde *creerSauvegardeMandelBrot(void *fractale, char* nomFichier){
	//declarations
	Sauvegarde *maSauvegarde;
	int i, j;
	
	//initialisation
	maSauvegarde = malloc(sizeof(Sauvegarde));
	
	//initialisation des attributs
	maSauvegarde->fractaleM = fractale;
	maSauvegarde->fractale = NULL;
	maSauvegarde->nomFichier = nomFichier;
	
	for(i=0 ; i<600; i++){
		for(j=0; j<600; j++)
			maSauvegarde->tableauPixelsPPM[i][j] = 0;
	}
	
	return maSauvegarde;
}

/**
 * \brief       Algorithme de Bresenham sur les huits octants
 * \details    	L’algorithme détermine quels sont les points d’un plan discret qui 
 * 				doivent être tracés afin de former une approximation de segment de droite entre deux points donnés.
 * 				N.B : Cette algorithme a été trouvé sur le site http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/
 * \param    	this					La sauvegarde
 * \param    	x1						Abscisse de premier point du segment
 * \param    	y1						Ordonné de premier point du segment
 * \param    	x2						Abscisse de second point du segment
 * \param    	y2						Ordonné de second point du segment
 * \return    	(void)
 */
void TracerSegmentBresenham(Sauvegarde *this, int x1, int y1, int x2, int y2){
	//declarations
	int i, w, h, dx1, dy1, dx2, dy2, longueur, largeur, numerateur;
	
	//initialisation
	w = x2 - x1;
	h = y2 - y1;
	dx1 = dy1 = dx2 = dy2 = 0;
	
	if (w<0) dx1 = -1 ; else if (w>0) dx1 = 1 ;
    if (h<0) dy1 = -1 ; else if (h>0) dy1 = 1 ;
    if (w<0) dx2 = -1 ; else if (w>0) dx2 = 1 ;
	
	longueur = fabs(w);
	largeur = fabs(h);
	
	if(!(longueur > largeur)){
		longueur = fabs(h);
		largeur = fabs(w);
		if (h<0) dy2 = -1 ; else if (h>0) dy2 = 1 ;
        dx2 = 0 ; 
	}
	
	numerateur = longueur >> 1;
	for (i=0;i<=longueur;i++) {
        this->tableauPixelsPPM[x1][y1] = 1;
        numerateur += largeur ;
        if (!(numerateur<longueur)) {
            numerateur -= longueur ;
            x1 += dx1 ;
            y1 += dy1 ;
        } else {
            x1 += dx2 ;
            y1 += dy2 ;
        }
    }
}

/**
 * \brief       Génère un fichier de points
 * \details    	Produits un fichier qui contient tous les points (x y) de la fractale
 * \param    	this					La sauvegarde
 * \return    	(void)
 */ 
void genererFichierPoints(Sauvegarde *this){
	ecrire_liste(this->nomFichier, this->fractale->points);
}

/**
 * \brief       Lit un fichier de points pour restaurer une image
 * \details    	À partir d'une liste de points, crée l'image
 * \param    	this					La sauvegarde
 * \return    	Liste de points
 */ 
void restaurerFichierPoints(Sauvegarde *this){
	lire_liste(this->nomFichier);
}

/**
 * \brief       Génère une image PPM
 * \details    	Produits un fichier PPM qui contient tous les points (x y) de la fractale
 * \param    	this					La sauvegarde
 * \return    	(void)
 */ 
void genererFichierPPMKoch(Sauvegarde *this){
	//s'assure qu'il y a bien un flocon à sauvegarder
	if(this->fractale == NULL) return;
	
	//Déclarations
	FILE *fichier;
	int i, j;
	EPOINT *cur;
	
	//Initialisations
	cur = this->fractale->points;
	
	//parcourt tous les segments
	while(cur->next != NULL){
		TracerSegmentBresenham(this, cur->x, cur->y, cur->next->x, cur->next->y);
		cur = cur->next;
	}
	
	//dernier segment (pour faire le tour)
	TracerSegmentBresenham(this, cur->x, cur->y, this->fractale->points->x, this->fractale->points->y);
	
	//Ouverture fichier
	fichier = fopen(this->nomFichier, "w");
	
	//formation en-tête ppm
	fprintf(fichier, "P3\n#600 colonnes 600 lignes\n600 600\n#val max pour RGB\n255\n");
	
	//remplissage pixel ppm	
	for(i=0 ; i<600; i++){
		fprintf(fichier, "\n");
		for(j=0; j<600; j++)
			if(this->tableauPixelsPPM[i][j] == 0)
				fprintf(fichier, "255 255 255 ");
			else
				fprintf(fichier, "0 0 0 ");
	}
		
	//fermeture fichier
	fclose(fichier);
}


/**
 * \brief       Génère une image PPM pour la fractale Mandelbrot et ses ensemble Julia
 * \details    	Produits un fichier PPM qui contient tous les points (x y) de la fractale
 * \param    	this					La sauvegarde
 * \return    	(void)
 */ 
void genererFichierPPMMandelbrot(Sauvegarde *this){
	//s'assure qu'il y a bien une freactale à sauvegarder
	if(this->fractaleM == NULL) return;
	
	//Déclarations
	FILE *fichier;
	int i, j;
	
	//parcourt de la matrice de pixels de la fractale
	for(i = 0; i<600; i++){
		for(j = 0; j<600; j++){
			if(i+1 < 600 && j+1 < 600 && this->fractaleM->image->mesPixels[i+1][j+1]->rouge == 255 && this->fractaleM->image->mesPixels[i][j]->rouge == 255)
				TracerSegmentBresenham(this, this->fractaleM->image->mesPixels[i][j]->x, this->fractaleM->image->mesPixels[i][j]->y, this->fractaleM->image->mesPixels[i+1][j+1]->x, this->fractaleM->image->mesPixels[i+1][j+1]->y);
		}
	}
		
	
	//Ouverture fichier
	fichier = fopen(this->nomFichier, "w");
	
	//formation en-tête ppm
	fprintf(fichier, "P3\n#600 colonnes 600 lignes\n600 600\n#val max pour RGB\n255\n");
	
	//remplissage pixel ppm	
	for(i=0 ; i<600; i++){
		fprintf(fichier, "\n");
		for(j=0; j<600; j++)
			if(this->tableauPixelsPPM[i][j] == 0)
				fprintf(fichier, "255 255 255 ");
			else
				fprintf(fichier, "0 0 0 ");
	}
		
	//fermeture fichier
	fclose(fichier);
	
}
