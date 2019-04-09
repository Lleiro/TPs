package monteile.projetmobile;

import android.content.Intent;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.concurrent.TimeUnit;

import monteile.projetmobile.ressources.Geographie;

public class ExerciceActivityQCM extends AppCompatActivity {
    public static final String SCORE_KEY = "Score";
    public static final String DIFFICULTE_EXO_KEY = "difficulty_key";
    public static final String CHOIX_EXO_KEY = "exo_key";
    public static final String MATIERE_NAME_KEY = "matiere_key";
    public static final String ID_KEY = "id_key";



    private final int TOTAL_QUESTION = 15;
    private int questionCourante = 0;
    private int score = 0;
    private int scoreMax = -1;

    private Geographie geographie;

    private int difficulteInt;

    private Button rep1;
    private Button rep2;
    private Button rep3;
    private Button rep4;
    private TextView tvScore;

    private Button btnSuiv;



    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_exercice_qcm);

        if (getIntent().getStringExtra(DIFFICULTE_EXO_KEY).equals("Niveau Facile"))
            difficulteInt = 1;
        else if (getIntent().getStringExtra(DIFFICULTE_EXO_KEY).equals("Niveau Moyen"))
            difficulteInt = 2;
        else
            difficulteInt = 3;

        btnSuiv = (Button) findViewById(R.id.btnSuivant);
        btnSuiv.setVisibility(View.INVISIBLE);



        //Mise en place des différentes réponses;
        rep1 = (Button) findViewById(R.id.btnReponse1QCM);
        rep2 = (Button) findViewById(R.id.btnReponse2QCM);
        rep3 = (Button) findViewById(R.id.btnReponse3QCM);
        rep4 = (Button) findViewById(R.id.btnReponse4QCM);
        rep1.setBackgroundColor(Color.LTGRAY);


        tvScore = (TextView) findViewById(R.id.tvScore);
        tvScore.setText("Score : "  + score + " sur " + scoreMax);


        TextView diff = (TextView) findViewById(R.id.tvDifficulteQCM);
        diff.setText(getIntent().getStringExtra(DIFFICULTE_EXO_KEY));

        TextView titleExo = (TextView) findViewById(R.id.tvNomExoQCM);
        titleExo.setText(getIntent().getStringExtra(CHOIX_EXO_KEY));

        if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Géographie")) {
            geographie();
        }
    }

    public void geographie() {
        geographie = new Geographie(difficulteInt);
        goToNextExerciceGeo();

        rep1.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                if (geographie.getCurrentReponse().equals(rep1.getText()))
                    score++;
                else
                    rep1.setBackgroundColor(Color.RED);
                pauseAvantSuite(view);
            }
        });

        rep2.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                if (geographie.getCurrentReponse().equals(rep2.getText()))
                    score++;
                else
                    rep2.setBackgroundColor(Color.RED);
                pauseAvantSuite(view);
            }
        });

        rep3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                if (geographie.getCurrentReponse().equals(rep3.getText()))
                    score++;
                else
                    rep3.setBackgroundColor(Color.RED);
                pauseAvantSuite(view);
            }
        });

        rep4.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                if (geographie.getCurrentReponse().equals(rep4.getText()))
                    score++;
                else
                    rep4.setBackgroundColor(Color.RED);
                pauseAvantSuite(view);
            }
        });
    }

    public void pauseAvantSuite(View view) {
        rep1.setEnabled(false);
        rep2.setEnabled(false);
        rep3.setEnabled(false);
        rep4.setEnabled(false);

        if (geographie.getCurrentReponse().equals(rep1.getText())) {
            rep1.setBackgroundColor(Color.GREEN);
        } else if (geographie.getCurrentReponse().equals(rep2.getText())) {
            rep2.setBackgroundColor(Color.GREEN);
        } else if (geographie.getCurrentReponse().equals(rep3.getText())) {
            rep3.setBackgroundColor(Color.GREEN);
        } else if (geographie.getCurrentReponse().equals(rep4.getText())) {
            rep4.setBackgroundColor(Color.GREEN);
        }

        btnSuiv.setVisibility(View.VISIBLE);

        btnSuiv.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                rep1.setBackgroundColor(Color.LTGRAY);
                rep2.setBackgroundColor(Color.LTGRAY);
                rep3.setBackgroundColor(Color.LTGRAY);
                rep4.setBackgroundColor(Color.LTGRAY);

                rep1.setEnabled(true);
                rep2.setEnabled(true);
                rep3.setEnabled(true);
                rep4.setEnabled(true);

                btnSuiv.setVisibility(View.INVISIBLE);
                //permet de ne pas pouvoir répondre après le nombre de question total
                if (scoreMax != TOTAL_QUESTION)
                    goToNextExerciceGeo();
            }
        });

    }

    public void retourMenuMatiere(View view) {
        Intent intent = new Intent(ExerciceActivityQCM.this, MenuMatieresActivity.class);
        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
            intent.putExtra(MenuMatieresActivity.ID_KEY, ""+id);
        } else
            intent.putExtra(MenuMatieresActivity.ID_KEY, "");

        startActivity(intent);

    }

    public void goToNextExerciceGeo(){
        if (questionCourante == TOTAL_QUESTION) {
            Intent intent = new Intent(ExerciceActivityQCM.this, FeliciationActivity.class);
            if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
                int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
                intent.putExtra(FeliciationActivity.ID_KEY, ""+id);
            } else
                intent.putExtra(FeliciationActivity.ID_KEY, "");

            intent.putExtra(FeliciationActivity.CHOIX_EXO_KEY, getIntent().getStringExtra(CHOIX_EXO_KEY));
            intent.putExtra(FeliciationActivity.DIFFICULTY_KEY, getIntent().getStringExtra(DIFFICULTE_EXO_KEY));
            intent.putExtra(FeliciationActivity.SCORE_KEY, "" + score);
            startActivity(intent);
        }

        try {
            Thread.sleep(50);
        } catch (InterruptedException ex) {}

        TextView question = (TextView) findViewById(R.id.tvQuestionQCM);

        questionCourante++;
        scoreMax++;
        tvScore.setText("Score : "  + score + " sur " + scoreMax);
        geographie.setQuestionReponse();

        //Création question/Réponse
        String quest = geographie.getCurrentQuestion();
        String reponseVrai = geographie.getCurrentReponse();

        //Créer un arrayList avec 3 réponses fausse et une réponse vraie
        ArrayList<String> reponsesVraiesEtFausses = geographie.getReponsesVraiesFausses();
        Collections.shuffle(reponsesVraiesEtFausses);

        rep1.setText(reponsesVraiesEtFausses.get(0));
        rep2.setText(reponsesVraiesEtFausses.get(1));
        rep3.setText(reponsesVraiesEtFausses.get(2));
        rep4.setText(reponsesVraiesEtFausses.get(3));

        //Set de la question courrante
        question.setText(quest);
    }
}
