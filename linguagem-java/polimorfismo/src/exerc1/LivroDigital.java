package exerc1;

public class LivroDigital extends Livro {
	private int download;
	private double tamanhoMB;
	
	public LivroDigital(
			String titulo, Autor autor, String genero, 
			int edicao, int download, double tamanhoMB
		) 
	{
		super(titulo, autor, genero, edicao);
		setDownload(download);
		setTamanhoMB(tamanhoMB);
	}
	
	// ---
	
	public int getDownload() {
		return download;
	}

	public void setDownload(int download) {
		this.download = download;
	}
	
	// ---

	public double getTamanhoMB() {
		return tamanhoMB;
	}

	public void setTamanhoMB(double tamanhoMB) {
		this.tamanhoMB = tamanhoMB;
	}
	
	// ---
	
	public void info() {
		System.out.println(super.getTitulo() + " Edição " + super.getEdicao());
		System.out.println(super.getGenero());
		System.out.println("Por " + super.autor.getNome());
		System.out.println("Download: " + download);
		System.out.println(tamanhoMB + " MB");
	}
}
