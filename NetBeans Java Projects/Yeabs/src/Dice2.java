/**Class Dice2 is a simulation of the rolling of two dice. In addition
 * to this it is able to predict when a snake eye appears, which is when
 * 1 appears on both dice.  
 * @author Yeabs
 */
public class Dice2 {
	public static void main(String[] args) {
		int d1;
		int d2;
		int roll;
		d1 = (int)(6*Math.random() + 1);
		d2 = (int)(6*Math.random() + 1);
		roll = 0;
		while (true) {
			if (d1 == 1 && d2 == 1) {
				System.out.println("dice 1  dice 2");
				System.out.println(d1 + "        " + d2);
				System.out.println("Wow! You have found a snake eye after 1 roll.");
				break;
			}
			System.out.println("dice 1  dice 2");
			while (d1 != 1 || d2 != 1) {
				d1 = (int)(6*Math.random() + 1);
				d2 = (int)(6*Math.random() + 1);
				System.out.println(d1 + "        " + d2);
				roll++;
			}
			if ( d1 == 1 &&  d2 == 1 ) {
				System.out.println("Yes. You have got a snake eye after " + roll + " rolls.");
				break;
			}
		}
	}
}