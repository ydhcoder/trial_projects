/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Yeabsra
 */
import java.awt.*;
import java.io.*;
 public class Database {
    public String Name; // Identifier for a specific type of plant.
    private static int ID;  // Unique number that is given to every
                            // plant on the database.
    public double PH, temp, Hum, LI; // Suitable conditions for that plant's growth. 
    public String Status;   // Refers to whether the plant is marketable,
                            // edible or both.
    public Graphics Pic;    // Refers to the image of the plant.
    
    public interface ObjectStorer {
         public void put (Object key, Object object) throws IOException;
         public Object get (Object key) throws IOException,
            ClassNotFoundException, IllegalAccessException, InstantiationException;
    }
    public interface ObjectStorage {
        public void put (Object key, StorageFields object) throws IOException;
        public RetrievalFields get (Object key) throws IOException;
    }

}
