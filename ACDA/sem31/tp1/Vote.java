import java.sql.*;

public class Vote {
	// Constructeur
	public Vote(){
		try {
			Connection cnx = DriverManager.getConnection(
			"jdbc:mariadb://dwarves.iut-fbleau.fr/chollet",
				"chollet", "courgette09");
				try {
					// Requête à faire
					PreparedStatement pst = cnx.prepareStatement("Select * FROM ");
					// Faire la requête et vérifier le résultat

				}
				catch ( e) {

				}
		}
		catch(SQLException e) {
			System.err.println("Erreur d'accès à la BD, ou mauvaise URL.");
		}
		catch (SQLTimeoutException) {
			System.err.println("Temps dépassé (Time out).");
		}
	}

}
