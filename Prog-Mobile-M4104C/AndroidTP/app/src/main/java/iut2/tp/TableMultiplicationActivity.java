package iut2.tp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.NumberPicker;
import android.widget.TextView;

public class TableMultiplicationActivity extends AppCompatActivity {

    public static final String TABLE_KEY= "table_key";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_table_multiplication);

        String val = getIntent().getStringExtra(TABLE_KEY);
        for(int i = 1; i < 11; i++) {
            String id = "mult" + i;
            int resID = getResources().getIdentifier(id, "id", getPackageName());
            TextView recup = (TextView) findViewById(resID);
            recup.setText(i + " x " + val + " = ");
        }

    }

    public void tableValider(View view) {
        String val = getIntent().getStringExtra(TABLE_KEY);
        int nbErrors = 0;
        for(int i=1; i < 11; i ++ ) {
            String idRep = "rep" + i;
            String idMult = "mult" + i;
            int resIDRep = getResources().getIdentifier(idRep, "id", getPackageName());
            int resIDMult = getResources().getIdentifier(idMult, "id", getPackageName());
            TextView recupMult = (TextView) findViewById(resIDMult);
            EditText recupRep =  (EditText) findViewById(resIDRep);

            if (Integer.valueOf(val)* i != Integer.valueOf(recupRep.getText().toString()))
                nbErrors++;
        }

        if (nbErrors != 0) {
            Intent intent = new Intent(this, ErrorActivity.class);
            //intent.putExtra(TableMultiplicationActivity.TABLE_KEY, table);
            startActivity(intent);
        } else {
            Intent intent = new Intent(this, FelicitationActivity.class);
            //intent.putExtra(TableMultiplicationActivity.TABLE_KEY, table);
            startActivity(intent);
        }


    }
}
