package monteile.projetmobile.ressources;

import java.util.Random;

public class Maths {
    private int difficulte;
    private int nbAlea1 = 0;
    private int nbAlea2 = 0;
    private Operateur choixOperateur;
    public enum Operateur {
        MULTIPLICATION,
        ADDITION,
        SOUSTRACTION;
    }

    public Maths(int difficulte, Operateur op) {
        this.difficulte = difficulte;
        this.choixOperateur = op;

        do {
            nbAlea1 = this.varAlea();
            nbAlea2 = this.varAlea();
        } while (nbAlea1 < nbAlea2);
    }



    public boolean reponseMath(int reponse){
        switch (choixOperateur) {
            case MULTIPLICATION:
                return (reponse==nbAlea1*nbAlea2) ? true : false;
            case ADDITION:
                return (reponse==nbAlea1+nbAlea2) ? true : false;
            case SOUSTRACTION:
                return (reponse==nbAlea1-nbAlea2) ? true : false;
            default:
                return false;
        }
    }

    public void melangeValAlea() {
        do {
            nbAlea1 = this.varAlea();
            nbAlea2 = this.varAlea();
        } while (nbAlea1 < nbAlea2);
    }

    public void setNbAlea1(int nbAlea1) {
        this.nbAlea1 = nbAlea1;
    }

    public void setNbAlea2(int nbAlea2) {
        this.nbAlea2 = nbAlea2;
    }

    public int getNbAlea1(){
        return nbAlea1;
    }

    public int getNbAlea2() {
        return nbAlea2;
    }

    public int getDifficulte() {
        return this.difficulte;
    }

    public Operateur getChoixOperateur(){
        return this.choixOperateur;
    }

    public String operatorToString() {
        switch (choixOperateur) {
            case MULTIPLICATION:
                return " x ";
            case ADDITION:
                return " + ";
            case SOUSTRACTION:
                return " - ";
            default:
                return " ERROR ";
        }
    }


    //retourne un nobmre aléatoire entre valMin et ValMax exclu pour difficulté donné
    public int varAlea() {
        Random r = new Random();
        int valMin;
        int valMax;

        if (this.difficulte == 1) {
            valMin = 1;
            valMax = 10;
        } else if (this.difficulte == 2) {
            valMin = 5;
            valMax = 25;
        } else {
            valMin = 10;
            valMax = 50;
        }

        return valMin + r.nextInt(valMax- valMin);
    }


}
