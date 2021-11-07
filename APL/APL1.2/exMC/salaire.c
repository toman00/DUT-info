#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Fonction de calcul de salaire
double sal(int x, int b){
	// x => année(s) de travail
	double annee = (double) x;
	// b => salaire de base
	double base = (double) b;


	// Salaire à retourner
	double salaire = 0.0;

	// Si 0 <= x <= 34
	if ((x >= 0) && (x<=34)){
		salaire = base + base * annee / 34.0;


	}

	// Si 34 <= x <= 42 
	else if ((x > 34) && (x<=42)){
		salaire = 2 * base;
	}


	// Retourne le salaire
	return salaire;
}

// Fonction remplissage tableau 
void remp_tab(int b){
	// b => salaire de base
		
	// Tableau de valeurs de salaire
	double tab_sal[43];

	// Remplissage et affichage tableau
	for (int x=0; x <= 42 ; x++){
		tab_sal[x] = sal(x,b);
	}
		
}

// Fonction de calcul de moyenne salaire
double sal_moy(double *t, int taille) {
    // t => tableau contenant le salaire mensuel
    // taille => taille du tableau

    // Somme calculee
    double somme_sal = 0.0;

    // Somme de tous les salaires du tableau
    for (int i=0; i<taille; i++) {
        somme_sal += t[i];
    }

	// Calcul de la moyenne
    double moy_sal = somme_sal / (double) taille;

    // Retourne moyenne salaire
    return moy_sal;
}


int main(int argc, char *argv[]) {
	// Calcul du salaire
	double calcul_salaire=sal(10,1800);


	// Affichage du resultat
	// printf("Salaire : %.2lf", calcul_salaire);
	
	// Remplissage tableau avec base = 1800
	remp_tab(1800);

	// Calcul moyenne
	// Tableau de salaire moyen
	double tab_sal[43];

	// choix du salaire au hasard : entre 1450 et 1800
	srand(time (NULL));
	// rand(): entre 0 et RAND_MAX
	int base = 1450+rand()% 350;

	// Remplissage et affichage tableau
	for (int x=0; x <= 42 ; x++){
		tab_sal[x] = sal(x,base);
		printf("Valeur salaire (x=%d) : %.2lf\n", x, tab_sal[x]);
	}

	// Affichage du salaire de base
	printf("Salaire de base : %d\n", base);


	double calcul_moy = sal_moy(tab_sal,43);

	// Affichage moyenne
	printf("Salaire moyen sur la carrière : %.2lf \n",calcul_moy);

	// Fin de programme
	return EXIT_SUCCESS;
}