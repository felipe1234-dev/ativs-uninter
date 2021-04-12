#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musica {
    char nome[50];
    char autor[50]; // artista solo ou banda
    float duracao_da_faixa; // unidade em minutos
    struct Musica* prox;
    struct Musica* antr; // anterior
};

typedef struct Musica Musica;

void listarMusicas(Musica *head);
int contarMusicas(Musica *head, int *tamanho);
void iniciarInsercao(Musica *head, int *pos, Musica *novoElemento);
void inserir(Musica *head, Musica *novoElemento, int pos, int tamanho);

int main()
{
    // ALOCAÇÃO NA MEMÓRIA
    Musica* head     = (Musica*) malloc(sizeof(Musica));
    Musica* segunda  = (Musica*) malloc(sizeof(Musica));
    Musica* terceira = (Musica*) malloc(sizeof(Musica));
    // FIM ALOCAÇÃO NA MEMÓRIA
    
    
    // INICIALIZAÇÃO DE 3 MÚSICAS (para começar)
    strcpy(head->nome      , "Sing for the Moment");
    strcpy(head->autor     , "Eminem");
    head->duracao_da_faixa = 5.43; // 5 minutos e 26 segundos.
    head->prox             = segunda;
    head->antr             = terceira;
    
    strcpy(segunda->nome      , "King and Lionheart");
    strcpy(segunda->autor     , "Of Monsters And Men");
    segunda->duracao_da_faixa = 4.583; // 4 minutos e 35 segundos.
    segunda->prox             = terceira;
    segunda->antr             = head;
    
    strcpy(terceira->nome      , "Pra Você Guardei O Amor");
    strcpy(terceira->autor     , "Nando Reis");
    terceira->duracao_da_faixa = 5.716; // 5 minutos e 43 segundos.
    terceira->prox             = head;
    terceira->antr             = segunda;
    // FIM INICIALIZAÇÃO DE MÚSICAS
  
    
    // Conterá a opção escolhida pelo usuário.
    int decisao;
    
    printf("PLAYER DE MÚSICA");
    printf("\n\n");
    
    
    // LOOPING INFINITO
    for (;;) {
        printf("Digite: \n");
        
        printf("1 - para inserir nova música\n");
        printf("2 - para listar todas as músicas\n");
        printf("3 - para encerrar\n");
        
        printf("Decisão: ");
        scanf("%d", &decisao);
        
        // "3 - para encerrar".
        if (decisao == 3)
            break;
            // break quebra o loop e vai direto 
            // ao return do main onde se finaliza 
            // o programa.

        // "2 - para listar todas as músicas".       
        if (decisao == 2)
            listarMusicas(head);
        
        // "1 - para inserir nova música".
        if (decisao == 1) {
            
            // Posição de onde o usuário quer inserir, e o tamanho 
            // da lista atual, respectivamente.
            int pos, tamanho;
            
            system("clear");
            
            // REGRAS DE ESCOLHA DE POSIÇÃO
            contarMusicas(head, &tamanho);
            printf("Sua playlist possui atualmente %d músicas\n\n", tamanho);
            printf("Insira uma posição entre 1 (ou igual a 1) e %d (ou igual a %d)\n", tamanho, tamanho);
            printf("Qualquer número abaixo de 1 será interpretado como inserção no\n");
            printf("início e acima de %d será interpretado como inserção no final\n\n", tamanho);
            // FIM REGRAS
            
            
            // Alocando o novo elemento (a nova música) na memória.
            Musica* novoElemento = (Musica*) malloc(sizeof(Musica));
            
            // Inicia os chats de inserção, onde se pergunta dados 
            // sobre a nova música antes de inserir e grava-os no
            // novoElemento já alocado, assim como a posição onde 
            // o usuário quer inseri-lo.
            iniciarInsercao(head, &pos, novoElemento);
            
            // Esta função é capaz de inserir no início, meio e fim.
            // Fazendo desnecessária a criação de funções específicas
            // como ministrado nas aulas.
            inserir(head, novoElemento, pos, tamanho);
            
            // Ela apenas não é capaz de alterar o head globalmente,
            // quando houver inserção no início.
            
            // Este if vai verificar se o usuário escolheu inserção
            // no início e alterará o head globalmente.
            // Se o valor de pos for menor ou igual a 1, conforme
            // as regras explicadas, significa que o usuário es-
            // colheu inserção no início.
            if (pos <= 1) 
               // PASSO 6 (CASO SE ESCOLHA INSERIR NO INÍCIO)
               /*
                 ANTES:
                 antrAoElVrd     novoElemento  elementoVarredura   próximo 
                     |               |               |               | 
                     |               |               |               |   
                 +---+---+       +---+---+       +---+---+       +---+---+ 
                 | # | #<----------O | #<----------O | #<----------O | # |
                 | # | O----------># | O----------># | O----------># | # |
                 +---+---+       +---+---+       +---+---+       +---+---+ 
                                           _____ 
                                          |     |
                                          |     |
                                       ___|     |___
                                       \           /
                                         \       /
                                           \   /
                                             V
                 DEPOIS:
                 antrAoElVrd        head      elementoVarredura   próximo 
                     |               |               |               | 
                     |               |               |               | 
                 +---+---+       +---+---+       +---+---+       +---+---+ 
                 | # | #<----------O | #<----------O | #<----------O | # |
                 | # | O----------># | O----------># | #----------># | # |
                 +---+---+       +---+---+       +---+---+       +---+---+ 
               */
               // CÓDIGO: 
               head = novoElemento;
               // FIM PASSO 6
        }
        
        system("clear");
    }
    // FIM LOOPING INFINITO
    
    
    return 0;
}

void listarMusicas(Musica *head) {
    system("clear");
    
    int i = 1;
    Musica* elementoVarredura = head;
    
    printf("LISTA DE MÚSICAS \n\n");
    do {
        printf("%d - %s - por %s \n",  i, elementoVarredura->nome, elementoVarredura->autor);
        printf("Duração: %.2f minutos\n\n", elementoVarredura->duracao_da_faixa);
        elementoVarredura = elementoVarredura->prox; 
        i++;
    } while (elementoVarredura != head);
    
    char c;
    printf("\nPressione qualquer tecla para voltar...\n");
    scanf(" %[^\n]", &c);
}

int contarMusicas(Musica *head, int *tamanho) {
    *tamanho = 0;
    Musica* elementoVarredura = head;
    
    do {
        elementoVarredura = elementoVarredura->prox;
        *tamanho = *tamanho + 1;
    } while (elementoVarredura != head);
    
}

void iniciarInsercao(Musica *head, int *pos, Musica *novoElemento) {
    printf("Posição: ");
    scanf("%d", pos);
    printf("\n\n");
    
    printf("Nome da música: ");
    scanf("%s", novoElemento->nome);
    
    printf("Nome da banda/do artista: ");
    scanf("%s", novoElemento->autor);
    
    printf("Duração da faixa (em minutos): ");
    scanf("%f", &novoElemento->duracao_da_faixa);
}

void inserir(Musica *head, Musica *novoElemento, int pos, int tamanho) {
    int i = 1;
    Musica* elementoVarredura = head;
    
    // Lembre-se que valores acima do tamanho da lista 
    // ou abaixos de 1 são considerados, temos que tratar
    // essas possibilidades para não dar erro no código
    // posteriormente.
    pos = (pos > tamanho)? tamanho : (pos < 1)? 1 : pos; 
    
    do {
        if (i >= pos) 
            break;
        elementoVarredura = elementoVarredura->prox; 
        i++;
    } while (1);
            
    
    
    // ESTADO INICIAL
    /*
           anterior     elementoVarredura   próximo 
               |               |               | 
               |               |               | 
           +---+---+       +---+---+       +---+---+ 
    <-ANTR | # | #<----------O | #<----------O | # |   
           | # | O----------># | O----------># | # | PROX->
           +---+---+       +---+---+       +---+---+ 
    */
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 1
    /*
          antrAoElVrd   elementoVarredura   próximo 
               |               |               | 
               |               |               | 
           +---+---+       +---+---+       +---+---+ 
           | # | #<----------O | #<----------O | # |   
           | # | O----------># | O----------># | # | 
           +---+---+       +---+---+       +---+---+ 
    */
    // CÓDIGO:
    Musica* antrAoElVrd = elementoVarredura->antr;
    // FIM PASSO 1
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 2
    /*
       antrAoElVrd   elementoVarredura   próximo 
            |               |               | 
            |               |               | 
        +---+---+       +---+---+       +---+---+ 
        | # | #<----------O | #<----------O | # |
        | # | O------   | # | O----------># | # |
        +---+---+    |  +---+---+       +---+---+ 
                     |
                     |    +---+---+
                     |    | # | # | _________ novoElemento
                      -----># | # |
                          +---+---+ 
    */
    // CÓDIGO:
    antrAoElVrd->prox = novoElemento;
    // FIM PASSO 2
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 3
    /*
       antrAoElVrd                        elementoVarredura   próximo 
            |                                    |               | 
            |                                    |               |  
        +---+---+                            +---+---+       +---+---+ 
        | # | #<-------------------------------O | #<----------O | # |
        | # | O--------                -------># | O----------># | # |
        +---+---+      |              |      +---+---+       +---+---+ 
                       |   +---+---+  |
                       |   | # | # |  |
                        ----># | O----
                           +---+---+ 
                              |
                              |
                            novoElemento
    */
    // CÓDIGO:
    novoElemento->prox = elementoVarredura;
    // FIM PASSO 3
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 4
    /*
       antrAoElVrd                        elementoVarredura   próximo 
            |                                    |               | 
            |                                    |               |   
        +---+---+                            +---+---+       +---+---+ 
        | # | # |                      --------O | #<----------O | # |
        | # | O--------               |    ---># | O----------># | # |
        +---+---+      |              |   |  +---+---+       +---+---+ 
                       |   +---+---+  |   |
                       |   | # | #<---    |
                        ----># | O--------
                           +---+---+ 
                              |
                              |
                            novoElemento
    */
    // CÓDIGO:
    elementoVarredura->antr = novoElemento;
    // FIM PASSO 4
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 5
    /*
       antrAoElVrd                        elementoVarredura   próximo 
            |                                    |               | 
            |                                    |               |   
        +---+---+                            +---+---+       +---+---+ 
        | # | #<-----                  --------O | #<----------O | # |
        | # | O---   |                |    ---># | O----------># | # |
        +---+---+ |  |                |   |  +---+---+       +---+---+ 
                  |  |     +---+---+  |   |
                  |   -------O | #<---    |
                   ---------># | O--------
                           +---+---+ 
                              |
                              |
                            novoElemento
    */
    // CÓDIGO:
    novoElemento->antr = antrAoElVrd;
    // FIM PASSO 5
    
    /*-----------------------------------------------------------------*/
    
    // RESULTADO FINAL
    /*
       antrAoElVrd     novoElemento  elementoVarredura   próximo 
            |               |               |               | 
            |               |               |               |   
        +---+---+       +---+---+       +---+---+       +---+---+ 
        | # | #<----------O | #<----------O | #<----------O | # |
        | # | O----------># | O----------># | O----------># | # |
        +---+---+       +---+---+       +---+---+       +---+---+ 
    */
}
