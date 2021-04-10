#include <stdlib.h>
#include <string.h>
// colocada para permitir o uso da função toupper(), como requisitado
#include <ctype.h>
// biblio para acentos
#include <locale.h>
int main()
{
    /*
    * Aviso: Originalmente, eu tinha o costume de escrever código somente em Inglês
    * (nome das variáveis, por exemplo), nestas lições, acabei mesclando
    * entre ambos os idiomas.
    */
// permite o uso de acentos
    setlocale(LC_ALL, "Portuguese");
// uma array 2d...
// guarda 50 caracteres para cada 5 frases
    char **frases = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++) {
        frases[i] = (char *)malloc(50 * sizeof(char));
    }
    printf("Digite 5 frases aleatórias: ");
    printf("\n\n");
    for (int j = 0; j < 5; j++) {
        printf("%d.\n", j+1);
        scanf(" %[^\n]", &(frases[j][0]));
// testa, por meio da função strlen(),
// se a frase enviada está dentro do limite
        if (strlen(frases[j]) > 50) {
            printf("\nSua frase excedeu o limite de 50 caracteres.");
// esse j-- acaba trancando o usuário no mesmo
// índice (se está em j=2,
// if diminui 1 de j, j=1, for soma 1 novamente e,
// j volta a ser 2, até ele por
// uma frase n_ch =< 50)
            j--;
        }
        printf("\n\n");
    }
    printf("\n\n");
// path é inicializado
// ele é o "caminho" (nome) do arquivo
// máximo: 20 caracteres
    char *path = (char *)malloc(20 * sizeof(char));
    printf("Escreva o nome do arquivo no qual você quer gravar: ");
    scanf("%s", path);
    printf("\n\n");
// inicializa arquivo no modo append
// modo append é bom porque, se quiser,
// poderei por mais frases no futuro
    FILE *arq = fopen(path, "a");
    if((arq = fopen(path, "a")) != NULL) {
        printf("Aberto com sucesso!\n");
        printf("Inserindo as frases, um momento...");
        printf("\n\n");
        for (int k = 0; k < 5; k++) {
// strlen() pega somente o nº de casas preenchidas
            int lim = strlen(frases[k]);
            for (int l = 0; l < lim; l++) {
                frases[k][l] = toupper(frases[k][l]);
                fputc(frases[k][l], arq);/*
...transforma-as em maiúsculas e,
em seguida, as envia ao arquivo
*/
            }
        }
// dá uma limpada primeiro na 2ª dimensão
// da array... (250 slots)
        for (int m = 0; m < 5; m++) {
            free(frases[m]);
        }
// em seguida, limpar os 5 slots restantes
        free(frases);
    } else {
        printf("Houve algum erro ao criar o arquivo.\n");
        printf("Problema comum: Antivírus está bloqueando acesso à pasta.");
        printf("\n\n");
        system("pause");
// li que o parâmetro 1 indica finalização com fracasso
// do programa, 0 o oposto.
        exit(1);
    }
// fecha
    fclose(arq);
    printf("Fechado e inseridas as frases corretamente.");
    printf("\n\n");
// inicializa, novamente, o arquivo, mas
// em modo de leitura
    arq = fopen(path, "r");
    if((arq = fopen(path, "r")) != NULL) {
// não precisamos mais do path,
// podemos limpá-lo
        free(path);
// pegaremos os chars do arquivo
// para imprimir na tela
// ch conter-as-á
        int ch;
// for funciona enquanto o arquivo não
// retornar o EOF (que sinaliza o
// fim do arquivo)
        for (int n = 0; feof(arq) == 0; n++) {
// pega o caractere e envia para ch
            ch = fgetc(arq);
// printa o anterior
            printf("%c", (char) ch);
        }
        printf("\n\n");
        printf("Arquivo lido com sucesso!");
    } else {
        printf("Houve algum problema ao ler o arquivo.\n");
        printf("Tente novamente mais tarde");
        printf("\n\n");
        system("pause");
        exit(1);
    }
    printf("\n\n");
// fecha
    fclose(arq);
    system("pause");
