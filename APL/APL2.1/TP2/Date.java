/**
* @version 2.0
* @author Tomy Da Rocha
*/

public class Date {
	// Attributs
	private short month = 1; // mois
	private short day = 1; // jour(s)
	private short year = 0; // année(s)

	/* Affiche le prochain jour */
	public Date lendemain() {
		/* On réassigne les valeurs utilisées dans la classe en paramètre
		 * une à une dans une nouvelle classe Lendemain. */
		Date lendemain = new Date();
		lendemain.year = this.year;
		lendemain.month = this.month;
		lendemain.day = this.day;


		// Si xxxx/12/31 -> Nouvelle année
		if (lendemain.month == 12 && lendemain.day == 31) {
			// Reviens au 1 jan. de l'année suivante
			lendemain.month = 1;
			lendemain.day = 1;
			lendemain.year += 1;
		}

		/* Si le mois est impaire entre janvier et juillet inclus, 
		 * ou si c'est août, fait donc 31 jours,
		 * de septembre à decembre, c'est inverse */
		else if (lendemain.month%2 == 1 && lendemain.month < 8 || lendemain.month == 8
			|| lendemain.month%2 == 0 && lendemain.month > 8) {
			if (lendemain.day == 31) {
				lendemain.day = 1;
				lendemain.month += 1;
			}
			else {
				lendemain.day += 1;
			}
		}

		/* Si le mois fini par jour : 30 */
		else {
			if (lendemain.day == 30) {
				lendemain.day = 1;
				lendemain.month += 1;
			}
			else {
				lendemain.day += 1;
			}	
		}

		// Si la date est invalide
		if (lendemain.testDate() == false) {
			System.err.println("Error : invalid date.");
			System.exit(1);
		}
		// On retourne la date correspondant au jour suivant
		return lendemain;
	}


	/* Méthode tester si la date est valide */
	public boolean testDate() {
		/* On teste si le mois est compris en janvier et dec. */
		if (this.month >= 0 & this.month <= 12) {
			/* Si le nombre de jour est invalide */
			if (this.day >= 0 && this.day <= 31) {
				/* Si le nb de jour d'un mois composé normalement de 30j est bon */
				if (((this.month%2 == 0 && this.month < 8) || (this.month%2 == 1 && this.month > 8))
					&& this.day < 31) {
					// Si toutes les conditions sont remplies
					return true;
				}
				/* Si le mois doit avoir 31j max */
				else if (this.month%2 == 1 && this.month < 8 || this.month == 8
				|| this.month%2 == 0 && this.month > 8) {
					// Si toutes les conditions sont remplies
					return true;
				}
			}
		}
		
		return false;
	}

	// Méthode pour comparer 2 dates
	public int compareDate(Date date1) {
		// Si date1 est plus récent
		/*
		 * C'est soit que l'année de date1 plus grande 
		 * Soit que ce sont la même année éventuellement le même mois, mais que date1
		 * soit plus loin dans l'année que this 
		 * */
		if ((date1.year > this.year) || ((date1.day > this.day) 
			&& (date1.year == this.year) && (date1.month >= this.month))) {
			return 1;
		}

		// Si les dates sont identiques
		else if (date1.year == this.year && date1.month == this.month 
			&& date1.day == this.day){
			return 0;
		}

		// Retourne 1 si date1 est plus ancienne que this
		return -1;
	}

	// Méthode pour savoir le nb de jours entre 2 dates données
	public short interDate(Date date1) {
		short count = 0; // Intervalle de jours entre 2 dates, valeur de retour
		// Premièrement on teste quelle date la plus ancienne
		int compare = this.compareDate(date1); // Compare les deux dates
		// Date temporaire pour ne pas changer la date la plus ancienne
		Date temp = new Date();
		// Date temporaire pour ne pas changer la plus récente, celle d'arrivée
		Date arrivee = new Date(); 


		// Si date2 est plus vieille que date1
		if (compare == -1) {
			temp.day = date1.day;
			temp.month = date1.month;
			temp.year = date1.year;

			arrivee.day = this.day;
			arrivee.month = this.month;
			arrivee.year = this.year;
		}

		// Si date1 est plus vieille que date2
		else if (compare == 1) {
			temp.day = this.day;
			temp.month = this.month;
			temp.year = this.year;

			arrivee.day = date1.day;
			arrivee.month = date1.month;
			arrivee.year = date1.year;
		}

		while (temp.year != arrivee.year && temp.month != arrivee.month 
			&& temp.day != arrivee.day) {
				temp = temp.lendemain(); // On passe au jour suivant
				++count; // Incrémente le compteur de jour (différence)
		}
		if (count > 1) {
			System.out.println("Il y a "+ count + "jours d'intervalles");
		}
		else {
			System.out.println("Il y a "+ count + "jour d'intervalle");
		}
		return count;
	}

  /**
  * @param args utilisée
  */
  	public static void main(String[] args) {
		Date date = new Date();
		Date lendemain;
		date.day = 31;
		date.year = 2010;
		date.month = 12;

		// Teste de la date
		if (date.testDate() == false) {
			System.err.println("Error : invalid date.");
			System.exit(1);
		}
		// Affiche la date d'entrée
		System.out.println(date.year+"/"+date.month+"/"+date.day);
		
		// On récupère dans lendemain le pointeur avec les attributs
		lendemain = date.lendemain();
		// Affiche le lendemain
		System.out.println(lendemain.year+"/"+lendemain.month+"/"+lendemain.day);		
  	}
}