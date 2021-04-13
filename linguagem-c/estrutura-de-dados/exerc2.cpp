#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constante Hash.
#define A 0.618
// Tamanho da tabela Hash.
#define M 10

typedef struct Aluno {
    int RU;
    char email[50];
    char nome[50];
    char status; // L = livre, O = Ocupado e R = Removido.
} Aluno;

// Função hash.
int h(int k);

// Começa chat de remoção.
void iniciarRemocao(Aluno tabelaAlunos[], int *numAlunos);
// Faz a remoção de aluno na tabela hash.
void removerAluno(int RU, int *numAlunos, Aluno tabelaAlunos[]);

// Começa chat de inserção.
void iniciarInsercao(Aluno tabelaAlunos[], int *numAlunos);
// Faz a inserção de alunos na tabela hash.
void inserirAluno(int RU, char nome[], char email[], int *numAlunos, Aluno tabelaAlunos[]);

// Começa chat de busca.
void iniciarBusca(Aluno tabelaAlunos[]);
// Efetua a busca de alunos por RU.
void buscarAluno(int RU, Aluno tabelaAlunos[]);

int main() {
    // Tabela Hash contendo dados de todos os alunos.
    Aluno tabelaAlunos[M];
    
    // numAlunos = Quantidade de inserções/cadastrados (por sessão).
    int numAlunos = 0, decisao;
    
    // numAlunos aumenta 1 sempre que algum aluno for inserido e 
    // diminui 1 sempre que um for removido. É possível notar que
    // este tipo de sistema é benéfico para diminuir a complexidade
    // assintótica da função de inserir.
   
    
    // INÍCIO INSERÇÃO DE 10 CONTATOS
    // 1.
    char nome[] = {"FELIPE ALVES"}, email[] = {"j.contato.felipe@gmail.com"};
    inserirAluno(3344308, nome, email, &numAlunos, tabelaAlunos);
    // 2.
    strcpy(nome    , "WEBER DE QUADROS"); 
    strcpy(email   , "q.contato.weber@gmail.com");
    inserirAluno(1989966, nome, email, &numAlunos, tabelaAlunos);
    // 3.
    strcpy(nome    , "CARLOS QUEIROZ"); 
    strcpy(email   , "q.contato.carlos@gmail.com");
    inserirAluno(3602569, nome, email, &numAlunos, tabelaAlunos);
    // 4.
    strcpy(nome    , "RODRIGO RIBEIRO"); 
    strcpy(email   , "r.contato.ribeiro@gmail.com");
    inserirAluno(6133069, nome, email, &numAlunos, tabelaAlunos);
    // 5.
    strcpy(nome    , "SHANA FEITEN"); 
    strcpy(email   , "f.contato.shana@gmail.com");
    inserirAluno(5542266, nome, email, &numAlunos, tabelaAlunos);
    // 6.
    strcpy(nome    , "CARLOS QUEIROZ"); 
    strcpy(email   , "q.contato.carlos@gmail.com");
    inserirAluno(2094187, nome, email, &numAlunos, tabelaAlunos);
    // 7.
    strcpy(nome    , "SOFIA BRENDA"); 
    strcpy(email   , "b.contato.sofia@gmail.com");
    inserirAluno(9734032, nome, email, &numAlunos, tabelaAlunos);
    // 8.
    strcpy(nome    , "ELLEN BEATRIZ"); 
    strcpy(email   , "b.contato.ellen@gmail.com");
    inserirAluno(6900784, nome, email, &numAlunos, tabelaAlunos);
    // 9.
    strcpy(nome    , "DIEGO VENANCIO"); 
    strcpy(email   , "v.contato.diego@gmail.com");
    inserirAluno(6619693, nome, email, &numAlunos, tabelaAlunos);
    // 10.
    strcpy(nome    , "NAÍME ANDREOTTI"); 
    strcpy(email   , "a.contato.naime@gmail.com");
    inserirAluno(2902164, nome, email, &numAlunos, tabelaAlunos);
    // FIM INSERÇÃO
    
    
    for (;;) {
        system("clear");
        
        printf("inserir [1] - remover [2] - buscar por RU [3]\n");
        scanf(" %d", &decisao);
        
        system("clear");
            
        if (decisao == 3)
            iniciarBusca(tabelaAlunos);
        else if (decisao == 2)
            iniciarRemocao(tabelaAlunos, &numAlunos);
        else if (decisao == 1)
            iniciarInsercao(tabelaAlunos, &numAlunos);
        
        printf("\nPressione qualquer tecla para voltar...\n");
        char ch;
        scanf(" %c", &ch);
    }
    
    return 0;
}

int h(int k) {
    return floor(M*(k*A - floor(k*A)));
}

void iniciarRemocao(Aluno tabelaAlunos[], int *numAlunos) {
    int RU;
    printf("RU do aluno que quer remover: ");
    scanf(" %d", &RU);
    
    printf("\n");
    removerAluno(RU, numAlunos, tabelaAlunos);
    printf("\n");
}

void removerAluno(int RU, int *numAlunos, Aluno tabelaAlunos[]) {
    int d = RU, i = 0; 
    
    do {
        d = h(d + i);
        i++;
    } while ((tabelaAlunos[d].RU != RU) && (i <= M));
    // Enquanto o RU for diferente, ele continua pas-
    // sando até achar.
    
    // Também impede que o looping continue infinita-
    // mente caso não haja correspondente, usando 
    // "i <= M".
    
    if (tabelaAlunos[d].RU == RU) {
        
        // Como removemos, numAlunos diminui 1.
        *numAlunos -= 1;
        
        // Atualizando o status do campo.
        tabelaAlunos[d].status = 'R';
        
        printf("%c", tabelaAlunos[d].status);
        printf("Aluno removido com sucesso!");
    } else {
        printf("Nenhum RU correspondente!");
    }
}

void iniciarInsercao(Aluno tabelaAlunos[], int *numAlunos) {
    
    int RU;
    printf("RU: ");
    scanf(" %d", &RU);
    
    char nome[50];
    printf("Nome: ");
    scanf(" %s", nome);
    
    char email[50];
    printf("Email: ");
    scanf(" %s", email);
    
    printf("\n");
    inserirAluno(RU, nome, email, numAlunos, tabelaAlunos);
    printf("\n");
}

void inserirAluno(int RU, char nome[], char email[], int *numAlunos, Aluno tabelaAlunos[]) {
    
    
    // Este if testa de antemão se a quantidade de
    // alunos inseridos desde o momento que o pro-
    // grama começou a rodar já superou a quantia 
    // de espaço disponível na tabela.
    
    if (*numAlunos => M) {
        printf("A tabela está cheia!");
        // return "quebra" a função, nada abaixo 
        // disto será efetuado.
        return;
    }
    
    // Isso diminui a complexidade assintótica do pro-
    // grama, porque, sem o if, o looping a seguir se-
    // ria obrigado a verificar todos os elementos da
    // tabela para afirmar com certeza que todos os 
    // campos estão ocupados.
    
    // Complexidade assintótica: "CA"
    
    // Temos 3 situações: o programa achar espaço li-
    // vre de primeira (CA unitário/constante - Big 
    // Omega), ele demorar um pouco até achar espa-
    // ço livre (CA indetermindo - Big Theta) ou a
    // tabela estar cheia e ele ter que varrer todos 
    // os elementos (CA n - Big O).
    
    // Ao substituírmos a terceira situação por um if
    // no início temos que a CA resultante será unitá-
    // ria, tanto no Big O quanto no Big Omega!
    
    // O Big Theta acaba sendo mais complexo virando o
    // novo Big O.
    
    // A vantagem disso é um programa mais rápido!
    
    *numAlunos += 1;
    
    int d = RU, i = 0; 
    
    do {
        d = h(d + i);
        i++;
    } while (tabelaAlunos[d].status == 'O');
    // Enquanto o status for de ocupado, ele con-
    // tinua passando até achar um ponto livre ou 
    // removido. 
    
    // Vamos inserir os dados passados na po-
    // sição d.
    tabelaAlunos[d].RU           = RU;
    strcpy(tabelaAlunos[d].email , email);
    strcpy(tabelaAlunos[d].nome  , nome);
    // Sinalizamos que o campo foi ocupado
    // ("O").
    tabelaAlunos[d].status       = 'O';
}

void iniciarBusca(Aluno tabelaAlunos[]) {
    int RU;
    
    printf("Busca: ");
    scanf(" %d", &RU);
        
    printf("\n");
    buscarAluno(RU, tabelaAlunos);
    printf("\n");
}

void buscarAluno(int RU, Aluno tabelaAlunos[]) {
    int d = RU, i = 0; 
    
    do {
        d = h(d + i);
        i++;
    } while ((tabelaAlunos[d].RU != RU) && (i <= M));
    // Enquanto o RU for diferente, ele continua pas-
    // sando até achar.
    
    // Também impede que o looping continue infinita-
    // mente caso não haja correspondente, usando 
    // "i <= M".
    
    if ((tabelaAlunos[d].RU == RU) && (tabelaAlunos[d].status != 'R')) {
        printf("Aluno: %s\n", tabelaAlunos[d].nome);
        printf("Email: %s\n", tabelaAlunos[d].email);
        printf("RU: %d\n"   , tabelaAlunos[d].RU);
        printf("Pos: %d\n"  , d);
        printf("Encontrado na %dª tentativa", i);
    } else {
        printf("Nenhum aluno encontrado!");
    }
}
