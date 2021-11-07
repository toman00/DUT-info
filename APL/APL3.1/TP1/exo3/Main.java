public class Main {
	// Execution
	public static void main(String[] args) {
		Frequence<String> freq = new Frequence<String>();
		String[] tabTest = {"allo", "Test", "Tes", "Tes"};
		String res = freq.searchMostFrequent(tabTest);
		System.out.println(res);
	}
	
}