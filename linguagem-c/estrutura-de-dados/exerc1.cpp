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
void inserirInicioFinal(Musica *head, Musica *novoElemento);
void inserirMeio(Musica *head, Musica *novoElemento, int pos);

int main()
{
    // ALOCAÇÃO NA MEMÓRIA
    Musica* head     = (Musica*) malloc(sizeof(Musica));
    Musica* segunda  = (Musica*) malloc(sizeof(Musica));
    Musica* terceira = (Musica*) malloc(sizeof(Musica));
    // FIM ALOCAÇÃO NA MEMÓRIA
    
    
    // INICIALIZAÇÃO DE MÚSICAS
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
            // ao return do main onde finaliza 
            // o programa.

        // "2 - para listar todas as músicas".       
        if (decisao == 2)
            listarMusicas(head);
        
        // "1 - para inserir nova música".
        if (decisao == 1) {
            
            // Posição de onde o usuário quer inserir, e o tamanho 
            // da lista atual, respectivamente.
            int pos, tamanho;
            
            // Alocando o novo elemento (a nova música) na memória.
            Musica* novoElemento = (Musica*) malloc(sizeof(Musica));
            
            system("clear");
    
            contarMusicas(head, &tamanho);
            printf("Sua playlist possui atualmente %d músicas\n\n", tamanho);
            printf("Insira uma posição entre 1 (ou igual a 1) e %d (ou igual a %d)\n", tamanho, tamanho);
            printf("Qualquer número abaixo de 1 será interpretado como inserção no\n");
            printf("início e acima de %d será interpretado como inserção no final\n\n", tamanho);
            
            // Inicia os chats de inserção, onde se pergunta dados 
            // sobre a nova música antes de inserir, assim como a
            // posição onde o usuário quer inseri-la.
            iniciarInsercao(head, &pos, novoElemento);
            
            // Conforme explicado pelo texto: 
            // "Qualquer número abaixo de 1 será interpretado como inserção no
            // início e acima de %d será interpretado como inserção no final".
            if ((pos <= 1) || (pos >= tamanho)) {
               
                // Este if é verdadeiro para ambos os casos descritos
                // porque o procedimento para ambos em parte é o mesmo, 
                // tais procedimentos foram englobados em uma única função.
                inserirInicioFinal(head, novoElemento);
                // Isto devve-se ao fato que esta é uma lista dupla-
                // mente encadeada e circular.
                // Por conta disso, itens inseridos ao final
                // e no começo têm os mesmos ponteiros apontando
                // para as mesmas coisas.
                
                // O único ponto diferencial é que itens inseridos 
                // ao final não poderão ser o head, mas os itens 
                // inseridos ao início, sim.
                if (pos <= 1) 
                    // PASSO 6
                    /*
                       antrAoHead        head           segundo         terceiro
                            |             |               |               |
                            |             |               |               |
                        +---+---+       +---+---+       +---+---+       +---+---+ 
                        | # | #<----------O | #<----------O | #<----------O | # |
                        | # | O----------># | O----------># | #----------># | # |
                        +---+---+       +---+---+       +---+---+       +---+---+ 
                    */
                    // CÓDIGO: 
                    head = novoElemento;
                    // FIM PASSO 6
            } else {
                inserirMeio(head, novoElemento, pos);
            } 
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
    
    // Por questão de praticidade,
    // char Nome[50] será utilizado pa-
    // ra abrigar todas as variáveis do
    // tipo vetor de caracteres deste 
    // seguimento.
    char nome[50];
    
    printf("Nome da música: ");
    scanf("%s", nome);
    strcpy(novoElemento->nome, nome);
    
    printf("Nome da banda/do artista: ");
    scanf("%s", nome);
    strcpy(novoElemento->autor, nome);
    
    float faixa;
    printf("Duração da faixa (em minutos): ");
    scanf("%f", &faixa);
    novoElemento->duracao_da_faixa = faixa;
}



void inserirInicioFinal(Musica *head, Musica *novoElemento) {
    // ESTADO INICIAL
    /*
           último           head          segundo 
               |             |             | 
               |             |             | 
           +---+---+       +---+---+       +---+---+ 
    <-ANTR | # | #<----------O | #<----------O | # |   
           | # | O----------># | O----------># | # | PROX->
           +---+---+       +---+---+       +---+---+ 
    */
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 1
    /*
       antrAoHead        head           segundo 
            |             |               | 
            |             |               | 
        +---+---+       +---+---+       +---+---+ 
        | # | #<----------O | #<----------O | # |
        | # | O----------># | O----------># | # |
        +---+---+       +---+---+       +---+---+ 
    */    
    // CÓDIGO:
    Musica* antrAoHead = head->antr;
    // FIM PASSO 1
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 2
    /*
       antrAoHead        head           segundo 
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
    antrAoHead->prox = novoElemento;
    // FIM PASSO 2
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 3
    /*
       antrAoHead                             head           segundo 
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
    novoElemento->prox = head;
    // FIM PASSO 3
    
    /*-----------------------------------------------------------------*/
    
    // PASSO 4
    /*
      antrAoHead                             head           segundo 
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
    head->antr = novoElemento;
    // FIM PASSO 4
    
    /*-----------------------------------------------------------------*/

    // PASSO 5
    /*
      antrAoHead                             head           segundo 
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
    novoElemento->antr = antrAoHead;
    // FIM PASSO 5
    
    /*-----------------------------------------------------------------*/
    
    // RESULTADO FINAL
    /*
       antrAoHead      novoElemento      head           segundo
            |             |               |               |
            |             |               |               |
        +---+---+       +---+---+       +---+---+       +---+---+ 
        | # | #<----------O | #<----------O | #<----------O | # |
        | # | O----------># | O----------># | O----------># | # |
        +---+---+       +---+---+       +---+---+       +---+---+ 
    */
}

void inserirMeio(Musica *head, Musica *novoElemento, int pos) {
    int i = 1;
    Musica* elementoVarredura = head;
                
    do {
        elementoVarredura = elementoVarredura->prox; 
        i++;
    } while (i < pos);
            
    
    
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
