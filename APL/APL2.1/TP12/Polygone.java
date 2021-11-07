import java.io.*;

public class Polygone {
	// Attributs
	private FileInputStream file;
	private DataInputStream flux;
	private int[] coord;

	// Constructeur
	public Polygone() {
		try {
			this.file = new FileInputStream("polygone.bin");
			this.flux = new DataInputStream(file);
			try {
				this.coord = new Integer[flux.available()]
				while (flux.available() >= 4) {
					this.coord = flux.readInt();
				}
			}
			catch() {

			}
		}
		catch(FileNotFoundException e) {
			System.err.println("Fichier introuvable");
		}
	}
}