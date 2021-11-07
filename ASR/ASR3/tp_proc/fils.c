  /* 
   Le programme créer 5 processus fils.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main()
{ 
  int pidChild, i, status;

  /* Boucle de création des processus fils */
  for (i = 0; i < 5; i++) {
    
    pidChild = fork();

    /* Processus fils */
    if (pidChild == 0) {
      
      printf("Fils %d (%d) \n", i, getpid());
      
      exit(0);
    } 

    /* Processus père */
    else {
      printf("Fork %d à retourné : %d\n", i, pidChild);
    }
  }

  pidChild = wait(&status);
  printf("wait() à retourné : %d\n", pidChild);
  


  return 0;
}
