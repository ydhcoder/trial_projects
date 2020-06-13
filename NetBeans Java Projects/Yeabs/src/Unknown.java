public class Unknown {
	public static boolean random1;
	public static void main(String[] args) {
		TextIO.putln("Hi, in this game you will give you numbersno and if you see that the "
				+ "sum of the numbers is correct answer true else false");
		boolean playAgain;
		playAgain = true;
		do {
			Game();
			TextIO.putln("Do you wanna play again?");
			playAgain = TextIO.getBoolean();
		} while(playAgain);
		TextIO.putln("Thanks for playing.");
	}
	public static void Asker() {
		TextIO.putln("Hi, What is your name?");
		String name = TextIO.getln();
		TextIO.putln("Hi, " + name + ", Where do you live?");
		String place = TextIO.getln();
		TextIO.putln("Bye " + name + ". See you another time. Thank you for your"
				+ "information.");
	}
	public static void Game() {
		while(true) {
			int num1 = (int)(100*Math.random()) + 1;
			int num2 = (int)(100*Math.random()) + 1;
			int random = (int)(2*Math.random());
			int answer2 = 0;
			int sum = 0;
			switch (random ) {
			case 1:
				random1 = true;
			case 2:
				random1 = false;
		
			}
			if (random1) {
				sum = num1 + num2;
				answer2 = sum;
			}
			else {
				answer2 = (int)(200*Math.random()) + 1;
			}
			TextIO.putln("The sum of " + num1 + " and " + num2 + " is " + answer2);
			boolean answer1 =  TextIO.getBoolean();
			int counttot = 0;
			int countmark = 0;
			counttot++;
			if ( answer1 == random1 ) {
				TextIO.putln("Yes, you are right....Bravo");
				countmark++;
			}
			else 
				TextIO.putln("Oh, I am very sorry. You are wrong");
			
		}
	}
}


