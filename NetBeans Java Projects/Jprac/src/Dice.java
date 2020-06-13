class Dice {
    public static void main(String[]args) { 
 
		int dicex;
                int dicey;
                int t;
		dicex = (int)(Math.random()*6) + 1;
		dicey = (int)(Math.random()*6) + 1;
                t = dicex + dicey;
                
                
		System.out.println("The first die comes up" + dicex );
		System.out.println("The second die comes up" + dicey );
		System.out.println("Your total roll is " + t);

	}
}