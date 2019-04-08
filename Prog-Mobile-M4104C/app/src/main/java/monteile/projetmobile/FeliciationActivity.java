package monteile.projetmobile;

import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

import monteile.projetmobile.db.DatabaseClient;
import monteile.projetmobile.db.Users;

public class FeliciationActivity extends AppCompatActivity {
    public final static String SCORE_KEY = "score_key";
    public final static String ID_KEY = "id_key";
    public final static String DIFFICULTY_KEY = "diff_key";
    public final static String CHOIX_EXO_KEY = "exo key";

    private int diff = 0;
    private String matiere;

    private DatabaseClient mDb;

    private int score;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_feliciation);

        Log.d("Bonjour",getIntent().getStringExtra(ID_KEY));

        mDb = DatabaseClient.getInstance(getApplicationContext());
        score = Integer.valueOf(getIntent().getStringExtra(SCORE_KEY));


        TextView score = (TextView) findViewById(R.id.scoreFinal);
        score.setText("Votre score est de : " + getIntent().getStringExtra(SCORE_KEY));

        if (getIntent().getStringExtra(DIFFICULTY_KEY).equals("Niveau Facile"))
            diff = 1;
        else if (getIntent().getStringExtra(DIFFICULTY_KEY).equals("Niveau Moyen"))
            diff = 2;
        else
            diff = 3;


        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            getUser();
        }



    }

    public void sauverScore(Users user) {
        switch (diff) {
            case 1:
                if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("addition") && score > user.getScoreAddition1())
                    user.setScoreAddition1(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("soustraction") && score > user.getScoreSoustration1())
                    user.setScoreSoustration1(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("multiplication") && score > user.getScoreMutiplication1())
                    user.setScoreMutiplication1(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("capitales") && score > user.getScoreCapitale1())
                    user.setScoreCapitale1(score);
                break;
            case 2:
                if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("addition") && score > user.getScoreAddition2())
                    user.setScoreAddition2(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("soustraction") && score > user.getScoreSoustration2())
                    user.setScoreSoustration2(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("traduction") && score > user.getScoreTraduction1())
                    user.setScoreTraduction1(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("multiplication") && score > user.getScoreMutiplication2())
                    user.setScoreMutiplication2(score);
                break;
            case 3:
                if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("addition") && score > user.getScoreAddition3())
                    user.setScoreAddition3(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("soustraction") && score > user.getScoreSoustration3())
                    user.setScoreSoustration3(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("multiplication") && score > user.getScoreMutiplication3())
                    user.setScoreMutiplication3(score);
                else if (getIntent().getStringExtra(CHOIX_EXO_KEY).toLowerCase().equals("capitales") && score > user.getScoreCapitale3())
                    user.setScoreCapitale3(score);

                break;

        }

        class UpdateUser extends AsyncTask<Users, Void, Void> {
            @Override
            protected Void doInBackground(Users... users) {

                // adding to database
                mDb.getAppDatabase()
                        .usersDAO()
                        .update(users[0]);

                return null;
            }
        }

        UpdateUser st = new UpdateUser();
        st.execute(user);
    }

    public void goToMain(View view) {

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
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
                Users monUser = new Users();
                for (int i=0; i<users.size();i++){
                    if (users.get(i).getId() == id) {
                        monUser = users.get(i);
                        break;
                    }
                }



                sauverScore(monUser);

            }

        }

        //////////////////////////
        // IMPORTANT bien penser à executer la demande asynchrone
        // Création d'un objet de type GetTasks et execution de la demande asynchrone
        GetUsers gt = new GetUsers();
        gt.execute();
    }



    public void goToMatieres (View view) {

        Intent intent = new Intent(this, MenuMatieresActivity.class);
        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
            intent.putExtra(MenuMatieresActivity.ID_KEY, ""+id);
        } else
            intent.putExtra(MenuMatieresActivity.ID_KEY, "");
        startActivity(intent);
    }
}
