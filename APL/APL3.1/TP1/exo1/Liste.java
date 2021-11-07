package exo1;
import java.util.ArrayList;
// Exercice 1

public class Liste {
	// Différentes arrayList à tester
	private ArrayList<Integer> intList;
	private ArrayList<Float> floatList;
	private ArrayList<Number> numberList;
	private ArrayList<ArrayList<? extends Number>> container;


	// Elements à ajouter pour test
	private final Long longTest = 10111l;
	private final Float floatTest = 101.1f;
	private final Integer intTest = 101101;

	// Constructeur
	public Liste() {
		// Création des listes
		this.intList = new ArrayList<Integer>();
		this.floatList = new ArrayList<Float>();
		this.numberList = new ArrayList<Number>();

		this.container = new ArrayList<ArrayList<? extends Number>>();
		this.container.add(this.intList);
		this.container.add(this.floatList);
		this.container.add(this.numberList);
	}

	// Question b.
	public void testAdd() {
		// Ajout dans la liste de Number
		this.numberList.add(floatTest);
		this.numberList.add(longTest);
		this.numberList.add(intTest);

		// Ajout dans la liste de Integer
		//this.intList.add(floatTest); // IMPOSSIBLE
		//this.intList.add(longTest); // IMPOSSIBLE
		this.intList.add(intTest);


		// Ajout dans la liste de Float
		this.floatList.add(floatTest);
		//this.floatList.add(longTest); // IMPOSSIBLE
		//this.floatList.add(intTest); // IMPOSSIBLE


		
		// Afficher les élements des arraylist
		this.container.forEach((res) -> System.out.println(res));
	}

	// Question b.
	public void testAddAll() {
		// Test des listes
		// intList
		// this.intList.addAll(this.floatList); // impossible
		// this.intList.addAll(this.numberList); // impossible
		// 
		// floatList
		// this.floatList.addAll(this.numberList); // impossible
		// this.floatList.addAll(this.intList); // impossible
		//
		// numberList (seul addAll qui fonctionne)
		this.numberList.addAll(this.floatList); 
		this.numberList.addAll(this.intList);
	}
}
