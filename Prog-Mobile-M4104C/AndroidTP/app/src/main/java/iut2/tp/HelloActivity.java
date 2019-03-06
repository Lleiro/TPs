package iut2.tp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.TextView;

public class HelloActivity extends AppCompatActivity {


    public static final String PRENOM_KEY= "prenom_key";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hello);


        String prenom = getIntent().getStringExtra(PRENOM_KEY);
        TextView hello = (TextView) findViewById(R.id.hello);
        if (!TextUtils.isEmpty(hello.getText())) {
            hello.setText("Hello " + prenom + " !");
        }
    }

    public void retourActivity4(View view) {
        super.finish();
    }

    public void retourMain(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        startActivity(intent);
    }


}
