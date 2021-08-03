package system.board;

import system.enums.State;
import system.enums.Level;

import java.util.Scanner;

import system.ai.Computador;
import system.ai.LvlEasy;
import system.ai.LvlNormal;
import system.ai.LvlHard;
import system.ai.CustomLvl;
import system.human.Jogador;
import system.enums.Player;

public class Tabuleiro implements UsefulMethods {
	
	/* @attribute fields: os campos no tabuleiro, no total são 9, podem ser manipu-
	 * lados para por um X, O ou ' ' (caractere de espaço) como chars;
	 * 
	 * @class matches: tem os atributos:
	 * 1. @attribute human: conta as vitórias do jogador humano;
	 * 2. @attribute computer: conta as vitórias do computador;
	 * 3. @attribute ties: conta a quantidade de empates.
	 * 
	 * @attribute turn: Controla de quem é a vez de jogar;
	 * 
	 * @attribute winner: Grava o jogador vencedor;
	 * 
	 * @attribute gameState: Determina qual é o estado do jogo: JOGANDO (PLAYING), 
	 * EMPATE (TIE) e VITÓRIA (WIN);
	 * 
	 * @attribute occupiedFields: Conta a quantidade de lugares ocupados no tabu-
	 * leiro, quando esse número atingir 9 (todo o tabuleiro) e nenhum outro esta-
	 * do for verdadeiro, o jogo empatou; 
	 * 
	 * @attribute human, computer: Uma variável que conterá um objeto da classe 
	 * "jogador" e "computador", respectivamente; 
	 * 
	 * @attribute player, opponent: player é o jogador humano e opponent é o compu-
	 * tador. Cada um contém um char representando a "marca"/"peça" de jogo: X ou O. 
	 */
	
	// ATRIBUTOS
	public Field[][] fields = new Field[3][3];
	static class Matches {
		int human    = 0;
		int computer = 0;
		int ties     = 0;
	}
	private Matches matches = new Matches();
	private Player turn;
	public Player winner;
	public State gameState = State.PLAYING;
	private int occupiedFields = 0;
	public Jogador human = new Jogador(this);
	public Computador computer;

	public char player, opponent;
	// FIM-ATRIBUTOS
	
	// CONSTRUTORES
	public Tabuleiro(Player firstMove, Level lvl) {
		super();
		this.turn 	  = firstMove;
		this.player   = firstMove == Player.HUMAN   ? 'X' : 'O';
		this.opponent = firstMove == Player.COMPUTER? 'X' : 'O';

		switch(lvl) {
			case EASY:
				this.computer = new LvlEasy(this);
				break;
			case NORMAL:
				this.computer = new LvlNormal(this);
				break;
			case HARD:
				this.computer = new LvlHard(this);
				break;
		}
	}
	
	public Tabuleiro(Player firstMove, int predict) {
		super();
		this.turn 	  = firstMove;
		this.player   = firstMove == Player.HUMAN   ? 'X' : 'O';
		this.opponent = firstMove == Player.COMPUTER? 'X' : 'O';
		this.computer = new CustomLvl(this, predict);
	}
	// FIM-CONSTRUTORES
	
	// MÉTODOS PÚBLICOS 
	public void startGame() {
		startFields();
		
		while (!endGame()) {
			System.out.println(" Você " + matches.human + " vs " + matches.computer + " Computador");
			System.out.println("      " + matches.ties + " empates");
			System.out.println();
			
			drawBoard();
			
			switch (turn) {
				case HUMAN:
					human.makeMove();
					break;
				case COMPUTER:
					computer.makeMove();
					break;
			}

			turn = getOpponentFor(turn);
			cleanScreen();
		}
		
		endMsg();
	}
	
 	public void makePlay(int y, int x, char gamePiece) {
 		fields[y][x].text = gamePiece;
 		occupiedFields++;
		
		if (occupiedFields == 9) {
			gameState = State.TIE;
			matches.ties++;
		}
		else if (isWinner(fields, gamePiece)) {
			gameState = State.WIN;
			winner 	  = gamePiece == player? Player.HUMAN : Player.COMPUTER; 
			
			if (gamePiece == player) {
				matches.human++;
			}
			else {
				matches.computer++;
			}
			
		}
	}	
	
	private void startFields() {
		
		for (int y = 0; y < fields.length; y++) {
			
			for (int x = 0; x < fields[y].length; x++) {
				fields[y][x] = new Field();
			}
			
	    }
		
	}
	
	private boolean endGame() {
		return !(gameState == State.PLAYING);
	}
	
	private void endMsg() {
		drawBoard();
		
		switch (gameState) {
		
			case WIN:
				System.out.println();
				
				switch(winner) {
					case HUMAN:
						System.out.println("     Você venceu! :)"); 
						break;
					case COMPUTER:
						System.out.println("     Você perdeu! :("); 
						break;
				}
				break;
				
			case TIE:
				System.out.println("     Empate!");
				break;
		}
		
		try (Scanner teclado = new Scanner(System.in)) {
			System.out.println();
			System.out.println("Quer jogar novamente? [s/n]");
			String res = teclado.next();
			
			switch(res) {
				case "s":
					reconfigure();
					break;
				default:
					break;
			}
		}
		
	}
	
	private void reconfigure() {
		try (Scanner teclado = new Scanner(System.in)) {
			System.out.println("Quer começar jogando? [s/n]");
			String res = teclado.next();
			
			switch(res) {
				case "s":
					turn = Player.HUMAN;
					break;
				default:
					turn = Player.COMPUTER;
					break;
			}

			restartVariables();
			
			System.out.println("Qual o nível da IA que você quer?");
			System.out.println("FÁCIL [0], NORMAL [1], DIFÍCIL [2], CUSTOMIZÁVEL [3]");
			res = teclado.next();
			
			switch(res) {
				case "0":
					this.computer = new LvlEasy(this);
					break;
				case "1":
					this.computer = new LvlNormal(this);
					break;
				case "2":
					this.computer = new LvlHard(this);
					break;
				case "3":
					System.out.println();
					System.out.println("Selecione um nível de habilidade para a AI");
					System.out.println("Para referência, FÁCIL = 1, NORMAL = 3 e DIFÍCIL = 5");
					int predict = teclado.nextInt();
					
					this.computer = new CustomLvl(this, predict);
					break;
				default:
					this.computer = new LvlNormal(this);
					break;
			}
			
			startGame();
		}
	}
	
	private void restartVariables() {
		gameState = State.PLAYING;
		occupiedFields = 0;
		player   = turn == Player.HUMAN   ? 'X' : 'O';
		opponent = turn == Player.COMPUTER? 'X' : 'O';
	}
	
	private void drawBoard() {
		char[][] b = new char[3][3]; 
		Field aux;
		
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				aux = fields[y][x];
				b[y][x] = aux.text;
			}
		}
		
		System.out.printf("    0.    1.    2.  x\n");
		System.out.printf("       |     |       \n");
		System.out.printf("0.  %s  |  %s  |  %s \n", b[0][0], b[0][1], b[0][2]);
		System.out.printf("  _____|_____|_____  \n");
		System.out.printf("       |     |       \n");
		System.out.printf("1.  %s  |  %s  |  %s \n", b[1][0], b[1][1], b[1][2]);
		System.out.printf("  _____|_____|_____  \n");
		System.out.printf("       |     |       \n");
		System.out.printf("2.  %s  |  %s  |  %s \n", b[2][0], b[2][1], b[2][2]);
		System.out.printf("       |     |       \n");
		System.out.printf("y\n");
		
	}
	// FIM-MÉTODOS PRIVADOS
}