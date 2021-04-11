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
void inserirInicio(Musica *head, Musica *novoElemento);
void inserirFinal(Musica *head, Musica *novoElemento);
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
    head->duracao_da_faixa = 5.43; // 5 minutos e 26 segundos
    head->prox             = segunda;
    head->antr             = terceira;
    
    strcpy(segunda->nome      , "King and Lionheart");
    strcpy(segunda->autor     , "Of Monsters And Men");
    segunda->duracao_da_faixa = 4.583; // 4 minutos e 35 segundos
    segunda->prox             = terceira;
    segunda->antr             = head;
    
    strcpy(terceira->nome      , "Pra Você Guardei O Amor");
    strcpy(terceira->autor     , "Nando Reis");
    terceira->duracao_da_faixa = 5.716; // 5 minutos e 43 segundos
    terceira->prox             = head;
    terceira->antr             = segunda;
    // FIM INICIALIZAÇÃO DE MÚSICAS
  
    // Conterá a opção escolhida pelo usuário
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
        
        // "3 - para encerrar"
        if (decisao == 3)
            break;
            // break quebra o loop e vai direto 
            // ao return do main onde finaliza 
            // o programa

        // "2 - para listar todas as músicas"        
        if (decisao == 2)
            listarMusicas(head);
        
        // "1 - para inserir nova música"
        if (decisao == 1) {
            int pos, tamanho;
            Musica* novoElemento = (Musica*) malloc(sizeof(Musica));
            
            system("clear");
    
            contarMusicas(head, &tamanho);
            printf("Sua playlist possui atualmente %d músicas\n\n", tamanho);
            printf("Insira uma posição entre 1 (ou igual a 1) e %d (ou igual a %d)\n", tamanho, tamanho);
            printf("Qualquer número abaixo de 1 será interpretado como inserção no\n");
            printf("início e acima de %d será interpretado como inserção no final\n\n", tamanho);
            
            iniciarInsercao(head, &pos, novoElemento);
            if (pos <= 1) {
                inserirInicio(head, novoElemento);
                head = novoElemento;
            } else if (pos >= tamanho) {
                inserirFinal(head, novoElemento);
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

void inserirInicio(Musica *head, Musica *novoElemento) {
    Musica* antr       = head->antr;
    antr->prox         = novoElemento;
    novoElemento->prox = head;
    novoElemento->antr = antr;
    head->antr         = novoElemento;
}

void inserirFinal(Musica *head, Musica *novoElemento) {
    Musica* antr       = head->antr;
    antr->prox         = novoElemento;
    novoElemento->prox = head;
    novoElemento->antr = antr;
    head->antr         = novoElemento;
}

void inserirMeio(Musica *head, Musica *novoElemento, int pos) {
    int i = 1;
    Musica* elementoVarredura = head;
                
    do {
        elementoVarredura = elementoVarredura->prox; 
        i++;
    } while (i < pos);
            
    Musica* antr       = elementoVarredura->antr;

    antr->prox         = novoElemento;
    novoElemento->antr = antr;
    novoElemento->prox = elementoVarredura;
}
