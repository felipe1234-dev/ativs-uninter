package exerc3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ReverterArray {

	public static void main(String[] args) {
		/* Fazer vetor:
		 * 
		 * Método 1 
		 * 	int vetor[] = { 3, 4, 5, ... }
		 * 
		 * Método 2
		 * 	import java.util.ArrayList;
		 * 	...
		 * 	ArrayList<Integer> vetor = new ArrayList();
		 * 	vetor.add(3);
		 *  vetor.add(4);
		 *  vetor.add(5);
		 *  vetor.remove(índice); 
		 * */
		
		ArrayList<String> nomes = new ArrayList();
		Scanner teclado = new Scanner(System.in);
		
		String aux;
		
		System.out.println("Digite a quantidade de nomes: ");
		int cont = teclado.nextInt();
		
		System.out.println("Digite os nomes: ");
		for (int i = 0; i < cont; i++) {
			aux = teclado.next();
			nomes.add(aux);
		}
		
		System.out.println();
		
		System.out.println("Ordem normal");
		for (String n : nomes) {
			System.out.println(n);
		}
		
		System.out.println();
		
		System.out.println("Ordem reversa");
		for (int i = cont-1; i >= 0; i--) {
			System.out.println(nomes.get(i));
		}
		
		System.out.println("ou (veja no código)");
		
		System.out.println("Ordem reversa");
		Collections.reverse(nomes);
		System.out.println(nomes);

	}

}
