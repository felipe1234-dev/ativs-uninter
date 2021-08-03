package system.board;

import system.enums.Player;

public interface UsefulMethods {
	
	default Player getOpponentFor(Player player) {
		switch (player) {
			case HUMAN:
				return Player.COMPUTER;
			default:
				return Player.HUMAN;
		}
	}
	
	default void cleanScreen() {
		for (int i = 0; i < 100; ++i)  
            System.out.println();
	}
	
	default boolean isWinner(Field[][] board, char gamePiece) {
		return (
			rows(board, gamePiece) || columns(board, gamePiece) || 
			diagonal(board, gamePiece) || reverseDiagonal(board, gamePiece)
		);
	}
	
	default boolean rows(Field[][] board, char gamePiece) {
		int sum = 0;

		for (int row = 0; row < 3; row++) {
			
			for (int col = 0; col < 3; col++) {
				sum += board[row][col].text == gamePiece? 1 : 0;
			}

			if(sum == 3) {
				return true;
			}
			else {
				sum = 0;
			}
		}
		
		return false;
	}
	
	default boolean columns(Field[][] board, char gamePiece) {
		int sum = 0;
		
		for (int col = 0; col < 3; col++) {
			
			for (int row = 0; row < 3; row++) {
				sum += board[row][col].text == gamePiece? 1 : 0;
			}
			
			if (sum == 3) {
				return true;
			}
			else {
				sum = 0;
			}
		}
		
		return false;
		
	}
	
	default boolean diagonal(Field[][] board, char gamePiece) {
		int sum = 0;
		
		for (int row = 0, col = 0; row < 3 && col < 3; row++, col++) {
			sum += board[row][col].text == gamePiece? 1 : 0;
		}
		
		return sum == 3;
	}
	
	default boolean reverseDiagonal(Field[][] board, char gamePiece) {
		int sum = 0;
		
		for (int row = 0, col = 2; row < 3 && col > -1; row++, col--) {
			sum += board[row][col].text == gamePiece? 1 : 0;
		}
		
		return sum == 3;
	}
	
}
