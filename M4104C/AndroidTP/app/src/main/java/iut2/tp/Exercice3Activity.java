package iut2.tp;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.RadioGroup;
import android.widget.TextView;

import iut2.tp.exercice4Data.Jeu;
import iut2.tp.exercice4Data.Resultat;

public class Exercice3Activity extends AppCompatActivity {
    private Resultat resultat = new Resultat();

    private int nbVic =0;
    private int nbDef = 0;
    private int nbEga =0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // On charge le XML pour créer l'arbre graphique
        setContentView(R.layout.activity_exercice3);
    }

    public void exercice3Jeu(View v) {
        ImageView pierre = (ImageView) findViewById(R.id.pierre);
        ImageView feuille = (ImageView) findViewById(R.id.feuille);
        ImageView ciseaux = (ImageView) findViewById(R.id.ciseaux);
        ImageView coupOrdi = (ImageView) findViewById(R.id.mainOrdi);
        TextView victoire = (TextView) findViewById(R.id.victoire);
        TextView defaite = (TextView) findViewById(R.id.defaite);
        TextView egalite = (TextView) findViewById(R.id.egalite);
        TextView res = (TextView) findViewById(R.id.resultat);
        int choix = 0;



        do {
            Jeu jeu = new Jeu();

            choix = v.getId();
            switch (choix) {
                case R.id.pierre:
                    pierre.setBackgroundColor(Color.RED);
                    ciseaux.setBackgroundColor(Color.BLACK);
                    feuille.setBackgroundColor(Color.BLACK);
                    jeu.setMainJoueur(Jeu.CAILLOUX);
                    break;
                case R.id.feuille:
                    feuille.setBackgroundColor(Color.RED);
                    pierre.setBackgroundColor(Color.BLACK);
                    ciseaux.setBackgroundColor(Color.BLACK);
                    jeu.setMainJoueur(Jeu.PAPIER);
                    break;
                case R.id.ciseaux:
                    ciseaux.setBackgroundColor(Color.RED);
                    pierre.setBackgroundColor(Color.BLACK);
                    feuille.setBackgroundColor(Color.BLACK);
                    jeu.setMainJoueur(Jeu.CISEAUX);
                    break;
            }

            //int mainOrdi = jeu.getMainOrdinateur();
            if (jeu.getMainOrdinateur() == Jeu.CAILLOUX) {
                System.out.println("Cailloux");
                coupOrdi.setImageResource(R.drawable.caillou);

            } else if (jeu.getMainOrdinateur() == Jeu.PAPIER) {
                System.out.println("Papier");
                coupOrdi.setImageResource(R.drawable.papier);

            } else if (jeu.getMainOrdinateur() == Jeu.CISEAUX) {
                System.out.println("Ciseaux");
                coupOrdi.setImageResource(R.drawable.ciseaux);

            }

            //System.out.println("MAIN ORDI   " + mainOrdi);
            System.out.println("MAIN JOUEUR : " + jeu.getMainJoueur());

            if (jeu.joueurGagne()) {
                nbVic++;
                res.setText("VICTOIRE !");
                victoire.setText("nombre de victoires : " + nbVic);

            } else if (jeu.egalite()) {
                resultat.addEgalite();
                nbEga++;
                res.setText("ÉGALITÉ !");
                egalite.setText("nombre de nuls : " + nbEga);
            } else {
                resultat.addDefaite();
                res.setText("DÉFAITE !");
                nbDef++;
                defaite.setText("nombre de défaites : " + nbDef);
            }
        } while(v.getId() != choix);


    }
}
