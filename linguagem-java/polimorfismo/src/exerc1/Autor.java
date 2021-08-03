package exerc1;

public class Autor {
	private String nome;
	private String email;
	private String nacionalidade;
	
	public Autor(String nome, String email, String nacionalidade) {
		setNome(nome);
		setEmail(email);
		setNacionalidade(nacionalidade);
	}
	
	// ---
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	// ---
	
	public String getEmail() {
		return email;
	}
	
	public void setEmail(String email) {
		this.email = email;
	}
	
	// ---
	
	public String getNacionalidade() {
		return nacionalidade;
	}
	
	public void setNacionalidade(String nacionalidade) {
		this.nacionalidade = nacionalidade;
	}
	
	// ---
	
	public void info() {
		System.out.println(nome);
		System.out.println(email);
		System.out.println("Nacionalidade: " + nacionalidade);
	}

}
