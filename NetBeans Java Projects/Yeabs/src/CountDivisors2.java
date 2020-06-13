
public class CountDivisors2 {
	public static void main(String[] args) {
		int N;
		int count;
		int testdivisor;
		count = 0;
		TextIO.writeFile("data.txt");
		for (N = 2; N < 100 ; N++ ) {
			for ( testdivisor = 1;testdivisor <= N; testdivisor++ ) {
				if ( N % testdivisor == 0) 
					count++;
			}
			TextIO.putln( N + " has: ");
			TextIO.putln(count + " divisors");
			count = 0;
		}
		TextIO.writeStandardOutput();
		String fileName = "data.txt";
		while (true) {
			try { 
				TextIO.readFile( fileName ); // Try to open the file for input. 
				break; // If that succeeds, break out of the loop. 
			} 
			catch ( IllegalArgumentException e ) { 
				TextIO.putln("Can’t read from the file \"" + fileName + "\"."); 
				TextIO.putln("Please try again.\n");
			}
		}
		try {
			while (true) { // Loop ends when an exception occurs. 
				int prevN = TextIO.getlnInt();
				int Dprevcount = TextIO.getlnInt();
				int nextN = TextIO.getlnInt();
				int Dnextcount = TextIO.getlnInt();
				for ( prevN = 2; prevN < 99; prevN = nextN - 1) {
					for ( nextN = 3 ; nextN < 100; nextN++) {
						if ( Dnextcount > Dprevcount ) {
							System.out.println( nextN + " has larger number of divisors " +
									"than " + prevN + " which is " + Dnextcount );
						}
						else if ( Dnextcount < Dprevcount ) {
							System.out.println( prevN  + " has larger number of divisors " +
									"than " + nextN + " which is " + Dprevcount );
						}
					}
				}
			}  
		}
		catch ( IllegalArgumentException e ) { 
			// We expect this to occur when the end-of-file is encountered.
			// We don’t consider this to be an error, so there is nothing to do 
			// in this catch clause. Just proceed with the rest of the program. 
		}
	}
}
