package exerc1;

public class Principal {

	public static void main(String[] args) {
		Nota carlos = new Nota();
		
		carlos.setNota1(5);
		carlos.setNota2(8);
		carlos.setFaltas(8);
		
		System.out.println("Nota 1 => " + carlos.getNota1());
		System.out.println("Nota 2 => " + carlos.getNota2());
		System.out.println("<Resultado>");
		carlos.resultado();
		
		System.out.println();
		
		Nota joana = new Nota(7, 8, 3);
		
		System.out.println("Nota 1 => " + joana.getNota1());
		System.out.println("Nota 2 => " + joana.getNota2());
		System.out.println("<Resultado>");
		joana.resultado();
	}

}
