package exerc1;

import java.util.Scanner;

public class IMC {

	public static void main(String[] args) {
		// F�rmula: peso/altura�
		Scanner teclado = new Scanner(System.in);
		
		System.out.println("Por favor, digite o seu peso (em kg): ");
		float peso = teclado.nextFloat(); 
		
		System.out.println("Digite a sua altura (em m): ");
		float altura = teclado.nextFloat();
		
		float imc = (float) (peso/Math.pow(altura, 2));
		System.out.println("Seu IMC (�ndice de Massa Corp�rea): ");
		System.out.printf("%.2f", imc);
	}

}
