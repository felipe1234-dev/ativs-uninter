package system.human;

import java.util.Scanner;
import system.controller.Controller;
import system.board.Tabuleiro;

public class Jogador extends Controller  {
	public Jogador(Tabuleiro board) {
		super(board);
	}
	
	@Override
	public void makeMove() {
		@SuppressWarnings("resource")
		Scanner teclado = new Scanner(System.in);
		boolean control = true;
		
		System.out.println();
		System.out.println("     Sua vez!");
		
		while (control) {
			System.out.printf("y: ");
			int row = teclado.nextInt();
			
			System.out.printf("x: ");
			int col = teclado.nextInt();
			
			try {
				
				if ((row > 2 || row < 0) || (col > 2 || col < 0)) {
					throw new Exception("Valor de posição fora dos limites");
				}
				else if (board.fields[row][col].text != ' ') {
					throw new Exception("Lugar ocupado");
				}
				else {
					board.makePlay(row, col, board.player);
					control = false;
				}
				
			}
			catch(Exception e) {
				System.out.println("Aconteceu um problema: " + e.getMessage());
			}
		
		}
	}
	
}
