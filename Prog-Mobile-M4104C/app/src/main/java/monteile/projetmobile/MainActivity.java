package monteile.projetmobile;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.content.Intent;

import java.util.List;

import monteile.projetmobile.db.DatabaseClient;
import monteile.projetmobile.db.Users;
import monteile.projetmobile.ressources.RecyclerAdaptaterUsers;

public class MainActivity extends AppCompatActivity {

    // DATA
    private DatabaseClient mDb;
    private RecyclerAdaptaterUsers adaptaterUsers = new RecyclerAdaptaterUsers(this);


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Récupération du DatabaseClient
        mDb = DatabaseClient.getInstance(getApplicationContext());


        final RecyclerView rv = (RecyclerView) findViewById(R.id.recyclerViewUsers);
        rv.setLayoutManager(new LinearLayoutManager(this));
        rv.setAdapter(adaptaterUsers);
        rv.isNestedScrollingEnabled();

        getUser();

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
                adaptaterUsers.setUsers(users);

                // Now, notify the adapter of the change in source
                adaptaterUsers.notifyDataSetChanged();
            }

        }

        //////////////////////////
        // IMPORTANT bien penser à executer la demande asynchrone
        // Création d'un objet de type GetTasks et execution de la demande asynchrone
        GetUsers gt = new GetUsers();
        gt.execute();
    }

    public void goToInscription (View view) {
        Intent intent = new Intent(this, InscriptionActivity.class);
        intent.putExtra(InscriptionActivity.ID_KEY, "");
        startActivity(intent);
        finish();
    }

    public void goToMatieresUsers(View view, int id) {
        Intent intent = new Intent(this, MenuMatieresActivity.class);
        intent.putExtra(MenuMatieresActivity.ID_KEY, ""+id);
        startActivity(intent);
        finish();

    }

    public void editUser(View view, int id) {
        Intent intent = new Intent(this, InscriptionActivity.class);
        intent.putExtra(InscriptionActivity.ID_KEY, ""+id);
        startActivity(intent);
        finish();
    }

    public void goToMatieres (View view) {
        Intent intent = new Intent(this, MenuMatieresActivity.class);
        intent.putExtra(MenuMatieresActivity.ID_KEY, "");
        startActivity(intent);
        finish();
    }
}
