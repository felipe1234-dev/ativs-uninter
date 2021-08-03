package exerc2;

import java.util.Scanner;

public class MemeLeonidas {

	public static void main(String[] args) {
		Scanner teclado = new Scanner(System.in);
		int chute;

		System.out.println("Ôh, Leonidas... Quantos vamos enfrentar? ");
		
		do {
			
			chute = teclado.nextInt();
			System.out.printf("%d? \n", chute);
			
			if (chute != 10000) {
				System.out.println((chute < 10000)? "Um pouco mais..." : "Um pouco menos...");
			} 
		} while (chute != 10000);
		
		System.out.println("Isso mesmo!");
	}

}
