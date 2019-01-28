#Compilateur

CC= gcc 
CFLAGS = -Wall -W -std=c99 -pedantic -O2 -g 
LIBS   = -lX11 -lXext
LIBS_I =
REP=-I ./

EXECS = main

SHELL  = /bin/bash
RM     = rm -f
EXT    =

all: main

$(EXECS): main.o listep_op.o cplxio.o cplxop.o util.o pixel.o image.o mandelbrot.o koch.o sauvegarde.o bouton.o itemOption.o listeChoix.o jauge.o menu.o zoom.o fractaleManager.o ez-draw.o
	$(CC) $(REP) -lm -o $@ $^ $(LIBS)


#compilation main
main.o: main.c fractaleManager.h
	$(CC) $(REP) -c $(CFLAGS) main.c


#compilation modele
listep_op.o: listep_op.c listep.h listep_op.h
	$(CC) $(REP) -c $(CFLAGS) listep_op.c

cplxio.o: cplxio.c cplxio.h
	$(CC) $(REP) -c $(CFLAGS) cplxio.c
				
cplxop.o: cplxop.c cplx.h
	$(CC) $(REP) -c $(CFLAGS) cplxop.c
		
util.o: util.c util.h
	$(CC) $(REP) -c $(CFLAGS) util.c

pixel.o: pixel.c pixel.h 
	$(CC) $(REP) -c $(CFLAGS) pixel.c

image.o: image.c image.h 
	$(CC) $(REP) -c $(CFLAGS) image.c

mandelbrot.o: mandelbrot.c mandelbrot.h 
	$(CC) $(REP) -c $(CFLAGS) mandelbrot.c

koch.o: koch.c koch.h listep_op.h
	$(CC) $(REP) -c $(CFLAGS) koch.c
	
sauvegarde.o: sauvegarde.c sauvegarde.h
	$(CC) $(REP) -c $(CFLAGS) sauvegarde.c


#compilation vue
bouton.o: bouton.c bouton.h
	$(CC) $(REP) -c $(CFLAGS) bouton.c

itemOption.o: itemOption.c itemOption.h
	$(CC) $(REP) -c $(CFLAGS) itemOption.c

menu.o: menu.c menu.h
	$(CC) $(REP) -c $(CFLAGS) menu.c

listeChoix.o: listeChoix.c itemOption.h
	$(CC) $(REP) -c $(CFLAGS) listeChoix.c

jauge.o: jauge.c jauge.h
	$(CC) $(REP) -c $(CFLAGS) jauge.c

zoom.o: zoom.c zoom.h
	$(CC) $(REP) -c $(CFLAGS) zoom.c

#compilation controleur
fractaleManager.o: fractaleManager.c
	$(CC) $(REP) -c $(CFLAGS) fractaleManager.c


clean:
	rm -f main *.o 
