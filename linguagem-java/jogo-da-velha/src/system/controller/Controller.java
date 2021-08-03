package system.controller;

import system.board.Tabuleiro;

public abstract class Controller {
	protected Tabuleiro board;
	protected char human, computer;
	
	public Controller(Tabuleiro board) {
		super();
		this.board    = board;
		this.human    = board.player;
		this.computer = board.opponent;
	}
	
	public abstract void makeMove();
}
