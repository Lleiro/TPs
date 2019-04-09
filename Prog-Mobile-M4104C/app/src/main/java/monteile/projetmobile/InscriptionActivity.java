package monteile.projetmobile;

import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

import monteile.projetmobile.db.DatabaseClient;
import monteile.projetmobile.db.Users;


public class InscriptionActivity extends AppCompatActivity {
    public static final String ID_KEY = "ID_KEY";


    private DatabaseClient mDb;

    private EditText editTextPrenom;
    private EditText editTextNom;
    private EditText editTextAge;
    private Button btnInscription;
    private Users userCourrant;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_inscription);

        mDb = DatabaseClient.getInstance(getApplicationContext());

        editTextAge = findViewById(R.id.ageReponse);
        editTextNom = findViewById(R.id.nomReponse);
        editTextPrenom = findViewById(R.id.prenomReponse);

        btnInscription = (Button) findViewById(R.id.inscription);
        Button btnRetour = (Button) findViewById(R.id.retour);
        TextView title = (TextView) findViewById(R.id.tvTitleInsc);

        //On regarde si c'est un edit ou pas
        //si oui
        if (!getIntent().getStringExtra(ID_KEY).isEmpty()) {
            getUser();

            btnInscription.setText("Valider la mise à jour");
            btnRetour.setText("Annuler la mise à jour");
            title.setText("Mise à jour utilisateur");

        } else {
            title.setText("Création utilisateur");
            btnInscription.setText("Valider l'inscription");
            btnRetour.setText("Annuler l'inscription");
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

                userCourrant = new Users();
                for (int i=0; i<users.size();i++){
                    if (users.get(i).getId() == id) {
                        userCourrant = users.get(i);
                        break;
                    }
                }

                editTextNom.setText(userCourrant.getNom());
                editTextPrenom.setText(userCourrant.getPrenom());
                editTextAge.setText(userCourrant.getAge());

                btnInscription.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        updateUser(userCourrant);
                    }

                });
            }

        }

        //////////////////////////
        // IMPORTANT bien penser à executer la demande asynchrone
        // Création d'un objet de type GetTasks et execution de la demande asynchrone
        GetUsers gt = new GetUsers();
        gt.execute();
    }

    public void goBack(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public void updateUser(final Users monUser) {
        // Récupérer les informations contenues dans les vues
        final String sPrenom = editTextPrenom.getText().toString().trim();
        Log.d("bonjour", "Val prenom : " + sPrenom);
        final String sNom = editTextNom.getText().toString().trim();
        final String sAge = editTextAge.getText().toString().trim();

        // Vérifier les informations fournies par l'utilisateur
        if (sPrenom.isEmpty()) {
            editTextPrenom.setError("Prenom requis");
            editTextPrenom.requestFocus();
            return;
        }

        if (sNom.isEmpty()) {
            editTextNom.setError("Nom Requis");
            editTextNom.requestFocus();
            return;
        }

        if (sAge.isEmpty()) {
            editTextAge.setError("Age Requis");
            editTextAge.requestFocus();
            return;
        }
        /**
         * Création d'une classe asynchrone pour sauvegarder la tache donnée par l'utilisateur
         */
        class UpdateUser extends AsyncTask<Void, Void, Users> {


            @Override
            protected Users doInBackground(Void... voids) {

                // creating a task
                monUser.setPrenom(sPrenom);
                monUser.setAge(sAge);
                monUser.setNom(sNom);


                // adding to database
                mDb.getAppDatabase()
                        .usersDAO()
                        .update(monUser);

                return monUser;
            }

            @Override
            protected void onPostExecute(Users users) {
                super.onPostExecute(users);

                // Quand la tache est créée, on arrête l'activité AddTaskActivity (on l'enleve de la pile d'activités)
                setResult(RESULT_OK);
                finish();
                Toast.makeText(getApplicationContext(), "Saved", Toast.LENGTH_LONG).show();
            }
        }

        UpdateUser st = new UpdateUser();
        st.execute();

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
        finish();
    }

    public void saveUsers(View view) {

        // Récupérer les informations contenues dans les vues
        final String sPrenom = editTextPrenom.getText().toString().trim();
        final String sNom = editTextNom.getText().toString().trim();
        final String sAge = editTextAge.getText().toString().trim();

        // Vérifier les informations fournies par l'utilisateur
        if (sPrenom.isEmpty()) {
            editTextPrenom.setError("Prenom requis");
            editTextPrenom.requestFocus();
            return;
        }

        if (sNom.isEmpty()) {
            editTextNom.setError("Nom Requis");
            editTextNom.requestFocus();
            return;
        }

        if (sAge.isEmpty()) {
            editTextAge.setError("Age Requis");
            editTextAge.requestFocus();
            return;
        }

        /**
         * Création d'une classe asynchrone pour sauvegarder la tache donnée par l'utilisateur
         */
        class SaveTask extends AsyncTask<Void, Void, Users> {


            @Override
            protected Users doInBackground(Void... voids) {

                // creating a task
                Users users = new Users();
                users.setPrenom(sPrenom);
                users.setAge(sAge);
                users.setNom(sNom);
                users.resetScore();

                // adding to database
                mDb.getAppDatabase()
                        .usersDAO()
                        .insert(users);

                return users;
            }

            @Override
            protected void onPostExecute(Users users) {
                super.onPostExecute(users);

                // Quand la tache est créée, on arrête l'activité AddTaskActivity (on l'enleve de la pile d'activités)
                setResult(RESULT_OK);
                finish();
                Toast.makeText(getApplicationContext(), "Saved", Toast.LENGTH_LONG).show();
            }
        }

        SaveTask st = new SaveTask();
        st.execute();

        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
        finish();
    }
}
