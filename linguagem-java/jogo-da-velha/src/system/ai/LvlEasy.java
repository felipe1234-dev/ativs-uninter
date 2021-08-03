package system.ai;

import system.board.Tabuleiro;

public class LvlEasy extends Computador {
	// @predict: O computador poderá prever @predict possibilidades
	private final int predict = 1;
	
	public LvlEasy(Tabuleiro board) {
		super(board);
	}

	@Override
	public void makeMove() {
		
		Move bestMove = findBestMove(board.fields, predict, computer, human);
		board.makePlay(bestMove.row, bestMove.col, computer);
	}

}
