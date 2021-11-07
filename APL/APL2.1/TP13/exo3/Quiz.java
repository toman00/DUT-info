// Dépendances
import java.io.*;
import java.util.*;

public class Quiz {
    // Nombre de question(s)    
    private int nbQuestions;

    // Constructeur
    public Quiz() {
        try {
            // Ouverture du flux du fichier (lecture)
            FileReader flux = new FileReader("java.quiz");
            BufferedReader reader = new BufferedReader(flux);
            
            BufferedReader terminal = new BufferedReader(new InputStreamReader(System.in));
            try {
                // Buffer de lecture
                String buffer = "";
                // Réponses de l'utilisateur
                ArrayList<String> answerList = new ArrayList<String>();
                // Dernière réponse de l'utilisateur (à désinfecter)
                String answer = " ";
                // Si les réponses possibles sont en cours de parcours
                // Vrai si c'est le cas, faux si c'est le contraire
                Boolean asking = false;
                int nbAnswers = 0;

                // Tant qu'on a pas atteint la fin du fichier ou qu'il faut demander à l'utilisateur
                // de saisir sa dernière réponse
                while ((buffer = reader.readLine()) !=  null || asking == true) {
                    // Si on lit des propositions de réponse
                    if (buffer != null && buffer.startsWith("-")) {
                        asking = true;
                        // On incrémente le nb de réponse
                        nbAnswers += 1 ;
                        System.out.print(nbAnswers + " ");
                    }
                    // Si on ne lit plus de propositions de réponse
                    else if (asking == true) {
                        // Vide la réponse précédente (si elle existe)
                        answer = "";
                        // Demande à l'utilisateur la réponse (tant qu'il n'a rien enregistré)
                        while (answer.isEmpty()) {
                            answer = terminal.readLine();
                            // Vérification de la réponse
                            if (!this.isValidated(answer, 1, nbAnswers)) {
                                // On re-vide la chaîne de caractère afin de refaire un cycle
                                answer = "";
                                System.err.println("Réponse invalide, réponse entre 1 et " 
                                + nbAnswers + " .Réessayez ...");
                            }
                            else {
                                // Ajoute la réponse dans la liste
                                answerList.add(answer);
                            }
                        }

                        // On ne lit actuellement plus de propositions de réponse
                        asking = false;
                        // On incrémente le nb de question
                        this.nbQuestions += 1;
                        // Remet à 0 le nb de réponse
                        nbAnswers = 0;
                    }
                    if (buffer != null) {
                        // On affiche la question/reponse
                        System.out.println(buffer);
                    }
                }
                this.writeAnswer(answerList, "reponses.txt");
            }
            catch (IOException e) {
                System.err.println("Erreur !");
            }
            try {
                // Essaie de fermer le fichier
                reader.close();
            }
            catch (IOException e) {
                System.err.println("Impossible de fermer le fichier !");
            }
        }
        catch (IOException e) {
            System.err.println("Impossible d'ouvrir le flux.");
        }
    }

    // Méthode qui écrit dans le fichier réponse les chaînes stockées dans le tableau
    public void writeAnswer(ArrayList<String> answers, String filename) {
        try {
            // Ouverture du fichier en écriture
            FileWriter flux = new FileWriter(filename);
            BufferedWriter write = new BufferedWriter(flux);
            try {
                // Essaie d'écrire dans le fichier chacune des réponse
                for (int i = 0; i < answers.size(); i++) {
                    String buffer = answers.get(i) + "\n";
                    write.write(buffer);
                }
                try {
                    // Essaie de fermer le fichier
                    write.close();
                }
                catch (IOException e) {
                    System.err.println("Impossible de fermer le fichier" + filename + " !");
                }
            }
            catch (IOException e) {
                System.err.println("Impossible d'écrire dans le fichier" + filename + " !");
            }
        }
        catch (IOException e) {
            System.err.println("Impossible d'ouvrir le fichier" + filename + " !");
        }
    }

    // Vérifie si la chaîne de caractère en entrée correspond à un entier
    // et serait compris dans un intervalle donné
    public boolean isValidated(String answer, int lower, int higher) {
        boolean validated = false;
        boolean started = false;
        // Tant qu'on a pas commencé à tester, ou que les bornes inf
        // et sup ne sont pas identiques
        while ((lower <= higher) || (started == false)){
            // Algo démarré
            started = true;
            // On le compare, si c'est validé on peut arrêter
            if (answer.compareTo(Integer.toString(lower)) == 0) {
                validated = true;
                break;
            }
            lower += 1;
        }
        return validated;
    }
}
