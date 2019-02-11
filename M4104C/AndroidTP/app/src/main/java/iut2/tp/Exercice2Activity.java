package iut2.tp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.RadioGroup;
import android.widget.TextView;

public class Exercice2Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // On charge le XML pour créer l'arbre graphique
        setContentView(R.layout.activity_exercice2);
    }

    public void exercice2Valider (View v) {
        RadioGroup group = (RadioGroup) findViewById(R.id.radiogroupe);
        TextView reponseVraie = (TextView) findViewById(R.id.reponseVraie);
        TextView reponseFausse = (TextView) findViewById(R.id.reponseFausse);
        TextView reponseAvant = (TextView) findViewById(R.id.avantReponse);
        TextView reponse = (TextView) findViewById(R.id.reponse);

        if (group.getCheckedRadioButtonId()  ==  R.id.radioGroupeBonneReponse) {

        }
    }
}
