import java.util.Scanner;

public class Ask {

	public static void main(String[] args) {

		Scanner stdin = new Scanner ( System.in );
		String name;
		System.out.println("What's your name?");
		name = stdin.next();
		System.out.println("Hello, " + name.toUpperCase() + ", nice to "
                        + "meet you!");		 
	}
}