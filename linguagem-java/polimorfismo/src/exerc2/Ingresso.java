package exerc2;

public class Ingresso {
	public String nomeEvento;
	public double valor;
	
	public Ingresso(String nomeEvento, double valor) {
		super();
		setNomeEvento(nomeEvento);
		setValor(valor);
	}

	// ---
	
	public String getNomeEvento() {
		return nomeEvento;
	}
	
	public void setNomeEvento(String nomeEvento) {
		this.nomeEvento = nomeEvento;
	}
	
	// ---
	
	public double getValor() {
		return valor;
	}
	
	public void setValor(double valor) {
		this.valor = valor;
	}
	
	// ---
	
	public void info() {
		System.out.println("Ingresso para " + nomeEvento);
		System.out.printf("Preço      : R$ %.2f\n", valor);
	}
}
