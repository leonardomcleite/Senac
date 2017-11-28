package com.example.alunos.imc;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        SeekBar seekBarPeso = (SeekBar) findViewById(R.id.seekBarPeso);
        final TextView txtPeso = (TextView) findViewById(R.id.txtPeso);

        SeekBar seekBarAltura = (SeekBar) findViewById(R.id.seekBarAltura);
        final TextView txtAltura = (TextView) findViewById(R.id.txtAltura);

        seekBarPeso.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBarPeso, int progress, boolean fromUser) {
                txtPeso.setText(progress + " Kg");
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBarPeso) {
                //Toast.makeText(MainActivity.this, "COMEÇOU A MOVER", Toast.LENGTH_SHORT ).show();
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBarPeso) {
                //Toast.makeText(MainActivity.this, "PAROU DE MOVER", Toast.LENGTH_SHORT ).show();
            }
        });

        seekBarAltura.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBarAltura, int progress, boolean fromUser) {
                txtAltura.setText(progress / 100.00 + " m");
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBarAltura) {
                //Toast.makeText(MainActivity.this, "COMEÇOU A MOVER", Toast.LENGTH_SHORT ).show();
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBarAltura) {
                //Toast.makeText(MainActivity.this, "PAROU DE MOVER", Toast.LENGTH_SHORT ).show();
            }
        });
    }

    public void calcularImc(View view){

        SeekBar seekBarPeso = (SeekBar)findViewById(R.id.seekBarPeso);
        int peso = seekBarPeso.getProgress();

        SeekBar seekBarAltura = (SeekBar)findViewById(R.id.seekBarAltura);
        double altura = seekBarAltura.getProgress();

        Intent intent = new Intent(this, ImcActivity.class);

        intent.putExtra("ALTURA", altura);
        intent.putExtra("PESO", peso);

        startActivity(intent);
        overridePendingTransition(android.R.anim.fade_in,android.R.anim.fade_out);


    }

}
