import java.util.*;
import java.io.*;

public class Devinette {
	// Attributs
	private int randomValue;
	private int nbTry;
	private int guess;

	// Constructeur
	public Devinette() {
		try {
			BufferedReader entree = new BufferedReader(new InputStreamReader(System.in));
			// Nb aléatoire
			Random gen = new Random();

			this.randomValue =gen.nextInt(100);
			//this.guess = 100;
			this.nbTry = 0;
			System.out.println("Tentez votre chance :");

			while (this.guess != randomValue && this.nbTry < 5) {
				if (nbTry != 0) {
					if (this.guess > randomValue) {
						System.out.println("C'est moins !");
					}
					else {
						System.out.println("C'est plus !");
					}
				}
				// On transforme le caractère en un entier
				this.guess = Integer.parseInt(entree.readLine());
				this.nbTry += 1;
			}

			if (this.guess == randomValue) {
				System.out.println("Bien joué, vous avez trouvé !");
			}
			else {
				System.out.println("Désolé, une prochaine fois peut être ! C'était " + randomValue);
			}

		}
		catch(IOException e) {
			System.err.println("Erreur de lecture");
		}
	}
}