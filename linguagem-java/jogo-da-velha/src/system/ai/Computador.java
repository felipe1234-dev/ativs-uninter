package system.ai;

import system.board.Tabuleiro;
import system.controller.Controller;

public abstract class Computador extends Controller implements AI {
	
	public Computador(Tabuleiro board) {
		super(board);
	}

	public abstract void makeMove();
}
