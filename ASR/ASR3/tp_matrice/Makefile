### VARIABLES ###
 
CC = gcc
CFLAGS = -Wall \
	-pedantic
EXE = matrix
OFILES = matrix.o \
	 main.o
  
### BUT PAR DEFAUT ###
   
run : ${EXE}
	 
### REGLES ESSENTIELLES ###
	  
matrix.o : matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c
	 
main.o : main.c
	$(CC) $(CFLAGS) -c main.c
	 
${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}
		 
### REGLES OPTIONNELLES ###
		  
clean :
	-rm -f ${OFILES} ${EXE} 
		 
mrproper : clean run
	 
### BUTS FACTICES ###
	  
.PHONY : run clean mrproper
	 
### FIN ###
