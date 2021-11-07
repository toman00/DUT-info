public class Frequence<T> {
	Association<T> lien;

	// Constructeur
	public Frequence() {
		this.lien = new Association<T>();
	}

	// Recherche l'élement le plus fréquent dans un tableau
	public T searchMostFrequent(T[] arrayTest) {
		try {
			lien.setFrequence(1);
			for(int i = 0; i < arrayTest.length; i++) {
				int freq = 1;
				for (int j = i + 1; j < arrayTest.length; j++) {
					if (arrayTest[i] == arrayTest[j]) {
						freq += 1;
						
					}
					// Si un élément bat la plus haute fréquence précédente
					if (freq > this.lien.getFrequence()) {
						this.lien.setFrequence(freq);
						this.lien.setElement(arrayTest[j]);
					}
				}
			}
			return this.lien.getElement();
		}
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("ERREUR : Le tableau en entrée est vide.");
			return null;
		}
		
	}
}
