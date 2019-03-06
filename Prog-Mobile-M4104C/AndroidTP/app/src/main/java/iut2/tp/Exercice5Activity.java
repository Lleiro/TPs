package iut2.tp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.NumberPicker;
import android.widget.TextView;

public class Exercice5Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // On charge le XML pour créer l'arbre graphique
        setContentView(R.layout.activity_exercice5);

        NumberPicker table = (NumberPicker) findViewById(R.id.TableMulti);
        table.setMinValue(1);
        table.setMaxValue(10);
    }

    public void exercice5Valider(View view) {
        NumberPicker tableTemp = (NumberPicker) findViewById(R.id.TableMulti);
        String table = "" + tableTemp.getValue();

        Intent intent = new Intent(this, TableMultiplicationActivity.class);
        intent.putExtra(TableMultiplicationActivity.TABLE_KEY, table);
        startActivity(intent);

    }
}
