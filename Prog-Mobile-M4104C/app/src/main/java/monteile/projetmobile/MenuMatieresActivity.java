package monteile.projetmobile;



import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.List;

import monteile.projetmobile.db.DatabaseClient;
import monteile.projetmobile.db.Users;
import monteile.projetmobile.ressources.*;

public class MenuMatieresActivity extends AppCompatActivity {
    private RecyclerAdaptaterMatieres mesMat = new RecyclerAdaptaterMatieres(this);
    public static final String ID_KEY = "id_key";
    private TextView tvBienvenue;
    private DatabaseClient mDb;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu_matieres);

        mDb = DatabaseClient.getInstance(getApplicationContext());


        final RecyclerView rv = (RecyclerView) findViewById(R.id.matieres);
        rv.setLayoutManager(new LinearLayoutManager(this));
        rv.setAdapter(mesMat);
        rv.isNestedScrollingEnabled();

        tvBienvenue = (TextView) findViewById(R.id.tvBienvenue);

        //si on joue en invité ou pas
        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            getUser();
        } else
            tvBienvenue.setText("Bonjour, vous jouez en tant qu'invité !");
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

                Users userCourrant = users.get(0);
                for (int i=0; i<users.size();i++){
                    if (users.get(i).getId() == id) {
                        userCourrant = users.get(i);
                        break;
                    }
                }
                Log.d("testid", "numero id :" + id);

                tvBienvenue.setText("Bonjour " + userCourrant.getPrenom() + " !");
            }

        }

        //////////////////////////
        // IMPORTANT bien penser à executer la demande asynchrone
        // Création d'un objet de type GetTasks et execution de la demande asynchrone
        GetUsers gt = new GetUsers();
        gt.execute();
    }



    public void goToExercices(View view, String currentMatieres) {
        Intent intent = new Intent(this, MenuExerciceActivity.class);
        intent.putExtra(MenuExerciceActivity.MATIERE_NAME_KEY, currentMatieres);
        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            int id = Integer.valueOf(getIntent().getStringExtra(ID_KEY));
            intent.putExtra(MenuExerciceActivity.ID_KEY, ""+id);
        } else
            intent.putExtra(MenuExerciceActivity.ID_KEY, "");
        startActivity(intent);
    }

    public void retourMenuMain (View view) {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}
