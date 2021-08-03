package exerc2;

public class Principal {
	
	public static void main(String[] args) {
		Curso ads 	 = new Curso("Análise e Desenvolvimento de Sistemas", 300); 
		Aluno felipe = new Aluno("Felipe Alves", 3344308, 30, ads);
		
		felipe.descrever();
		System.out.printf(
			"Mensalidade após o desconto: R$%.2f",
			felipe.pagamento()
		);
	}
	
}
