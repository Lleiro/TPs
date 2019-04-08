package monteile.projetmobile;

import android.content.Intent;
import android.os.CountDownTimer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.InputType;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import monteile.projetmobile.ressources.Anglais;
import monteile.projetmobile.ressources.Geographie;
import monteile.projetmobile.ressources.Maths;

public class ExerciceActivity extends AppCompatActivity {
    public static final String SCORE_KEY = "Score";
    public static final String DIFFICULTE_EXO_KEY = "difficulty_key";
    public static final String CHOIX_EXO_KEY = "exo_key";
    public static final String MATIERE_NAME_KEY = "matiere_key";
    public static final String ID_KEY = "id_key";

    private CountDownTimer timer;
    private int score = 0;
    private EditText reponse;
    private TextView scoreView;
    private Maths math;
    private int difficulteInt;
    private Anglais anglais;
    private Geographie geographie;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_exercice);

        Log.d("Bonjour","TESTED " + getIntent().getStringExtra(ID_KEY));


        if (getIntent().getStringExtra(DIFFICULTE_EXO_KEY).equals("Niveau Facile"))
            difficulteInt = 1;
        else if (getIntent().getStringExtra(DIFFICULTE_EXO_KEY).equals("Niveau Moyen"))
            difficulteInt = 2;
        else
            difficulteInt = 3;

        scoreView = (TextView) findViewById(R.id.score);

        reponse = (EditText) findViewById(R.id.reponse);

        TextView diff = (TextView) findViewById(R.id.difficulte);
        diff.setText(getIntent().getStringExtra(DIFFICULTE_EXO_KEY));

        TextView titleExo = (TextView) findViewById(R.id.nomExo);
        titleExo.setText(getIntent().getStringExtra(CHOIX_EXO_KEY));


        // MISE EN PLACE DU CHRONOMETRE
        final TextView chronoTest = (TextView) findViewById(R.id.chrono);
        timer = new CountDownTimer(61000, 1000) {
            public void onTick(long millisUntilFinished) {
                chronoTest.setText("" + millisUntilFinished / 1000);
            }

            public void onFinish() {
                Intent intent = new Intent(ExerciceActivity.this, FeliciationActivity.class);
                intent.putExtra(FeliciationActivity.SCORE_KEY, "" + score);
                intent.putExtra(FeliciationActivity.DIFFICULTY_KEY, getIntent().getStringExtra(DIFFICULTE_EXO_KEY));

                if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
                    int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
                    intent.putExtra(FeliciationActivity.ID_KEY, ""+id);
                } else
                    intent.putExtra(FeliciationActivity.ID_KEY, "");

                intent.putExtra(FeliciationActivity.CHOIX_EXO_KEY, getIntent().getStringExtra(CHOIX_EXO_KEY));
                startActivity(intent);
            }
        };
        timer.start();



        //Lancement de chaque exercice
        if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Mathématiques")) {
            maths();
        } else if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Anglais")) {
            anglais();
        }  else {
            histoire();
        }

    }

    public void histoire() {
        timer.cancel();
        TextView question = (TextView) findViewById(R.id.question);
        Button btnPasser = (Button) findViewById(R.id.passer);
        scoreView.setText("");
        btnPasser.setVisibility(View.GONE);
        reponse.setVisibility(View.GONE);
        question.setText("A VENIR !");
        question.setTextSize(80);
    }

    public void maths() {
        //Définition de l'opérateur et de la difficulté en int;
        Maths.Operateur op = Maths.Operateur.valueOf(getIntent().getStringExtra(CHOIX_EXO_KEY).toUpperCase());


        reponse.setInputType(InputType.TYPE_CLASS_NUMBER);

        //définition de l'objet Maths
        math = new Maths(difficulteInt, op);
        goToNextExerciceMath();

        reponse.addTextChangedListener(new TextWatcher() {
            public void afterTextChanged(Editable s) {
                if ((s.toString() != null)){
                    try {

                        if (math.reponseMath(Integer.valueOf(s.toString()))) {
                            score++;
                            //Mise a jour de l'affichage du score
                            scoreView.setText("   -   Score : " + score);
                            goToNextExerciceMath();
                        }
                    } catch (NumberFormatException n){}
                }
            }
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            public void onTextChanged(CharSequence s, int start, int before, int count) {}
        });
    }

    public void goToNextExerciceMath() {
        //Mise a jour des questions
        TextView question = (TextView) findViewById(R.id.question);
        math.melangeValAlea();
        question.setText("" + math.getNbAlea1() + math.operatorToString() + math.getNbAlea2());

        //réinitialisation du champ de texte
        reponse.setText("");
    }

    public void nextExercice(View view) {
        if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Mathématiques"))
            goToNextExerciceMath();
        else if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Anglais"))
            goToNextExerciceAnglais();
    }


    protected void anglais() {
        anglais = new Anglais(difficulteInt);

        goToNextExerciceAnglais();

        reponse.addTextChangedListener(new TextWatcher() {
            public void afterTextChanged(Editable s) {
                if (s.toString() != null ){
                    if (anglais.reponseAnglais(s.toString())) {
                        score++;
                        scoreView.setText("   -   Score : " + score);
                        goToNextExerciceAnglais();
                    }
                }
            }
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            public void onTextChanged(CharSequence s, int start, int before, int count) {}
        });

    }

    protected void goToNextExerciceAnglais(){        //Mise a jour des questions
        TextView question = (TextView) findViewById(R.id.question);
        String quest = anglais.getQuestion();

        question.setText(quest);

        //réinitialisation du champ de texte
        reponse.setText("");
    }



    public void goToMenuMatiere(View view) {

        timer.cancel();
        Intent intent = new Intent(this, MenuMatieresActivity.class);

        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
            intent.putExtra(MenuMatieresActivity.ID_KEY, ""+id);
        } else
            intent.putExtra(MenuMatieresActivity.ID_KEY, "");

        startActivity(intent);
    }


}