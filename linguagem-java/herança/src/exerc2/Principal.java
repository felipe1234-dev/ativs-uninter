package exerc2;

public class Principal {
	
	public static void main(String[] args) {
		Curso ads 	 = new Curso("An�lise e Desenvolvimento de Sistemas", 300); 
		Aluno felipe = new Aluno("Felipe Alves", 3344308, 30, ads);
		
		felipe.descrever();
		System.out.printf(
			"Mensalidade ap�s o desconto: R$%.2f",
			felipe.pagamento()
		);
	}
	
}
