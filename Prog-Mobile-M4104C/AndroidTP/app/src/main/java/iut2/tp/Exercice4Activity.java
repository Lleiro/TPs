package iut2.tp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.TextView;

public class Exercice4Activity extends AppCompatActivity {



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // On charge le XML pour créer l'arbre graphique
        setContentView(R.layout.activity_exercice4);

    }

    public void exercice4Valider (View view) {
        TextView prenomTemp = (TextView) findViewById(R.id.prenom);
        String prenom = prenomTemp.getText().toString();

        Intent intent = new Intent(this, HelloActivity.class);
        intent.putExtra(HelloActivity.PRENOM_KEY, prenom);
        startActivity(intent);
    }
}
