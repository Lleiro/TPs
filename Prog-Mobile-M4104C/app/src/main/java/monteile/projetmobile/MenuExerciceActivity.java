package monteile.projetmobile;

import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.List;

import monteile.projetmobile.db.DatabaseClient;
import monteile.projetmobile.db.Users;

public class MenuExerciceActivity extends AppCompatActivity {
     public static final String MATIERE_NAME_KEY = "matiere_key";
     public static final String ID_KEY="id key";
     public String diffExplicit ="";

     public String exo = "";
     private DatabaseClient mDb;

     private Users monUser;
     private int diffInt = 0;

     private TextView meilleurScore;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu_exercice);

        mDb = DatabaseClient.getInstance(getApplicationContext());


        TextView title = (TextView) findViewById(R.id.title);
        title.setText(getIntent().getStringExtra(MATIERE_NAME_KEY));

        TextView diff1 = (TextView) findViewById(R.id.difficulte1);
        TextView diff2 = (TextView) findViewById(R.id.difficulte2);
        TextView diff3 = (TextView) findViewById(R.id.difficulte3);

        TextView exo1 = (TextView) findViewById(R.id.exercice1);
        TextView exo2 = (TextView) findViewById(R.id.exercice2);
        TextView exo3 = (TextView) findViewById(R.id.exercice3);

        meilleurScore = (TextView) findViewById(R.id.meilleurScore);



        if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Géographie")) {
            diff1.setText("1");
            diff1.setBackgroundResource(R.drawable.border_red);
            diff2.setBackgroundResource(R.drawable.border_transparent);
            diff2.setText("");
            diff3.setText("2");

            exo1.setText("");
            exo3.setText("");
        } else if (!getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Mathématiques")) {
            diff1.setText("");
            diff2.setText("1");
            diff3.setText("");

            exo1.setText("");
            exo3.setText("");
        }


        diffExplicit = "Niveau Moyen";
        diffInt = 2;


        if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Géographie")) {
            exo2.setText("Capitales");
            diffExplicit = "Niveau Facile";
            diffInt = 1;
        } else if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Anglais")) {
            exo2.setText("Traduction");
        } else if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Histoire")){
            exo2.setText("Dates Clefs");
        }

        exo = exo2.getText().toString();

        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            getUser();
        } else
            meilleurScore.setText("");
    }

    public void retourMenuMatiere (View view) {
        Intent intent = new Intent(this, MenuMatieresActivity.class);
        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
            intent.putExtra(MenuMatieresActivity.ID_KEY, ""+id);
        } else
            intent.putExtra(MenuMatieresActivity.ID_KEY, "");
        startActivity(intent);
    }

    public void choixDiffMath (View view) {
        TextView diff1 = (TextView) findViewById(R.id.difficulte1);
        TextView diff2 = (TextView) findViewById(R.id.difficulte2);
        TextView diff3 = (TextView) findViewById(R.id.difficulte3);

        TextView exo1 = (TextView) findViewById(R.id.exercice1);
        TextView exo2 = (TextView) findViewById(R.id.exercice2);
        TextView exo3 = (TextView) findViewById(R.id.exercice3);

        int choix = 1;

        choix = view.getId();

        switch (choix) {
            case R.id.difficulte1:
                diff1.setBackgroundResource(R.drawable.border_red);
                diff2.setBackgroundResource(R.drawable.border_transparent);
                diff3.setBackgroundResource(R.drawable.border_transparent);
                diffExplicit = "Niveau Facile";
                diffInt = 1;
                break;
            case R.id.difficulte2:
                diff1.setBackgroundResource(R.drawable.border_transparent);
                diff2.setBackgroundResource(R.drawable.border_red);
                diff3.setBackgroundResource(R.drawable.border_transparent);
                diffExplicit = "Niveau Moyen";
                diffInt = 2;
                break;
            case R.id.difficulte3:
                diff1.setBackgroundResource(R.drawable.border_transparent);
                diff2.setBackgroundResource(R.drawable.border_transparent);
                diff3.setBackgroundResource(R.drawable.border_red);
                diffExplicit = "Niveau Difficile";
                diffInt = 3;
                break;
            case R.id.exercice1:
                exo1.setBackgroundResource(R.drawable.border_red);
                exo2.setBackgroundResource(R.drawable.border_transparent);
                exo3.setBackgroundResource(R.drawable.border_transparent);
                exo = exo1.getText().toString();
                break;
            case R.id.exercice2:
                exo1.setBackgroundResource(R.drawable.border_transparent);
                exo2.setBackgroundResource(R.drawable.border_red);
                exo3.setBackgroundResource(R.drawable.border_transparent);
                exo = exo2.getText().toString();
                break;
            case R.id.exercice3:
                exo1.setBackgroundResource(R.drawable.border_transparent);
                exo2.setBackgroundResource(R.drawable.border_transparent);
                exo3.setBackgroundResource(R.drawable.border_red);
                exo = exo3.getText().toString();
                break;
        }


        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            miseAJourMeilleurScore();
        }
    }

    public void getUser() {
        ///////////////////////
        // Classe asynchrone permettant de récupérer des taches et de mettre à jour le listView de l'activité
        class GetUsers extends AsyncTask<Void, Void, List<Users>> {

            @Override
            protected List<Users> doInBackground(Void... voids) {
                List<Users> usersList = mDb.getAppDatabase()
                        .usersDAO()
                        .getAll();
                return usersList;
            }

            @Override
            protected void onPostExecute(List<Users> users) {
                super.onPostExecute(users);
                int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
                monUser = new Users();
                for (int i=0; i<users.size();i++){
                    if (users.get(i).getId() == id) {
                        monUser = users.get(i);
                        break;
                    }
                }


                miseAJourMeilleurScore();
            }

        }

        //////////////////////////
        // IMPORTANT bien penser à executer la demande asynchrone
        // Création d'un objet de type GetTasks et execution de la demande asynchrone
        GetUsers gt = new GetUsers();
        gt.execute();
    }

    public void miseAJourMeilleurScore() {
        int score = 0;

        switch (diffInt) {
            case 1:
                if (exo.toLowerCase().equals("addition"))
                    score = monUser.getScoreAddition1();
                else if (exo.toLowerCase().equals("soustraction"))
                    score = monUser.getScoreSoustration1();
                else if (exo.toLowerCase().equals("multiplication"))
                    score = monUser.getScoreMutiplication1();
                else if (exo.toLowerCase().equals("capitales"))
                    score = monUser.getScoreCapitale1();
                break;
            case 2:
                if (exo.toLowerCase().equals("addition"))
                    score = monUser.getScoreAddition2();
                else if (exo.toLowerCase().equals("soustraction"))
                    score = monUser.getScoreSoustration2();
                else if (exo.toLowerCase().equals("multiplication"))
                    score = monUser.getScoreMutiplication2();
                else if (exo.toLowerCase().equals("traduction"))
                    score = monUser.getScoreTraduction1();
                break;
            case 3:
                if (exo.toLowerCase().equals("addition"))
                    score = monUser.getScoreAddition3();
                else if (exo.toLowerCase().equals("soustraction"))
                    score = monUser.getScoreSoustration3();
                else if (exo.toLowerCase().equals("multiplication"))
                    score = monUser.getScoreMutiplication3();
                else if (exo.toLowerCase().equals("capitales"))
                    score = monUser.getScoreCapitale3();
                break;
        }
        meilleurScore.setText("Meilleur score : " + score);
    }

    public void choixDiffGeo(View view) {
        TextView diff1 = (TextView) findViewById(R.id.difficulte1);
        TextView diff3 = (TextView) findViewById(R.id.difficulte3);
        int choix = 1;

        choix = view.getId();

        switch (choix) {
            case R.id.difficulte1:
                diff1.setBackgroundResource(R.drawable.border_red);
                diff3.setBackgroundResource(R.drawable.border_transparent);
                diffExplicit = "Niveau Facile";
                diffInt = 1;
                break;
            case R.id.difficulte3:
                diff1.setBackgroundResource(R.drawable.border_transparent);
                diff3.setBackgroundResource(R.drawable.border_red);
                diffExplicit = "Niveau Difficile";
                diffInt = 3;
        }

        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            miseAJourMeilleurScore();
        }
    }

    public void gestionDifficulteExercice (View view) {
        if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Mathématiques"))
            choixDiffMath(view);
        else if (getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Géographie"))
            choixDiffGeo(view);
    }

    public void goToExercice(View view) {
        Intent intent;
        if (!getIntent().getStringExtra(MATIERE_NAME_KEY).equals("Géographie"))
           intent = new Intent(this, ExerciceActivity.class);
        else
            intent = new Intent(this, ExerciceActivityQCM.class);

        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
            intent.putExtra(ExerciceActivity.ID_KEY, ""+id);
        } else
            intent.putExtra(ExerciceActivity.ID_KEY, "");

        intent.putExtra(ExerciceActivity.SCORE_KEY, "0");
        intent.putExtra(ExerciceActivity.DIFFICULTE_EXO_KEY, diffExplicit);
        intent.putExtra(ExerciceActivity.CHOIX_EXO_KEY, exo);
        intent.putExtra(ExerciceActivity.MATIERE_NAME_KEY, getIntent().getStringExtra(MATIERE_NAME_KEY));
        startActivity(intent);
    }
}
