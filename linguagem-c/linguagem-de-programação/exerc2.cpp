#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// esta struct vai gravar as informações do usuário
struct imposto_renda {
    char nome[100];
    float sal;
    float res;
};
struct imposto_renda imp;
// será uma função para formatar números em valores monetários (ex. 1700,50 -> 1.700,50)
// para mais informações a respeito, procure pela função no fim do código
char* convert2Mon(float num, int format);
int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("E aí, amigo! Quer saber seu imposto de renda?\n");
    printf("\n\n");
    printf("Então, informe primeiro o seu nome para eu não ser deseducado: \n");
    scanf("%s", &(imp.nome));
    printf("\n\n");
    printf("%s, agora informe seu salário também: \n", imp.nome);
    scanf("%f", &(imp.sal));
    if (imp.sal >= 1637.12 && imp.sal <= 2453.5)
    {
        imp.res = (imp.sal * 7.5) / 100;
    }
    else if (imp.sal >= 2453.51 && imp.sal <= 3271.38)
    {
        imp.res = (imp.sal * 15) / 100;
    }
    else if (imp.sal >= 3271.39 && imp.sal <= 4087.65)
    {
        imp.res = (imp.sal * 22.5) / 100;
    }
    else if (imp.sal >= 4087.66)
    {
        imp.res = (imp.sal * 27.5) / 100;
    }
    else
    {
        imp.res = 0;
    }
    if (imp.res != 0) {
        printf("\n\n");
        /*
        Eu aprendi que não tem como retornar uma array de
        chars em uma função...
        Pesquisei bastante, e cheguei à conclusão que deveria
        criar uma array para
        receber os valores de uma array interna à função (vi a
        ideia no StackOverflow) e,para isso, eu devo transformar a função em ponteiro
        também (você pode observar isso na assinatura e nela
        mesma).
        Eu li em outro lugar também que não dava para fazer isso
        (dar um print em uma
        array de char retornada por uma função (ex. printf("%s",
        convert2Mon(1700.00, 0)); )
        porque ela não era uma string porque não terminava com
        '\0', pensei em acrescentar
        isso ao final manualmente na função mas ainda não
        testei.
        Também poderia ter simplesmente posto o printf dentro da
        função mas eu queria
        deixar essa função reutilizável para outros códigos.
        Outra coisa: eu optei por fazer minha própria função
        porque não entendi e
        fiquei com preguiça de aprender como usar uma função da
        biblio monetary.h,
        também tentei uma tal de comma flag ("%'.2f") que
        disseram que ia funcionar
        mas não funcionou.
        Para deixar ainda mais reutilizável, eu deixei um
        segundo parâmetro,
        que é um inteiro que seleciona qual conjunto utilizar: .
        e , ou , e .
        Dependendo da minha necessidade no momento (posso um dia
        estar querendo
        escrever em dólares, por exemplo).
        0 = "12.345,00"
        1 = "12,345.00"
        2 = "12 345,00"
        3 = "12 345.00"
        Ah! E eu gosto de escrever as coisas em Inglês. Foi mal.
        */
        char* mon = convert2Mon(imp.res, 2);
        printf("Seu imposto de renda: R$ %s", mon);
// limpando ...
        free(mon);
    }
    else
    {
        printf("É o seu dia de sorte : ) Nada de imposto de renda.\n");
        printf("Ou não, considerando que isso também significa que sua renda mensal à baixa xD");
    }
    printf("\n\n");
    system("pause");
    return 0;
}
char* convert2Mon(float num, int format) {
// esse num2 vai ser usado e logo descartado para ser
// dividido por dez várias vezes
    double num2 = num;
// à o tamanho da parte inteira do número
    int length = 0;
// a cada vez que ele à dividido por 10, length ganha mais um
// se o num2 chegar a 1 ou ser menos que 1, o código para,
// justamente porque precisamos contar somente a parte inteira
    do {
        num2 /= 10;
        length++;
    }
    while (num2 >= 1);
// calloc vai alocar as "casas" à array
// "length + 3" porque há também os dois decimais de centavos e a
// vírgula/ponto que separa a parte decimal
// pois é, vamos converter em string
    char* arr = (char*)calloc((length + 3), sizeof(char));
// isso aqui vai ser usado para converter
// à da biblio stdio.h
    sprintf(arr, "%.2f", num);
// agora, a gente dá uma olhada no formato escolhido
// e troca de acordo
    if (!format || format == 2) {
        for (int k = 0; k < length + 3; k++)
            if (arr[k] == '.') arr[k] = ',';
    }
// res: 123456.78 => 123456,78
    else {
        for (int k = 0; k < length + 3; k++)
            if (arr[k] == ',') arr[k] = '.';
    }
// res: 123456,78 => 123456.78
// os números são divididos de três em três algarismos...
    int i = 0;
    while (i < length) {
        i++;
// então, ele vai somando mais um no i
// e verificando com o if se a divisão dele com 3 dê exata
// o i++; vem primeiro, porque 0/3 não dá resto também
// mas não posso deixar o código usar i=0 porque bugaria
// o sistema todo
// poderia ter inicializado o i com 1, mas tanto faz
        if (i % 3 == 0) {
// agora vem a mágica
// este trecho move todos os itens da array um índice adiante
// até o ponto onde deverá ser localizado o divisor,
// o que ele na realidade faz à pegar o número do índice anterior e
// colocar no atual assim sucessivamente, criando uma cópia temporária,
// visto isso, quando chegar na casa do divisor ele para e
// deixa duplicado, sem subscrever com o anterior em cima,
// basta substituir mais tarde
            for (int j = length + 4; j > length - i; j--) {
// não quero que ele chegue até o índice 0
// ex. 123456,78 tem 6 dígitos na parte inteira
// (length 6), i primeiro começa com 3 (length-i = 3)
// se arr[0] = 1, arr[1] = 2... então:
// arr[3] = 4, logo: 1234456,78
// beleza, o próximo i é 6, se eu deixasse o loop usar o 6
// então length - i = 0, índice = 0, ocorreria isto:
// 11234456,78, mas eu não quero que o primeiro se
// repita (não existem números assim: .123.456,78 -
// pois lembre que vamos substituí-los)
                if (length - i > 0)
                    arr[j] = arr[j - 1];
            }
// agora vem a substituição
// verifiquei de novo se a subtração
// dos dois não vai dar 0
            if (length - i > 0) {
// checa o formato
                if (!format) {
// pega a posição que precisa ser substituída
// pela subtração de length e i
                    arr[length - i] = ' ';
                }
                else if (format == 1) {
                    arr[length - i] = ',';
                }
                else {
                    arr[length - i] = ' ';
                }
            }
        }
    };
// retorna o arr
    return arr;
// fim
}
