package exerc1;

public class Principal {

	public static void main(String[] args) {
		Autor autor = new Autor(
			"Neil deGrasse Tyson", "t.contato.neil@gmail.com",
			"Americano"
		);
		
		Livro livroDigital = new LivroDigital(
			"Astrofísica para Apressados", autor, "Ciência",
			1, 1, 500
		);
		
		Livro livroFisico = new LivroFisico(
			"Cosmic Queries", autor, "Ciência",
			1, 1, 300
		);
		
		System.out.println("Sobre o autor");
		autor.info();
		
		System.out.println();
		System.out.println("Sobre o livro físico");
		livroFisico.info();
		
		System.out.println();
		System.out.println("Sobre o livro digital");
		livroDigital.info();
	}

}
