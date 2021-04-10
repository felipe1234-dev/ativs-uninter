#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
struct ponto_inicial {
    float x1;
    float y1;
};
struct ponto_final {
    float x2;
    float y2;
};
struct ponto2d {
    struct ponto_inicial p0;
    struct ponto_final p1;
    float dist;
};
struct ponto2d coord;
/*
* Eu costumo escrever meus códigos em Inglês
*/
// processar escolha
void proccessChoice(int choice);
// printar instruções
void printInstructions(int choice);
// calcular distância
void calcDistance(float *dist, float x1, float y1, float x2, float y2);
int main() {
// permite todos os caracteres possíveis,
// será importante na função printInstructions
    setlocale(LC_ALL, "");
// inicializando
// coord = coordenada
    coord.p0.x1 = 0;
    coord.p0.y1 = 0;
    coord.p1.x2 = 0;
    coord.p1.y2 = 0;// começa
// ele inicia com 4
// porque 4 equivale
// ao ínicio do programa
    proccessChoice(4);
    return 0;
}
// esta função contém a base
// de tudo que vamos fazer no main
void proccessChoice(int choice) {
// sempre que há uma redefinição
// da escolha (choice)
// a tela é limpa
    system("cls");
// printa as instruções
// choice é passado como parâmetro
// para por o sinal de selecionado,
// (">"), ao lado da instrução equivalente
// observe que esse caractere só
// aparece por conta da configuração
// do setlocale
    printInstructions(choice);
// verifica o valor de choice
// e faz as instruções de acordo
    switch (choice) {
      case 1:
          printf("Valores:\n");
          printf("x1 = %.3f\n", (coord.p0.x1));
          printf("y1 = %.3f", (coord.p0.y1));
          printf("\n\n");
          printf("Novos valores:\n");
          printf("x1 = ");
          scanf("%f", &(coord.p0.x1));
          printf("y1 = ");
          scanf("%f", &(coord.p0.y1));
  // choice = 4 para sair automaticamente
  // deste menu
          choice = 4;
          break;
      case 2:
          printf("Valores:\n");
          printf("x2 = %.3f\n", (coord.p1.x2));
          printf("y2 = %.3f", (coord.p1.y2));
          printf("\n\n");
          printf("Novos valores:\n");
          printf("x2 = ");
          scanf("%f", &(coord.p1.x2));
          printf("y2 = ");
          scanf("%f", &(coord.p1.y2));
  // choice = 4 para sair automaticamente// deste menu
          choice = 4;
          break;
      case 3:
  // função de calcular distância e seus parâmetros
          calcDistance(&coord.dist, coord.p0.x1, coord.p0.y1, coord.p1.x2, coord.p1.y2);
          printf("Distância entre dois pontos (x1,y1)(x2,y2): d = %f", coord.dist);
          printf("\n\n");
          printf("Escolha: ");
  // solicitar-lhe-á uma nova escolha
          scanf("%d", &choice);
          break;
      case 4:
          printf("Escolha: ");
  // solicitar-lhe-á uma nova escolha
          scanf("%d", &choice);
          break;
      default:
  // qualquer número acima de 4 ou abaixo
  // de 0 finaliza o programa
          system("pause");
  // 0 sinaliza que foi com sucesso
          exit(0);
          break;
    }
// como é uma função recursiva,
// a função se chama dentro dela
// mesma
// mas sempre como parâmetro um
// novo valor de choice que
// foi ou pôde ser redefinido
// em cada case pelo usuário
    proccessChoice(choice);
// tal sistema torna a experiência
// bastante interativa e agradável,
// em que o usuário pode escolher o
// que fazer em seguida, limpando a
// a tela a cada escolha,
// deixando somente o que o
// usuário pedir e não cheio
// de informações desnecessárias
// além de poder mudar e olhar de novo
// as coordenadas quantas vezes
// quiser sem precisar reiniciar
// o programa, permitindo diversos
// “experimentos” com novas coordenadas
// de forma eficiente
}
void printInstructions(int choice) {
    printf("Pressione...");
    printf("\n\n");
// aqui foi usado o operador ternário,
// eu acabei testando e por sorte isso
// funciona em printfs. Olha só que interessante!
    printf("[1] - Digitar os valores do primeiro ponto %c\n", choice == 1 ? ">" : "");
// cada operador ternário verifica se o número do
// choice equivale à numeração de sua instrução
// se sim, envia o símbolo, ">", que significa "selecionado"
// caso contrário, espaço vazio
    printf("[2] - Digitar os valores do segundo ponto %c\n", choice == 2 ? ">" : "");
    printf("[3] - Mostrar a distância entre os pontos %c\n", choice == 3 ? ">" : "");
    printf("[4] - Sair\n");
    printf("[+] - Finalizar programa\n\n");
}
void calcDistance(float *dist, float x1, float y1, float x2, float y2) {
// isto calcula a distância
// já vem com um ponteiro para
// mudar diretamente na memória
// e para que o print no proccessChoice
// puxe o valor resultante daqui
    *dist = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}
