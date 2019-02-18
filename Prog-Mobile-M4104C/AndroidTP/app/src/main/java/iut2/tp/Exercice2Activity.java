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
        TextView reponse = (TextView) findViewById(R.id.reponse);

        if (group.getCheckedRadioButtonId()  ==  R.id.radioGroupeBonneReponse) {
            reponse.setText("Excellent bonne réponse !");
        } else if (group.getCheckedRadioButtonId() != R.id.radioGroupeBonneReponse) {
            reponse.setText("Mauvaise réponse !");
        }
    }
}
