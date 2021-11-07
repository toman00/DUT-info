public class Plantage {


	public static void main(String[] args) throws ArrayIndexOutOfBoundsException {
		int taille = 5;
		char tab[] = new char[taille];

		for (int i = 0; i < 6; i++) {
			tab[i] = 'i';
			// Si on ajoute une valeur au-delà des limites du tableau
			if (tab[i] > taille) {
				// Throw une erreur
				throw new ArrayIndexOutOfBoundsException("Limites du tableau de charactère atteintes !");
			}
		}
	}
}