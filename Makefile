all: a.out
				echo "Construction de realisee !"

a.out:
			gcc -Wall main.c Fichier.c login.c menu.c actes.c functions.c basicfct.c structure.h family.c -o prog.exe

clear:
	 		rn -f prog.exe 
