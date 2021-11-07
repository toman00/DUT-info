import javax.swing.*;
import java.awt.*;

public class VolumeRefresh {
	protected int volumeTot;
	private Volume volume[];
    private JPanel panel;
	private VolumeRefresh volumeRefresh;
    private int count; // Volume à afficher (restant)
	private int i;
	private JFrame window;

	// Constructeur
	public VolumeRefresh(JPanel panel) {	
		this.panel = panel;
		
		this.volume = new Volume[10];
		this.count = this.volumeTot;

		for (i = 0; i < volume.length; ++i) {
			this.volume[i] = new Volume(this);
			panel.add(volume[i]);
		}
	}

	public void setVolume(int volume) {
		// Si le volume est compris entre 0 et 10
		if ((volumeTot == 0 && volume > 0) || (volumeTot == 10 && volume < 0)
			|| (volumeTot > 0 && volumeTot < 10)) {
			this.volumeTot += volume;
		}
		this.count = this.volumeTot;

		if (volume > 0) {
			for (i = 0; i < this.volumeTot; ++i) {
				this.volume[i].repaint();
			}
		}
		else {
			for (i = 0; i < this.volume.length; ++i) {
				this.volume[i].repaint();
			}
		}
		
		System.out.println(this.count);
	}

	public int getVolume() {
		return this.volumeTot;
	}

	public void setCount(int newCount) {
		if (this.count > 0) {
			this.count += newCount;
		}
	}

	public int getCount() {
		return this.count;
	}

	
	

} 