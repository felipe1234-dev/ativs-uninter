package exerc1;

public class Nota {
	private double nota1;
	private double nota2;
	private int faltas;
	
	public Nota() {}
	
	public Nota(double nota1, double nota2, int faltas) {
		this.setNota1(nota1);
		this.setNota2(nota2);
		this.setFaltas(faltas);
	}
	
	public void setNota1(double nota) {
		if (nota < 0) {
			System.out.println("Nota1 não pode ser negativa");
		} 
		else if (nota > 10) {
			System.out.println("Nota1 não pode ser maior que 10");
		}
		else {
			nota1 = nota;
		}
	}
	
	public void setNota2(double nota) {
		if (nota < 0) {
			System.out.println("Nota2 não pode ser negativa");
		} 
		else if (nota > 10) {
			System.out.println("Nota2 não pode ser maior que 10");
		}
		else {
			nota2 = nota;
		}
	}
	
	public void setFaltas(int faltas) {
		if (faltas < 0) {
			System.out.println("Valor não pode ser negativo");
		}
		this.faltas = faltas;
	}
	
	public double getNota1() {
		return nota1;
	}
	
	public double getNota2() {
		return nota2;
	}
	
	public int getFaltas() {
		return faltas;
	}
	
	public void resultado() {
		double media = (nota1 + nota2)/2;
		System.out.println("Média: " + media);
		
		System.out.println(faltas + " faltas");
		if (faltas > 7) {
			System.out.println("Reprovado por faltas");
		}
		else if (media < 4) {
			System.out.println("Reprovado");
		}
		else if (media < 7) {
			System.out.println("Exame final");
		}
		else {
			System.out.println("Aprovado");
		}
	}
}
