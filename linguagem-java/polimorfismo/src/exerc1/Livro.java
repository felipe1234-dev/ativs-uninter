package exerc1;

public abstract class Livro {
	private String titulo;
	protected Autor autor;
	private String genero;
	private int edicao;
	
	public Livro(String titulo, Autor autor, String genero, int edicao) {
		setTitulo(titulo);
		setAutor(autor);
		setGenero(genero);
		setEdicao(edicao);
	}

	// ---
	
	public String getTitulo() {
		return titulo;
	}
	
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	
	// ---
	
	public Autor getAutor() {
		return autor;
	}
	
	public void setAutor(Autor autor) {
		this.autor = autor;
	}
	
	// ---
	
	public String getGenero() {
		return genero;
	}
	
	public void setGenero(String genero) {
		this.genero = genero;
	}
	
	// ---
	
	public int getEdicao() {
		return edicao;
	}
	
	public void setEdicao(int edicao) {
		this.edicao = edicao;
	}
	
	// ---
	
	public abstract void info();
}
