package monteile.projetmobile.ressources;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import monteile.projetmobile.InscriptionActivity;
import monteile.projetmobile.MainActivity;
import monteile.projetmobile.MenuMatieresActivity;
import monteile.projetmobile.R;
import monteile.projetmobile.db.AppDatabase;
import monteile.projetmobile.db.DatabaseClient;
import monteile.projetmobile.db.Users;

public class RecyclerAdaptaterUsers extends RecyclerView.Adapter<RecyclerAdaptaterUsers.MyViewHolder> {
    private List<Users> users= new ArrayList<>();
    private MainActivity main;

    public RecyclerAdaptaterUsers(MainActivity menu) {
        main = menu;
    }

    public void setUsers(List<Users> users) {
        this.users = users;
    }

    public void addUsers(Users user) {
        this.users.add(user);
    }

    @Override
    public int getItemCount() {return users.size();}

    public List<Users> getUsers() {
        return users;
    }

    @Override
    public RecyclerAdaptaterUsers.MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View view = inflater.inflate(R.layout.list_users, parent, false);
        return new RecyclerAdaptaterUsers.MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(MyViewHolder holder, int position) {
        Users user = users.get(position);
        holder.display(user);
    }


    public class MyViewHolder extends RecyclerView.ViewHolder {

        private final TextView prenom;
        private final TextView nom;
        private final TextView age;
        private Users currentUsers;

        public MyViewHolder(View itemView) {
            super(itemView);
            prenom = ((TextView) itemView.findViewById(R.id.textViewPrenom));
            nom = ((TextView) itemView.findViewById(R.id.textViewNom));
            age = ((TextView) itemView.findViewById(R.id.textViewAge));

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    main.goToMatieresUsers(view, currentUsers.getId());
                }

            });

            ImageView imageViewDelete = itemView.findViewById(R.id.imageViewDelete);
            ImageView imageViewEdit = itemView.findViewById(R.id.imageViewEdit);

            imageViewDelete.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    AlertDialog.Builder builder = new AlertDialog.Builder(main);

                    builder
                            .setMessage("Are you sure?")
                            .setPositiveButton("Yes",  new DialogInterface.OnClickListener(){
                                @Override
                                public void onClick(DialogInterface dialog, int id) {


                                    class DeleteUsers extends AsyncTask<Void, Void, Void> {
                                        private DatabaseClient mDb = DatabaseClient.getInstance(main);

                                        @Override
                                        protected Void doInBackground(Void... voids) {
                                            mDb.getAppDatabase()
                                                    .usersDAO()
                                                    .delete(currentUsers);
                                            return null;
                                        }

                                        @Override
                                        protected void onPostExecute(Void voids) {
                                            super.onPostExecute(voids);
                                            main.getUser();
                                        }

                                    }
                                    DeleteUsers gt = new DeleteUsers();
                                    gt.execute();
                                }
                            })
                            .setNegativeButton("No", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog,int id) {
                                    dialog.cancel();
                                }
                            })
                            .show();
                }
            });

            imageViewEdit.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    main.editUser(view, currentUsers.getId());
                }

            });

        }



        public void display(Users user) {
            currentUsers = user;
            prenom.setText(user.getPrenom());
            nom.setText(user.getNom());
            age.setText(user.getAge()+ " ans");

        }
    }
}
