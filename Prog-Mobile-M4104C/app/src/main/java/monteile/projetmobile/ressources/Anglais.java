package monteile.projetmobile.ressources;

import java.util.ArrayList;
import java.util.Random;

public class Anglais {
    private ArrayList<String> questionEtReponse;
    private String currentReponse;
    private int difficulte;

    public Anglais(int difficulte) {
        questionEtReponse = new ArrayList<>();
        questionEtReponse.add("car voiture");
        questionEtReponse.add("chat cat");
        questionEtReponse.add("chien dog");
        questionEtReponse.add("maison house");
        questionEtReponse.add("ballon ball");
        questionEtReponse.add("chaise chair");
        questionEtReponse.add("cheveux hair");
        questionEtReponse.add("yeux eyes");
        questionEtReponse.add("nez nose");
        questionEtReponse.add("lapin rabbit");
        questionEtReponse.add("viande meat");
        questionEtReponse.add("ordinateur computer");
        questionEtReponse.add("écran screen");
        questionEtReponse.add("pomme apple");
        questionEtReponse.add("tomate tomato");
        questionEtReponse.add("souris mouse");
        questionEtReponse.add("rouge red");
        questionEtReponse.add("vert green");
        questionEtReponse.add("jaune yellow");
        questionEtReponse.add("chapeau hat");
        questionEtReponse.add("avoir have");
        questionEtReponse.add("être be");
        questionEtReponse.add("arbre tree");
        questionEtReponse.add("un one");
        questionEtReponse.add("cinq five");
        questionEtReponse.add("dix ten");
        questionEtReponse.add("vingt twenty");
        questionEtReponse.add("cinquante fifty");
        questionEtReponse.add("cent hundred");
        questionEtReponse.add("seize sixteen");
        questionEtReponse.add("équipe team");
        questionEtReponse.add("homme man");
        questionEtReponse.add("femme woman");
        questionEtReponse.add("fils son");
        questionEtReponse.add("fille daughter");
        questionEtReponse.add("frère brother");
        questionEtReponse.add("soeur sister");
        questionEtReponse.add("papa dad");
        questionEtReponse.add("maman mom");
        questionEtReponse.add("fille girl");
        questionEtReponse.add("garçon boy");
        questionEtReponse.add("rose pink");
        questionEtReponse.add("violet purple");
        questionEtReponse.add("blanc white");
        questionEtReponse.add("noir black");
        questionEtReponse.add("clavier keyboard");
        questionEtReponse.add("oreille hear");
        questionEtReponse.add("dessin drawing");
        questionEtReponse.add("lettre letter");
        questionEtReponse.add("pays country");
        questionEtReponse.add("ville town");
        questionEtReponse.add("vache cow");
        questionEtReponse.add("cochon pig");
        questionEtReponse.add("poulet chicken");
        questionEtReponse.add("cheval horse");
        questionEtReponse.add("grenouille frog");
        questionEtReponse.add("assiette plate");
        questionEtReponse.add("couteau knife");
        questionEtReponse.add("fourchette fork");
        questionEtReponse.add("cuillère spoon");
        questionEtReponse.add("herbe grass");
        questionEtReponse.add("fleur flower");
        questionEtReponse.add("araigné spider");
        questionEtReponse.add("chaton kitten");

    }

    public ArrayList<String> getQuestionEtReponse() {
        return questionEtReponse;
    }

    public boolean reponseAnglais(String rep) {
        return currentReponse.equals(rep.toLowerCase());
    }

    public String getQuestion(){
        Random r = new Random();
        int i = 0 + r.nextInt(questionEtReponse.size() - 0);

        String[] splitQuest = questionEtReponse.get(i).split(" ");
        currentReponse = splitQuest[1].toLowerCase();
        return splitQuest[0];
    }
}
