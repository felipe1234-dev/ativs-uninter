package exerc1;

public class Principal {

	public static void main(String[] args) {
		Autor autor = new Autor(
			"Neil deGrasse Tyson", "t.contato.neil@gmail.com",
			"Americano"
		);
		
		Livro livroDigital = new LivroDigital(
			"Astrof�sica para Apressados", autor, "Ci�ncia",
			1, 1, 500
		);
		
		Livro livroFisico = new LivroFisico(
			"Cosmic Queries", autor, "Ci�ncia",
			1, 1, 300
		);
		
		System.out.println("Sobre o autor");
		autor.info();
		
		System.out.println();
		System.out.println("Sobre o livro f�sico");
		livroFisico.info();
		
		System.out.println();
		System.out.println("Sobre o livro digital");
		livroDigital.info();
	}

}
