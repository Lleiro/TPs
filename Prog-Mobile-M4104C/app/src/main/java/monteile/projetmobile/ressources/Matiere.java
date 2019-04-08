package monteile.projetmobile.ressources;

public class Matiere {
    private String nomMatiere;
    private int refImg;

    public Matiere(String nomMat, int refImg) {
        nomMatiere = nomMat;
        this.refImg = refImg;
    }

    public String getNomMatiere() {
        return nomMatiere;
    }

    public void setNomMatiere(String nomMatiere) {
        this.nomMatiere = nomMatiere;
    }

    public int getRefImg() {
        return refImg;
    }

    public void setRefImg(int refImg) {
        this.refImg = refImg;
    }



}
