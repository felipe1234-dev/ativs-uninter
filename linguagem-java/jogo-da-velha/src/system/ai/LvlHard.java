package system.ai;

import system.board.Tabuleiro;

public class LvlHard extends Computador {
	// @predict: O computador poderá prever @predict possibilidades
	private final int predict = 5;
	
	public LvlHard(Tabuleiro board) {
		super(board);
	}

	@Override
	public void makeMove() {
		
		Move bestMove = findBestMove(board.fields, predict, computer, human);
		board.makePlay(bestMove.row, bestMove.col, computer);
	}
}
