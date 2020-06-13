package favor;
/*
 * This class provides as a database regarding the necessary biodiversities which are edible.
 * It is more likely that this class serves as a platform on which the arduino processing occurs.
 * @Author Yeabsra
 */
import java.awt.*;
 public class Edible {
    
    public static int ID_num;
    private String str;
    private Graphics g;

    public Edible(String str) {
        ID_num++;
    }
    public Edible(Graphics g) {
    }
    
    public Edible Bio_Name = new Edible(str);
    public Edible Bio_pic = new Edible(g);
 
}
