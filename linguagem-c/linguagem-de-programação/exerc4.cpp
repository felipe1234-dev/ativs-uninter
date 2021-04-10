#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
// assinatura...
void calc_hexa(float L, float *area, float *perimetro);

int main()
{
    float L, area, perimetro;
  
    // permitindo o uso de acentos e,
    // trocando o ponto pela vírgula
    // em números decimais
    setlocale(LC_ALL, "Portuguese");
  
    printf("Informe a medida da aresta do seu hexágono regular: \n");
    scanf("%f", &L);
  
    // limpa a tela
    system("cls");
  
    // -e comercial indica a passagem de um endereço
    calc_hexa(L, &area, &perimetro);
  
    printf("Área: %.2f", area);
    printf("\n\n");
    printf("PerÍmetro: %.2f", perimetro);
    printf("\n\n");
  
    system("pause");
    return 0;
}

void calc_hexa(float L, float *area, float *perimetro) {
    // ocorrerão mudanças diretamente na memória
    // esta função muda os valores das variáveis
    // em qualquer lugar do código
    *area = (3*pow(L,2)*sqrt(3))/2;
    *perimetro = 6*L;
}
