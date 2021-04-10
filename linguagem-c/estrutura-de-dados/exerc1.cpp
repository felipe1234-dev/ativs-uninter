#include <stdio.h>
#include <stdlib.h>

struct Musica {
    char nome[20];
    char artista[20];
    char banda[20];
    float duracao_da_faixa; // em minutos
    struct Musica* prox;
    struct Musica* antr; // anterior
};

typedef struct Musica Musica;

int main()
{
    Musica* head     = (Musica*) malloc(sizeof(Musica));
    Musica* segunda  = (Musica*) malloc(sizeof(Musica));
    Musica* terceira = (Musica*) malloc(sizeof(Musica));
    
    // INICIALIZAÇÃO DE ALGUMAS MÚSICAS
    head->nome             = "Sing for the Moment";
    head->artista          = "Eminem";
    head->duracao_da_faixa = 5.43; // 5 minutos e 26 segundos
    head->prox             = segunda;
    head->antr             = terceira;
    
    segunda->nome             = "King and Lionheart";
    segunda->banda            = "Of Monsters And Men";
    segunda->duracao_da_faixa = 4.583; // 4 minutos e 35 segundos
    segunda->prox             = terceira;
    segunda->antr             = head;
    
    terceira->nome             = "Pra Você Guardei O Amor";
    terceira->artista          = "Nando Reis";
    terceira->duracao_da_faixa = 5.716; // 5 minutos e 43 segundos
    terceira->prox             = head;
    terceira->antr             = segunda;
    // FIM INICIALIZAÇÃO
    
    int decisao;
    
    printf("PLAYER DE MÚSICA");
    printf("\n\n");
    
    for (;;) {
        printf("Digite: \n");
        
        printf("1 - para inserir nova música\n");
        printf("2 - para listar todas as músicas\n");
        printf("3 - para encerrar\n");
        
        printf("Decisão: ");
        scanf("%d", &decisao);
        
        if (decisao == 3)
            break;
        
        /*if (decisao == 2)
            listarMusicas*/
        
        system("clear");
    }
    
    
    return 0;
}
