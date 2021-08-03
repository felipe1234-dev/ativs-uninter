package exerc2;

public class Aluno {
	public String nome;
	private int matricula;
	private double desconto;
	Curso curso;
	
	public Aluno() {}
	
	public Aluno(
		String nome, int matricula, 
		double desconto, Curso curso
	) {
		setNome(nome);
		setMatricula(matricula);
		setDesconto(desconto);
		setCurso(curso);
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public void setMatricula(int matricula) {
		if (matricula >= 1000000 && matricula <= 9999999) {
			this.matricula = matricula;
		}
		else {
			System.out.println("Matrícula inválida");
		}
	}
	
	public void setDesconto(double desconto) {
		if (desconto > 0 && desconto <= 100) {
			this.desconto = desconto;
		}
		else {
			System.out.println(
				"Desconto inválido"
			);
		}
	}
	
	public void setCurso(Curso curso) {
		this.curso = curso;
	}
	
	public String getNome() {
		return nome;
	}
	
	public int getMatricula() {
		return matricula;
	}
	
	public double getDesconto() {
		return desconto;
	}
	
	public Curso getCurso() {
		return curso;
	}
	
	public void descrever() {
		System.out.println(
			nome + " - nº da matrícula: " + matricula
		);
		System.out.printf(
			"Cursando %s | R$%.2f por mês\n", 
			curso.getNome(), curso.getMensalidade()
		);
		System.out.println("Desconto de " + desconto + "%");	
	}
	
	public double pagamento() {
		return (1-desconto/100)*curso.getMensalidade();
	}
	
}
