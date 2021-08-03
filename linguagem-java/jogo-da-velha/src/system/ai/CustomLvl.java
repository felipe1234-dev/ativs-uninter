package system.ai;

import system.board.Tabuleiro;

public class CustomLvl extends Computador {
	private int predict = 0;
	
	public CustomLvl(Tabuleiro board, int predict) {
		super(board);
		this.predict = predict;
	}
	
	@Override
	public void makeMove() {
		Move bestMove = findBestMove(board.fields, predict, computer, human);
		board.makePlay(bestMove.row, bestMove.col, computer);
	}
}
