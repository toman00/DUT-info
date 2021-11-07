public class Association<E> {
	private E element;
	private int frequence;

	// Constructeur
	public Association(){
		this.frequence = 0;		
	}

	public void setElement(E newElement) {
		this.element = newElement;
	}


	public E getElement() {
		return this.element;
	}

	public void setFrequence(int freq) {
		this.frequence = freq;
	}

	public int getFrequence() {
		return this.frequence;
	}
	
}
