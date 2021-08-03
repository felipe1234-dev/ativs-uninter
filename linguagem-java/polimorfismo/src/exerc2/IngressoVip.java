package exerc2;

public class IngressoVip extends Ingresso {
	public double adicional;
	
	public IngressoVip(String nomeEvento, double valor, double adicional) {
		super(nomeEvento, valor);
		setAdicional(adicional);
	}
	
	// ---
	
	public double getAdicional() {
		return adicional;
	}
	
	public void setAdicional(double adicional) {
		this.adicional = adicional;
	}
	
	// ---
	
	@Override
	public void info() {
		super.info();
		System.out.printf("Adicional  : R$ %.2f\n", adicional);
		System.out.printf("Preço total: R$ %.2f", (valor + adicional));
	}
}
