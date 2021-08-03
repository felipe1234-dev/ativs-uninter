package main;

import system.board.Tabuleiro;
import system.enums.Level;
import system.enums.Player;
import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		try (Scanner teclado = new Scanner(System.in)) {
			
			Player firstPlayer;
			Level AILevel;
			int predict = 0;

			System.out.println("Quer começar jogando? [s/n]");
			String res = teclado.next();
			
			switch(res) {
				case "s":
					firstPlayer = Player.HUMAN;
					break;
				default:
					firstPlayer = Player.COMPUTER;
					break;
			}
			
			System.out.println("Qual o nível da IA que você quer?");
			System.out.println("FÁCIL [0], NORMAL [1], DIFÍCIL [2], CUSTOMIZÁVEL [3]");
			res = teclado.next();
				
			switch(res) {
				case "0":
					AILevel = Level.EASY;
					break;
				case "1":
					AILevel = Level.NORMAL;
					break;
				case "2":
					AILevel = Level.HARD;
					break;
				case "3":
					AILevel = Level.CUSTOM;
					
					System.out.println();
					System.out.println("Selecione um nível de habilidade para a AI");
					System.out.println("Para referência, FÁCIL = 1, NORMAL = 3 e DIFÍCIL = 5");
					predict = teclado.nextInt();
					
					break;
				default:
					AILevel = Level.NORMAL;
					break;
						
			}
			
			Tabuleiro game = null;
			
			switch(AILevel) {
				case CUSTOM: 
					game = new Tabuleiro(firstPlayer, predict);
					break;
				default:
					game = new Tabuleiro(firstPlayer, AILevel);
					break;
			}
			
			game.startGame();
			
		}
		
	}

}
