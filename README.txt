			|Logiciel Fractale|


Date : 27/05/2016
Version 1.0

-----------------------------------------------------------------------

I) Installation

	Il faut d’abord installer les packages de développement. Ouvrez un terminal puis tapez (ou copiez-collez) :

-> sudo apt-get install libx11-dev x11proto-xext-dev libxext-dev

	Puis, rendez-vous dans le répertoire du logiciel et lancez :

-> make (entrer)
-> ./main


II) Fonctionnement

	Une fois le logicial demarré, deux fenêtres apparaissent. Le menu et la fenêtre qui affiche les fractales.
	Le menu est basé sur des listes déroulantes et des boutons.

	- Pour générer le flocon de Koch, il faut choisir les paramètres (nombre d'iterations, taille, couleur et  animation). Ensuite, cliquer sur "Valider" pour l'afficher.
	  Lorsqu'il est généré, il est possible de le sauver dans une image ppm ou un fichier points via les boutons adéquates ("Sauvegarder PPM" et "Sauvegarder Points").

	- La fractale de Mandelbrot et les ensembles de Julia se génèrent juste en choisissant le type de fractale.
	  La sauvegarde est identique que pour Koch.
