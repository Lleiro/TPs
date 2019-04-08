package monteile.projetmobile.ressources;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.Arrays;
import java.util.List;

import monteile.projetmobile.MenuMatieresActivity;
import monteile.projetmobile.R;

public class RecyclerAdaptaterMatieres extends RecyclerView.Adapter<RecyclerAdaptaterMatieres.MyViewHolder> {
    private final List<Matiere> matieres = Arrays.asList(
            new Matiere("Géographie", R.drawable.img_geographie),
            new Matiere("Mathématiques", R.drawable.img_mathematique),
            new Matiere("Anglais", R.drawable.img_anglais),
            new Matiere("Histoire", R.drawable.img_histoire)

    );

    private MenuMatieresActivity menuActivity;

    public RecyclerAdaptaterMatieres(MenuMatieresActivity menu) {
        menuActivity = menu;
    }


    @Override
    public int getItemCount() {return matieres.size();}

    public List<Matiere> getMatieres() {
        return matieres;
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View view = inflater.inflate(R.layout.list_matieres, parent, false);
        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(MyViewHolder holder, int position) {

        Matiere matiere = matieres.get(position);
        holder.display(matiere);

    }



    public class MyViewHolder extends RecyclerView.ViewHolder {

        private final TextView name_Matiere;
        private ImageView img_Matiere;
        private Matiere currentMatiere;

        public MyViewHolder(View itemView) {
            super(itemView);
            name_Matiere = ((TextView) itemView.findViewById(R.id.nomMatiere));
            img_Matiere = ((ImageView) itemView.findViewById(R.id.imgMatiere));

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    menuActivity.goToExercices(view, currentMatiere.getNomMatiere());
                }
            });
        }



        public void display(Matiere matiere) {
            currentMatiere = matiere;
            name_Matiere.setText(matiere.getNomMatiere());
            img_Matiere.setImageResource(matiere.getRefImg());

        }
    }

}