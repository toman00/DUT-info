// Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char** argv) {
	/* On appelle la fonction time afin d'avoir la date en seconde
    depuis 1970 */
    time_t timestamp = time(NULL);
    
    /* Appel de la fonction localtime afin de convertir la date (en seconde) en
    années) */
    struct tm * pTime = localtime( & timestamp );
    
    /* Affichage de la date avec le format voulu YY/MM/DD */
    printf( "Date : %04d/%02d/%02d\n",
    pTime->tm_year+1900, pTime->tm_mon+1, pTime->tm_mday);
    
     
    // Valeur de retour
    return 0;

}
