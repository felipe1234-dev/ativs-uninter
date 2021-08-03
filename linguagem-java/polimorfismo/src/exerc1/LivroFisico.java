package exerc1;

public class LivroFisico extends Livro {
	private int tiragem;
	private double peso;
	
	public LivroFisico(
			String titulo, Autor autor, String genero, 
			int edicao, int tiragem, double peso
		) 
	{
		super(titulo, autor, genero, edicao);
		setTiragem(tiragem);
		setPeso(peso);
	}
	
	// ---
	
	public int getTiragem() {
		return tiragem;
	}

	public void setTiragem(int tiragem) {
		this.tiragem = tiragem;
	}
	
	// ---

	public double getPeso() {
		return peso;
	}

	public void setPeso(double peso) {
		this.peso = peso;
	}
	
	// ---
	
	public void info() {
		System.out.println(super.getTitulo() + " Edição " + super.getEdicao());
		System.out.println(super.getGenero());
		System.out.println("Por " + super.autor.getNome());
		System.out.println("Tiragem: " + tiragem);
		System.out.println(peso + "g");
	}
}
