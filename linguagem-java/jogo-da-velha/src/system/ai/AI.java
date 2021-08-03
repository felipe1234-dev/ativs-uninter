package system.ai;

import system.board.Field;
import java.util.Random;

/* Toda a seguinte interface tenta implementar
 * fun��es que procuram simular uma intelig�ncia
 * artificial. O c�digo foi pegado e adaptado do
 * site GeeksForGeeks, o algoritmo � bastante co-
 * nhecido, seu nome � "minimax".
 * Bom, n�o � perfeito, � poss�vel que eu tenha 
 * feito alguma coisa errado, mas, valeu muito a 
 * experi�ncia e curiosidade :)
 */
public interface AI {
	
	/* @method noMovesLeft: Checa se n�o h� movimentos sobrando no tabuleiro;
	 * @method evaluate: A fun��o (m�todo) vai sempre retornar +10 se 
     * houver vit�ria por parte do computador;
	 * @method minimax: Esta � a fun��o minimax. Considera todos
     * os caminhos poss�veis que o jogo pode seguir,
     * retornando um escore associado ao objetivo de
     * vencer ou n�o perder;
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
    	
    	/* Ent�o, l� na outra fun��o, houve um movimento.
         * Imediatamente ap�s esse movimento, a fun��o 
         * minimaxfoi chamada que, por sua vez, a segun-
         * da coisa que faz � chamar o m�todo "evaluate" 
         * que, basicamente, checa se no estado atual 
         * do tabuleiro houve vit�ria decorrente dessa 
         * jogada/movimento, retornando uma pontua��o de-
         * pendendo do caso. 
         */
    	
    	int score = evaluate(board, computer, human);

    	/* Se Maximizer ganhou o jogo,
         * retorne sua pontua��o avaliada.
         * Maximizer � o computador.
         */
        if (score == 10) {
        	return score;
        }
        /* Se o Minimizer ganhou o jogo,
         * retorne sua pontua��o avaliada.
         * Minimizer � voc�, o advers�rio
         * do computador.
         */
        else if (score == -10) {
            return score;
        }
        /* Se n�o houver mais movimentos e
         * nenhum vencedor, ent�o � um empate.
         */
        else if (noMovesLeft(board)) {
            return 0;
        }

        int best;
        
        /* Se � o movimento do maximizer.
         * Ou seja, se � a vez do compu-
         * tador de jogar... 
         */
        if (isMax) {
        	/* Tamb�m h� uma chance vari�vel,
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
                         * escores para a fun��o Math.max() obter o maior. */
                        best = Math.max(best, minimax(board, depth - 1, !isMax, computer, human) );

                        // Desfaz a jogada/movimento
                        board[row][col].text = ' ';
                    }
                    
                }
            }
        }

        /* Se � o movimento do maximizer.
         * Ou seja, se � a vez do joga-
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
                         * escores para a fun��o Math.max() obter o menor. */
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

                // Checa se o campo est� vazio.
                if (board[row][col].text == ' ') {
                	
                    // Faz o movimento.
                    board[row][col].text = computer;
                    /* "computer" vem l� do construtor controller,
                     * se o jogador est� usando a bolinha, computer = 'O',
                     * caso contr�rio, computer = 'X'.
                     */
                    
                   
                    int moveScore = minimax(board, depth, false, computer, human);

                    /* Desfazer o movimento para n�o alterar o tabuleiro real.
                     * S� alteraremos quando houver uma decis�o.
                     */
                    board[row][col].text = ' ';
                    
                    
                    /* Se o valor do movimento atual � maior
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
