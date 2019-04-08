package monteile.projetmobile.db;


import android.arch.persistence.room.ColumnInfo;
import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;
import android.os.AsyncTask;
import android.widget.EditText;

import java.io.Serializable;

import monteile.projetmobile.R;

@Entity
public class Users implements Serializable {
    @PrimaryKey(autoGenerate = true)
    private int id;

    @ColumnInfo(name = "Prenom")
    private String prenom;

    @ColumnInfo(name = "Nom")
    private String nom;

    @ColumnInfo(name="Age")
    private String age;

    @ColumnInfo(name="scoreCapitale1")
    private int scoreCapitale1;

    @ColumnInfo(name="scoreCapitale3")
    private int scoreCapitale3;

    @ColumnInfo(name="scoreTraduction1")
    private int scoreTraduction1;

    @ColumnInfo(name="scoreAddition1")
    private int scoreAddition1;

    @ColumnInfo(name="scoreAddition2")
    private int scoreAddition2;

    @ColumnInfo(name="scoreAddition3")
    private int scoreAddition3;

    @ColumnInfo(name="scoreSoustration1")
    private int scoreSoustration1;
    @ColumnInfo(name="scoreSoustration2")
    private int scoreSoustration2;
    @ColumnInfo(name="scoreSoustration3")
    private int scoreSoustration3;

    @ColumnInfo(name="scoreMutiplication1")
    private int scoreMutiplication1;
    @ColumnInfo(name="scoreMutiplication2")
    private int scoreMutiplication2;
    @ColumnInfo(name="scoreMutiplication3")
    private int scoreMutiplication3;



    public void resetScore(){
        scoreAddition1 = 0;
        scoreAddition2 = 0;
        scoreAddition3 = 0;
        scoreCapitale1 = 0;
        scoreCapitale3 = 0;
        scoreMutiplication1 = 0;
        scoreMutiplication2 = 0;
        scoreMutiplication3 = 0;
        scoreSoustration1 = 0;
        scoreSoustration2 = 0;
        scoreSoustration3 = 0;
        scoreTraduction1 = 0;
    }

    public int getScoreAddition1() {
        return scoreAddition1;
    }

    public int getScoreAddition2() {
        return scoreAddition2;
    }

    public int getScoreAddition3() {
        return scoreAddition3;
    }

    public int getScoreCapitale1() {
        return scoreCapitale1;
    }

    public int getScoreCapitale3() {
        return scoreCapitale3;
    }

    public int getScoreMutiplication1() {
        return scoreMutiplication1;
    }

    public int getScoreMutiplication2() {
        return scoreMutiplication2;
    }

    public int getScoreMutiplication3() {
        return scoreMutiplication3;
    }

    public int getScoreSoustration1() {
        return scoreSoustration1;
    }

    public int getScoreSoustration2() {
        return scoreSoustration2;
    }

    public int getScoreSoustration3() {
        return scoreSoustration3;
    }

    public int getScoreTraduction1() {
        return scoreTraduction1;
    }

    public void setScoreAddition1(int scoreAddition1) {
        this.scoreAddition1 = scoreAddition1;
    }

    public void setScoreAddition2(int scoreAddition2) {
        this.scoreAddition2 = scoreAddition2;
    }

    public void setScoreAddition3(int scoreAddition3) {
        this.scoreAddition3 = scoreAddition3;
    }

    public void setScoreCapitale1(int scoreCapitale1) {
        this.scoreCapitale1 = scoreCapitale1;
    }

    public void setScoreCapitale3(int scoreCapitale3) {
        this.scoreCapitale3 = scoreCapitale3;
    }

    public void setScoreMutiplication1(int scoreMutiplication1) {
        this.scoreMutiplication1 = scoreMutiplication1;
    }

    public void setScoreTraduction1(int scoreTraduction1) {
        this.scoreTraduction1 = scoreTraduction1;
    }

    public void setScoreMutiplication2(int scoreMutiplication2) {
        this.scoreMutiplication2 = scoreMutiplication2;
    }

    public void setScoreMutiplication3(int scoreMutiplication3) {
        this.scoreMutiplication3 = scoreMutiplication3;
    }

    public void setScoreSoustration1(int scoreSoustration1) {
        this.scoreSoustration1 = scoreSoustration1;
    }

    public void setScoreSoustration2(int scoreSoustration2) {
        this.scoreSoustration2 = scoreSoustration2;
    }

    public void setScoreSoustration3(int scoreSoustration3) {
        this.scoreSoustration3 = scoreSoustration3;
    }

    public int getId() {
        return id;
    }

    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public String getAge() {
        return age;
    }

    public void setAge(String age) {
        this.age = age;
    }


}
