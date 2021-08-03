package exerc2;

public class Principal {

	public static void main(String[] args) {
		Ingresso ing1 = new Ingresso("Show de Concerto", 50);
		
		System.out.println();
		System.out.println("Ingresso 1");
		ing1.info();
		
		Ingresso ing2 = new IngressoVip("Show de Concerto", 50, 30);
		
		System.out.println();
		System.out.println("Ingresso 2");
		ing2.info();
	}

}
