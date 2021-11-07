import java.text.ParseException;
import java.text.RuleBasedCollator;
import java.util.Arrays;

public class Tableau {
	// Constructeur		
	public Tableau(){

	}

	// Méthode permettant d'afficher tous les élements d'un tableau à la console
	// (sans boucle)
	public void printSortedTab(String[] tab) {
		// Limite à AU PLUS, 5 éléments
		if (tab.length > 5) {
			tab = Arrays.copyOf(tab, 5);
		}
		
		try {
			// Trie les éléments
			String rules = "< a, A < b, B < c, C < d, D < e, E < f, F < g, G < h, H < i, I" +
			"< j, J < k, K < l, L < m, M < n, N < o, O < p, P < q, Q < r, R" +
			"< s, S < t, T < u, U < v, V < w, W < x, X < y, Y < z, Z" +
			"  aa, AA";
			RuleBasedCollator comp = new RuleBasedCollator(rules);
			Arrays.sort(tab, 0, tab.length, comp);
		}
		catch (ParseException e) {
			System.err.println("Erreur de conversion lors du tri.");
		}
		
		// Convertit en une chaîne de caractère un tableau d'éléments
		String element = Arrays.toString(tab);

		// Enlève les crochets
		element = element.substring(1,element.length()-1);
		
		// Affiche le résultat à la console
		System.out.println(element);
	}
}
