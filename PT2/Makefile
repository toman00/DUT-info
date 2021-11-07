### VARIABLES ###

JC = javac
JCFLAGS = -encoding UTF-8 -implicit:none

JVM = java
JVMFLAGS = 

### REGLES ESSENTIELLES ###

Main.class : Main.java MainWindow.class
	${JC} ${JCFLAGS} Main.java

MainWindow.class : MainWindow.java GridPanel.class
	${JC} ${JCFLAGS} MainWindow.java

GridPanel.class : GridPanel.java ScorePanel.class
	${JC} ${JCFLAGS} GridPanel.java

ScorePanel.class : ScorePanel.java Grid.class
	${JC} ${JCFLAGS} ScorePanel.java

Grid.class : Grid.java GameMenuPanel.class
	${JC} ${JCFLAGS} Grid.java

GameMenuPanel.class : GameMenuPanel.java GameMenuEvents.class
	${JC} ${JCFLAGS} GameMenuPanel.java

GameMenuEvents.class : GameMenuEvents.java Block.class
	${JC} ${JCFLAGS} GameMenuEvents.java

Block.class : Block.java BlockEvents.class
	${JC} ${JCFLAGS} Block.java

BlockEvents.class : BlockEvents.java Defines.class
	${JC} ${JCFLAGS} BlockEvents.java

Defines.class : Defines.java EndPanel.class
	${JC} ${JCFLAGS} Defines.java

EndPanel.class : EndPanel.java GamePanel.class
	${JC} ${JCFLAGS} EndPanel.java
	
GamePanel.class : GamePanel.java
	${JC} ${JCFLAGS} GamePanel.java

	


### REGLES OPTIONNELLES ###

run : Main.class
	${JVM} ${JVMFLAGS} Main


ifeq ($(OS),Windows_NT)
    #Windows
    RM = del -Rf
else
    #Linux
    RM = rm -rf
endif

clean :
	$(RM) *.class


mrproper : clean Main.class

### BUTS FACTICES ###

.PHONY : run clean mrproper

### FIN ###