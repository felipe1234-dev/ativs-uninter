// nossa.. vai ser cansativo comentar este
#include <stdio.h>

#include <stdlib.h>
// para incluir os acentos e os símbolos unicode das peças de xadrez
#include <locale.h>

// definindo constantes, linhas se referem à extensão vertical (8)
// e colunas à extensão horizontal (também 8)
#define LINHAS 8
#define COLUNAS 8

// vamos enumerar nossas peças, conforme mostrado no exercício
enum pieces {
    peao = 1, cavalo, torre, bispo, rei, rainha
};

// ao lado esquerdo do tabuleiro mosra-se as letras de A até H
char retornarLetra(int pos);

// esta função monta o tabuleiro atualizando-o
void montarTabuleiro(int tabuleiro[8][8], int r);

// o nome já diz
void montarMenu();

// "processar escolha", toda vez que um número do menu for enviado,
// esta função é chamada, também acrescenta elementos à matriz, por isso
// precisa de tabuleiro[8][8]
void procEscolha(int tabuleiro[8][8], int r);

// conta as peças uma de cada vez (haverá um loop que chamará esta
// função várias vezes)
int contarPeca(int tabuleiro[8][8], int p);

int main() {
    // configurando o local..
    setlocale(LC_ALL, "");

    // colocando as peças iniciais no tabuleiro como solicitado
    int tabuleiro[8][8] = {
        {1, 3, 0, 5, 4, 0, 2, 1},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 6, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 4, 0, 0, 1, 0},
        {0, 0, 3, 1, 0, 0, 1, 1},
        {1, 0, 6, 6, 0, 0, 1, 0},
        {1, 0, 5, 0, 1, 1, 0, 6}
    };

    // chama a função de montagem
    montarTabuleiro(tabuleiro, 3);
    return 0;
}

char retornarLetra(int pos) {
    switch (pos) {
        case 1:
            return 'A';
        case 2:
            return 'B';
        case 3:
            return 'C';
        case 4:
            return 'D';
        case 5:
            return 'E';
        case 6:
            return 'F';
        case 7:
            return 'G';
        case 8:
            return 'H';
    }
}

void montarTabuleiro(int tabuleiro[8][8], int r) {
    // fiz este vetor de chars para conter os unicodes de espaço em branco
    // por quê? esses espaços têm uma largura diferente que me ajudou a alinha os componentes do tabuleiro precisamente
    char whitespace[] = "\u2006\u2006\u2006\u2006\u2006\u2006\u2006";

    // toda vez que esta função for chamada, ela limpa a tela e remonta o tabuleiro
    // em sua forma atualizada, usei "clear" e não "cls" porque estava usando outro compilador
    // que aceitava unicodes, que não é do Windows, mas sim do Linux
    system("clear");

    printf("%s%s\u2006\u2006", whitespace, whitespace);

    // enumera as colunas, o printf anterior apenas deu um espaço
    // para alinhar
    for (int coluna = 0; coluna < COLUNAS; coluna++) {
        printf("(#%d) ", coluna + 1);
    }

    printf("\n");

    // aqui vamos criar o tabuleiro propriamente dito
    for (int linha = 0; linha < LINHAS; linha++) {
        // este printf contém uma função que pega o número da linha e retorna uma
        // letra do alfabeto de mesma ordem, para assim simular tabuleiros de verdade
        printf("(%c) ", retornarLetra(linha + 1));

        for (int coluna = 0; coluna < COLUNAS; coluna++) {
            // aqui pegamos o valor que está na matriz e comparamos com
            // o número gravado nas constantes lá do enum
            switch (tabuleiro[linha][coluna]) {
                // se o valor é igual a peao, que é 1 lá no enum...
                case peao:
                    // printa o unicode do desenho do peao e um pouco de espaço em
                    // branco à direita
                    printf("[\u2659] \u2006");
                    break;
                // se o valor é igual a cavalo, que é 2 lá no enum...
                case cavalo:
                    printf("[\u2658] \u2006");
                    break;
                // etc...
                case torre:
                    printf("[\u2656] \u2006");
                    break;
                case bispo:
                    printf("[\u2657] \u2006");
                    break;
                case rei:
                    printf("[\u2654] \u2006");
                    break;
                case rainha:
                    printf("[\u2655] \u2006");
                    break;
                // default lida com casas na matriz iguais a 0, que significam
                // ausência de peça, logo, espaço em branco
                default:
                    printf("[%s]\u2006 ", whitespace);
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");

    // como a tela vai ser sempre limpada,
    // remonta o menu toda vez, inclusive...
    montarMenu();
    // remonta a "seção" que se abre ao escolher algo do menu,
    // r foi passado como parâmetro e é a escolha que o usuário
    // solicitou no menu, esse r faz a volta por todas as funções
    procEscolha(tabuleiro, r);
}

void montarMenu() {
    printf("Menu\n");
    printf("[1] - Colocar peças no tabuleiro \n");
    printf("[2] - Contar quantidade de cada peça \n");
    printf("[3] - Sair\n");
    printf("[+] - Finalizar programa\n");
}

void procEscolha(int tabuleiro[8][8], int r) {
    int linha, coluna, peca;
    printf("\n");
    switch (r) {
        // se r for a escolha 1...
        // "colocar peças no tabuleiro"
        case 1:
            printf("Digite...\n");
            printf("[1] - Peão [2] - Cavalo [3] - Torre [4] - Bispo\n");
            printf("[5] - Rei [6] - Rainha\n");
            printf("Peça: ");
            // guarda a peça a ser inserida...
            scanf("%d", & peca);
            printf("\n");
            // cria um loop infinito com ";;"
            // truquezinho que aprendi no Stack
            for (;;) {
                printf("Informe a linha: ");
                // guarda a linha em sentido de posição
                // no eixo y
                scanf("%d", & linha);
                printf("Informe a coluna: ");
                // e no eixo x
                scanf("%d", & coluna);
                // verifica se nessas "coordenadas" há alguma peça
                // (linha/coluna-1 porque em matriz e vetores começa-se com 0)
                if (tabuleiro[linha - 1][coluna - 1] != 0) {
                    // se há, informa que há e não se pode colocar aí
                    printf("Atenção: espaço já está ocupado!\n\n");
                    // o loop vai se repetir porque é infinito e não houve break
                } else {
                    // se não há, a coloca no lugar...
                    tabuleiro[linha - 1][coluna - 1] = peca;
                    // coloca escolha como 3, que é o equivalente ao
                    // "sair" do menu
                    r = 3;
                    // usa break para sair do loop
                    break;
                }
            }
            break;
        // se r for a escolha 1...
        // "Contar quantidade de cada peça"
        case 2:
            printf("\n");
            // p é de peça
            // fará um loop onde p possui a "id"
            // de cada peça
            for (int p = 0; p < 7; p++) {
                switch (p) {
                // se p equivale à id do peao declarada lá no enum..
                case peao:
                    // haverá uma mensagem específica para ele
                    printf("Há %d peões no tabuleiro.\n", contarPeca(tabuleiro, p));
                    break;
                // mesma coisa...
                case cavalo:
                    // mesma coisa
                    printf("Há %d cavalos no tabuleiro.\n", contarPeca(tabuleiro, p));
                    break;
                case torre:
                    printf("Há %d torres no tabuleiro.\n", contarPeca(tabuleiro, p));
                    break;
                case bispo:
                    printf("Há %d bispos no tabuleiro.\n", contarPeca(tabuleiro, p));
                    break;
                case rei:
                    printf("Há %d reis no tabuleiro.\n", contarPeca(tabuleiro, p));
                    break;
                case rainha:
                    printf("Há %d rainhas no tabuleiro.\n", contarPeca(tabuleiro, p));
                    break;
                default:
                    printf("Há %d espaços vazios no tabuleiro.", contarPeca(tabuleiro, p));
                    break;
                    // todos usam a função contarPeca para pegar a contagem
                    // que retorna um int com o número de ocorrências da peça
                    // recebe p de peça e o tabuleiro inteiro do jogo como
                    // parâmetros
                }
            }
            printf("\n\n");
            printf("Escolha: ");
            scanf("%d", & r);
            break;
        // 3 é o início padrão do programa e também o equivalente ao botão de sair
        case 3:
            printf("Escolha: ");
            scanf("%d", & r);
            break;
        // qualquer coisa fora da lista finaliza o programa
        default:
            // 0 indica finalização com sucesso
            exit(0);
            break;
    }
    // remonta o tabuleiro, pois ele pode ter sido
    // reatualizado, e para caso r tenha sido
    // alterado e então volte até aqui para ser reprocessado
    montarTabuleiro(tabuleiro, r);
}

int contarPeca(int tabuleiro[8][8], int p) {
    // gravará o número de ocorrências da peça p
    int contagem = 0;
    // passará pelos dois eixos y e x (linha e coluna)
    // vendo todas as posições possíveis
    for (int linha = 0; linha < LINHAS; linha++) {
        for (int coluna = 0; coluna < COLUNAS; coluna++) {
            // se o número de determinada posição
            // equivale ao número da peça p
            if (tabuleiro[linha][coluna] == p) {
                // contagem é somado 1
                contagem++;
            }
        }
    }
    return contagem;
}
