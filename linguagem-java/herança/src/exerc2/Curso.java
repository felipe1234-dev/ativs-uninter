package exerc2;

public class Curso {
	public String nome;
	private double mensalidade;
	
	public Curso() {}
	
	public Curso(String nome, double mensalidade) {
		setNome(nome);
		setMensalidade(mensalidade);
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public void setMensalidade(double mensalidade) {
		this.mensalidade = mensalidade;
	}
	
	public double getMensalidade() {
		return mensalidade;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void descrever() {
		System.out.println("Curso " + nome);
		System.out.println("R$" + mensalidade + " por mês");
	}
}
