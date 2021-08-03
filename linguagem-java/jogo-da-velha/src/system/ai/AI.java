package system.ai;

import system.board.Field;
import java.util.Random;

/* Toda a seguinte interface tenta implementar
 * funções que procuram simular uma inteligência
 * artificial. O código foi pegado e adaptado do
 * site GeeksForGeeks, o algoritmo é bastante co-
 * nhecido, seu nome é "minimax".
 * Bom, não é perfeito, é possível que eu tenha 
 * feito alguma coisa errado, mas, valeu muito a 
 * experiência e curiosidade :)
 */
public interface AI {
	
	/* @method noMovesLeft: Checa se não há movimentos sobrando no tabuleiro;
	 * @method evaluate: A função (método) vai sempre retornar +10 se 
     * houver vitória por parte do computador;
	 * @method minimax: Esta é a função minimax. Considera todos
     * os caminhos possíveis que o jogo pode seguir,
     * retornando um escore associado ao objetivo de
     * vencer ou não perder;
     * @method findBestMove: encontra o melhor movimento para a jogada.
	 */
	
	static class Move {
        int row, col;
    };
    
    default Boolean noMovesLeft(Field[][] board) {

        for (int row = 0; row < 3; row++) {

            for (int col = 0; col < 3; col++) {

                if (board[row][col].text == ' ') {
                    return false;
                }

            }

        }
        
        return true;
    }

    default int evaluate(Field[][] board, char computer, char human) {
        
        for (int row = 0; row < 3; row++) {

            if (
                board[row][0].text == board[row][1].text && 
                board[row][1].text == board[row][2].text
            ) {
                
                if (board[row][0].text == computer) {
                    return +10;
                } else if (board[row][0].text == human) {
                    return -10;
                }

            }
        }

       
        for (int col = 0; col < 3; col++) {
            if (
                board[0][col].text == board[1][col].text && 
                board[1][col].text == board[2][col].text
            ) {

                if (board[0][col].text == computer) {
                    return +10;
                } else if (board[0][col].text == human) {
                    return -10;
                }

            }
        }

        
        if (
            board[0][0].text == board[1][1].text && 
            board[1][1].text == board[2][2].text
        ) {
            
            if (board[0][0].text == computer) {
                return +10;
            } else if (board[0][0].text == human) {
                return -10;
            }

        }

        if (
            board[0][2].text == board[1][1].text && 
            board[1][1].text == board[2][0].text
        ) {
            
            if (board[0][2].text == computer) {
                return +10;
            } else if (board[0][2].text == human) {
                return -10;
            }

        }

        return 0;
    }

    default int minimax(Field[][] board, int depth, Boolean isMax, char computer, char human) {
        
    	if (depth <= 0) {
    		return 0;
    	}
    	
    	/* Então, lá na outra função, houve um movimento.
         * Imediatamente após esse movimento, a função 
         * minimaxfoi chamada que, por sua vez, a segun-
         * da coisa que faz é chamar o método "evaluate" 
         * que, basicamente, checa se no estado atual 
         * do tabuleiro houve vitória decorrente dessa 
         * jogada/movimento, retornando uma pontuação de-
         * pendendo do caso. 
         */
    	
    	int score = evaluate(board, computer, human);

    	/* Se Maximizer ganhou o jogo,
         * retorne sua pontuação avaliada.
         * Maximizer é o computador.
         */
        if (score == 10) {
        	return score;
        }
        /* Se o Minimizer ganhou o jogo,
         * retorne sua pontuação avaliada.
         * Minimizer é você, o adversário
         * do computador.
         */
        else if (score == -10) {
            return score;
        }
        /* Se não houver mais movimentos e
         * nenhum vencedor, então é um empate.
         */
        else if (noMovesLeft(board)) {
            return 0;
        }

        int best;
        
        /* Se é o movimento do maximizer.
         * Ou seja, se é a vez do compu-
         * tador de jogar... 
         */
        if (isMax) {
        	/* Também há uma chance variável,
             * de acordo com a skill, de ele 
             * escolher o movimento errado (minimizer
             * no lugar de maximizer), comprome-
             * tendo sua jogada
             */
        	
            best = -1000;

            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                	
                    if (board[row][col].text == ' ') {
                    	
                        // Fazer a jogada
                        board[row][col].text = computer;

                        /* Chama o minimax recursivamente, retornando 
                         * escores para a função Math.max() obter o maior. */
                        best = Math.max(best, minimax(board, depth - 1, !isMax, computer, human) );

                        // Desfaz a jogada/movimento
                        board[row][col].text = ' ';
                    }
                    
                }
            }
        }

        /* Se é o movimento do maximizer.
         * Ou seja, se é a vez do joga-
         * dor humano de jogar... 
         */
        else {
            best = 1000;

            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                	
                    if (board[row][col].text == ' ') {
                    	// Fazer a jogada
                        board[row][col].text = human;

                        /* Chama o minimax recursivamente, retornando 
                         * escores para a função Math.max() obter o menor. */
                        best = Math.min(best, minimax(board, depth - 1, !isMax, computer, human) );

                        // Desfaz a jogada/movimento
                        board[row][col].text = ' ';
                    }
                    
                }
            }
        
        }
        
        return best;
    }
    
    default Move findBestMove(Field[][] board, int depth, char computer, char human) {
		int bestScore = -1000;
        Move bestMove = new Move();
        bestMove.row  = -1;
        bestMove.col  = -1;

       
        for (int row = 0; row < 3; row++) {

            for (int col = 0; col < 3; col++) {

                // Checa se o campo está vazio.
                if (board[row][col].text == ' ') {
                	
                    // Faz o movimento.
                    board[row][col].text = computer;
                    /* "computer" vem lá do construtor controller,
                     * se o jogador está usando a bolinha, computer = 'O',
                     * caso contrário, computer = 'X'.
                     */
                    
                   
                    int moveScore = minimax(board, depth, false, computer, human);

                    /* Desfazer o movimento para não alterar o tabuleiro real.
                     * Só alteraremos quando houver uma decisão.
                     */
                    board[row][col].text = ' ';
                    
                    
                    /* Se o valor do movimento atual é maior
                     * do que o melhor valor, atualize best{*}.
                     * */
                    if (moveScore > bestScore) {
                        bestMove.row = row;
                        bestMove.col = col;
                        bestScore    = moveScore;
                    }
                    
                }

            }
        }

        return bestMove;
	}
}
