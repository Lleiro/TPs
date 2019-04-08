package monteile.projetmobile.db;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Delete;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;
import android.arch.persistence.room.Update;

import java.util.List;

@Dao
public interface UsersDAO {

    @Query("SELECT * FROM Users")
    List<Users> getAll();


    @Insert
    void insert(Users users);

    @Insert
    long[] insertAll(Users... users);

    @Delete
    void delete(Users users);

    @Update
    void update(Users users);

}